#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int origin(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, length = nums.size() - 1;
        while (left <= right && right > 1)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > nums[mid - 1])
            {
                if (nums[mid] < nums[mid + 1] && nums[mid] > nums[length])
                {
                    left = mid + 1;
                }
                else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[0])
                {
                    right = mid - 1;
                }
                else if (nums[mid] > nums[mid + 1])
                {
                    return mid + 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        return 0;
    }
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        if (right == 0)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
                return -1;
        }
        else if (right == 1)
        {
            if (nums[0] == target || nums[1] == target)
            {
                return 0;
            }
            else
                return -1;
        }

        int mark1 = origin(nums);
        if (target == nums[mark1])
        {
            return mark1;
        }
        else if (target > nums[mark1] && target > nums[0])
        {
            right = mark1 - 1;
        }
        else if (target < nums[mark1])
        {
            left = mark1 + 1;
        }
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                right = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5};
    int target = 3;
    int result = sol.search(nums, target);
    cout << result;
    return 0;
}