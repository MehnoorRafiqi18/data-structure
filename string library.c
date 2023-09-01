// strings in c
#include <stdio.h>
#include <string.h>
int main() {
    char s1[50]="IUST";
    char s2[50]="cse";
    char s3[50];
    char s4[50];
    char s5[50]="Apple";
    char s6[50]="Appli";
    
    printf("Length of s1 is: %d\n",strlen(s1));
   
    strcpy(s3,s1);
    printf("s1 gets copied to s3: %s\n",s3);
    
    strncpy(s4,s1,2);
    printf("2 characters of s1 get copied to s4: %s\n",s4);
   
    strcat(s3,s2);
    printf("s2 concatinates to s3. s3 becomes: %s\n",s3);
    
    strncat(s3,s2, 2);
    printf("2 characters of s2 get concatinated to s3. s3 becomes: %s\n",s3);
   
    printf("Comparing s5 with s6: %d\n",strcmp(s5, s6));
    
    printf("Comparing first 4 characters of s5 and s6: %d\n",strncmp(s5, s6,4));
              
    printf("%s\n",strlwr(s1));
   
    printf("%s\n",strupr(s2));
    
    printf("%s\n",strrev(s1));
    printf("%s",s1);
    
    return 0;
}
