#include<stdio.h>

void swap(int arr[] ,int s,int h){
    int t=arr[s];
    arr[s]=arr[h];
    arr[h]=t;
}

void selectionsort(int arr[],int s,int e){

    for(int i=0;i<e;i++){
        int data=i;
        for(int j=i+1;j<=e;j++){
            if(arr[data]>arr[j])
            data=j;
        }
        swap(arr,i,data);
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
    selectionsort(arr,0,n-1);
    printf("AFTER SORTING:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}