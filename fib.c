#include<stdio.h>
int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else{
        return  fib(n-1)+ fib(n-2);
    }
}
int main()
{
    int n,i=0,f;
    printf("enter the nth term");
    scanf("%d",&n);
    printf("the fibonacci series of %d elements is: ",n);
    for(i=0; i<n; i++)
    {
        f= fib(i);
        printf("%d ",f);
    }
}