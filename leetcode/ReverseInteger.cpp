//
// Created by mac on 2020/6/28.
//
/**
 * 反转32位有符号整数，注意负数以及溢出
 */
#include "iostream"
#include <cmath>

using namespace std;

/**
 * 比较low的实现，把整数转换成字符串，然后对字符串逐位操作
 * 因为溢出问题runtime error了好几次，另外空间复杂度不行
 */
int reverse(int x) {
    string str = to_string(x);
    if (x < 0) {
        str = str.substr(1, str.length());
    }
    int rv = 0, tmp, sum;
    int digit = str.length();

    for (int i = digit - 1; i >= 0; --i) {
        tmp = rv;
        if (pow(10, i) * (str[i] - '0') > INT_MAX) {
            return 0;
        }

        sum = pow(10, i) * (str[i] - '0');
        if (sum > INT_MAX - tmp) {
            return 0;
        }

        rv = sum + tmp;
    }
    if (x >= 0) {
        return rv;
    } else {
        return -1 * rv;
    }
}

int main() {
    // 测试用例
    cout << reverse(123) << endl;
    cout << reverse(-123) << endl;
    cout << reverse(120) << endl;

    cout << reverse(1534236470) << endl;

    cout << reverse(12345678) << endl;
    cout << reverse(-12345678) << endl;
    cout << reverse(1015555555) << endl;
    cout << reverse(-1015555555) << endl;
    cout << reverse(pow(2, 31) - 1) << endl;
    cout << reverse(-1 * pow(2, 31)) << endl;
}