#include<bits/stdc++.h>
using namespace std; // only work 10 moves puzzle

vector<vector<int>> goal={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,-1}};
set<vector<vector<int>>> visited;
int x[]={1,0,0,-1};
int y[]={0,1,-1,0};

class node{
    public:
    vector<vector<int>> matrix;
    int cost;
    int sx,sy,m;
    node(){};
};

class compare{
    public:
    bool operator()(const node &n1,const node &n2){
        return n1.cost+n1.m>n2.cost+n2.m;
    }
};

int costt(vector<vector<int>> start){
    int c=0;

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(start[i][j]==-1)
            continue;
            else if(start[i][j]!=goal[i][j])
            c++;
        }
    }
    return c;
}

bool isSafe(int nr,int nc){
    if(nr<0 || nc<0 || nr>=4 || nc>=4)
    return false;
    return true;
}

void movetile(vector<vector<int>> &start,int nr,int nc,int r,int c){
    int t=start[nr][nc];
    start[nr][nc]=start[r][c];
    start[r][c]=t;
}

bool puzzle(vector<vector<int>> start){
    int nx,ny;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(start[i][j]==-1)
            nx=i,ny=j;
        }
    }

    priority_queue<node,vector<node>,compare> pq;
    node n;
    n.matrix=start;
    n.cost=costt(start);
    n.sx=nx;
    n.sy=ny;
    n.m=0;
    pq.push(n);

    while(!pq.empty()){
        node n=pq.top();
        pq.pop();

        if(n.matrix==goal)
        return true;

        if(visited.count(n.matrix))
        continue;
        else
        visited.insert(n.matrix);

    
        for(int i=0;i<4;i++){
            int sr=n.sx+x[i];
            int sc=n.sy+y[i];
            if(isSafe(sr,sc)){
                vector<vector<int>> temp=n.matrix;
                movetile(temp,sr,sc,n.sx,n.sy);
                node n2;
                n2.matrix=temp;
                n2.cost=costt(temp);
                n2.sx=sr;
                n2.sy=sc;
                n2.m=n.m+1;
                pq.push(n2);
            }
        }
    }
    return false;    
}

int main(){
    vector<vector<int>> start(4,vector<int>(4,0));
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin>>start[i][j];

    if(puzzle(start))
    cout<<"TRUE";
    else
    cout<<"FALSE";
}