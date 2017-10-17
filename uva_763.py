fib = [0 for x in range(111)]
fib[1] = 1
fib[2] = 2
for i in range(3, 111):
	fib[i] = fib[i-1] + fib[i-2];


case = 1
while True:
	try:
		A = input()
		B = input()
		if case != 1:
				print("")
		case += 1				
	except:
		break
	la = len(A)
	lb = len(B)
	total = 0
	for i in range(la):
		if A[i] == '1':
			total += fib[la-i]
	for i in range(lb):
		if B[i] ==  '1':
			total += fib[lb-i]
	if total == 0:
		print('0')
	else:
		ans = ['0' for x in range(111)]	
		for i in range(110, 0, -1):
			if fib[i] <= total:
				total -= fib[i]
				ans[i] = '1'
			
		k = 110
		while ans[k] == '0': k -= 1
		while k > 0: 
			print(ans[k],end='')
			k -= 1
		print("")			
	try:
		input()
	except:
		break
	
