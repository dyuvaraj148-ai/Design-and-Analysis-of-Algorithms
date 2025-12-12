#include<stdio.h>

void quicksort(float arr[],int n){

    for(int i=0;i<n;i++){
        float key=arr[i];
        int j=i-1;

        while(arr[j]>key && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void bucketsort(float arr[], int n){

    float a[10][n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        int m=arr[i]*10;
        a[m][count[m]++]=arr[i];
    }

    for(int i=0;i<10;i++){
        if(count[i]>0)
        quicksort(a[i],count[i]);
    }

    int k=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<count[i];j++){
            arr[k++]=a[i][j];
        }
    }

}

int main() {

    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    float arr[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }

    bucketsort(arr,n);
    printf("AFTER SORTING:\n");
    for(int i=0;i<n;i++){
        printf("% .3f",arr[i]);
    }
    return 0;
}