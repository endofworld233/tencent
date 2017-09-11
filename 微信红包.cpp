// 春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
// 给定一个红包的金额数组gifts及它的大小n，请返回所求红包的金额。
// 若没有金额超过总数的一半，返回0。
// 测试样例：
// [1,2,3,2,2],5
// 返回：2

//思路：维护一个统计价格出现次数的hash表，然后遍历该哈希表就行。
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
         map<int, int> valueMap;
        for(int i=0;i<gifts.size();i++){
            valueMap[gifts[i]]++;
        }
        for(auto ite=valueMap.begin();ite!=valueMap.end();ite++){
            if(ite->second > n/2){
				return ite->first;
            }
        }
        return 0;
    }
};