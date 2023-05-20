#include <stdio.h> 
void bellman_ford(int a[9][9], int source) { 
 int done[9], distance[9], parent[9]; 
 int i, j, k; 
 for(i=0;i<9;i++) { 
 done[i] = 0; 
 distance[i] = 10000; 
 parent[i] = -1; 
 } 
 distance[source] = 0; 
 for(i=0;i<8;i++) { 
 for(j=0;j<9;j++) { 
 for(k=0;k<9;k++) { 
 if(a[j][k] != 0 && distance[j] != 10000 && distance[k] > distance[j] + a[j][k]) { 
 distance[k] = distance[j] + a[j][k]; 
 parent[k] = j;
 } 
 } 
 } 
 } 
 for(j=0;j<9;j++) { 
 for(k=0;k<9;k++) { 
 if(a[j][k] != 0 && distance[j] != 10000 && distance[k] > distance[j] + a[j][k]) { 
 printf("Negative cycle detected!"); 
 return; 
 } 
 } 
 } 
 printf("Table is \n"); 
 printf("__________\n"); 
 printf("| Source | Distance | Parent |\n"); 
 printf("|___|___|____|\n"); 
 for(i=0;i<9;i++) { 
 printf("| %d | %d | %d |\n",i,distance[i],parent[i]); 
 printf("|___|___|____|\n"); 
 } 
} 
int main() { 
 int source = 0; 
 int a[9][9]={ 
 {0,4,0,0,0,0,0,8,0}, 
 {4,0,8,0,0,0,0,11,0}, 
 {0,8,0,7,0,4,0,0,2}, 
 {0,7,0,0,9,14,0,0,0}, 
 {0,0,0,9,0,10,0,0,0}, 
 {0,4,0,14,10,0,2,0,0}, 
 {0,0,0,0,0,2,0,1,6}, 
 {8,11,0,0,0,0,1,0,7}, 
 {0,2,0,0,0,0,6,7,0}, 
 }; 
 bellman_ford(a,source); 
 return 0; 
}