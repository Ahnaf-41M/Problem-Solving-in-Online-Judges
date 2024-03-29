/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    void inOrder(TreeNode *cur) {
        if (cur == NULL) return;
        inOrder(cur->left);
        ans.push_back(cur->val);
        inOrder(cur->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);

        /* Iterative */
        // if(root == NULL) return ans;
        // stack<TreeNode*> st;
        // TreeNode *cur = root;

        // while(cur != NULL || !st.empty()) {
        //     while(cur != NULL){
        //         st.push(cur);
        //         cur = cur->left;
        //     }
        //     cur = st.top();
        //     st.pop();
        //     ans.push_back(cur->val);
        //     cur = cur->right;
        // }
        // return ans;
    }
};