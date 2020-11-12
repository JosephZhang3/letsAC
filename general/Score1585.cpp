//
// Created by zhangjianghao on 6/27/2020.
//
/**
 * OJ水题
 * 思路：遇到X直接忽略，设定一个变量保存字母O连续的次数，遇到X时此变量置零；设定一个变量保存累加结果；遇到换行符终止循环执行下一个test case
 */
#include "iostream"
#include "string"
using namespace std;

int main(){
    string str;
    getline(cin, str);
    int caseNum = stoi(str);

    for (int j = 0; j < caseNum; ++j) {
        getline(cin, str);
        int sum = 0;
        int consecutiveCount = 0;

        for (char i : str) {
            if (i == 'X'){
                consecutiveCount = 0;
                continue;
            } else if (i == 'O'){
                consecutiveCount++;
                sum += consecutiveCount;
            } else {

            }
        }

        cout << sum << endl;
    }

    return 0;
}