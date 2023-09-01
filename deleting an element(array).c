// Deleting all the instance of an elemnt form an array
#include <stdio.h>
void deletion(int a[], int *n, int num)
{
    int i,j,p;
    for(i=0;i<*n;i++)
    {   
        if(a[i]==num)
        {
            p=i;
            for(j=p;j<*n;j++)
            {
                a[j]=a[j+1];
            }
            --i;
            *n=*n-1;
        }
        
    }
}
int main() {
    int i,j,n,num;
    printf("Enter size: "); 
	scanf("%d",&n);
    int a[100];
    
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }
    
    printf("Enter number to be deleted: ");
    scanf("%d", &num);
   
    deletion(a,&n, num);
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
