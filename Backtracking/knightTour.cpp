#include<bits/stdc++.h>
using namespace std;

#define MAX 100
int matrix[MAX][MAX];

int n;
int x[]={2,1,-1,-2,-2,-1,1,2};
int y[]={1,2,2,1,-1,-2,-2,-1};

bool issafe(int r,int c){
    if(r<0 || c<0 || r>=n || c>=n || matrix[r][c]!=0)
    return false;
    return true;
}

bool knight(int r,int c,int count){
    if(count==n*n)
    return true;

    matrix[r][c]=count;
    for(int i=0;i<8;i++){
        int nr=r+x[i];
        int nc=c+y[i];
        if(issafe(nr,nc)){
            if(knight(nr,nc,count+1))
            return true;
        }
    }
    matrix[r][c]=0;
    return false;

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=0;
        }
    }
    if(knight(0,0,1))
    cout<<"TRUE";
    else cout<<"FALSE";
}