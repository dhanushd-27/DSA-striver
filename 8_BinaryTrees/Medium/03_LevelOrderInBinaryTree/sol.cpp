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

vector<vector<int>> levelOrder(TreeNode* root) {
    
    // TC - O(n)
    // SC - O(n)

    // Intialize ans vector
    vector<vector<int>> ans;
    if(!root) return ans;

    // Intialize a queue data structure
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i = 0; i < size; i++){
            // store front node on a variable
            TreeNode* curr = q.front();
            q.pop();

            // check if both the child nodes are empty or not
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);

            // push curr node value into the level vector
            level.push_back(curr->val);
        }

        ans.push_back(level);
    }

    return ans;
}