#include <stdio.h>
#include<stdlib.h>
#define MAX_N 1000000 // the count of ants, 10^6
using namespace std;

int L, n;
int a[MAX_N];

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void solution()
{

    int minT = 0;// 全部蚂蚁掉落需要的最少秒
    for (int i = 0; i < n; i++)
    {
        // 内层的min函数求遍历到的这只蚂蚁掉落需要的最少秒，外层的max函数求全部蚂蚁掉落需要的最少秒
        minT = max(minT, min(a[i], L - a[i]));
    }

    int maxT = 0;
    for (int i = 0; i < n; i++)
    {
        maxT = max(maxT, max(a[i], L - a[i]));
    }

    printf("%d %d\n", minT, maxT);
}

int main()
{
    int caseNum;
    scanf("%d", &caseNum);// 扫描输入的case数量

    while (caseNum--)
    {
        scanf("%d%d", &L, &n);// L 杆长，n 蚂蚁数量
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        solution();
    }
    system("pause");
    return 0;
}