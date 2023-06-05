#include<stdio.h>
struct student
{
    char name[20];
    int rollnum;
    float marks;
    struct node next;
}
int main{
    struct student s1,s2,s3,s4,s5;
    s1.name= mehnoor;
    s2.name= sadiya;
    s3.name= neha;
    s4.name= mariya;
    s5.name= mansha;    

    s1.rollnum= 06;
    s2.rollnum= 01;
    s3.rollnum= 09;
    s4.rollnum= 19;
    s5.rollnum= 29;

    s1.marks= 80.6;
    s2.marks= 86.4;
    s3.marks= 87.3;
    s4.marks= 82.3;
    s5.marks= 84.3;

    s1.next= &s2;
    s2.next= &s3;
    s3.next= &s4;
    s4.next= &s5;
    s5.next= null;

    printf("%d\t %c\t %f\t\n",s1.name,s1.rollnum,s1.marks);
     printf("%d\t %c\t %f\t\n",s2.name,s2.rollnum,s2.marks);
      printf("%d\t %c\t %f\t\n",s3.name,s3.rollnum,s3.marks);
       printf("%d\t %c\t %f\t\n",s4.name,s4.rollnum,s4.marks);
        printf("%d\t %c\t %f\t\n",s5.name,s5.rollnum,s5.marks);

        printf("%d",n1.next->next->next->next->marks);


}