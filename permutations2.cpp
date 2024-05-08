#include<bits/stdc++.h>
using namespace std;
void findperm(int ind,vector<int>&nums,vector<vector<int>>&ans){
    if(ind==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
        swap(nums[ind],nums[i]);
        findperm(ind+1,nums,ans);
        swap(nums[ind],nums[i]);
    }
}
vector<vector<int>>permute(vector<int>&nums){
    vector<vector<int>>ans;
    //vector<int>ds;
    findperm(0,nums,ans);
    return ans;

}
int main(){
    vector<int>v{1,2,3};
    vector<vector<int>>sum=permute(v);
    for(int i=0;i<sum.size();i++){
        for(int j=0;j<sum[i].size();j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
}