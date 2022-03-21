class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        # 记 C[i] = A[0]×A[1]×…×A[i-1]
        # 记 D[i] = A[i+1]×…×A[n-1]
        # 则 B[i] = C[i]*D[i]
        # 先计算A[i]左边的元素乘积，再计算右边的乘积
        if not a:
            return []
        n = len(a)
        B = [1]*n
        # 先计算C[i]，C[i+1] = C[i]*A[i]
        # C是从C[1]开始，因为C[0]==1
        C = a[0]
        for i in range(1, n):
            B[i] = C
            C *= a[i]
        # 再计算D[i]，D[i-1] = D[i]*A[i]
        # D是从D[n-2]开始，因为D[n-1]==1
        D = a[n-1]
        for i in range(n-2, -1, -1):
            B[i] *= D
            D *= a[i]
        return B
