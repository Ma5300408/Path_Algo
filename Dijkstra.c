#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

bool visit[COLS];
int dist[COLS];


int choose(int size){

  int min = 1e9;
  int k;
  int re_value;
   for(k = 0; k < size; k++){
      if(dist[k] < min && visit[k]!=true){
        min = dist[k];
        re_value = k;
       }
    }

   return re_value;
}


void Dijkstra_Algo(const int n,const int v){

     int i;
     for(i = 0; i < n; i++){
             visit[i] = false;
       if(graph[v][i]!=0)dist[i] = graph[v][i];
       else dist[i] = 1e9;
     }
      visit[v] = true;
      dist[v] = 0;
    
     int j;
     for(j = 0; j < n; j++){
         int u = choose(n);  
         visit[u] = true;
         
         int w;
         for(w = 0; w < n; w++)
             if(!visit[w] && graph[u][w]!=0){
                  if(dist[u]+graph[u][w] < dist[w]){
                dist[w] = dist[u]+graph[u][w];
             }
           }


     }
}


int main()
{

  Dijkstra_Algo(ROWS,0);
  int i;
  for(i = 0; i < COLS; i++)printf(" %d ",dist[i]);


  return 0;
}
