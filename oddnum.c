#include<stdio.h>


int main(){

    int arr[5];
    printf("enter the elements if the array\n");
    for(int i = 0; i<5 ; i++){
        scanf("%d \n", &arr[i]);
    }
    for(int i =0; i<5 ; i++){
        printf("%d\t",arr[i]);
    }
for(int i =0; i<5 ; i++)

{    
    if(arr[i]%2!=0)
    {
        printf("\n%d is the odd number\n",arr[i]);
    }

}
 return 0;
}