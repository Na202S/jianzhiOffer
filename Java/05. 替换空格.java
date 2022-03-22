class Solution {
    public String replaceSpace(String s) {
        // Java中字符串为不可变类型
        // 因此不存在空间复杂度 O(1) 的解法
        return s.replace(" ", "%20");
    }
}