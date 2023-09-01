//Tower of Hanoi
#include <stdio.h>
void toh(int n, char Beg, char End, char Mid)
{
    if(n==1)
        printf("%c to %c\n",Beg,End);
    else{
        toh(n-1,Beg,Mid,End);
        printf("%c to %c\n",Beg,End);
        toh(n-1,Mid,End,Beg);
    }
    
}
int main() {
    int n;
    printf("No of rings: ");
    scanf("%d",&n);
    toh(n,'a','b','c');
    return 0;
}
