#include<stdio.h>
#include<stdlib.h>
typedef struct graph{
	int v;
	int e;
	int **adj;
}graph;
 
 graph* adjMatrix(){
	 int i,u,v,j;
	 graph* g=(graph*)malloc(sizeof(graph));
	 if(!g){
		 printf("memory error..");
		 return;
	 }
	 scanf("%d %d",&g->v,&g->e);
	 g->adj=(int**)malloc(sizeof(int*)*g->v);
	 for(i=0;i<g->v;i++){g->adj[i]=(int*)malloc(sizeof(int)*g->v);}
	 for(i=0;i<g->v;i++){
		 for(j=0;j<g->v;j++){
			 g->adj[i][j]=0;
		 }
	 }
	 for(i=0;i<g->e;i++){
		 scanf("%d %d",&u,&v);
		 g->adj[u][v]=1;
		 g->adj[v][u]=1;
	 }
	 return g;
 }
 printGraph(graph* g){
	 int i,j;
	 for(i=0;i<g->v;i++){
		 for(j=0;j<g->v;j++){
			 printf("%d\t",g->adj[i][j]);
		 }printf("\n");
	 }
 }
 printSimpleLanguage(graph* g){
	 int i,j;
	 for(i=0;i<g->v;i++){printf("nodes iinked with %d node are ->",i);
		 for(j=0;j<g->v;j++){
			 
			 if(g->adj[i][j]== 1){
				 printf("\t%d,",j);
			 }
		 } printf("\n");
	 }
 }
 int main(){
	 graph* g=adjMatrix();
	 printGraph(g);
	 printSimpleLanguage(g);
 }