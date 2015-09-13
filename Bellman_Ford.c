#include<stdio.h>
#include<stdlib.h>
#define ROWS 7
#define COLS 7


int graph [ROWS][COLS] = { 0, 7, 0, 5, 0, 0, 0,
                           7, 0, 8, 9, 7, 0, 0,
                           0, 8, 0, 0, 5, 0, 0,
                           5, 9, 0, 0, 15, 6, 0,
                           0, 7, 5, 15, 0, 8, 9,
                           0, 0, 0, 6, 8, 0, 11,
                           0, 0, 0, 0, 9, 11, 0 
                         };


int dist[COLS];

void BellmanFord(int *G,const int v){

    int i;
    for(i = 0; i < COLS; i++){
     if(G[v*COLS+i]!=0)dist[i] = G[v*COLS+i];
     else dist[i] = 1e9;
    }

    int j;
    int a;
    int b;
    for(j = 1; j <= COLS-1; j++) //repeated V-1 times
      for(a = 0; a < ROWS; a++){
        for(b = 0; b < COLS; b++){
          if(dist[a]!=1e9 && G[a*COLS+b]!=0){ // have a path to...b
                if(dist[a]+G[a*COLS+b] < dist[b]){
                   dist[b] = dist[a] + G[a*COLS+b];
                } 
           }

         }
      }
}



int main()
{

   BellmanFord((int*)graph,0);
   int i;
   for(i = 0; i < COLS; i++)printf(" %d ",dist[i]);


  return 0;
}
