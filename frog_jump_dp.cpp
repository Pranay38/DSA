#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>&height,vector<int>&dp){
    if(ind==0)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int two=INT_MAX;
    int one=f(ind-1,height,dp)+abs(height[ind-1]-height[ind]);
    if(ind>1)
    two=f(ind-2,height,dp)+abs(height[ind-2]-height[ind]);
    return dp[ind]=min(one,two);
}
int main(){
    vector<int>height{30,10,60,10,60,50};
    int n=height.size();
    vector<int>dp(n,-1);
    cout<<f(n-1,height,dp);
}