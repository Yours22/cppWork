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
public:
    bool isSym(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
        {
            if (p == nullptr && q == nullptr)
            {
                return true;
            }
            return false;
        }
        else if (isSym(p->left, q->right) && isSym(p->right, q->left) &&
                 (p->val == q->val))
            return true;
        else
            return false;
    };
    bool isSymmetric(TreeNode *root) { return isSym(root, root); }
};
