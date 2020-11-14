#include"iostream"
#include<vector>

using namespace std;

vector<int> getNext(const char *str){
    int len = strlen(str);               // 字符串长度
    vector<int> next(len, 0);            // 保存结果，next[0]=0
    for(int i = 1; i < len; i++)
    {
        int k = next[i - 1];             // k 表示需要比较的位置，初始值为 next[i - 1]
        while(k > 0 && str[i] != str[k]) // 比较，若不相等则继续分割，直到相等或k为0(即根本不含相同部分)
            k = next[k - 1];
        if(str[i] == str[k])             // 若相等，则 next[i] = k + 1，否则为0，其中 k 为索引
            k++;
        next[i] = k;                     // 更新 next[i]
    }
    return next;
}

// TODO 返回的是模式串最后一次出现的索引位置
int KMP(char s[],char p[]){
    if (strlen(s) == 0 || strlen(p) == 0) return -1;

    vector<int> next = getNext(p);
	int k = 0;
	int res = -1;
	for(int i =0; i < (int)strlen(s); i++){
	    while (k > 0 && s[i] != p[k])
		    k = next[k-1];
		if (s[i] == p[k]) 
			k++;
		if(k==(int)strlen(p)){ // 模式串与主串完全匹配
			res = i-k+1;
			break;
			// 如果需要进行下一轮匹配（找模式串最后一次出现的位置），则用下行换掉break
			//k = next[k-1];
		}
	}
	return res;
}

int main(){
    // test derive the next array
    vector<int> ne = getNext("abaabca");
    for (int i = 0; i < ne.size(); ++i)
    {
    	cout << ne[i] << "  ";
    }
    cout << endl;

    cout <<	KMP("laflabcabdabcabcd","xxxxxxx") << endl;
    cout << KMP("laflabcabdabcabcd","") << endl;
    cout <<	KMP("laflabcabdabcabcd","abca") << endl;
}
