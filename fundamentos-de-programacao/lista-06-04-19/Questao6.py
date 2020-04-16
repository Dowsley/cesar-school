s=float(input("Digite o valor do salario: "))
d=0.11*s
if d>=318.20:
    print("O desconto é de R$ 318.20")
else:
    print("O desconto é de R$ {}".format(d))
        
