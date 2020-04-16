segundosEntrada=int(input("Por favor, entre com o número de segundos que deseja converter: "))
dias=segundosEntrada//86400
segundosRestantesUm=segundosEntrada%86400
horas=segundosRestantesUm//3600
segundosRestantesDois=segundosRestantesUm%3600
minutos=segundosRestantesDois//60
segundosRestantesFinal=segundosRestantesDois%60
print(dias,"dias,",horas,"horas,",minutos,"minutos,",segundosRestantesFinal,"segundos.")



