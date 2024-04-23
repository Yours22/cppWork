#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <string>

// finished but not understood fully

using namespace std;

class Solution
{
public:
    string decodeString(string &str)
    {
        int len = str.size();
        stack<string> res;
        stack<int> nums;
        int times = 0;
        string result = "";

        for (int i = 0; i < len; i++)
        {
            if ((str[i] >= '0') && (str[i] <= '9'))
            {
                times = times * 10 + str[i] - '0';
            }
            else if (str[i] == '[')
            {
                nums.push(times);
                times = 0;
                res.push(result);
                result = "";
            }
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                result += str[i];
            }
            else if (str[i] == ']')
            {
                times = nums.top();
                nums.pop();
                for (int j = 0; j < times; j++)
                {
                    res.top() += result;
                }
                result = res.top();
                res.pop();
                times = 0;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string str = "3[a]2[bc]";

    string result = solution.decodeString(str);

    cout << result << endl;

    return 0;
}