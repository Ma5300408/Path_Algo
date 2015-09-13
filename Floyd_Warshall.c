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

int d[ROWS][COLS];
int medium[ROWS][COLS];

void Floyd_Warshall(int * G,const int loop_time)
{
   // int d[ROWS][COLS];
     int i;
     int j;
     int k;
     for(i = 0; i < ROWS; i++)
       for(j = 0; j < COLS; j++){
         if(G[i*COLS+j] != 0)d[i][j] = G[i*COLS+j];
         else d[i][j] = 1e9;

         medium[i][j] = -1;
       }

       for(i = 0; i < ROWS; i++)d[i][i] = 0;


       for(k = 0; k < loop_time; k++)
         for(i = 0; i < loop_time; i++)
           for(j = 0; j < loop_time; j++){

           if(d[i][k]+d[k][j] < d[i][j]){
                d[i][j] = d[i][k]+d[k][j];
                medium[i][j] = k;
             }

        }



}


void find_path(int i, int j)
{
     if(medium[i][j] == -1)return;

     find_path(i, medium[i][j]);
     printf(" %d ",medium[i][j]);
     find_path(medium[i][j], j);
}



int main()
{

  Floyd_Warshall((int*)graph,7);
  printf("internal path: ");
  find_path(0,6);
  printf("\n");
  
   printf("0 to nodes distances: ");
   int i;
   for(i = 0; i < COLS; i++)printf(" %d ",d[0][i]);

  return 0;
}
