#include <cstdio>

struct Node
{
    Node *next;
};

bool hasLoop(Node *head)
{
    // TODO: complete this function
    bool flag = false;

    Node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            flag = true;
            break;
        }
    }

    return flag;
}

int main()
{
    int n, x;
    scanf("%d", &n);
    Node **pool = new Node *[n + 1];
    pool[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        pool[i] = new Node;
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        pool[i]->next = pool[x];
    }
    puts(hasLoop(pool[1]) ? "Has Loop" : "No Loop");
}
