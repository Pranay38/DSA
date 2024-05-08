#include<bits/stdc++.h>
using namespace std;
void printans(vector<vector<int>>&ans){
    cout << "The unique subsets are " << endl;
  cout << "[ ";
  for (int i = 0; i < ans.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << "]";
  }
  cout << " ]";
}
void fun(vector<int>&nums,int ind,vector<int>ds,set<vector<int>>&res){
    if(ind==nums.size()){
        sort(ds.begin(),ds.end());
        res.insert(ds);
        return;
    }
    ds.push_back(nums[ind]);
    fun(nums,ind+1,ds,res);
    ds.pop_back();
    fun(nums,ind+1,ds,res);
}
vector<vector<int>>subsetswithdup(vector<int>&nums){
    vector<vector<int>>ans;
    vector<int>ds;
    set<vector<int>>res;
    fun(nums,0,ds,res);
    for(auto it:res){
        ans.push_back(it);
    }
    return ans;
}
int main(){
    vector<int>nums={1,2,2,2,3,3};
    vector<vector<int>>ans=subsetswithdup(nums);
    printans(ans);
    return 0;
}