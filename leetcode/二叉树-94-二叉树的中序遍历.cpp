#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<int> dealing;
        vector<int> result;
        while (root != nullptr || !dealing.empty())
        {
            while (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}