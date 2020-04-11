# Exercicios com MIPS assembly. 
## Instruções
- O exercicios devem ser implementadas usando o emulador MARS. 

- Cada exercício deverá ser salvo em um arquivo a parte com terminação ASM. Os nomes dos arquivos devem ser o seu primeiro nome seguido do último nome sem espaços seguido do número da questão separados por um ‘-’ (ex: JoaoLopes-1.asm, CarlosAlves-2.asm, etc). Arquivos com nomes em formatos diferentes destes serão ignorados. Não envie arquivos zipados. 

- Entrega: até às 23:55h do dia 13/04/2020 (não serão aceitas listas entregues após este horário).

- Os arquivos devem ser entregues pelo classroom.

- Cada aluno deve resolver a sua lista de forma individual. 

- CUIDADO COM CÓPIAS! Cópias não serão toleradas! Será usada uma ferramenta para detecção de cópias. Caso seja detectado que duas questões são idênticas, ambas serão anuladas não importando quem copiou de quem. 

- A lista vale 10 pontos e tem peso 35% na nota da primeira unidade. 

## Questões

**[EXERCICIO 1]** Implemente uma função que realiza um das quatro operações seguintes: Soma, Subtração, AND, OR. A função deverá receber três parâmetros:
	$a0 - operando 1
	$a1 - operando 2
	$a2 - um valor numérico que identifica a operação a ser executada: 
        1 - Soma, 2 - Subtração, 3 - AND, 4 - OR

- A função deve retornar o resultado da operação no registrador $v0.

- Implemente um programa principal que chama esta função quatro vezes: uma para cada operação. Ao final do programa, os resultados das quatro operações devem ser armazenados da seguinte forma: 
	$s0 - resultado da soma
	$s1 - resultado da subtração
	$s2 - resultado do AND
	$s3 - resultado do OR

- Escolha dois operandos (números) de sua preferência e use sempre os mesmos para todas as chamadas da função. Ao final do programa armazene os operandos que você escolheu nos registradores $s5 e $s6.

**[EXERCICIO 2]** Implementa a função que calcula o comprimento de uma string. A função deve receber um único parâmetro em $a0 e este parâmetro deve ser o endereço da string (ponteiro) na memória. 

- A string deve ser terminada com o terminado /0. 

- A função deve retornar o comprimento da string (desconsiderando o terminador) no registrador $v0.
Escreva uma função *main* que irá chamar a função. 

**[EXERCICIO 3]** A instrução **mul** multiplica dois números armazenados em registradores. Por exemplo, a instrução mul **t1, t2, t3**  irá multiplicar o conteúdo do registrador **t2** pelo conteúdo do registrador **t3**. Como a multiplicação de dois números de 32 bits pode gerar como resultado um número de 64 bits, o MIPS possui dois registradores especiais usados para armazenar o resultado da instrução de multiplicação. Estes registradores são o **hi** e o **lo** (escritos sem o ‘$’). O registrador **hi** irá armazenar os 32 bits mais significativos do resultado da multiplicação enquanto que o **lo** armazenará os 32 bits menos significativos. Adicionalmente, no exemplo **mul t1, t2, t3,** o **t1** irá receber os 32 bits menos significativos da multiplicação ou seja ficará igual ao registrador **lo**.

- O conteúdo dos registradores **hi** e **lo** só pode ser lido com instruções especiais. A instrução **mfhi** permite copiar o conteúdo do **hi** para qualquer registrador de uso geral (exemplo: mfhi $s0). Já a instrução **mflo** permite copiar o conteúdo do **lo** para qualquer registrador de uso geral (exemplo: mflo $t1)

- De posse destas informações escreva uma função que calcula o fatorial de um número. A função deve um único parâmetro no registrador $a0 (o número cujo fatorial se deseja). O resultado do cálculo deve ser retornado nos registradores $v1 (parte mais significativa) e $v0 (parte menos significativo). Utilize recursividade para implementar a função. 

- Uma função para cálculo de fatorial em C seria assim:

```
int fatorial( int num ) {
    if(num <= 1){
        return num;
    }else{
        return num * fatorial(num -1);
    }
}
```