#Questao 5
#Input: Quant de cigarros/dia, por quantos anos fumou. --> -10 mins de vida/cigarro
#Output: Tempo de vida perdido (em dias).
freq=int(input("Digite a quantidade média de cigarros fumados por dia: "))
t_fumo=int(input("Agora digite há quantos anos tal indivíduo fuma: "))
#Anos fumando X 365 X frequência para achar total de cigarros. 10 minutos X total de cigarros/1440 minutos para achar tempo perdido em dias.
t_perdido = (freq*365*t_fumo*10)/1440
print("O tempo de vida perdido dessa pessoa é de {} dias.".format(t_perdido))
