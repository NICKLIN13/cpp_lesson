#include <iostream>
using namespace std;

struct Test
{
    int N, M;
};



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main(){
    int N, M;
    cout << "Input N and M: ";
    cin >> N >> M;

    cout << N << " " << M << "\n";
    Test t = {N, M};
    cout << t.N << " " << t.M << "\n";
    return 0;
}