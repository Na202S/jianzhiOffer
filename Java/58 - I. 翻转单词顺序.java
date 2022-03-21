class Solution {
    public String replaceSpace(String s) {
        // Java中, 字符串为不可变类型
        // 所以不存在 O(1) 空间复杂度的解法
        // 给一个已有字符串"abcd"第二次赋值成"abcedl",
        // 不是在原内存地址上修改数据，而是重新指向一个新对象，新地址。
        return s.replace(" ", "%20");
    }
}