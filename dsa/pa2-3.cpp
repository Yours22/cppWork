#include <cstdio>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    int times = 0;
    scanf("%d", &times);

    deque<int> delicious;
    priority_queue<int> maxHeap;
    unordered_map<int, int> hash; // 统计出现次数

    for (int i = 1; i <= times; i++)
    {
        int operation;
        scanf("%d", &operation);

        if (operation == 1)
        {
            int deliciousNum;
            scanf("%d", &deliciousNum);

            delicious.push_back(deliciousNum);
            maxHeap.push(deliciousNum);
            hash[deliciousNum]++;
            printf("%d\n", maxHeap.top());
        }
        else if (operation == 2)
        {
            if (!delicious.empty())
            {
                int deletingDeliciousNum = delicious.back();
                delicious.pop_back();

                if (hash[deletingDeliciousNum] >= 1)
                {
                    hash[deletingDeliciousNum]--;
                }

                while (!maxHeap.empty() && hash[maxHeap.top()] == 0)
                {
                    maxHeap.pop();
                }
                if (maxHeap.empty())
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", maxHeap.top());
                }
            }
            else
                printf("-1\n");
            continue;
        }
    }
    return 0;
}