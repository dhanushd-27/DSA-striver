#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidNode(TreeNode* root, long long minVal, long long maxVal){
    
    // return true if the node is empty
    if(root == NULL) return true;

    // return false if it violates bst rules
    if(root->val <= minVal || root->val >= maxVal) return false;

    // check for left and right in recursive way
    return isValidNode(root->left, minVal, root->val) && isValidNode(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidNode(root, LLONG_MIN, LLONG_MAX);
}