#include<stdio.h>
#include<conio.h>
void dijkstras(int cost[10][10],int dist[10],int n,int v)
{
    int i,u,w,count,flag[10],min; 
    for(i=1;i<=n;i++)
    {
        flag[i]=0;
        dist[i]=cost[v][i];
    }
    flag[v]=1; 
    dist[v]=0; 
    count=1; 
    while(count<n)
    {
        for(i=1,min=999;i<=n;i++)
        {
            if(dist[i]<=min && !flag[i])
            {
                min=dist[i]; 
                u=i;
            }
        }     
 
        flag[u]=1; 
        count++; 
        for(w=1;w<=n;w++)
        {
            if(dist[u]+cost[u][w]<dist[w] && !flag[w]) 
            dist[w]=dist[u]+cost[u][w];
        }
    }
}
int main()

{
int n,cost[10][10],source,i,j,dist[10];
printf("Enter the number of vertices\n"); 
scanf("%d",&n);
printf("Enter the cost matrix\n"); 
for(i=1;i<=n;i++) 
    for(j=1;j<=n;j++)
    {
    scanf("%d",&cost[i][j]); 
    }
printf("source\n"); 
scanf("%d",&source); 
dijkstras(cost,dist,n,source);
printf("Vertex \t Destination\t Cost\n");
for(i=1;i<=n;i++)
if(source!=i) printf("%d\t%d\t%d\n",source,i,dist[i]);
getch(); 
}
