#include<iostream>

using namespace std;
#define MaxVertexNum 100
typedef int VertexType;
typedef enum{FALSE,TRUE}Boolean;//FALSEΪ0��TRUEΪ1
Boolean visited[MaxVertexNum]; //���ʱ�־������ȫ����

typedef struct node
{
  int adjvex;
  struct node *next;
  //��Ҫ��ʾ���ϵ�Ȩ����Ӧ����һ��������
}EdgeNode;

//�������
typedef struct vnode
{
  //������
  VertexType vertex;
  //�߱�ͷָ��
  EdgeNode *firstedge;
}VertexNode;

//AdjList���ڽӱ�����
typedef VertexNode AdjList[MaxVertexNum];

//���ڼ򵥵�Ӧ�ã����붨������ͣ���ֱ��ʹ��AdjList���͡�
typedef struct ALGraph
{
  //�ڽӱ�
  AdjList adjlist;
  //ͼ�е�ǰ������
  int n;
  //ͼ�е�ǰ����
  int e;
}Graphic;


//�˷����ǰ��½�����ͷ���ĺ���
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

//�����������
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

