// Add number in an array
#include <stdio.h>
void addition(int a[], int *n, int num)
{
	int i,p;
    for(i=0;i<*n;i++)
    {
        if(a[i]>num)
            {
                p=i;
                break;
            }
    }
    
    for(i=*n;i>p;i--)
    {
        a[i]=a[i-1];
    }
    a[p]=num;
    *n=*n+1;
}

int main() {
    int n,i,num,p;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[100];
    printf("Enter elements in ascending order: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter num to add: ");
    scanf("%d",&num);
   
    addition(a,&n, num);
    
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
