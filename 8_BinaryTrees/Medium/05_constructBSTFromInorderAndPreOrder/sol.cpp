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

TreeNode* solve(vector<int>& preorder, int start, int end, int &idx, unordered_map<int, int>& hash){
    // Break point
    if(start > end) return NULL;

    int nodeVal = preorder[idx];
    idx++;

    int i = hash[nodeVal];

    // new node
    TreeNode* root = new TreeNode(nodeVal);

    // Left Subtree
    root->left = solve(preorder, start, i - 1, idx, hash);
    // Right Subtree
    root->right = solve(preorder, i+1, end, idx, hash);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // The Question to return the head node of the tree
    // Use Hashmap to store index of all elements in inorder
    int n = inorder.size();

    // <val, index> hash values
    unordered_map<int, int> hash;

    for(int i = 0; i < n; i++){
        hash[inorder[i]] = i;
    }

    int idx = 0;

    TreeNode* root = solve(preorder, 0, n - 1, idx, hash);

    return root;
}