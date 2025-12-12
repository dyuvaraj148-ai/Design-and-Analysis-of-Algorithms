#include<bits/stdc++.h>
using namespace std;

vector<int> lps; 

void lpn(string p){
    int n=p.length();
    lps.resize(n);
    lps[0]=0;
    int j=0;
     
     for(int i=1;i<n;i++){
        while(j!=0 && p[i]!=p[j])
        j=lps[j-1];

        if(p[i]==p[j])
        j++;  
        lps[i]=j;
     } 
}  

bool kmp(string str,string p){
     int i=0,j=0;
     int pl=p.length();
     int sl=str.length();
     
     while(i<sl){
         
         if(str[i]==p[j])
         i++,j++;
         else if(j==0)
         i++;
         else
         j=lps[j-1];

         if(j==pl)
         return true;
     }
     
     if(j==pl)
     return true;
     else
     return false;
     
}
  
int main(){
    string str,pattern;
    cin>>str>>pattern;
    
    lpn(pattern);
    if(kmp(str,pattern))
    cout<<"TRUE";
    else
    cout<<"FALSE";
}