#include<bits/stdc++.h>
using namespace std;
int f(int ind,vector<int>&height,vector<int>&dp,int k){
    if(ind==0)
    return 0;
    if(dp[ind]!=-1)
    return dp[ind];
    int mmsteps=INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            int jump=f(ind-j,height,dp,k)+abs(height[ind]-height[ind-j]);
            mmsteps=min(jump,mmsteps);
        }
        
    }
    return dp[ind]=mmsteps;
}
int main(){
 vector<int>height{30,10,60,10,60,50};
    int n=height.size();
    int k=10;
    vector<int>dp(n,-1);
    cout<<f(n-1,height,dp,k);
}
