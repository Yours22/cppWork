#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (target >= nums[mid])
            {
                left = mid + 1;
            }
            else if (target < nums[mid])
            {
                right = mid - 1;
            }
        }
        if (right < 0 || right > nums.size() - 1 || nums[right] != target)
        {
            return -1;
        }
        return right;
    }
    int lowerBound(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;
            if (target <= nums[mid])
            {
                right = mid - 1;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
        }
        if (left < 0 || left > nums.size() - 1 || nums[left] != target)
        {
            return -1;
        }
        return left;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int upper = (nums.size() == 0) ? -1 : upperBound(nums, target);
        int lower = (nums.size() == 0) ? -1 : lowerBound(nums, target);
        vector<int> result = {lower, upper};

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1};
    int target = 0;
    vector<int> result = sol.searchRange(nums, target);
    cout << result[0] << result[1];
    return 0;
}