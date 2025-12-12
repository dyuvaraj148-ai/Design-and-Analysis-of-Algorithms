#include<bits/stdc++.h>
using namespace std;

int v;
vector<vector<int>> start;

class node{
    public:
    vector<int> path;
    vector<vector<int>> matrix;
    int cost,level,vertex;
    node(){};
};

class compare{
    public:
    bool operator()(const node &n1,const node &n2){
        return n1.cost>n2.cost;
    }
};

int reduction(vector<vector<int>> &matrix){
    int c=0;

    for(int i=0;i<v;i++){
        int rmin=INT_MAX;
        for(int j=0;j<v;j++){
            rmin=min(rmin,matrix[i][j]);
        }
        if(rmin!=INT_MAX && rmin>0){
            c+=rmin;
            for(int j=0;j<v;j++){
                if(matrix[i][j]!=INT_MAX)
                matrix[i][j]-=rmin;
            }
        }
    }

    for(int i=0;i<v;i++){
        int cmin=INT_MAX;
        for(int j=0;j<v;j++){
            cmin=min(cmin,matrix[j][i]);
        }
        if(cmin!=INT_MAX && cmin>0){
            c+=cmin;
            for(int j=0;j<v;j++){
                if(matrix[j][i]!=INT_MAX)
                matrix[j][i]-=cmin;
            }
        }
    }
    return c;
}

void branchbound(){
    int mincost=INT_MAX;
    vector<int> bestpath;

    priority_queue<node,vector<node>,compare> pq;

    node n;
    n.path.push_back(0);
    n.vertex=0;
    n.level=0;
    n.matrix=start;
    n.cost=reduction(n.matrix);
    pq.push(n);

    while(!pq.empty()){
        node n=pq.top();
        pq.pop();

        if(n.level==v-1){
            n.path.push_back(0);
            mincost=n.cost;
            bestpath=n.path;
            break;
        }

        for(int i=1;i<v;i++){
            unordered_set<int> visited(n.path.begin(), n.path.end());
            if(visited.count(i) || n.matrix[n.vertex][i]==INT_MAX) continue;

            node next;
            next.matrix=n.matrix;
            for(int j=0;j<v;j++){
                next.matrix[n.vertex][j]=INT_MAX;
                next.matrix[j][i]=INT_MAX;
            }
            next.matrix[i][0]=INT_MAX;

            next.path=n.path;
            next.path.push_back(i);

            next.vertex=i;
            next.level=n.level+1;

            next.cost=n.cost+n.matrix[n.vertex][i]+reduction(next.matrix);
            pq.push(next);

        }
    }

    cout<<"MIN COST:"<<mincost<<endl;
    cout<<"PATH:";
    cout<<bestpath[0];
    for(int i=1;i<bestpath.size();i++){
        cout<< "->" << bestpath[i];
    }

}

int main(){
    int e;
    cin>>v>>e;
    start.resize(v,vector<int>(v,INT_MAX));

    int e1,e2,d;
    for(int i=0;i<e;i++){
        cin>>e1>>e2>>d;
        start[e1][e2]=d;
    }

    branchbound();
}
