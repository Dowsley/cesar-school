# Operating System Concepts - Chapter 7: Project 2

O exercício corresponde ao Project 2 - The Sleeping Teaching Assistant, página P-38 do livro Operating System Concepts de Silberschatz da décima edição

Instruções:
O único arquivo a ser submetido no classroom deve se nomeado de acordo com o seguinte padrão:

sta_login.c

Em que o login deve ser substituído pelas iniciais, em minúsculo, da pessoa que está submetendo o arquivo. Exemplo: caso Erico Souza Teixeira, de login est, submeta o arquivo, o mesmo deve ser nomeado como a seguir:

sta_est.c

Não submeta ao arquivo compactado. Qualquer arquivo fora desse padrão será descartado.

Para execução, deve ser fornecido, como argumento por linha de comando, o número de estudantes. O exemplo abaixo mostra como seria a execução do arquivo sta_est considerando 5 (cinco) estudantes.

> ./sta_est 5

Ao longo da execução, todos estudantes serão atendidos pelo TA uma única vez, e as seguintes mensagens devem ser apresentadas:

TA is sleeping.
TA went back to sleep.
TA is teaching student #?.
TA finished teaching student #?.
Student #? is going to TA room.
Student #? is awaking the TA.
Student #? is getting inside TA room.
Student #? left TA room.
There is no available chair to student #?. The student will return late.
Student #? sat on chair #?. #? chair(s) remain.
There is no more students to help. TA left the room.

A seguir, um exemplo de como as mensagens podem ser apresentadas para o caso de 5 alunos:

TA is sleeping.
Student #2 is going to TA room.
Student #2 is awaking the TA.
Student #2 is getting inside TA room.
TA is teaching student #2.
Student #5 is going to TA room.
Student #3 is going to TA room.
Student #1 is going to TA room.
Student #4 is going to TA room.
Student #4 sat on chair #1. 2 chair(s) remain.
Student #5 sat on chair #2. 1 chair(s) remain.
Student #1 sat on chair #3. 0 chair(s) remain.
There is no available chair to student 3. The student will return late.
TA finished teaching student #2.
Student #2 left TA room.
Student #5 is getting inside TA room.
TA is teaching student #5.
TA finished teaching student #5.
Student #5 left TA room.
Student #1 is getting inside TA room.
TA is teaching student #1.
TA finished teaching student #1.
Student #1 left TA room.
Student #4 is getting inside TA room.
TA is teaching student #4.
TA finished teaching student #4
Student #4 left TA room.
TA went back to sleep.
Student #3 is going to TA room.
Student #3 is awaking the TA.
Student #3 is getting inside TA room.
TA is teaching student #3.
TA finished teaching student #3.
Student #3 left TA room.
TA went back to sleep.
There is no more students to help. TA left the room.

É preciso haver coerência na apresentação das mensagens, ou seja, a sequencia abaixo não é possível, pois nenhum estudante deve ser atendido se o TA não acordou:

TA is sleeping.
Student #2 is going to TA room.
Student #2 is getting inside TA room.
TA is teaching student #2.
Student #2 is awaking the TA.

Outras observações:
- a implementação deve compilar nos sistemas operacionais Linux e/ou Mac OS X. Caso a compilação não seja possível, ou seja, erro durante a compilação, o arquivo será descartado;
- implementações submetidas além do horário limite estabelecido serão descartadas;
- arquivos que apresentarem cópias, seja de soluções encontradas na internet ou entre estudantes, serão descartados;

Avaliação:
Threads para estudantes e TA - 20%
Sincronização com Mutex para evitar condições de corrida - 25%
Sincronização com Semáforos para evitar condições de corrida - 25%
Coerência e concordância das mensagens - 20%
Qualidade do código e comentários - 10%

Esse último item diz respeito a seguir o padrão de codificação do kernel do Linux, não existência do vazamento de memória, inserção de comentários que facilitem o entendimento do código e remoção de eventuais prints usados no debug.