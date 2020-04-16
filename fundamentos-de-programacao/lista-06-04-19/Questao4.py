#Questao 4
a=float(input("Digite o tamanho do primeiro lado: "))
b=float(input("Digite o tamanho do segundo lado: "))
c=float(input("Digite o tamanho do terceiro lado: "))

if (abs(b-c))<a<(b+c):
    if a==b==c:
        print("É um triângulo equilátero")
    elif a!=b!=c:
        print("É um triângulo escaleno.")
    else:
        print("É um triângulo isosceles.")
else:
    print("Não pode formar um triângulo")
