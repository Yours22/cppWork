#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    int ans;

public:
    int diamater(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = diamater(root->left);
        int right = diamater(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 1;
        diamater(root);
        return ans;
    }
};