#Questao 4
#Input: Dist (km) percorrida, dias de aluguel.
#Output: Preço a pagar --> Carro custa R$ 60/dia e R$ 0,15/km rodado.
d = int(input("Digite a quantidade de km percorridos pelo carro alugado: "))
t = int(input("Digite a quantidade de dias pelos quais o carro foi alugado: "))
pd = 0.15*d
pt = 60*t
p_final = pt+pd
print("O preço a pagar pelo aluguel é de R$ {}".format(p_final))
