#include<stdio.h>
#define INF 9999
#define MAX 10
void dijkstra(int G[MAX][MAX],int n ,int start)
{
    int cost[MAX][MAX],pred[MAX],distance[MAX],visited[MAX];
    int count, mindistance, i ,j, next;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=INF;
            else
                cost[i][j]=G[i][j];
        }
    }
        for(i=0;i<n;i++)
        {
            distance[i]=cost[start][i];
            pred[i]=start;
            visited[i]=0;
        }
        distance[start]=0;
        visited[start]=1;
        count=1;
        while(count<n-1)
        {
            mindistance=INF;
            for(i=0;i<n;i++)
            {
                if(distance[i]<mindistance && visited[i]==0)
                {
                    mindistance=distance[i];
                    next=i;
                }
            }
            visited[next]=1;
            for(i=0;i<n;i++)
            {
                
                if(visited[i]==0)
                {
                    if(mindistance+cost[next][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[next][i];
                        pred[i]=next;
                    }
                }
                count++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i!=start)
            {
                printf("\nDistance of node %d= %d",i,distance[i]);
                printf("\n Path= %d",i);
                j=i;
                do{
                    j=pred[j];
                    printf(" <-%d",j);
                }while(j!=start);
            }
        }
}

int main()
{
int G[MAX][MAX],i,j,n,u;
printf("Enter no. of vertices:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&G[i][j]);
printf("\nEnter the starting node:");
scanf("%d",&u);
dijkstra(G,n,u);
return 0;
}




