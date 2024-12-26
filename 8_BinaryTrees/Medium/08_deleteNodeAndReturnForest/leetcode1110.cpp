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

TreeNode* solve(TreeNode* root, unordered_set<int>& deleteNodes, vector<TreeNode*>& result){
    if(root == NULL) return NULL;

    root->left = solve(root->left, deleteNodes, result);
    root->right = solve(root->right, deleteNodes, result);

    if(deleteNodes.find(root->val) != deleteNodes.end()){

        if(root->left != NULL) result.push_back(root->left);
        if(root->right != NULL) result.push_back(root->right);

        return NULL;
    } else {
        return root;
    }
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    
    // bottom - up approach
    // Copy all values of to_delete vector to a set
    unordered_set<int> deleteNodes;
    vector<TreeNode*> result;

    for(int &num: to_delete){
        deleteNodes.insert(num);
    }

    solve(root, deleteNodes, result);

    if(deleteNodes.find(root->val) == deleteNodes.end()){
        result.push_back(root);
    }

    return result;
}