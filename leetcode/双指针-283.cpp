// 283 - 移动零

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int *fast = &nums[0];
        int *slow = &nums[0];

        int j = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (j < i)
            {
                j = i + 1;
            }
            if (*(slow + i) == 0)
            {
                while (j < nums.size())
                {
                    if (*(fast + j) != 0)
                    {
                        int temp = *(slow + i);
                        *(slow + i) = *(fast + j);
                        *(fast + j) = temp;
                        j++;
                        break;
                    }
                    j++;
                }
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 0};

    solution.moveZeroes(nums);

    // 打印结果
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}