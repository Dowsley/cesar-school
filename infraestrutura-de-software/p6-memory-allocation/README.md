# Implementação intitulada por "Contiguous Memory Allocation" e descrita na página P-48 de 1Silberschatz A, Galvin PB, Gagne G. Operating System Concepts. 10th ed.; 2018.
## Instruções
Um adendo ao exercício: quando a requisição não puder ser realizada, a seguinte mensagem deve ser apresentada:
```
The request of <process> fail
```
Em que <process> será o processo referenciado com comando RQ

Algo semelhando quando tenta-se liberar o espaço de memória para um processo inexistente:
```
Fail to release <process>
```
Em que <process> será o processo referenciado com comando RL

O único arquivo a ser submetido no classroom deve se nomeado de acordo com o seguinte padrão:
```
memory_login.c
```
Em que o login deve ser substituído pelas iniciais, em minúsculo, da pessoa que está submetendo o arquivo. Exemplo: caso Erico Souza Teixeira, de login est, submeta o arquivo, o mesmo deve ser nomeado como a seguir:
```
memory_est.c
```

Não submeta ao arquivo compactado. Qualquer arquivo fora desse padrão será descartado.

A implementação deve compilar nos sistemas operacionais Linux e/ou Mac OS X. Caso a compilação não seja possível, ou seja, erro durante a compilação, o arquivo será descartado;

Implementações submetidas além do horário limite estabelecido serão descartadas;

Arquivos que apresentarem cópias, seja de soluções encontradas na internet ou entre estudantes, serão descartados;

## Avaliação:
- Requisição com First Fit - 20%
- Requisição com Best Fit - 20%
- Requisição com Worst Fit - 20%
- Compactação - 15%
- Release - 15%
- Status - 10%

E aqueles códigos que:
- seguirem o padrão de codificação do kernel do Linux;
- não apresentem vazamento de memória e prints usados no debug

terão um acréscimo de 20% da nota