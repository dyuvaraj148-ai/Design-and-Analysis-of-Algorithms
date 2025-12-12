#include<bits/stdc++.h>
using namespace std;
#define MAX 100

class MST{
    int v;
    int graph[MAX][MAX];
    public:
    MST(int n){ 
        v=n;
        adjMatrix();
    }

    void adjMatrix(){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++)
            graph[i][j]=0;
        }

        int e,e1,e2,w;
        cin>>e;
        cout<<"Enter node(1,2) and weight:"<<endl;
        for(int i=0;i<e;i++){
            cin>>e1>>e2>>w;
            graph[e1][e2]=graph[e2][e1]=w;
        }
    }

    void printmst(vector<int> parent){
        for(int i=1;i<v;i++)
        cout<<parent[i]<<"-"<<i<<"->"<< graph[parent[i]][i]<<endl;
    }

    int minkey(vector<int> key,vector<bool> mst){
        int min=INT_MAX,mini;
        for(int i=0;i<v;i++){
            if(!mst[i] && key[i]<min)
            min=key[i],mini=i;
        }
        return mini;
    }

    void prim(){
        vector <int> parent(v);
        vector <int> key(v,INT_MAX);
        vector <bool> mst(v,false);

        key[0]=0;
        parent[0]=-1;

        for(int i=0;i<v-1;i++){
            int u=minkey(key,mst);
            mst[u]=true;
            for(int i=0;i<v;i++){
                if(graph[u][i]!=0 &&!mst[i] && graph[u][i]<key[i] )
                key[i]=graph[u][i],parent[i]=u;
            }
        }
        printmst(parent);
    }

};

int main(){
    int v;
    cin>>v;
    MST ms(v);
    ms.prim();
}