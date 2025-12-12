#include<stdio.h>

void swap(int arr[] ,int s,int h){
    int t=arr[s];
    arr[s]=arr[h];
    arr[h]=t;
}

void bubblesort(int arr[],int s,int e){

    for(int i=0;i<e;i++){
        for(int j=0;j<e-i;j++){
            if(arr[j]>arr[j+1])
            swap(arr,j,j+1);
        }
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
    bubblesort(arr,0,n-1);
    printf("AFTER SORTING:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}