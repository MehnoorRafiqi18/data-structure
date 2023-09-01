// Linked List
#include <stdio.h>
#include <string.h>
struct student{
    char name[30];
    int roll;
    float marks;
    struct student *next;
};
int main() {
    struct student s1,s2,s3,s4,s5;
    printf("Enter name, roll no and marks for s1: ");
	scanf("%s %d %f",s1.name,&s1.roll,&s1.marks);
    
    printf("Enter name, roll no and marks for s2: ");
	scanf("%s %d %f",s2.name,&s2.roll,&s2.marks);
    
    printf("Enter name, roll no and marks for s3: ");
	scanf("%s %d %f",s3.name,&s3.roll,&s3.marks);
    
    printf("Enter name, roll no and marks for s4: ");
	scanf("%s %d %f",s4.name,&s4.roll,&s4.marks);
	
	printf("Enter name, roll no and marks for s5: ");
	scanf("%s %d %f",s5.name,&s5.roll,&s5.marks);
	
	s1.next=&s2;
	s2.next=&s3;
	s3.next=&s4;
	s4.next=&s5;
	s5.next=NULL;
	
	printf("%d",s1.next->next->next->roll);


    return 0;
}
