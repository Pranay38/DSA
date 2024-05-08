#include<bits/stdc++.h>
using namespace std;
void printans(vector<vector<int>>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
           
        }
         cout<<"]";
         cout<<endl;
    }
}
void findsubset(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
    ans.push_back(ds);
    for(int i=ind;i<nums.size();i++){
        if(i!=ind&&nums[i]==nums[i-1]){
            continue;
        }
        ds.push_back(nums[i]);
        findsubset(i+1,nums,ds,ans);
        ds.pop_back();
    }
}
vector<vector<int>>subsetwithdup(vector<int>&nums){
    vector<int>ds;
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    findsubset(0,nums,ds,ans);
    return ans;

}
int main(){
    vector<int>nums{1,2,2};
    vector<vector<int>>ans=subsetwithdup(nums);
    printans(ans);
    return 0;
}