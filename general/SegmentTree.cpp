//
// Created by mac on 2020/11/9.
//

#include "SegmentTree.h"
#include "iostream"

using namespace std;
#define maxn 100007
#define ls l, m, rt<<1
#define rs m+1, r, rt<<1|1

// 维护序列区间和
int sum[maxn << 2], add[maxn << 2];// add为懒惰标记
int a[maxn], n;

// 上推，求和，因为update时下推了标记，所以，节点的add值一定为0，就不需要考虑add
void pushUp(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

// 下推 ln rn分别为左/右子树的数字数量
void pushDown(int rt, int ln, int rn) {
    if (add[rt]) {// 当前节点标记大于0
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] += add[rt] * ln;
        sum[rt << 1 | 1] += add[rt] * rn;
        add[rt] = 0;// 清除标记
    }
}

// 建树，rt表示当前节点索引
void build(int l, int r, int rt) {
    if (l == r) {
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, rt >> 1);
    build(m + 1, r, rt >> 1);
    pushUp(rt);
}

// 点修改 x表示被修改的点的索引，i表示增加的值，rt表示当前节点缩影
void update(int L, int i, int l, int r, int rt) {
    if (l == r) {
        sum[rt] += i;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) {
        update(L, i, l, m, rt << 1);
    } else {
        update(L, i, m + 1, r, rt << 1);
    }
    pushUp(rt);
}

// 区间修改 L,R表示操作区间，l r表示当前节点区间
void update(int L, int R, int i, int l, int r, int rt) {
    if (L <= l && r <= R) {
        sum[rt] += i * (r - l + 1);
        add[rt] += i;

        return;
    }
    int m = (l + r) >> 1;
    pushDown(rt, m - l + 1, r - m);// 下推标记，传左子树个数，右子树个数

    if (L <= m) {
        update(L, R, i, l, m, rt << 1);
    }
    if (R > m) {
        update(L, R, i, m + 1, r, rt << 1);
    }
    pushUp(rt);
}

// 区间查询
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }

    int m = (l + r) >> 1;
    pushDown(rt, m - l + 1, r - m);

    int ans = 0;
    if (L <= m) {
        ans += query(L, R, l, m, rt >> 1);
    }
    if (R > m) {
        ans += query(L, R, m + 1, r, rt >> 1);
    }
    return ans;
}

int main() {
    // 等价于 6*(2^3) +1
    // cout << (6 << 3 | 1) << endl;

    cout << "start" << "\n";

    int n = 13, L = 2, R = 9, i = 6;

    build(1, n, 1);

    update(L, i, 1, n, 1);

    update(L, R, i, 1, n, 1);

    int ans = query(L, R, 1, n, 1);

    cout << ans << "\n";
}