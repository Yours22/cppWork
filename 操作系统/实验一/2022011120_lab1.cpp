#include <cstdio>
#include <thread>
#include <semaphore>

const int N = 10; // 缓冲区大小
int buffer[N];    // 缓冲区
int in = 0;       // 下一个生产者将放置项目的位置
int out = 0;      // 下一个消费者将取出项目的位置

std::counting_semaphore<> empty(N); // 缓冲区空余位置数量
std::counting_semaphore<> full(0);  // 缓冲区已占用位置数量
std::binary_semaphore mutex(1);     // 用于缓冲区的互斥访问

void produce_item(int item)
{
    // 生产项目的代码2
    printf("Produced: %d\n", item);
    printf("Buffer: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void consume_item(int item)
{
    // 消费项目的代码
    printf("Consumed: %d\n", item);
    printf("Buffer: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void producer()
{
    for (int i = 0; i < 20; ++i)
    {
        produce_item(i); // 生产一个新的项目

        // TODO: 等待缓冲区有空位
        empty.acquire();

        // TODO: 进入临界区
        mutex.acquire();

        buffer[in] = i;    // 将项目放入缓冲区
        in = (in + 1) % N; // 更新下一个生产者将放置项目的位置

        // TODO: 离开临界区
        mutex.release();

        // TODO: 增加缓冲区已占用位置数量
        full.release();
    }
}

void consumer()
{
    for (int i = 0; i < 20; ++i)
    {
        // TODO: 等待缓冲区有数据
        full.acquire();

        // TODO: 进入临界区
        mutex.acquire();

        int item = buffer[out]; // 从缓冲区取出项目
        out = (out + 1) % N;    // 更新下一个消费者将取出项目的位置

        // TODO: 离开临界区
        mutex.release();

        // TODO: 增加缓冲区空余位置数量

        empty.release();

        consume_item(item); // 使用项目
    }
}

int main()
{
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
