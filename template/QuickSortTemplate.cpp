#include<iostream>

using namespace std;

void qsort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    qsort(a, l, j);
    qsort(a, j + 1, r);
}

int main() {
    int a[] = {9, 23, 4, 0, 8};
    qsort(a, 0, 4);
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    cout << endl;
}