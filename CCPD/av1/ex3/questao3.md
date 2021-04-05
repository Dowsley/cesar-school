# Questão 3
## O Java oferece, embarcado na classe Object, um mecanismo de monitores capaz de oferecer tanto exclusão mútua como bloqueios. Explique a utilidade da palavra reservada synchronized e os métodos: wait, notify e notifyAll.

## Resposta:
### Synchronized
Qualquer função (trecho de código) com a palavra reservada "Synchronized" irá fazer com que o Java automaticamente permita a execução de apenas uma instância de Thread (que use esta função) por vez. É uma maneira built-in do Java para facilmente evitar condição de concorrência por um recurso. 

### wait()
Wait é um método presente em qualquer objeto Mutex, que representa um "sinalizador" para se recursos podem ser acessados ou não. Toda vez que uma Thread executa o wait, ela é ordenada para pausar a execução do programa nesta linha e esperar uma notificação do Mutex... que é explicado abaixo.

### notify()
É o método do Mutex que notifica *uma* Thread que estava travada no `wait`. Porém, é bom lembrar que o notify não libera o recurso necessariamente, ele apenas NOTIFICA que o recurso foi liberado, pois na realidade a Thread que foi notificada apenas resume execução quando o bloco synchronized da thread notificadora termina.

### notifyAll()
Tem o mesmo efeito do `notify`, porém para TODAS as Threads que estavam travadas no `wait`, ao invés de só uma.