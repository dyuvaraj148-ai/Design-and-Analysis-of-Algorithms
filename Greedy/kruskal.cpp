#include<bits/stdc++.h>
using namespace std;

class disjointset{
    public:
    vector <int> parent,rank;
    disjointset(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++)
        parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
        parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);

        if(rootx==rooty)
        return false;

        if(rank[rootx]>=rank[rooty]){
            parent[rooty]=rootx;
            rank[rootx]+=rank[rooty];
        }
        else{
            parent[rootx]=rooty;
            rank[rooty]+=rank[rootx];
        }
        return true;
    }
};

class edge{
    public:
    int e1,e2,d;
    edge(int e1,int e2,int d){
        this->e1=e1;
        this->e2=e2;
        this->d=d;
    }
    void display(){
        cout<<e1<<"->"<<e2<<"=>"<<d<<endl;
    }
};
class compare{
    public:
    bool operator()( const edge &e1,const edge &e2){
    return e1.d>e2.d;
    }
};


int main(){
    int v,e,e1,e2,d;
    cin>>v>>e;
    priority_queue<edge,vector<edge>,compare> edges;
    disjointset dsu(v);

    for(int i=0;i<e;i++){
        cin>>e1>>e2>>d;
        edge e3(e1,e2,d);
        edges.push(e3);
    }

    vector<edge>mst;
    while(!edges.empty()){
        edge pair=edges.top();
        edges.pop();
        if(dsu.unite(pair.e1,pair.e2)){
            mst.push_back(pair);
        }
        if(mst.size()==v-1)
        break; 
    }

    for(auto &pair:mst){
        pair.display();
    }

}