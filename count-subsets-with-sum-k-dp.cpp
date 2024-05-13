#include<bits/stdc++.h>
using namespace std;
int f(int ind,int target,vector<vector<int>>&dp,vector<int>&arr){
    if(target==0)
    return 1;
    if(ind==0)
    return (arr[ind]==target)?1:0;
    if(dp[ind][target]!=-1)
    return dp[ind][target];
    int notpick=f(ind-1,target,dp,arr);
    int pick=0;
    if(arr[ind]<=target)
    pick=f(ind-1,target-arr[ind],dp,arr);

    return dp[ind][target]=pick+notpick;
}
int main(){
    vector<int>arr{1,2,2,3};
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }

    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    cout<<f(n-1,sum,dp,arr);
}