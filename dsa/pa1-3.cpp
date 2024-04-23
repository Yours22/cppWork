#include <iostream>

struct ArrInfo
{
    unsigned int *arr;
    unsigned int nums;     // 已有元素数量
    unsigned int capacity; // 数组容量
};

// 操作
unsigned int search(unsigned int num, ArrInfo &arr)
{
    int index = 0;

    for (int i = arr.nums - 1; i >= 0; --i)
    {
        if (arr.arr[i] <= num)
        {
            if (arr.arr[i] == 0)
            {
                continue;
            }

            index = i + 1;
            break;
        }
    }

    return index;
}

// 用于操作结构体和返回数组内元素的移动次数
unsigned int dynamic_alloc(char s, unsigned int operateNum, ArrInfo &Arr)
{
    unsigned int moves = 0;
    // 操作结构体
    switch (s)
    {
    case 'A':
    {
        // 判断扩容
        if (Arr.nums == Arr.capacity)
        {
            unsigned int *newArr = new unsigned int[Arr.capacity * 2];
            std::copy(Arr.arr, Arr.arr + Arr.nums, newArr);
            delete[] Arr.arr;
            Arr.arr = newArr;
            Arr.capacity *= 2;

            unsigned int addingIndex = 0;
            addingIndex = search(operateNum, Arr);
            std::copy_backward(Arr.arr + addingIndex, Arr.arr + Arr.nums, Arr.arr + Arr.nums + 1);
            Arr.arr[addingIndex] = operateNum;

            moves = Arr.nums;
            Arr.nums++;

            break;
        }

        // 检索和移动
        unsigned int addingIndex = 0;
        addingIndex = search(operateNum, Arr);
        std::copy_backward(Arr.arr + addingIndex, Arr.arr + Arr.nums, Arr.arr + Arr.nums + 1);

        Arr.arr[addingIndex] = operateNum;

        moves = Arr.nums - addingIndex;
        Arr.nums++;
        break;
    }
    case 'D':
    {

        // 待完善
        //  判断缩容
        if (Arr.nums <= Arr.capacity / 4)
        {
            unsigned int *newArr = new unsigned int[Arr.capacity / 2];
            std::copy(Arr.arr, Arr.arr + Arr.nums, newArr);
            delete[] Arr.arr;
            Arr.arr = newArr;
            Arr.capacity /= 2;

            unsigned int deletingIndex = 0;
            deletingIndex = search(operateNum, Arr) - 1;
            std::copy(Arr.arr + deletingIndex + 1, Arr.arr + Arr.nums, Arr.arr + deletingIndex);
            Arr.arr[Arr.nums - 1] = 0;
            moves = Arr.nums - 1;
            Arr.nums--;

            break;
        }
        // 检索和移动
        unsigned int deletingIndex = 0;
        deletingIndex = search(operateNum, Arr) - 1;
        std::copy(Arr.arr + deletingIndex + 1, Arr.arr + Arr.nums, Arr.arr + deletingIndex);
        Arr.arr[Arr.nums - 1] = 0;

        moves = Arr.nums - (deletingIndex + 1);
        Arr.nums--;
        break;
    }
    }

    return moves;
};

int main()
{
    ArrInfo arr;
    arr.arr = new unsigned int[2];
    arr.nums = 0;
    arr.capacity = 2;

    unsigned int n = 0, x = 0;
    char s = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> s >> x;
        std::cout << dynamic_alloc(s, x, arr) << std::endl;

        // 测试用
        // for (int j = 0; j < arr.nums; j++)
        // {
        //     if (arr.arr[j] == 0)
        //     {
        //         continue;
        //     }
        //     std::cout << arr.arr[j] << ' ';
        // }
        // std::cout << std::endl;
    }

    return 0;
}