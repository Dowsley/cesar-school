# Exercicios com MIPS assembly. 

## Instruções de Entrega

- O exercicios devem ser implementadas usando o emulador MARS. Cada exercício deverá ser salvo em um arquivo a parte com terminação ASM. Os nomes dos arquivos devem ser o seu primeiro nome seguido do último nome sem espaços seguido do número da questão separados por um ‘-’ (ex: JoaoLopes-1.asm, CarlosAlves-2.asm, etc). **Arquivos com nomes em formatos diferentes destes serão ignorados.**

- Entrega: até às 23:55h do dia 08/04/2020 (não serão aceitas listas entregues após este horário).
Os arquivos devem ser entregues pelo classroom.

- Cada aluno deve resolver a sua lista de forma individual. 

- CUIDADO COM CÓPIAS! Cópias não serão toleradas! Caso seja detectado que duas questões são idênticas, ambas serão anuladas não importando quem copiou de quem. 

- A lista vale 10 pontos e tem peso 35% na nota da primeira unidade. 

## Exercícios

**[EXERCICIO 1 ] (X)** Implemente um programa que realiza a soma de todos os elementos de um array. 

- O vetor deve ser inicializado com os valores: 0x10, 0x67, 0x90, 0x56, 0x45, 0x12, 0x99

- Implemente um loop que itera sobre todos os elementos do array somando os seus valores. 

- Ao final do programa, o resultado, ou seja, a soma, deve ser armazenado no registrador $v0.
	
**[EXERCICIO 2] (X)** Implemente um programa que converte todos os caracteres de uma string de minúsculo para maiúsculo. Os caracteres que já forem maiúsculos deverão permanecer inalterados.

- Para este exercício, declare uma variável que deverá ser inicializada com uma string que deverá conter tanto caracteres maiúsculos quanto minúsculos (você pode escolher a string a sua preferência). Uma segunda variável deverá ser usada para armazenar a string convertida. 

- Calcule também o tamanho da string em bytes. Ao final do programa armazene este tamanho no registrador $v1. 
	
**[EXERCICIO 3] (X)** Escreva um programa que calcula a soma todos os números inteiros entre 10 e 40 (inclusive). Ao final do programa armazene o resultado no registrador $v1.
