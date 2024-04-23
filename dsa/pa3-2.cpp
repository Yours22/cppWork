#include <cstdio>
#include <string>

char str[10000000];

struct TreeNode
{
    char value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode *createTree(const std::string &str, int &index)
{
    if (index >= str.size() || str[index] == '#')
    {
        index++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(str[index++]);
    node->left = createTree(str, index);
    node->right = createTree(str, index);

    return node;
};

void InorderTree(TreeNode *tree)
{
    if (tree->left != nullptr)
        InorderTree(tree->left);

    printf("%c", tree->value);

    if (tree->right != nullptr)
        InorderTree(tree->right);
}

int main()
{
    scanf("%s", str);
    int index = 0;
    TreeNode *root = createTree(str, index);
    InorderTree(root);
    return 0;
}
