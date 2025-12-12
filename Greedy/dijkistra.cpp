#include<bits/stdc++.h>
using namespace std;

typedef struct Edge{
    int vertex,dist;
}se;

class  sn{
    public:
    int vertex,dist;
    sn(int v,int d){
        vertex=v;
        dist=d;
    }
};
class compare{
    public:
    bool operator()(const sn &a,const sn &b){
        return a.dist>b.dist;
    }
};

void dijkistra(vector<vector<se>> &matrix,int s,int v){
    vector<int> dist(v,INT_MAX);
    vector<bool> visit(v,false);
    priority_queue<sn,vector<sn>,compare> pq;
    dist[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        sn ptr=pq.top();
        pq.pop();
        int u=ptr.vertex;
        if(visit[u])
        continue;
        visit[u]=true;
        for(se &ex:matrix[u]){
            int u2=ex.vertex;
            int w=ex.dist;
            if(!visit[u2] && dist[u]+w<dist[u2] ){
                dist[u2]=w+dist[u];
                pq.push({u2,dist[u2]});
            }
        }
    }

    for(int i=0;i<v;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int v,e;
    cin>>v;
    vector<vector<se>> matrix(v);
    cin>>e;

    int v1,v2,w;
    for(int i=0;i<e;i++){
        cin>>v1>>v2>>w;
        matrix[v1].push_back({v2,w});
        matrix[v2].push_back({v1,w});
    }

    int s;
    cin>>s;
    dijkistra(matrix,s,v);
}