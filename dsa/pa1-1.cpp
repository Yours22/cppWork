#include <iostream>
#include <vector>

std::vector<int> poly_plus(const std::vector<int> &poly0, const std::vector<int> &poly1)
{
    /* TODO: 在这里完成多项式加法的运算函数 */
    int len0 = poly0.size(), len1 = poly1.size(), len = std::max(len0, len1);
    std::vector<int> poly_add(len);
    for (int i = 0; i < len; i++)
    {
        while (i < std::min(len0, len1))
        {
            poly_add[i] = poly0[i] + poly1[i];
            i++;
        }
        if (len0 >= len1)
        {
            poly_add[i] = poly0[i];
        }
        else
        {
            poly_add[i] = poly1[i];
        }
    }
    return poly_add;
}

std::vector<int> poly_mul(const std::vector<int> &poly0, const std::vector<int> &poly1)
{
    /* TODO: 在这里完成多项式乘法的运算函数 */
    int len0 = poly0.size(), len1 = poly1.size(), len = len0 + len1 - 1;
    std::vector<int> poly_mul(len);

    for (int i = 0; i < len0; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            poly_mul[i + j] += (poly0[i] * poly1[j]);
        }
    }

    return poly_mul;
}

void print_vector(const std::vector<int> &poly)
{
    printf("%d", poly[0]);
    for (int i = 1; i < poly.size(); i++)
        printf(" %d", poly[i]);
    putchar('\n');
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> poly0(n + 1), poly1(m + 1);
    for (int i = 0; i <= n; i++)
        scanf("%d", &poly0[i]);
    for (int i = 0; i <= m; i++)
        scanf("%d", &poly1[i]);
    print_vector(poly_plus(poly0, poly1));
    print_vector(poly_mul(poly0, poly1));
}
