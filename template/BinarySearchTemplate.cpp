#include "iostream"

using namespace std;

int bs(int a[], int l, int r, int x) {
    if (l > r) return -1;
    int m = l + ((r - l) >> 1);
    if (a[m] < x) {
        return bs(a, m + 1, r, x);
    } else if (a[m] > x) {
        return bs(a, l, m - 1, x);
    } else {
        return m;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 7, 9};
    int result = bs(a, 0, 6, 5);
    cout << "结果是" << result << endl;
    return 0;
}