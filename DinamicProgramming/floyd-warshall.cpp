#include<bits/stdc++.h>
using namespace std;

int main(){
    int v,e,a,b,c,source;
    cin>>v>>e;
    vector<vector<int>>matrix(v,vector<int>(v));

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(j==i)
            matrix[i][j]=0;
            else
            matrix[i][j]=INT_MAX;
        }
    }
    for(int i=0;i<e;i++){
        cin>>a>>b>>c;
        matrix[a][b]=c;
    }

    cout<<"RESULTANT MATRIX:"<<endl;
    for(int k=0;k<v;k++){ //k is intermediate
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX)
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(matrix[i][j]==INT_MAX)
            cout<<"INF ";
            else
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}