#include<stdio.h>
#include<math.h>
#define MAX 100

void sort(int arr[],int n,int r){
    
    int a[10][MAX];
    int count[10]={0};
    int m=pow(10,r+1);
    int d=pow(10,r);
    for(int i=0;i<n;i++){
        int e=arr[i];
        int ra=e%m;
        int sd=ra/d;
        a[sd][count[sd]++]=e;
    }
    
    int k=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i];j++){
            arr[k++]=a[i][j];
        }
    }
}

void radixsort(int arr[],int n){
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
        max=arr[i];
    }
    
    int len=0;
    while(max>0){
        len++;
        max/=10;
    }
    
    for(int i=0;i<len;i++){
        sort(arr,n,i);
    }
}

int main() {
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    radixsort(arr,n);
    printf("AFTER SORTING:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}