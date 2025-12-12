#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define MAX 100
int matrix[MAX][MAX];
bool visit[MAX];
int mincost=INT_MAX;
int start;
int v;

void Tour(int node,int cost,int count){
    if(cost>mincost)
    return;

    if(count==v){
        if(matrix[node][start]!=INT_MAX)
        mincost=min(mincost,cost+matrix[node][start]);
        return ;
    }

    for(int i=0;i<v;i++){
        if(!visit[i] && matrix[node][i]!=INT_MAX){
            visit[i]=true;
            Tour(i,cost+matrix[node][i],count+1);
            visit[i]=false;
        }
    }
}

int main(){
    int e,e1,e2,d;
    cout<<"Enter no of villages(nodes):";
    cin>>v;
    cout<<"Enter no of roads(edges):";
    cin>>e;

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(j==i) matrix[i][j]=0;
            else matrix[i][j]=INT_MAX;
        }
    }

    cout<<"Enter edges one by one:";
    for(int i=0;i<e;i++){
        cin>>e1>>e2>>d;
        matrix[e1][e2]=matrix[e2][e1]=d;
    }

    cout<<"Enter Start point:";
    cin>>start;
    visit[start]=true;

    Tour(start,0,1);
    cout<<mincost;
}