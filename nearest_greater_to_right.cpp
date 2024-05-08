#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={1,3,0,0,1,2,4};
    vector<int>v;
    stack<int>s;
    for(int i=arr.size()-1;i>=0;i--){
        if(s.size()==0)
        v.push_back(-1);
        else if(s.size()>0&&s.top()>arr[i])
        v.push_back(s.top());
        else if(s.size()>0&&s.top()<arr[i]){
            while(s.size()>0&&s.top()<arr[i]){
                s.pop();
            }
            if(s.size()==0)
            v.push_back(-1);
            else
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}