#Questao 3
a=int(input("Digite a altura em CENTIMETROS: "))
p=int(input("Digite o peso em KG: "))
a=a/100
imc=p/(a**2)
if imc>25:
    print("Está acima do peso")
else:
    print("Não está acima do peso")
    
