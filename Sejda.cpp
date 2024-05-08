#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        vector<vector<int>>tr(m,vector<int>(2,-1));
        for(int i=0;i<m-1;i++){
            for(int j=0;j<2;j++){
                cin>>tr[i][j];
            }
        }
        vector<vector<int>>close(m+1);
        for(int i=0;i<m;i++){
            close[tr[i][0]].push_back(tr[i][1]);
            close[tr[i][1]].push_back(tr[i][0]);
        }
        int ans=0;
        for(int i=0;i<=m;i++){
            if(tr[i].size()==1)
            ans++;
        }
        int res=ans/2+ans%2;
        cout<<res<<endl;

    }
    return 0;
}