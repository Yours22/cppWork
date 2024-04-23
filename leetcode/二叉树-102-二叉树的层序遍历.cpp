#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        vector<int> level;
        vector<int> zero;

        queue<TreeNode *> bfs;
        if (root == nullptr)
            return result;
        bfs.push(root);

        while (!bfs.empty())
        {
            int size = bfs.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = bfs.front();
                bfs.pop();
                level.push_back(temp->val);

                if (temp->left != nullptr)
                    bfs.push(temp->left);
                if (temp->right != nullptr)
                    bfs.push(temp->right);
            }

            result.push_back(level);
            vector<int>().swap(level);
        }
        return result;
    }
};