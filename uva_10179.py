import math

m = int(math.sqrt(10**9))
isPrime = [True]*m
primes = []

for i in range(2, m):
	if isPrime[i]:
		primes.append(i);
		for j in range(i*i, m, i):
			isPrime[j] = False


while True:
	n = int(input())
	if n == 0: break
	phi = float(n)
	for p in primes:
		if n%p == 0:
			phi *= (1 - 1/p)
			while n%p == 0: n //= p
		if p > n: break
		
	if n != 1: phi *= (1 - 1/n)
	print(int(phi))
