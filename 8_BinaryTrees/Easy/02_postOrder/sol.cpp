#include <bits/stdc++.h>
using namespace std;

// Leetcode 145

// TC - O(n);
// SC - O(n);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root){

    if(root == NULL) return {};

    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    st1.push(root);

    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);

        if(root->left != NULL) st1.push(root->left);

        if(root->right != NULL) st1.push(root->right);
    }

    vector<int> result;

    while(!st2.empty()){
        root = st2.top();
        result.push_back(root->val);
        st2.pop();
    }
    
    return result;
}