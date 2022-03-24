// https://leetcode.com/problems/broken-calculator/
// 991. Broken Calculator

// 想不出來，直接抄答案
// 雖然能理解discuss中提供的解法(參考brokenCalc_discuss)，但都少了證明這是最佳解
// 證明
// https://leetcode.com/problems/broken-calculator/discuss/236565/Detailed-Proof-Of-Correctness-Greedy-Algorithm/687663
// 1.如果y是奇數，y的前一步必是y+1
// 2.如果y是偶數 (請參考huangdachuan的評論)
//   2-1 jump_max的值不重要，只是過程需要
//   2-2 從(m=k)到(2m)的兩種方法，證明了最後一步要是乘法
class Solution {
   public:
    int brokenCalc_proof(int x, int y) {
        int count = 0;
        while (y != x) {
            if (x >= y)
                return ((x - y) + count);

            /* If y is even, the last move was multiplication, else decrement */
            if (y % 2 == 0)
                y = y / 2;
            else
                y++;

            // One operation used
            count++;
        }
        return count;
    }

    int brokenCalc_discuss(int startValue, int target) {
        if (startValue > target) {
            return startValue - target;
        }
        if (startValue == target) {
            return 0;
        }
        if (startValue < target) {
            int count = 0;
            while (startValue < target) {
                if (target % 2 == 1) {
                    ++target;
                } else {
                    target >>= 1;
                }
                ++count;
            }
            return count + brokenCalc(startValue, target);
        }
        return -1;
    }
};
