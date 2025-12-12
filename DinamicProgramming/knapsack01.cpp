#include<bits/stdc++.h>
using namespace std;

typedef struct value{
    int weight;
    int profit;
}nv;

void knapsack(nv items[],int n,int m){
    int matrix[n+1][m+1];

    for(int i=0;i<=m;i++)
        matrix[0][i]=0;
    for(int i=0;i<=n;i++)
        matrix[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(items[i-1].weight>j)
                matrix[i][j]=matrix[i-1][j];
            else
                matrix[i][j]=max(matrix[i-1][j],matrix[i-1][j-items[i-1].weight]+items[i-1].profit);
        }
    }
    cout<<"MAX PROFIT:"<<matrix[n][m]<<endl;

    int vector[n]={0};
    int i=n,j=m;
    while(i>0 && j>0){
        if(matrix[i][j]!=matrix[i-1][j]){
            j-=items[i-1].weight;
            vector[i-1]=1;
        }
        i--;
    }

    cout<<"VECTOR:";
    for(int i=0;i<n;i++){
        cout<<vector[i]<<" ";
    }
}

int main(){
    int n,capacity;
    cout<<"Enter no of items:";
    cin>>n;
    nv items[n];
    cout<<"Enter capacity of bag:";
    cin>>capacity;
    cout<<"Enter weight with profit:"<<endl;
    for(int i=0;i<n;i++){
        cin>>items[i].weight;
        cin>>items[i].profit;
    }
    knapsack(items,n,capacity);
}
