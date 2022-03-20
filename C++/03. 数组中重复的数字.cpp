class Solution {
   public:
    int findRepeatNumber(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            // 重复这个过程直到下标为 i 的位置上放的是数字 i
            while (nums[i] != i) {
                int x = nums[i];
                // 如果下标为 x 的位置上也是 x，则找到了重复的数字
                if (nums[x] == x) {
                    return x;
                }
                // 否则，将数字 x 放到下标为 x 的位置上
                swap(nums[i], nums[x]);
            }
        }
        return -1;
    }
};