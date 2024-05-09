#include<bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>&dp,vector<vector<int>>&points){
    if(dp[day][last]!=-1)
    return dp[day][last];
    //base case
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=fmax(maxi,points[0][last]);
            }

        }
        return dp[day][last]=maxi;
    }
        int maxi=0;
        //for current day
        for(int i=0;i<=2;i++){
            if(i!=last){
                int activity=points[day][i]+f(day-1,i,dp,points);
                maxi=fmax(maxi,activity);
            }
        }
        return dp[day][last]=maxi;
    }

int main(){
    vector<vector<int>> points = {{10, 40, 70},{20, 50, 80},{30, 60, 90}};
    int n=points.size();
    vector<vector<int>>dp(n,vector<int>(4,-1));
    cout<<f(n-1,3,dp,points);
}