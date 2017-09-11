// 假定一种编码的编码范围是a ~ y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa, aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。 编写一个函数，输入是任意一个编码，输出这个编码对应的Index. 
// 输入描述:
// 输入一个待编码的字符串,字符串长度小于等于100.

// 输出描述:
// 输出这个编码的index

//example:输入baca，输出16331
//思路，由于只算25个字符，可以将这个问题当成进制转换问题，以25为一个进制。理解这个字典序的含义

#include <iostream>
#include <string.h>
using namespace std;
 
int main()
{
    int w[4] = {25*25*25+25*25+25+1,25*25+25+1,25 + 1, 1};  //辅助数组，表示当前位置底数代表的进制
    char code[5] = {0};
    int index = 0;
    cin >>code;
    int len = strlen(code);
    for(int i =0; i<len;i++){
        if (i == 0){
            index = index + (code[i]-'a')*w[i];
        }
        else{
        index = index +(code[i]-'a')*w[i]+1;
        }
    }
    cout<<index<<endl;
    return 0;
}
