#include<bits/stdc++.h>
using namespace std;

//-----------MEMOIZATION------------------
// int f(int day,int last,vector<vector<int>>&dp,vector<vector<int>>&points){
//     if(dp[day][last]!=-1)
//     return dp[day][last];
//     //base case
//     if(day==0){
//         int maxi=0;
//         for(int i=0;i<=2;i++){
//             if(i!=last){
//                 maxi=fmax(maxi,points[0][last]);
//             }

//         }
//         return dp[day][last]=maxi;
//     }
//         int maxi=0;
//         //for current day
//         for(int i=0;i<=2;i++){
//             if(i!=last){
//                 int activity=points[day][i]+f(day-1,i,dp,points);
//                 maxi=fmax(maxi,activity);
//             }
//         }
//         return dp[day][last]=maxi;
//     }

// int main(){
//     vector<vector<int>> points = {{10, 40, 70},{20, 50, 80},{30, 60, 90}};
//     int n=points.size();
//     vector<vector<int>>dp(n,vector<int>(4,-1));
//     cout<<f(n-1,3,dp,points);
// }

//-----------TABULATION------------------
// int f(int n,vector<vector<int>>&points){
//     vector<vector<int>>dp(n,vector<int>(4,0));
//     dp[0][0]=fmax(points[0][1],points[0][2]);
//     dp[0][1]=fmax(points[0][0],points[0][2]);
//     dp[0][2]=fmax(points[0][0],points[0][1]);
//     dp[0][3]=fmax(points[0][0],fmax(points[0][1],points[0][2]));

//     for(int day=1;day<n;day++){
//         for(int last=0;last<=3;last++){
//             dp[day][last]=0;
//             for(int task=0;task<=2;task++){
//                 if(task!=last){
//                     int activity=points[day][task]+dp[day-1][task];
//                     dp[day][last]=fmax(dp[day][last],activity);

//                 }
//             }
//         }
//     }
//     return dp[n-1][3];
// }
// int main(){
//     vector<vector<int>> points = {{10, 40, 70},{20, 50, 80},{30, 60, 90}};
//     int n=points.size();
    
//     cout<<f(n,points);
// }


//---------Space Optimization--------------
int f(int n,vector<vector<int>>&points){
  vector<int>prev(4,0);
    prev[0]=fmax(points[0][1],points[0][2]);
    prev[1]=fmax(points[0][0],points[0][2]);
    prev[2]=fmax(points[0][0],points[0][1]);
    prev[3]=fmax(points[0][0],fmax(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                     temp[last]=fmax(temp[last],points[day][task]+prev[task]);
                }
        }
    }
    prev=temp;
}
return prev[3];

}
int main(){
    vector<vector<int>> points = {{10, 40, 70},{20, 50, 80},{30, 60, 90}};
    int n=points.size();
    
    cout<<f(n,points);
}