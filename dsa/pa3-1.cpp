#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);

    priority_queue<int, vector<int>, greater<int>> deal;
    priority_queue<int, vector<int>, greater<int>> copy;

    for (int i = 0; i < n; i++)
    {
        int operation;
        scanf("%d", &operation);
        int length;
        switch (operation)
        {
        case 1:
            /* code */
            deal = priority_queue<int, vector<int>, greater<int>>();
            scanf("%d", &length);
            int push0;
            for (int j = 0; j < length; j++)
            {
                scanf("%d", &push0);
                deal.push(push0);
            }
            break;
        case 2:
            /* code */
            copy = deal;
            while (!copy.empty())
            {
                printf("%d ", copy.top());
                copy.pop();
            }
            printf("\n");
            break;
        case 3:
            /* code */
            int push1;
            scanf("%d", &push1);
            deal.push(push1);
            break;
        case 4:
            /* code */
            printf("%d\n", deal.top());
            deal.pop();
            break;

        default:
            break;
        }
    }

    return 0;
}