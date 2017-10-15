#include <stdio.h>
#include <stdlib.h>
 typedef struct node{
	 int vertexNumber;
	 struct node* next;
 }list;
 
 typedef struct graph{
	 int v;
	 int e;
	 list* array;
 }graph;
int visited[8]; int parent[8];
 graph* arrayList(){
	 int i,x,y;
	 list* temp;
	 graph* g=(graph*)malloc(sizeof(graph));
	 if(!g){
		 printf("memory error...");
		 return;
	 }
	 scanf("%d %d",&g->v,&g->e);
	 (g->array)=(list*)malloc(sizeof(list)*g->v);
	 for(i=0;i<g->v;i++){
		// g->array[i]=(list*)malloc(sizeof(list));
		 g->array[i].vertexNumber=i;
		 g->array[i].next=NULL;
	 }
	 for(i=0;i<g->e;i++){
		 scanf("%d %d",&x,&y);
		 temp=(list*)malloc(sizeof(list));
		 temp->vertexNumber=y;
		 temp->next=g->array[x].next;
		 g->array[x].next=temp;
		 /*temp=(list*)malloc(sizeof(list));
		 temp->vertexNumber=x;
		 temp->next=g->array[y].next;
		 g->array[y].next=temp;*/
	 }
	 return g;
 }

 void printGraph(graph* g)
{
    int i;
    for (i = 0; i < g->v; i++)
    {
        list *temp= g->array[i].next;// i may remain it as *temp=g->array[i]; see what happen than...
        printf("\n Adjacency list of vertex %d------>  ", i);
        while (temp)
        {
            printf("-> %d", temp->vertexNumber);
            temp = temp->next;
        }
        printf("\n");
    }
}
void DFS(graph* g, int u){ list* temp=g->array[u].next;
	visited[u]=1; printf("\n%d",u);
	while(temp){if(visited[temp->vertexNumber]== 0){ parent[u]= temp->vertexNumber;
	DFS(g,temp->vertexNumber);}
	else return;
	temp=temp->next;}
	
}
void DFStraversal(graph* g,int startpoint){int i;
	for(i=0;i<g->v;i++){visited[i]=0; parent[i]= 0;}
	//for(i=0;i<g->v;i++){
		//if(!visited[i])
			DFS(g,startpoint);
	
}
 int main(){ int i=0;
	 graph* g=arrayList();
	 printGraph(g);for(i=0;i<g->v;i++) printf("\n%d is a parent of %d",i,parent[i]);
  DFStraversal(g,0);	 
 }