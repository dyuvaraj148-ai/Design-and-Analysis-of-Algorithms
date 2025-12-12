#include<stdio.h>

void swap(int arr[],int a,int b){

    int t=arr[a];
    arr[a]=arr[b];
    arr[b]=t;
}

int partion(int arr[], int s,int e){

    int pi=s;
    for(int i=s;i<e;i++){
        if(arr[i]<arr[e]){
            swap(arr,pi,i);
            pi++;
        }
    }
    swap(arr,pi,e);
    return pi;
}

void quicksort(int arr[],int s,int e){

    if(s<e){
        int pi=partion(arr,s,e);
        quicksort(arr,s,pi-1);
        quicksort(arr,pi+1,e);
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
    quicksort(arr,0,n-1);
    printf("AFTER SORTING:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}