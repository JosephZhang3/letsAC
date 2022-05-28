#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "iostream"
using namespace std;

#define MAX_N 1000
int n, m, k[MAX_N]; // n 每个人抽到的数值，m 要求数值之和，MAX_N 能抽到的最大数值

bool binary_search(int x)
{
    int l = 0, r = n;

    while (l <= r - 1)// TODO deal [half,left] job
    {
        int i = l + (r - l) >> 2;
        if (k[i] == x)
        {
            return true;
        }
    }

    return false;
}

// 复杂度为 n的3次幂乘logn 的解法，外边3层for循环，最里层一个二分查找函数（对数时间）
void solution1()
{
}

// 抽签问题
int main()
{
    cout << (8 >> 2) << endl;
    system("pause"); // 暂停main函数，使控制台不退出
}