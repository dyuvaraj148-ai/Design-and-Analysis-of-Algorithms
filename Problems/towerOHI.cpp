#include<bits/stdc++.h>
using namespace std;

stack<int> s,i,d;

void movedisk(int val,char p1,char p2){
    cout<<"Move disk "<<val<<" from  "<<p1<<" to rod "<<p2<<endl;
}

void move(stack<int> &s1,stack<int> &s2,char p1,char p2){
    if(s1.size()==0){
        int val=s2.top();
        s2.pop();
        s1.push(val);
        movedisk(val,p2,p1);
    }

    else if(s2.size()==0){
        int val=s1.top();
        s1.pop();
        s2.push(val);
        movedisk(val,p1,p2);
    }

    else {
        int val1=s1.top();
        int val2=s2.top();
        if (val1 < val2) {
            int val =val1 ;
            s1.pop();
            s2.push(val);
            movedisk(val,p1,p2);
        }

        else {
        int val = val2;
        s2.pop();
        s1.push(val);
        movedisk(val,p2,p1);
        }
    }
}

int main(){
    int n;
    cin>>n;

    for(int i=n;i>=1;i--)
        s.push(i);
    char from = 'A', to = 'B', in = 'C';

    if(n%2==0){
        char c=to;
        to=in;
        in=c;
    }

    long total=pow(2,n)-1;
    for(int j=1;j<=total;j++){
        if(j%3==1)
            move(s,d,from,to);
        if(j%3==2)
            move(s,i,from,in);
        if(j%3==0)
            move(d,i,to,in);
    }

}