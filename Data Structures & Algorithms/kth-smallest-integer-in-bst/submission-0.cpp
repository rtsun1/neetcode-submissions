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
    int kthSmallest(TreeNode* root, int k) {
        // inorder traversal with counter and check if counter == k
        this->k = k;
        return dfs(root);
    }

private:
    int counter = 1;
    int k;
    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left_result = dfs(node->left);
        if (counter++ == k) {
            return node->val;
        }
        int right_result = dfs(node->right);
        return left_result + right_result;
    }
};
