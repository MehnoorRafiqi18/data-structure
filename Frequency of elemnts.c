// Frequency of each element in array
#include <stdio.h>

int main() {
    int a[5]={1,1,5,3,5},f[5];
    int i,j,count;
    for(i=0;i<5;i++)
    {
        f[i]=-1;
    }
    for(i=0;i<5;i++)
    {
    	count=1;
        for(j=i+1;j<6;j++)
        {
                if(a[i]==a[j])
                {
                    count++;
                    f[j]=0;
                }
        }
        if(f[i]!=0)
        {
            f[i]=count;
        }
    }
    
    for(i=0;i<5;i++)
    {
        if(f[i]!=0)
        {
            printf("%d has frequency = %d\n",a[i],f[i]);
        }
    }

    return 0;
}
