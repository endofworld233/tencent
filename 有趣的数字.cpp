// 小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？

// 输入描述:
//  输入包含多组测试数据。
//  对于每组测试数据：
//  N - 本组测试数据有n个数
//  a1,a2...an - 需要计算的数据
//  保证:
//  1<=N<=100000,0<=ai<=INT_MAX.  
// 输出描述:
// 对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。

#include <iostream>
#include <climits>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    while (cin >> N) {
        map<int, int> datas;
        if (N == 1) {
            cout << 0 << " "<< 0 << endl;
            continue;
        }
        if (N > 100000) {
            continue;
        }
        int minPairs, maxPairs, temp;
        int minValue = INT_MAX;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            datas[temp] ++;  //会自动排序
        }
 
        //计算最大值
        if (datas.begin()->first == datas.rbegin()->first) {
            //所有元素都相等
            maxPairs = N*(N - 1) / 2;
            minPairs = maxPairs;
            cout << minPairs << " " << maxPairs << endl;
            continue; //跳出循环
        }
        else {
            maxPairs = (datas.begin()->second)*(datas.rbegin()->second);
        }
 
        //计算最小值
        minPairs = 0;
        if (datas.size() < N) {
            //有重复元素，最小值为0
            for (map<int, int>::iterator it = datas.begin(); it != datas.end(); it++) {
                if ((it->second) > 1) {
                    minPairs += (it->second)*((it->second) - 1) / 2; //排列计算公式 C(n)(2)=(n)*(n-1)/2
                }
            }
        }
        else {
            //没有重复元素
            map<int, int>::iterator it = datas.begin();
            int preValue = it->first;
            for (it++; it != datas.end(); it++) {
                if (minValue > (it->first - preValue)) {
                    minValue = it->first - preValue;
                    minPairs = 1;
                }
                else if (minValue == (it->first - preValue)) {
                    minPairs++;
                }
                preValue = it->first;
            }
        }
        cout << minPairs << " "<<maxPairs<<endl;
 
    }
    return 0;
}