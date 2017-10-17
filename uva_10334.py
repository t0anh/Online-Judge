fib = [1 for x in range(1001)]

fib[1] = 2
fib[2] = 3
for i in range(3, 1001):
	fib[i] = fib[i-1] + fib[i-2]

while True:
	try:
		n = int(input())
	except:
		break
	print(fib[n])
