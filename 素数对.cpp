// 给定一个正整数，编写程序计算有多少对质数的和等于输入的这个正整数，并输出结果。输入值小于1000。
// 如，输入为10, 程序应该输出结果为2。（共有两对质数的和为10,分别为(5,5),(3,7)） 
// 输入描述:
// 输入包括一个整数n,(3 ≤ n < 1000)

// 输出描述:
// 输出对数

// 示例1
// 输入
// 10
// 输出
// 2
#include <iostream>
#include <cmath>
using namespace std;
//判断是否是素数
bool isPrime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int i,n,cnt=0;
    cin>>n;
    for(i=2;i<=(n+1)/2;i++){
        if(isPrime(i)&&isPrime(n-i)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}