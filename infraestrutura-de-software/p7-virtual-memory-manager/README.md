# Implementação intitulada por "Designing a Virtual Memory Manager" e descrita na página P-51 de 1Silberschatz A, Galvin PB, Gagne G. Operating System Concepts. 10th ed.; 2018.
## Instruções
O único arquivo a ser submetido no classroom deve se nomeado de acordo com o seguinte padrão:
```
vm_login.c
```
Em que o login deve ser substituído pelas iniciais, em minúsculo, da pessoa que está submetendo o arquivo. Exemplo: caso Erico Souza Teixeira, de login est, submeta o arquivo, o mesmo deve ser nomeado como a seguir:
```
vm_est.c
```
Não submeta ao arquivo compactado. Qualquer arquivo fora desse padrão será descartado.

Não é preciso a implementação da TLB

A memória física deverá ser simulada com 128 frames (ver item "Page Replacement") e o algoritmo a ser implementado é o LRU

A implementação deve compilar nos sistemas operacionais Linux e/ou Mac OS X. Caso a compilação não seja possível, ou seja, erro durante a compilação, o arquivo será descartado;

Implementações submetidas além do horário limite estabelecido serão descartadas;

Arquivos que apresentarem cópias, seja de soluções encontradas na internet ou entre estudantes, serão descartados;

## Avaliação:
- Address Translation - 15%
- Page Table - 20%
- Physical Memory - 15%
- LRU - 20%
- Statistics - 15%
- Output - 15%

E aqueles códigos que:
- seguirem o padrão de codificação do kernel do Linux;
- não apresentem vazamento de memória e prints usados no debug

terão um acréscimo de 20% da nota