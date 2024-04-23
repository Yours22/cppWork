#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int left1 = 0, right1 = row - 1;
        int left2 = 0, right2 = col - 1;

        int mark = 0;

        while (left1 < right1)
        {
            int mid = (right1 - left1) / 2 + left1;
            if (matrix[mid][0] == target)
            {
                return true;
            }
            if (matrix[mid][0] < target && matrix[mid][col - 1] >= target)
            {
                mark = mid;
                break;
            }

            if (matrix[mid][0] < target)
            {
                left1 = mid;
            }
            else
            {
                right1 = mid - 1;
            }
            mark = left1;
        }

        while (left2 <= right2)
        {
            int mid = (right2 - left2) / 2 + left2;
            if (matrix[mark][mid] == target)
            {
                return true;
            }
            if (matrix[mark][mid] < target)
            {
                left2 = mid + 1;
            }
            else
            {
                right2 = mid - 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution Sol;
    vector<vector<int>> matrix = {{-8, -7, -5, -3, -3, -1, 1}, {2, 2, 2, 3, 3, 5, 7}, {8, 9, 11, 11, 13, 15, 17}, {18, 18, 18, 20, 20, 20, 21}, {23, 24, 26, 26, 26, 27, 27}, {28, 29, 29, 30, 32, 32, 34}};
    int target = -5;
    bool result = Sol.searchMatrix(matrix, target);
    cout << (result ? "True" : "False") << endl;
    return 0;
}