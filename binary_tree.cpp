#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int main() {
    stringstream cin("7\n5 3 6 2 4 -1 7");

    // cin >> input;
    int N;
    char c;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < N; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";

    vector<TreeNode> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i].val = nums[i];
    }

    nodes[0].left = &nodes[1];
    nodes[0].right = &nodes[2];
    
    nodes[1].left = &nodes[3];
    nodes[1].right = &nodes[4];

    nodes[2].left = &nodes[5];
    nodes[2].right = &nodes[6];

    nodes[3].left = &nodes[5];
    nodes[3].right = &nodes[6];

    nodes[4].left = &nodes[5];
    nodes[4].right = &nodes[6];

    nodes[5].left = &nodes[5];
    nodes[5].right = &nodes[6];

// min heap -> Priorty Queue
//        0 
//      1   2
//   3   4  5   6
//  7 8 91011121314

    for (int i = 0; i < (N-1)/2; i++) {
        nodes[i].left = &nodes[i * 2 + 1];
        nodes[i].right = &nodes[i * 2 + 2];
    }

/*
https://www.desmos.com/calculator/hcwfvuvjqp
y=\operatorname{floor}\left(\frac{\left(x-1\right)}{2}\right)
(1,0),(2,0),(3,1),(4,1),(5,2),(6,2)
*/
// 2     ..
// 1   ..
// 0 ..
//  0123456
    /*
    123456
        / % -1/
1    0  0 1 0 0
2    0  1 0 1 0
3    1  1 1 2 1
4    1  2 0 3 1
5    2  2 1 4 2
6    2  3 0 5 2



    123456
    */

    cout << nodes[1].val << "\n";
    cout << (*(nodes[0].left)).val << "\n";


}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        while (root) {
            if (!root->left) { // if root.left IS null
                ans.push_back(root->val); // Record root.val
                root = root->right; // Let root.right be the new root
            } else { // if root.left is NOT null

                // Let current node be the right-most children in the left tree of root
                TreeNode* node = root->left;
                while (node->right && (node->right != root)) {
                    // TODO (node->right != root) seems always be true?
                    node = node->right;
                }

                if (!node->right) { // if node.right is NOT null
                    ans.push_back(root->val); // Record root.val

                    node->right = root; // Point node.right to the root
                    root = root->left; // Let root.left be the new root
                } else { // if node.right IS null
                    root = root->right; // Let root.right be the new root
                    node->right = nullptr;
                }
            }
        }
        return ans;
    }
};