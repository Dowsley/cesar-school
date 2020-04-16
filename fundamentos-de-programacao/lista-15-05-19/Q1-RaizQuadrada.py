n = float(input("Digite o número: "))
b=2
dif=3.14
while dif >= 0.0001:
	p=(b+(n/b))/2
	print("p é",p)
	b=p
	pq = p*p
	dif=abs(n-pq)