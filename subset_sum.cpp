#include<bits/stdc++.h>
using namespace std;
void subsethelper(int ind,vector<int>&arr,int n,vector<int>&ans,int sum){
    if(ind==n){
        ans.push_back(sum);
        return;
    }
    subsethelper(ind+1,arr,n,ans,sum+arr[ind]);
    subsethelper(ind+1,arr,n,ans,sum);
}
    vector<int>subsetsums(vector<int>&arr,int n){
        vector<int>ans;
        subsethelper(0,arr,n,ans,0);
        sort(ans.begin(),ans.end());
        return ans;

    }

int main(){
     vector<int>arr{3,1,2};
     vector<int>ans=subsetsums(arr,arr.size());
     sort(ans.begin(),ans.end());
     for(auto it:ans){
        cout<<it<<" ";
     }
     cout<<endl;
     return 0;
}