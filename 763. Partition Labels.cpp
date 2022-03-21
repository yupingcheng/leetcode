#include <algorithm>
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::make_unique;
using std::max;
using std::string;
using std::vector;

// https://leetcode.com/problems/partition-labels/
// 763. Partition Labels
class Solution {
   public:
    vector<int> partitionLabels(string s) {
        // 用來記錄substring的長度
        vector<int> result{};
        // 'a'~'z'最後一次出現的index
        auto lastIndex = make_unique<int[]>(26);

        // 把'a'~'z'最後一次出現的index紀錄到lastIndex[0]~[25]
        for (int pos{0}; pos < s.length(); ++pos) {
            lastIndex[s[pos] - 'a'] = pos;
        }

        // pos表示input的index，start、last表示目前substring的頭、預期最尾端
        // 隨著pos向後，last繼續向後調整
        // pos從0開始追last，如果追到last，表示0~last為一組substring
        // 下一組substring從pos+1開始
        for (int start{0}, last{0}, pos{0}; pos < s.length(); ++pos) {
            last = max(lastIndex[s[pos] - 'a'], last);
            if (pos == last) {
                // cout << "start = " << start << ", last = " << last
                //      << ", substr = " << s.substr(start, last - start + 1) << endl;
                result.push_back(last - start + 1);
                start = pos + 1;
            }
        }
        return result;
    }
};

int main(void) {
    auto test = make_unique<Solution>();
    string testStr{"eccbbbbdec"};
    auto ans = test->partitionLabels(testStr);
    for (auto num : ans) {
        cout << num << " ";
    }
    return 0;
}