#include <stdio.h>
void hex(int n)
{
      if(n<=9)
      {
          printf("%d",n);
      }
      else if(n==10)
      {
          printf("A");
      }
      else if(n==11)
      {
          printf("B");
      }
       else if(n==12)
      {
          printf("C");
      }
      else if(n==13)
      {
          printf("D");
      }
       else if(n==14)
      {
          printf("E");
      }
      else if(n==15)
      {
          printf("F");
      }
      else
      {
          hex(n/16);
          hex(n%16);
      }
}

int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d",&n);
    hex(n);
    
    return 0;
}
