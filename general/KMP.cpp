#include"iostream"
#include<vector>
#include"string"

using namespace std;

/**
 * 无回溯模式匹配算法
 */

/**
 * 求最长公共前后缀长度
 * @param str
 * @return
 */
vector<int> getNext(string str) {
    int len = str.length();
    // 保存结果的容器，默认容器每个元素的
    vector<int> next(len, 0);
    for (int i = 1; i < len; i++) {
        // k 表示需要比较的位置，初始值为 next[i - 1] 即 next[0] next[1] next[2] ...
        int k = next[i - 1];
        while (k > 0 && str[i] != str[k]) {
            k = next[k - 1];
        }
        if (str[i] == str[k])
            k++;
        next[i] = k;
    }
    return next;
}

int KMP(string s, string p) {
    if (s.length() == 0 || p.length() == 0) return -1;

    vector<int> next = getNext(p);
    int k = 0;
    int res = -1;
    for (int i = 0; i < (int) s.length(); i++) {
        while (k > 0 && s[i] != p[k])
            k = next[k - 1];
        if (s[i] == p[k])
            k++;
        if (k == (int) p.length()) { // 模式串与主串完全匹配
            res = i - k + 1;
            break;
            // 如果需要进行下一轮匹配（找模式串最后一次出现的位置），则用下行换掉break
            // k = next[k-1];
        }
    }
    return res;
}

int main() {
    // test derive the next array
//    vector<int> ne = getNext("abaabca");
//    for (int i = 0; i < ne.size(); ++i) {
//        cout << ne[i] << "  ";
//    }
//    cout << endl;

//    cout << KMP("laflabcabdabcabcd", "xxxxxxx") << endl;
//    cout << KMP("laflabcabdabcabcd", "") << endl;
    cout << KMP("laflabcbbdabcabcd", "abca") << endl;
}
