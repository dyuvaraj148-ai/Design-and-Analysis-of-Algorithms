#include<bits/stdc++.h>
using namespace std;

map<char,int> bd; 

void bdn(string p){
    int n=p.length();
    bd.insert({'*',n});
    
    for(int i=n-1;i>=0;i--){
        if(bd.find(p[i])==bd.end()){
            int m=max(1,n-i-1);
            bd.insert({p[i],m});
        }
    }

    for(auto &a:bd){
        cout<<a.first<<" "<<a.second<<endl;
    }
}  

bool boyar(string str,string p){
    int sl=str.length();
    int pl=p.length();

    if(sl<pl)
    return false;

    int i=pl-1;
    int j=pl-1;

    while(j<sl){
        if(str[j]==p[i]){
            int ti=i-1;
            int tj=j-1;

            while(ti>=0 && tj>=0 && str[tj]==p[ti]){
                ti--;
                tj--;
            }

            if(ti<0)
            return true;

            int shift;
            if(bd.find(str[tj])!=bd.end())
            shift=bd[str[tj]];
            else
            shift=bd['*'];
            j+=shift;
                
        }
        else{
            int shift;
            if(bd.find(str[j])!=bd.end())
                shift=bd[str[j]];
            else
                shift=bd['*'];
            j+=shift;
        }
    }

    return false;
}

int main(){
    string str,pattern;
    cin>>str>>pattern;
    
    bdn(pattern);
    if(boyar(str,pattern))
    cout<<"TRUE";
    else
    cout<<"FALSE";
}