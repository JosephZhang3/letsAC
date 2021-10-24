#include <sstream>
#include "iostream"
using namespace std;

/**
 * 三位数翻转
 * 思路：百位数字等于n模100，十位数字等于n除10再模10（除10去掉个位，模10得到十位），个位数字等于n模10
 * 最后3个数字倒序输出
 *
 * simple test case
 * 127
 * 100
 * 999
 */
int main(){
    int t;
    string str;
    getline(cin, str);
    stringstream ss(str);// 流式处理，以空格分隔字符串
    ss >> t;

    // integer formal
    int tar;
    tar = t / 100 + t / 10 % 10 * 10 + t % 10 * 100;
    cout << tar << endl;

    // string formal
    printf("%d%d%d", t%10, t/10%10, t/100);

    return 0;
}