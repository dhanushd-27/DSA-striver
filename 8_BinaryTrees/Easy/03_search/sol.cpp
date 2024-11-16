#include <bits/stdc++.h>
using namespace std;

// Leetcode - 700

// TC - O(n)
// SC - O(1)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val){

    while(root != NULL && root->val != val){
        root->val > val ? root = root->left : root = root->right;
    }

    return root;
}