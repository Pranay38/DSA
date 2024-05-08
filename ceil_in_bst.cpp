#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right): val(x),left(left),right(right){}
};
int findceil(TreeNode* &root,int &key ){
   int ceil=-1;
   while(root){
    if(root->val==key){
        ceil=root->val;
        return ceil;
    }
    if(root->val>=key){
        ceil=root->val;
        root=root->left;
    }
    else{
        root=root->right;
    }

   }
   return ceil;
}
int main() {
    // Create the binary tree from the example in the explanation:
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->right->left=new TreeNode(11);
    root->right->right=new TreeNode(14);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->left->right->right=new TreeNode(9);
    root->left->left->left=new TreeNode(2);
    root->left->left->right=new TreeNode(4);
    root->right->left = new TreeNode(2);
    int key=9;
    int d=findceil(root,key);
    cout<<d<<endl;

}