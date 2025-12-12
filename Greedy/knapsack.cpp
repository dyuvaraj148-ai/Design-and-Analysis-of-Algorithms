#include<bits/stdc++.h>
using namespace std;

class nv{
    public:
    int weight;
    int profit;
    double ratio;
    nv(int w,int p,double r){
        weight=w;
        profit=p;
        ratio=r;
    }
};

struct compare{
    bool operator()(const nv &a,const nv &b){
        return a.ratio<b.ratio;
    }
};

double method(priority_queue<nv,vector<nv>,compare> &pq,int n,int capacity){
    double totprofit=0;

    while(capacity!=0){
        if(!pq.empty()){
            nv p=pq.top();
            pq.pop();
            if(p.weight<=capacity){
            capacity-=p.weight;
            totprofit+=p.profit;
            }
            else{
                totprofit+=p.profit*((double)capacity/p.weight);
                break;
            }
        }
        else break;
    }
    return totprofit;
}

int main(){
    int n,capacity;
    cout<<"Enter no of weights:";
    cin>>n;
    priority_queue<nv,vector<nv>,compare> pq;
    cout<<"Enter capacity of bag:";
    cin>>capacity;
    cout<<"Enter weight with profit:"<<endl;

    int w,p;
    double r;
    for(int i=0;i<n;i++){
        cin>>w;
        cin>>p;
        r=(double)p/w;
        pq.push(nv(w,p,r));
    }
    cout<<"Max profit:";
    double profit=method(pq,n,capacity);
    cout<<profit<<endl;

}