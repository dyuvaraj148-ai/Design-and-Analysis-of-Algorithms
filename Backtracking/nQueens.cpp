#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int> ans,int r,int c){
    if(find(ans.begin(), ans.end(), c) != ans.end())
    return false;
    for(int i=0;i<r;i++){
        if(i+ans[i]==r+c || i-ans[i]==r-c)
        return false;
    }
    return true;
}

void nQueens(vector<vector<int>> &result,vector<int> ans,int r,int n){
    if(r==n){
        result.push_back(ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(isSafe(ans,r,i)){
            ans.push_back(i);
            nQueens(result,ans,r+1,n);
            ans.pop_back();
        }
    }
    return;
}

int main(){
    int n;
    cout<<"Enter no of queens:";
    cin>>n;
    vector<vector<int>> result;
    vector<int> ans;
    nQueens(result,ans,0,n);
    cout<<"{ ";
    for(vector<int> a:result){
        cout<<"[ ";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"] ";
    }
    cout<<" }";
}
