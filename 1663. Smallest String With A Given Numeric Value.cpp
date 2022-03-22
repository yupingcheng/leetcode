#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::make_unique;
using std::max;
using std::string;

// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// 1663. Smallest String With A Given Numeric Value
class Solution {
   public:
    string getSmallestString(int n, int k) {
        // (n,k) with 1-indexed 視為 (n, k-n) with 0-indexed
        // 結果用regex表示應該長得像這樣 a*[a-y]?z*
        // 1.結尾盡可能放最多的z
        int zLength = max((k - n) / 25, 0);
        string end(zLength, 'z');
        // 2.如果z放完，長度不夠(或者說zLength*26<k)，在放一個a-y
        int midLength = zLength == n ? 0 : 1;
        string mid(midLength, 'a' + (k - n) % 25);
        // 3.左邊補滿a
        string front(n - midLength - zLength, 'a');
        return front + mid + end;
    }
};

int main(void) {
    auto test = make_unique<Solution>();
    auto ans = test->getSmallestString(3, 27);
    cout << ans << endl;
    return 0;
}