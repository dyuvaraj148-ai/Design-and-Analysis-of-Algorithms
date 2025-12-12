#include<stdio.h>
#include<limits.h>

int main(){
    int n;
    scanf("%d",&n);
    int nums[n];
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    
    int max=nums[0];
    int sum=nums[0];
    int start=0;
    int end=0,tempstart=0;
    for(int i=1;i<n;i++){
        if(nums[i]>sum+nums[i]){
            tempstart=i;
            sum=nums[i];
        }
        else sum+=nums[i];

        if(sum>=max){
            start=tempstart;
            end=i;
            max=sum;
        }
    }

    printf("Max sum:%d",max);
    printf("\nMax sum Array:[ ");
        for(int i=start;i<=end;i++){
            printf("%d ",nums[i]);
        }
        printf("]");
}