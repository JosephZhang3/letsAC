#include <stdio.h>
#include <stdlib.h>
// #include <sstream>
#include "iostream"
#include <vector>
using namespace std;

int main(){
    cout << "cout here" << endl;

    // use auto iterator to access elements in array looply
    vector<int> iv;
    iv.push_back(3);
    iv.push_back(1);
    iv.push_back(2);
    for(auto item : iv){
        cout << item << endl;
    }

    // system("pause");// 暂停main函数，使控制台不退出
    return 0;
}