// 11-盛最多水的容器

// Try to use two-pointers. Set one pointer to the left and one to the right of the array. Always move the pointer that points to the lower line.

#include <iostream>
#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int *left = &height[0];
        int *right = &height[height.size() - 1];
        int area0 = (right - left) * std::min(*left, *right);

        while (left != right)
        {
            if (*left < *right)
            {
                left++;
            }
            else
            {
                right--;
            }

            area0 = std::max((right - left) * std::min(*left, *right), (long int)area0);
        }
        return area0;
    }
};

int main()
{
    Solution solution;

    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = 0;
    result = solution.maxArea(height);

    std::cout << result << std::endl;

    return 0;
}