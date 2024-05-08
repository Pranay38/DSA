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

bool isChildrenSumProperty(TreeNode* root) {
    // Base case: If the node is null, it satisfies the property (as it has no children).
    if (root == nullptr)
        return true;

    // If the node is a leaf node, it satisfies the property (as it has no children).
    if (root->left == nullptr && root->right == nullptr)
        return true;

    int leftVal = 0, rightVal = 0;

    // Calculate the values of left and right children (if they exist).
    if (root->left)
        leftVal = root->left->val;

    if (root->right)
        rightVal = root->right->val;

    // Check if the current node's value is equal to the sum of its children's values.
    if (root->val == leftVal + rightVal)
        return isChildrenSumProperty(root->left) && isChildrenSumProperty(root->right);
    else
        return false;
}

int main() {
    // Create the binary tree from the example in the explanation:
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);

    if (isChildrenSumProperty(root))
        std::cout << "The binary tree satisfies the Children Sum Property." << std::endl;
    else
        std::cout << "The binary tree does not satisfy the Children Sum Property." << std::endl;

    // Remember to free the dynamically allocated memory to avoid memory leaks.
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}

