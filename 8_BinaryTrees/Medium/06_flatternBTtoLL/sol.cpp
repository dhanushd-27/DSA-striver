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

// Recursive
// TC - O(n)
// SC - O(n)

// Use a global variable prev
// TreeNode* prev;
// void flatten(TreeNode* root) {
//     if(root == NULL) return;

//     // Do reverse post order traversal - Right, Left, Root
//     flatten(root->right);
//     flatten(root->left);

//     root->right = prev;
//     root->left = nullptr;
//     prev = root;
// }

// Iterative
void flatten(TreeNode* root) {
    // Use a stack data structure

    if(root == NULL) return;

    stack<TreeNode*> st;
    st.push(root);
    TreeNode* node;

    while(!st.empty()){
        node = st.top();
        st.pop();

        // Push Right Node First then Left
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);

        if(!st.empty()){
            // Access the top node always
            node->right = st.top();
            node->left = nullptr;
        }
    }
}

// Morris Traversal Later