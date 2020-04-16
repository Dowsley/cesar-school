n=int(input("Digite um número inteiro: "))
m=n%3
l=n%5
if m==0 and l==0:
    print("FizzBuzz")
else:
    print(n)
