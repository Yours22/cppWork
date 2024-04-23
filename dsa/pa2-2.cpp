#include <Eigen/Sparse>
#include <vector>
#include <cstdio>
#include <algorithm>

typedef Eigen::SparseMatrix<int> SpMatInt;
typedef Eigen::Triplet<int> TriInt;

SpMatInt readMat()
{
    int nnz, n = 0, m = 0, x, y, v;
    std::vector<TriInt> coo;

    scanf("%d", &nnz);
    for (int i = 0; i < nnz; ++i)
    {
        scanf("%d%d%d", &x, &y, &v);
        coo.push_back(TriInt(x, y, v));
        n = std::max(n, x + 1);
        m = std::max(m, y + 1);
    }
    SpMatInt res(1000, 1000);
    res.setFromTriplets(coo.begin(), coo.end());
    return res;
}

void writeMat(const SpMatInt &m)
{
    printf("%ld\n", m.nonZeros());
    SpMatInt mt = m.transpose();
    for (int k = 0; k < mt.outerSize(); ++k)
    {
        for (SpMatInt::InnerIterator it(mt, k); it; ++it)
        {
            printf("%ld %ld %d\n", it.col(), it.row(), it.value());
        }
    }
}

int main()
{

    SpMatInt mat1, mat2, mat3;

    mat1 = readMat();
    mat2 = readMat();

    mat3 = mat1 * mat2;
    writeMat(mat3);

    return 0;
}