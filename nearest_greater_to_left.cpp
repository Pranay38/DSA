#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v={1,3,2,4};
    vector<int>ans;
    stack<int>s;
    for(int i=0;i<v.size();i++){
        if(s.size()==0){
            ans.push_back(-1);
        }
        else if(v[i]<s.top()&&s.size()>0){
            ans.push_back(s.top());
            
        }
        else if(v[i]>=s.top()&&s.size()>0){
            while(s.size()>0&&s.top()<=v[i]){
                s.pop();
            }
            if(s.size()==0)
            ans.push_back(-1);
            else if(s.top()>v[i]){
                ans.push_back(s.top());
            }
            
        }
        s.push(v[i]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}