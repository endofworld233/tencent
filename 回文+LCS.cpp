
// 给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
// 输出需要删除的字符个数。

// 输入描述:
// 输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
// 输出描述:
// 对于每组数据，输出一个整数，代表最少需要删除的字符个数。

//思路：回文序列即就是本字符串和其逆置字符串相等，为了保证得到的回文串最长，其实就是求该字符串和逆置字符串的LCS，减去这个LCS的长度得到的就是删除字符的个数。LCS用动态规划做
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int MAX = 1001;
int MaxLen[MAX][MAX]; //最长公共子序列，动态规划求法
int maxLen(string s1, string s2){
    int length1 = s1.size();
    int length2 = s2.size();
    for (int i = 0; i < length1; ++i)
        MaxLen[i][0] = 0;
    for (int i = 0; i < length2; ++i)
        MaxLen[0][i] = 0;
     
    for (int i = 1; i <= length1; ++i)
    {
        for (int j = 1; j <= length2; ++j)
        {
            if (s1[i-1] == s2[j-1]){
                MaxLen[i][j] = MaxLen[i-1][j - 1] + 1;
            }
            else
            {
                MaxLen[i][j] = max(MaxLen[i - 1][j], MaxLen[i][j - 1]);
            }
        }
    }
 
    return MaxLen[length1][length2];
}
 
int main(){
    string s;
    while (cin >> s){
        int length = s.size();
        if (length == 1){
            cout << 1 << endl;
            continue;
        }
        //利用回文串的特点
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int max_length = maxLen(s, s2);
        cout << length - max_length << endl;
    }
    return 0;
}