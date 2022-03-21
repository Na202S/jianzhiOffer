class Solution {
   public:
    string replaceSpace(string s) {
        int length = s.size();
        // 从前向后遍历
        for (int i = 0; i < length; i++) {
            // 每遇到1个空格
            if (s[i] == ' ') {
                // 则在原字符串结尾添加2个空格作为额外空间
                s += "  ";
            }
        }
        // 双指针，从后向前遍历
        // i 指向原字符串，j 指向新字符串
        int j = s.size() - 1;
        for (int i = length - 1; i >= 0; i--) {
            // 遇到空格，则替换
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                // 否则直接复制
                s[j--] = s[i];
            }
        }
        return s;
    }
};