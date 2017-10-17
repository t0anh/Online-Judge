def matrix_multiply (A, B, m):
	a00 = A[0][0]*B[0][0] + A[0][1]*B[1][0]
	a01 = A[0][0]*B[0][1] + A[0][1]*B[1][1]
	a10 = A[1][0]*B[0][0] + A[1][1]*B[1][0]
	a11 = A[1][0]*B[0][1] + A[1][1]*B[1][1]
	return [[a00%m, a01%m],[a10%m, a11%m]]
	
def matrix_power (M, n, mod):
	ret = M
	while n > 0:
		if n%2 == 1: ret = matrix_multiply(ret, M, mod)
		M = matrix_multiply(M, M, mod)
		n //= 2
	return ret

BASE = [[1, 1], [1, 0]]
mod = [0, 10, 100, 1000, 10000]

cases = int(input())
for _ in range(0, cases):
	a, b, n, m = map(int, input().split())
	M = matrix_power(BASE, n-1, mod[m])
	# answer = fib(n-1)*a + fib(n)*b
	print((M[1][1]*a + M[1][0]*b) % mod[m])

	
