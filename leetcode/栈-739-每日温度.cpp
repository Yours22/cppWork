#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 单调栈，写之前没学过

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int len = temperatures.size();
        vector<int> result(len);
        stack<int> mono;

        for (int i = 0; i < len; i++)
        {

            // if (temperatures[j] > temperatures[i])
            // {
            //     result[i] = j - i;
            //     break;
            //     if (j == len - 1)
            //         result[i] = 0;
            // }
            while (!mono.empty() && temperatures[i] > temperatures[mono.top()])
            {
                int index = mono.top();
                result[index] = i - index;
                mono.pop();
            }
            mono.push(i);
        }
        return result;
    }
};

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution sol;
    vector<int> result = sol.dailyTemperatures(temperatures);

    for (const auto &val : result)
    {
        cout << val << ' ';
    }
    cout << endl;
}