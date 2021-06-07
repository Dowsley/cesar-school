# Questão 3

Vemos normalmente associado a middlewares orientados a mensagem os conceitos de tópicos e filas. Explique, com suas palavras, os dois conceitos e as principais diferenças entre eles.

## Resposta:

A fila é uma espécie de pipeline de mensagens na qual cada uma delas chega e vai, em ordem, para apenas um "subscriber", isto é, assinante.

Já o conceito de Topics é uma pipeline onde as mensagens que chegam vão para cada assinante diferente.