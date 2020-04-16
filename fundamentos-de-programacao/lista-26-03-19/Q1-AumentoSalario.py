#Questao 1
#Input: Valor do salário e a porcentagem de aumento do mesmo.
#Output: Valor do aumento e do novo salário
salario_inicial = float(input("Digite o valor do seu salário atual: "))
porc_aumento = float(input("Digite a porcentagem do seu aumento: "))
porc_aumento = porc_aumento/100
valor_aumento = porc_aumento*salario_inicial
salario_final = salario_inicial + valor_aumento
print("Após um aumento de R$"+str(valor_aumento)+", seu novo salário será R$",salario_final)
