#include<stdio.h>

void mearge(int arr[],int s1,int e1,int s2,int e2){

    int a[e2-s1+1],k=0;
    int i=s1,j=s2;
    while(i<=e1 && j<=e2)
    {
        
        if(arr[i]<arr[j])
        a[k++]=arr[i++]; 
        else
        a[k++]=arr[j++];
    }

    while(i<=e1)
    a[k++]=arr[i++];
    while(j<=e2)
    a[k++]=arr[j++];

    k=0;
    for(int i=s1;i<=e2;i++)
    arr[i]=a[k++];

}

void mergesort(int arr[],int s,int e){

    if(s<e){
        int mid=(s+e)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        mearge(arr,s,mid,mid+1,e);
    }
}

int main(){
    int n ;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}