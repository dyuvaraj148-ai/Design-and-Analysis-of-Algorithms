#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    char c;
    int freq;
    node* lnext;
    node* rnext;
    node(char ch='#',int d=0){
        c=ch;
        freq=d;
        lnext=nullptr;
        rnext=nullptr;
    }
 };

 class com{
    public:
    bool operator()(const node *a,const node *b){
        return a->freq>b->freq;
    }
 };

node* head=nullptr;
map<char,string> codes;

void generate(node* ptr,string s){
    if(ptr!=nullptr){
        if(ptr->c!='#')
        codes[ptr->c]=s;
        generate(ptr->lnext,s+"0");
        generate(ptr->rnext,s+"1");
    }
}

int main(){
    int n,fr;
    char c;
    cin>>n;

    priority_queue<node*,vector<node*>,com> pq;
    for(int i=0;i<n;i++){
        cin>>c>>fr;
        pq.push(new node(c,fr));
    }

    while(!pq.empty()){
        node* n1=pq.top();
        pq.pop();
        if(pq.empty()){
            head=n1;
            break;
        }
        node* n2=pq.top();
        pq.pop();
        node *ptr=new node('#',n1->freq+n2->freq);
        ptr->lnext=n1;
        ptr->rnext=n2;
        pq.push(ptr);
    }

    generate(head,"");
    for(auto &a:codes)
        cout<<a.first<<":"<<a.second<<endl;

}