import math

def pow (a, n):
	ret = 1
	while n:
		if n&1:
			ret *= a
		a *= a
		n >>= 1
	return ret

#get prime numbers less than 32768
M = 32768
isPrime = [1]*M
for i in range(2, int(math.sqrt(M))):
	if isPrime[i]:
		for j in range(i*i, M, i):
			isPrime[j] = 0

primes = []
for x in range(2, M):
	if isPrime[x]:
		primes.append(x)
#process cases
while 1:
	a = [int(x) for x in input().split()]
	if len(a) == 1 :
		break
	
	n = 1
	for i in range(0,len(a)-1, 2):
		n *= pow(a[i], a[i+1])
		
	n -= 1
	ans = []
	for prime in primes:
		if prime > n: break
		if n%prime == 0:
			cnt = 0
			while n%prime == 0:
				n //= prime
				cnt += 1
			ans.append([prime, cnt])
		if n == 1: break
		
	ans.sort(reverse=True)
	print("{} {}".format(ans[0][0], ans[0][1]), end='')
	for i in range(1, len(ans)):
		print(" {} {}".format(ans[i][0], ans[i][1]), end='')
	print()
	
	
	
	
	
	
	
	
	
	
					
