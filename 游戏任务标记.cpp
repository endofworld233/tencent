// 游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，这类任务一共有1024个，任务ID范围[1,1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；并检查第二个ID的任务是否已经完成。 输出一个参数，如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1,1024]范围，则输出-1。 
// 输入描述:
// 输入包括一行,两个整数表示人物ID.

// 输出描述:
// 输出是否完成
//范例：
// 输入 1024 1024
// 输出 1

//思路：没啥思路，直接撸。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int main() {
    using namespace std;
    unsigned int n, m;
    while (cin >> n >> m) {
        if (n < 1 || n > 1024 || m < 1 || m > 1024) {
            cout << -1 << endl;
        }
        else {
            if (n == m) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}