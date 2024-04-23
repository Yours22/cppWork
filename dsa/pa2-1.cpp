#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    char **border(char **matrix, int row, int col)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int xx, yy;
        queue<pair<int, int>> queue;

        // 第一行
        for (int j = 0; j < col; j++)
        {
            int i = 0;
            if (matrix[i][j] == '.')
            {
                matrix[i][j] = 'a';
                queue.push({i, j});

                while (!queue.empty())
                {
                    auto [x0, y0] = queue.front();
                    queue.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        xx = x0 + dx[k];
                        yy = y0 + dy[k];

                        if (xx < 0 || yy < 0 || xx > row - 1 || yy > col - 1)
                        {
                            continue;
                        };
                        if (matrix[xx][yy] == '*')
                        {
                            matrix[xx][yy] = '#';
                        }
                        else if (matrix[xx][yy] == '.')
                        {
                            matrix[xx][yy] = 'a';
                            queue.push({xx, yy});
                        }
                    }
                }
            }
            else if (matrix[i][j] == '*')
            {
                matrix[i][j] = '#';
            }
        }

        // 测试用
        // for (int i = 0; i < row; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //     {
        //         if (matrix[i][j] == 'a')
        //         {
        //             cout << ".";
        //         }
        //         else
        //         {
        //             cout << matrix[i][j];
        //         }
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // 最后一行
        for (int j = 0; j < col; j++)
        {
            int i = row - 1;
            if (matrix[i][j] == '.')
            {
                matrix[i][j] = 'a';
                queue.push({i, j});

                while (!queue.empty())
                {
                    auto [x0, y0] = queue.front();
                    queue.pop();
                    for (int k = 0; k < 4; k++)
                    {

                        yy = y0 + dy[k];
                        xx = x0 + dx[k];

                        if (xx < 0 || yy < 0 || xx > row - 1 || yy > col - 1)
                        {
                            continue;
                        };
                        if (matrix[xx][yy] == '*')
                        {
                            matrix[xx][yy] = '#';
                        }
                        else if (matrix[xx][yy] == '.')
                        {
                            matrix[xx][yy] = 'a';
                            queue.push({xx, yy});
                        }
                    }
                }
            }
            else if (matrix[i][j] == '*')
            {
                matrix[i][j] = '#';
            }
        }

        // 测试用
        // for (int i = 0; i < row; i++)
        // {
        //     for (int j = 0; j < col; j++)
        //     {
        //         if (matrix[i][j] == 'a')
        //         {
        //             cout << ".";
        //         }
        //         else
        //         {
        //             cout << matrix[i][j];
        //         }
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // 第一列
        for (int i = 1; i < row - 1; i++)
        {
            int j = 1;
            if (matrix[i][j] == '.')
            {
                matrix[i][j] = 'a';
                queue.push({i, j});

                while (!queue.empty())
                {
                    auto [x0, y0] = queue.front();
                    queue.pop();
                    for (int k = 0; k < 4; k++)
                    {

                        yy = y0 + dy[k];
                        xx = x0 + dx[k];

                        if (xx < 0 || yy < 0 || xx > row - 1 || yy > col - 1)
                        {
                            continue;
                        };
                        if (matrix[xx][yy] == '*')
                        {
                            matrix[xx][yy] = '#';
                        }
                        else if (matrix[xx][yy] == '.')
                        {
                            matrix[xx][yy] = 'a';
                            queue.push({xx, yy});
                        }
                    }
                }
            }
            else if (matrix[i][j] == '*')
            {
                matrix[i][j] = '#';
            }

            // 测试用
            //     for (int i = 0; i < row; i++)
            //     {
            //         for (int j = 0; j < col; j++)
            //         {
            //             if (matrix[i][j] == 'a')
            //             {
            //                 cout << ".";
            //             }
            //             else
            //             {
            //                 cout << matrix[i][j];
            //             }
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
        }

        // 最后一列
        for (int i = 0; i < row - 1; i++)
        {
            int j = col - 1;

            if (matrix[i][j] == '.')
            {
                matrix[i][j] = 'a';
                queue.push({i, j});

                while (!queue.empty())
                {
                    auto [x0, y0] = queue.front();
                    queue.pop();
                    for (int k = 0; k < 4; k++)
                    {

                        yy = y0 + dy[k];
                        xx = x0 + dx[k];

                        if (xx < 0 || yy < 0 || xx > row - 1 || yy > col - 1)
                        {
                            continue;
                        };
                        if (matrix[xx][yy] == '*')
                        {
                            matrix[xx][yy] = '#';
                        }
                        else if (matrix[xx][yy] == '.')
                        {
                            matrix[xx][yy] = 'a';
                            queue.push({xx, yy});
                        }
                    }
                }
            }
            else if (matrix[i][j] == '*')
            {
                matrix[i][j] = '#';
            }
        }
        // 测试用
        //  for (int i = 0; i < row; i++)
        //  {
        //      for (int j = 0; j < col; j++)
        //      {
        //          if (matrix[i][j] == 'a')
        //          {
        //              cout << ".";
        //          }
        //          else
        //          {
        //              cout << matrix[i][j];
        //          }
        //      }
        //      cout << endl;
        //  }
        //  cout << endl;

        return matrix;
    }
};
// for (int p = 0; p < row; p++)
// {
//     for (int q = 0; q < col; q++)
//     {
//         cout << matrix[p][q];
//     }
//     cout << endl;
// }

int main()
{
    int row, col;
    cin >> row >> col;

    char **matrix = new char *[row];
    for (int i = 0; i < row; ++i)
        matrix[i] = new char[col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = '0';
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution solution;
    solution.border(matrix, row, col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 'a')
            {
                cout << ".";
            }
            else
            {
                cout << matrix[i][j];
            }
        }
        cout << endl;
    }

    for (int i = 0; i < row; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}