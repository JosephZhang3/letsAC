#include"iostream"

using namespace std;
int next[100];

void getNext(int a[]){
     
}

int KMP(int start,char s[],char t[]){
	int i=start,j=0;
	while(s[i] != '\0' && t[j] != '\0'){
        if(j==-1 || s[i] == t[j]){
            i++;
			j++;
		}
		else j=next[j];
	}
	if(t[j] == '\0') return i-j;
	else return -1;
}

int main(){
    cout << "ad";
}
