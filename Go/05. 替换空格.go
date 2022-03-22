func replaceSpace(s string) string {
	// Go中字符串为不可变类型
	// 因此不存在空间复杂度 O(1) 的解法
	return strings.Replace(s, " ", "%20", -1)
}