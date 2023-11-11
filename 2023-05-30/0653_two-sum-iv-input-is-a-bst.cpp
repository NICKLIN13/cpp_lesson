
#include <set>
using namespace std;

// [Two Sum IV - Input is a BST - LeetCode](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)
class Solution {
public:
    vector<int> res;

    bool findTarget(TreeNode* root, int k) {
      if(root) {
        if (st.find(k - root->val) != res.end()) return true;

        res.insert(root->val);
        findTarget(root->left);
        findTarget(root->right);
      }
      findTarget(root);
      return false;
  }
};