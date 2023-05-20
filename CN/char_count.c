#include<stdio.h>
#include<string.h>
int main()
{
    int i,n;
    printf("Enter the number of frames: ");
    scanf("%d",&n);
    char data[n][20];
    int size[100];
    printf("Enter the frames: ");
    for(i=0;i<n;i++)
    {
        scanf("%s",data[i]);
        size[i]=strlen(data[i]);
    }
    
    printf("The output:");
    for(i=0;i<n;i++)
    {
    printf("|  %d%s ",size[i]+1,data[i]);
    if(i==n-1)
        printf("|");
    }
    return 0;
}