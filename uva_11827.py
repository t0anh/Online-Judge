
def gcd (a, b):
	while a and b:
		if a > b: a %= b
		else: b %= a
	return a + b

cases = int(input())

for case in range(cases):
	a = [int(x) for x in input().split()]
	
	gcd_max = 0
	for i in range(len(a)):
		for j in range(len(a)):
			if i != j:
				gcd_max = max(gcd_max, gcd(a[i], a[j]))
	
	print(gcd_max)
	
