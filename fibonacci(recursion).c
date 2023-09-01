#include <stdio.h>
int rec_fib(int n)
{
      if(n==0)
      {
          return 0;
      }
      else if(n==1)
      {
          return 1;
      }
      else
      {
          return (rec_fib(n-1)+rec_fib(n-2));
      }
}

int main() {
    int n,a,i;
    printf("Length of series: ");
    scanf("%d",&n);
    printf("Fibnocci series: ");
    for(i=0;i<n;i++)
    {
        a=rec_fib(i);
        printf("%d  ",a);
    }
    
    return 0;
}
