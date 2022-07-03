## Objetivo geral
Desenvolver uma aplicação de troca de mensagens segura capaz de, na camada de aplicação, fornecer uma comunicação confidencial e autêntica para os dados tocados entre os sistemas finais.

## Características específicas
- A comunicação deve ocorrer via sockets;
- A aplicação deve permitir que todas as mensagens trocadas sejam confidenciais e
autenticadas;
- A confidencialidade deve ser obtida através de criptografia simétrica. A chave secreta deve
ser trocada de maneira segura e gerada por sessão;
- A troca da chave secreta deverá utilizar algum método de criptografia assimétrica;
- O código da aplicação bem como um relatório (incluindo o seu manual de utilização) devem
ser entregues no dia da apresentação.


## Idea
Use RSA along with EAS.

See https://www.precisely.com/blog/data-security/aes-vs-rsa-encryption-differences

And https://en.wikipedia.org/wiki/Hybrid_cryptosystem

## How to use
`config.json` should have a list of chat origins, each containing an local ip on the network and a valid port. Use "fell" and "cami" as examples.

The baseline command is
```
python chat.py from to mode
# from = key from who is sending
# to = key from who is receiving
# mode = can be either "sender" or "receiver" although there is no real difference
```

For test usages, replace the ip of both fell and cami with the ip of your local machine. The ports described there should work if they are not being used. Then, in two different terminals, execute a sender a receiver.

```
# Execute the sender
"chat.py fell cami sender"

```

```
# Execute the receiver
"chat.py cami fell receiver"

```

Then chat.