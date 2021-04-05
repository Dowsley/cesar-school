### Neste projeto, a classe Main utiliza de Busy-Wait para detectar a conclusão. Quais as implicações dessa implementação e quais as alternativas?
R: Busy-waiting é considerado um anti-padrão, pois gasta recursos (tempo) do processador computando uma tarefa inútil (verificando uma condição por tempo indefinido), que ele poderia estar usando para executar outras tarefas que produzem resultado. 

Uma alternativa melhor é usar o Wait-notify, que possui pouco overhead em comparação. Mas o jeito mais simples é usar `.join()`