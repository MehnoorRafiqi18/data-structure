#include<stdio.h>
int main()
{
     int arr[10],i,j,n,flag=0;
     int size;
     printf("enter the number of elements you want in the array");
     scanf("%d",&size);
    printf("enter the elements if the array\n");
    for(i=0; i<size ; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<size; i++)
    {
        n=arr[i];
        for(j=2; j<n; j++)
        {
            if(n%j==0)
            {
                flag=1;
                break;
            }
        }
      if(flag==0)
            {
                printf("%d is the prime number\n",n);
            }
    }
    return 0;
}