import math

def gcd (a, b):
	while a and b:
		if a > b: a %= b
		else: b %= a
	return a+b

def lcm (a, b):
	return a*b/gcd(a,b)

while 1:
	n = int(input())
	if n == 0: break
	
	divisors = [1, n]
	m = int(math.sqrt(n))
	# get divisors of n
	for i in range(2, m+1):
		if n%i == 0:
			divisors.append(i)
			if i != n//i: 
				divisors.append(n//i)
		
		
	# (n, n) is a corner case	
	ans = 1		
	for a in divisors:
		for b in divisors:
			if a > b and n == lcm(a,b):
				ans += 1
	
	print(n, ans)
