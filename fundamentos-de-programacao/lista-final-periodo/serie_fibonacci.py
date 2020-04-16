def serie_fibonacci(n):
	l = [0, 1]
	if n >= 2 and type(n) == int:
		for i in range(0, n-2):
			l.append(l[i]+l[i+1])
		print(l)

	else:
		print ('Erro.')

serie_fibonacci(int(input('Digite: ')))