v=float(input("Digite o valor da casa a comprar: "))
s=float(input("Digite o seu salário: "))
t=float(input("Digite a quantidade de ANOS a pagar: "))

t=t*12
pm=v/t

if pm<=(0.3*s):
    print("Emprestimo aprovado")
else:
    print("Emprestimo reprovado, pois a prestação mensal ultrapassa 30% do seu salário.")
