a=int(input("Digite um ano: "))

if a%400==00 or a%4==0 and a%100!=0:
    print("É um ano bissexto")
else:
    print("Não é um ano bissexto")
