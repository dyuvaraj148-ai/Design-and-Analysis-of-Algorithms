#include<bits/stdc++.h>
using namespace std;

void display(vector<int> distance,int v){
    for(int i=0;i<v;i++){
        if(distance[i]==INT_MAX)
        cout<<"INF ";
        else
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}

void dijkistra(vector<vector<int>> matrix,int source,int v){
    vector<int> distance(v,INT_MAX);
    distance[source]=0;
    vector<bool> visit(v);
    for(int i=0;i<v;i++){
        int minvalue=INT_MAX;
        int minindex;
        for(int j=0;j<v;j++){
            if(!visit[j] && minvalue>distance[j]){
                minvalue=distance[j];
                minindex=j;
            }
        }
        visit[minindex]=true;

        for(int j=0;j<v;j++){
            if(!visit[j] &&matrix[minindex][j]!=INT_MAX && distance[minindex]+matrix[minindex][j]<distance[j])
                distance[j]=distance[minindex]+matrix[minindex][j];
        }
    }

    display(distance,v);
}

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
        matrix[a][b]=matrix[b][a]=c;
    }
    cin>>source;
    dijkistra(matrix,source,v);

}