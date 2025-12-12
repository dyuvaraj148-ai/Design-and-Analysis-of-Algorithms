#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int v,d;
    node(int vec,int dis){
        v=vec;
        d=dis;
    }
};

class min_heap{
    public:
    vector<node> heap;
    vector<int> pos;
    min_heap(int v){
        pos.resize(v,-1);
    }

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    void build_heap(int v){
        for(int i=0;i<v;i++){
            node n(i,INT_MAX);
            push(n);
        }
    }

    void push(node n){
        heap.push_back(n);
        pos[n.v]=heap.size()-1;
        heapifyup(heap.size()-1);
    }

    node extractMin(){
        node n=heap[0];
        pos[n.v]=-1;
        heap[0]=heap.back();

        heap.pop_back();
        if(!heap.empty()){
            pos[heap[0].v]=0;
            heapifydown(0);
        }
        return n;
    }

    void heapifyup(int i){
        while(i!=0 && heap[parent(i)].d>heap[i].d){
            int p=parent(i);
            swap(heap[i],heap[p]);
            
            pos[heap[i].v]=i;
            pos[heap[p].v]=p;
            i=p;
        }
    }

    void heapifydown(int i){
        int n=heap.size();
        while(true){
            int small=i;
            int l=2*i+1;
            int r=2*i+2;
            if(l<n && heap[l].d<heap[small].d)
            small=l;
            if(r<n && heap[r].d<heap[small].d)
            small=r;
            if(small!=i){
                int s=small;
                swap(heap[i],heap[s]);
                pos[heap[i].v]=i;
                pos[heap[s].v]=s;
                i=s;
            }
            else break;
        }
    }

    void decreaseKey(int ver,int da){
        int i=pos[ver];
        heap[i].d=da;
        heapifyup(i);
    }

    bool empty(){
        return heap.empty();
    }
};

int main(){
    int v,e;
    cin>>v>>e;
    min_heap mh(v);
    mh.build_heap(v);

    int matrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i==j) matrix[i][j]=0;
            else matrix[i][j]=INT_MAX;
        }
    }

    int e1,e2,d;
    for(int i=0;i<e;i++){
        cin>>e1>>e2>>d;
        matrix[e1][e2]=matrix[e2][e1]=d;
    }

    int source;
    cin>>source;

    vector<int> dis(v,INT_MAX);
    vector<bool> visit(v,false);
    mh.decreaseKey(source,0);
    dis[source]=0;
    
    while(!mh.empty()){
        node n=mh.extractMin();
        int ver=n.v;
        int di=n.d;
        visit[ver]=true;
        for(int i=0;i<v;i++){
            if(!visit[i] && matrix[ver][i]!=INT_MAX && di+matrix[ver][i]<dis[i]){
                dis[i]=di+matrix[ver][i];
                mh.decreaseKey(i,dis[i]);
            }
        }
    }

    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }

}