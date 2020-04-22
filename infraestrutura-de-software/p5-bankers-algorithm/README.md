# Algumas modificações do exercício com relação ao Banker’s Algorithm apresentado na página P-45 do livro Operating System Concepts, Silberschatz, A. et al, décima edição.

O NUMBER_OF_CUSTOMERS e o NUMBER_OF_RESOURCES não são fixos, e
serão determinados de acordo com a entrada do programa, a ser melhor descrita a
seguir.

Cada argumento na chamada do programa representa a quantidade de recursos para
cada tipo. Considerando que o arquivo resultante da compilação seja denominado por
banker, o exemplo a seguir apresenta 3 tipos diferentes de recursos e com quantidades
de 10 5 7 respectivamente

```
./banker 10 5 7
```

O arquivo contendo os clientes será denominado por customer.txt, com mesmo
formato daquele apresentado no livro. Contudo há uma pequena diferença: o número
de linhas irá indicar a quantidade de clientes. O exemplo a seguir temos 5 clientes.

```
7,5,3
3,2,2
9,0,2
2,2,2
4,3,3
```

No lugar do programa permitir comandos do usuário, um outro arquivo deve ser lido,
commands.txt, que conterá uma sequência de comandos RQ, RL e *, com a mesma
formatação daquela apresentada no livro. A seguir, um exemplo do arquivo:

```
RQ 0 0 2 1
RQ 2 3 0 2
RQ 1 2 0 0
RQ 4 0 0 2
RL 0 0 1 1
RQ 3 2 1 1
*
RQ 4 4 0 0
RQ 1 1 0 2
RQ 0 0 2 0
RQ 2 0 1 0
```

Como saída, o programa deverá produzir o arquivo result.txt. Para as entradas acima
apresentadas, seguem as informações da saída:

```
Allocate to customer 0 the resources 0 2 1
Allocate to customer 2 the resources 3 0 2
Allocate to customer 1 the resources 2 0 0
Allocate to customer 4 the resources 0 0 2
Release from customer 0 the resources 0 1 1
Allocate to customer 3 the resources 2 1 1
MAXIMUM | ALLOCATION | NEED
7 5 3 | 0 1 0 | 7 4 3
3 2 2 | 2 0 0 | 1 2 2
9 0 2 | 3 0 2 | 6 0 0
2 3 3 | 2 1 1 | 0 1 1
4 3 3 | 0 0 2 | 4 3 1
AVAILABLE 3 3 2
The resources 3 2 2 are not enough to customer 4 request 4 0 0
Allocate to customer 1 the resources 1 0 2
The customer 0 request 0 2 0 was denied because result in an unsafe state
The customer 2 request 1 1 0 was denied because exceed its maximum allocation
```

# Outras observações:
O único arquivo a ser submetido no classroom deve se nomeado de acordo com o
seguinte padrão:
``` 
banker_login.c
```
Em que o login deve ser substituído pelas iniciais, em minúsculo, da pessoa que está
submetendo o arquivo. Exemplo: caso Erico Souza Teixeira, de login est, submeta o
arquivo, o mesmo deve ser nomeado como a seguir:
banker_est.c

Não submeta ao arquivo compactado. Qualquer arquivo fora desse padrão será
descartado.

A implementação deve compilar nos sistemas operacionais Linux e/ou Mac OS X.
Caso a compilação não seja possível, ou seja, erro durante a compilação, o arquivo
será descartado;

Implementações submetidas além do horário limite estabelecido serão descartadas;

Arquivos que apresentarem cópias, seja de soluções encontradas na internet ou entre
estudantes, serão descartados;

Avaliação:
- Algoritmo de Banker - 60%
- Coerência e concordância das mensagens - 30%
- Qualidade do código e comentários - 10%

Esse último item diz respeito a seguir o padrão de codificação do kernel do Linux, não
existência do vazamento de memória, inserção de comentários que facilitem o
entendimento do código e remoção de eventuais prints usados no debug.