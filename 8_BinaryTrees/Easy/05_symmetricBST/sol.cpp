#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode* l, TreeNode* r){

    // if both are null i.e both are symmetrical
    if(l == NULL && r == NULL) return true;

    // if any one is NULL and the other one is not they are not symmetrical
    if(l == NULL || r == NULL) return false;

    // if any one condition fails return false;
    return l->val == r->val && check(l->left, r->right) && check(l->right, r->left);
}

bool isSymmetric(TreeNode* root) {
    return check(root->left, root->right);
}