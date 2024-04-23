#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>

class Solution
{
public:
    bool isValid(std::string s)
    {
        int len = s.size();
        std::stack<char> handle;
        handle.push(0);
        handle.push(s[0]);
        for (int i = 1; i < len; i++)
        {
            if (handle.top() == 0)
            {
                handle.push(s[i]);
            }
            else if ((s[i] - handle.top() <= 2) && (s[i] - handle.top() > 0))
            {
                handle.pop();
            }
            else
            {
                handle.push(s[i]);
            }
        }
        if (handle.top() == 0)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    std::string s = "{[]}";

    if (solution.isValid(s))
    {
        std::cout << "true" << std::endl;
    }
    else
        std::cout << "false" << std::endl;

    return 0;
}