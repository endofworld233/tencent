// 小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
// 你能帮帮小Q吗？

// 输入描述:
// 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
// 输出描述:
// 对于每组数据，输出移位后的字符串。

//思路：题目中说了不能申请额外空间。。。其实简单，直接遍历输出就行了，让小写字母先输出即可。。
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    string s;
    while(cin >> s){
        if(s.length() >= 1 && s.length() <= 1000){
            for(int i = 0; i < s.length(); i++)
                if(s[i] >= 'a' && s[i] <= 'z')
                    cout << s[i];
            for(int i = 0; i < s.length(); i++)
                if(s[i] <= 'Z' && s[i] >= 'A')
                    cout << s[i];
            cout << endl;
        }
    }
    return 0;
}