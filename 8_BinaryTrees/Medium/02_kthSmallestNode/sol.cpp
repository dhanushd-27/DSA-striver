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

// Inorder traversal is the best way
    // Left most node is the smallest as you comeback minus k by 1

    // TC - O(k)
    // SC - O(k) - auxillary stack space

int ans = 0;
void inorder(TreeNode* root, int &k){

    if(root == NULL) return;

    inorder(root->left, k);
    k--;
    if(k == 0){
        ans = root->val;
    }
    inorder(root->right, k);
}

int kthSmallest(TreeNode* root, int k) {
    inorder(root, k);
    return ans;
}