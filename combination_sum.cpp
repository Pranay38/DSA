#include<bits/stdc++.h>
using namespace std;
//class Solution{
  //  public:
     void findcombination(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(ds);
        }
        //else
        return;
    }
    if(arr[ind]<=target){
        ds.push_back(arr[ind]);
        findcombination(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    }
    findcombination(ind+1,target,arr,ans,ds);
     }

//}
//public:
vector<vector<int>>combinationsum(vector<int>&candidates,int target){
    vector<vector<int>>ans;
    vector<int>ds;
    findcombination(0,target,candidates,ans,ds);
    return ans;
}
//};
int main(){
    //Solution obj;
    vector<int>v{2,3,6,7};
    /*v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);*/
    int target=7;
    vector < vector < int >> ans ;
    ans= combinationsum(v, target);

    cout<<"Combinations are:"<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
           
        }
         cout<<endl;
    }
}