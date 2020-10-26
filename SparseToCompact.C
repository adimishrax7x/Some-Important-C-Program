#include<stdio.h>
//function calling
void s2c(int S[10][10],int m, int n)
{
    //initialisation
    int i,j,k=1,c=0;
    int com[10][3];
    //to find no. of rows in compact matrix
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(S[i][j]!=0)
            c++;
        }
    }
    //initialising top row
    com[0][0]=m;
    com[0][1]=n;
    com[0][2]=c;
    
    //operation 
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(S[i][j]!=0)
            {
                com[k][0]=i;
                com[k][1]=j;
                com[k][2]=S[i][j];
                k++;
            }
        }
    }
    printf("\nCOMPACT ARRAY IS :\n ");
    //display compact array of sparse matrix
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",com[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int S[10][10];
    int m,i,j,n;
    printf("Enter no. of rows in the sparse matrix : ");
    scanf("%d",&m);
    printf("Enter no. of columnss in the sparse matrix : ");
    scanf("%d",&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter Element of sparse matrix at S[%d][%d] : ",i,j);
            scanf("%d",&S[i][j]);
        }
    }
    printf("\nYOUR ENTERED ARRAY : \n");
       for(i=0;i<m;i++)
       {
        for(j=0;j<n;j++)
            {
                printf("%d\t",S[i][j]);
            }
            printf("\n");
       }
    s2c(S,m,n);
        
    return 0;
}
