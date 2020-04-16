#Questao 1
#Aceita com lista pf, com condicional fica desnecessariamente complicado
a=int(input("Digite um inteiro: "))
b=int(input("Mais outro: "))
c=int(input("Mais outro: "))
d=int(input("Mais outro: "))
e=int(input("Mais outro: "))
myList=[a,b,c,d,e]
myList.sort()
print("O maior valor é:", myList[4])
print("O menor número é:", myList[0])
