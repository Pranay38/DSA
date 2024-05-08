#include<bits/stdc++.h>
using namespace std;
//--------MEMOIZATION----------
// int f(int n,vector<int>dp){
//     if (n<=1)
//     return n;
//     if(dp[n]!=-1)
//     return dp[n];
//     return dp[n]=f(n-1,dp)+f(n-2,dp);
// }
// int main(){
// int n=10;
// //cin>>n;
// vector<int>dp(n+1,-1);
// cout<<f(n,dp);
// return 0;

// }
//-----------TABULATION-------

int main(){
    int n=5;
    vector<int>dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    dp[i]=dp[i-2]+dp[i-1];
    cout<<dp[n];
    return 0;
}