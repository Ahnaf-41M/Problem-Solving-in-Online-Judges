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

    void postOrder(TreeNode *cur) {
        if (cur == NULL) return;
        postOrder(cur->left);
        postOrder(cur->right);
        ans.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        /* Iterative */
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()) {
        //     TreeNode *cur = st.top();
        //     if(cur == NULL) {
        //         st.pop();
        //         continue;
        //     }
        //     if(cur->left == NULL && cur->right == NULL) {
        //         ans.push_back(cur->val);
        //         st.pop();
        //         continue;
        //     }
        //     st.push(cur->right);
        //     st.push(cur->left);
        //     cur->right = cur->left = NULL;
        // }
        return ans;
    }
};