// [Binary Tree Preorder Traversal - LeetCode](https://leetcode.com/problems/binary-tree-preorder-traversal/)

class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
      if(root) {
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
      }
      return ans;
    }
};