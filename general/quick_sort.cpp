#include <iostream>

using namespace std;
const int N = 100010;
int n;

/**
 * 快速排序过程分析
 *
 * @param q
 * @param l
 * @param r
 */
void quick_sort(int q[], int l, int r) {
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    cout << endl;
    // 当左右标记重合时，停止
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    cout << "i = " << i << ", j = " << j << ", 轴心点元素index = " << ((l + r) >> 1) << ", value = " << x << endl << endl;

    while (i < j) {
        do i++; while (q[i] < x);// 左区间遇到大于等于x的元素时，停下
        do j--; while (q[j] > x);// 右区间遇到小于等于x的元素时，停下
        // 当i和j未交错时，交换两元素
        if (i < j) {
            swap(q[i], q[j]);
            cout << "交换了索引 " << i << "和" << j << endl;
        }
    }

    // 轴心点左区间
    quick_sort(q, l, j);
    // 轴心点右区间
    quick_sort(q, j + 1, r);
}

int main() {
    int q[N];
//    int n;
    scanf("%d", &n);
    // & 取数组索引位置i的地址，把从终端扫描到的数存入数组
    cout << "输入数组 ";
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    // 不使用 & 则是直接取索引位置i的地址
    cout << "输出数组";
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}