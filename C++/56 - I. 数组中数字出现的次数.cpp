class Solution {
   public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 异或运算性质: 交换律;结合律;归零律;恒等律;自反性
        // 假设所求数字为 m 和 n
        // 利用归零律(x^x=0)和恒等律(x^0=x)
        // 所有数字异或, 得到 mXORn = m^n
        int m = 0, n = 0, mXORn = 0;
        for (int num : nums) {
            mXORn ^= num;
        }
        // x & (-x)求得最低位的"1", 即 m 异于 n 的最低位
        int div = mXORn & (-mXORn);
        for (int num : nums) {
            // 将所有在该位上为1的 num 异或, 即可得到 m
            if (num & div) {
                m ^= num;
            }
        }
        // 利用自反性(x^y^y=x^(y^y)=x^0=x), 即可得到n
        n = mXORn ^ m;
        return vector<int>{m, n};
    }
};