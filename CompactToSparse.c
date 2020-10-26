#include<stdio.h>
//function declaration
void c2s(int s[100][100],int c[100][3],int x)
{
    //initilaisaton of essential variables
    int a,b,i,j;
    //operation
    for( i=0;i<x;i++)
    {
        a=c[i][0];
        b=c[i][1];
        s[a][b]=c[i][2];
    }
    a=c[0][0];
    b=c[0][1];
    //display of sparse matrix
    printf("the sparce matrix : \n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            printf("%d\t",s[i][j]);
        }
    printf("\n");
    }
    
}

//main function
int main()
{
    //initialization of compact,sparse array and size of compact array
    int c[100][3],s[100][100],x;
    int i,j;
    printf("Enter no. of rows of compact matrix : ");
    scanf("%d",&x);
    //entry of compact matrix
    for(i=0;i<x;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("Enter element of position c[%d][%d]",i,j);
            scanf("%d",&c[i][j]);
        }
    printf("\n");
    }
    //preview entered compact array
            printf("Entered Compact array : ");
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",c[i][j]);
        }
    printf("\n");
    }
    //calling of function
    c2s(s,c,x);
    return 0;
    
}
