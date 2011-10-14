#include<iostream>

using namespace std;
#define MaxVertexNum 100
typedef int VertexType;
typedef enum{FALSE,TRUE}Boolean;//FALSE为0，TRUE为1
Boolean visited[MaxVertexNum]; //访问标志向量是全局量

typedef struct node
{
  int adjvex;
  struct node *next;
  //若要表示边上的权，则应增加一个数据域
}EdgeNode;

//顶点表结点
typedef struct vnode
{
  //顶点域
  VertexType vertex;
  //边表头指针
  EdgeNode *firstedge;
}VertexNode;

//AdjList是邻接表类型
typedef VertexNode AdjList[MaxVertexNum];

//对于简单的应用，无须定义此类型，可直接使用AdjList类型。
typedef struct ALGraph
{
  //邻接表
  AdjList adjlist;
  //图中当前顶点数
  int n;
  //图中当前边数
  int e;
}Graphic;


//此方法是把新结点插在头结点的后面
void CreateGraphic(ALGraph *G,int* data,int dim)
{
  for(int i=0;i<dim;i++)
  {
    G->adjlist[i].firstedge=NULL;
    for(int j=i+1;j<dim;j++)
    {
      if(data[i*dim+j]!=0)
      {
        EdgeNode *edgeNode=new EdgeNode;
        edgeNode->adjvex=j;
        edgeNode->next=G->adjlist[i].firstedge;
        G->adjlist[i].firstedge=edgeNode;
      }
    }
  }
}

//深度优先搜索
void DFSTraverse(ALGraph *G)
{
  for(int i=0;i<G->n;i++)
    visited[i]=FALSE;
  for(int i=0;i<G->n;i++)
  {
    if(visited[i]==FALSE)
    {
      visited[i]=TRUE;
      cout<<i<<",";
      EdgeNode *edgeNode=G->adjlist[i].firstedge;
      while(edgeNode!=NULL)
      {
        if(visited[edgeNode->adjvex]==FALSE)
        {
          cout<<edgeNode->adjvex<<",";
          visited[edgeNode->adjvex]=TRUE;
          edgeNode=edgeNode->next;
        }
      }
    }
  }
  cout<<endl;
}

int main()
{
  Graphic Create;
  Create.n=4;
  int data[4][4]={{0,1,1,1},{1,0,1,1},{1,1,0,0},{1,1,0,0}};
  CreateGraphic(&Create,*data,4);
  DFSTraverse(&Create);
  return 0;
}

