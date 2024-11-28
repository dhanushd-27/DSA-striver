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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // TC - O(n)
    // SC - O(n)

    // Intialize ans vector
    vector<vector<int>> ans;
    if(!root) return ans;

    // Intialize a queue data structure
    queue<TreeNode*> q;
    q.push(root);

    // bool to toggle the insertion way
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();

        // Intialize a vector of size same as queue's
        vector<int> level(size);

        for(int i = 0; i < size; i++){

            // this line will decide the index
            int index = leftToRight ? i : size - i - 1;

            // store front node on a variable
            TreeNode* curr = q.front();
            q.pop();

            // check if both the child nodes are empty or not
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);

            // push curr node value into the level vector
            level[index] = curr->val;
        }

        leftToRight = !leftToRight;
        ans.push_back(level);
    }

    return ans;
}