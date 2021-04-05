# Avaliacao 1

Esta avaliação é composta de cinco exercícios que estão disponíveis nas pastas ex1, ex2, ex3, ex4 e ex5 deste zip.

## Exercício 1

O objetivo do exercício um é implementar as classes faltantes para que seja possível calcular os números primos menores ou iguais a 1000. Existe um método rudimentar e ineficiente que pode ser usado para verificar se um dado número é primo.
O processamento *deve* ser distribuído de forma igual entre quatro threads. Ao final, os números primos identificados 
devem ser atribuídos à variável primos declarada no método main da classe school.cesar.primos.Main 

## Exercício 2

No exercício dois, quatro threads compartilham um objeto Printer que imprime uma simples sequência de -| no console,
entretanto como as threads estão compartilhando esse objeto sem nenhum controle de concorrência, algumas vezes a saída
no terminal é intercalada, resultando em sequências de -- ou de ||. Faça as modificações necessárias para que a saída
seja sempre -|-|-| independente de termos 4 threads executando em paralelo.

## Exercício 3

O exercício três é uma questão discursiva a respeito da infraestrutura disponível na linguagem Java para exclusão mútua e comunicação entre Threads.

## Exercício 4

O exercício quatro apresenta um código em Java que simula o comportamento de uma tarefa assíncrona executada em uma Thread, a Thread principal faz uso da estratégia de Busy-Wait para detectar a conclusão da tarefa assíncrona. Analise o código e responda no arquivo CONSIDERACOES.md quais as implicações de se usar essa estratégias e quais alternativas existem.

## Exercício 5

No diretório ex5 há uma cópia do código disponível no exercício quatro, o objetivo do exercício cinco e implementar a mesma tarefa assíncrona sem utilizar Busy-Wait, fazendo com que a Thread principal suspenda a execução enquanto a tarefa assíncrona não é concluída e sendo posteriormente notificada de sua conclusão.

