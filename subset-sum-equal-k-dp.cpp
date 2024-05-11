#include<bits/stdc++.h>
using namespace std;
bool f(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0)
    return true;
    if(ind==0)
    return bool(arr[ind]==target);
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    bool notpick=f(ind-1,target,arr,dp);
    bool pick=false;
    if(arr[ind]<=target){
        pick=f(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]=pick||notpick;
}

int main() {
    vector<int>arr={1,2,3,4};
    int k=4;
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    if(f(n-1,k,arr,dp))
    cout<<"true";
    else
    cout<<"false";
}

