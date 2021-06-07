# Questão 4:

O RabbitMQ implementa o protocolo AMQP. Diferente da grande maioria dos protocolos de middlewares orientados a mensagens, o AMQP separa a entrega das mensagens em dois conceitos: as exchanges e as filas. Explique, com suas palavras, os diferentes tipos de exchanges e como é possível combiná-los com o conceito de fila do AMQP para construir sofisticados mecanismos de entrega de mensagens.

## Resposta:

### Tipos de Exchange:
- Direct: Roteia mensagens com uma chave de roteamento igual à chave de roteamento declarada antes na _binding queue_.

- Fanout: Ao contrário do Direct, roteia mensagens para todas as filas vinculadas, sem nenhum critério. Qualquer chave de roteamento fornecida é ignorada.

- Topic: Roteia mensagens para as filas que a chave de roteamento corresponde é igual a todas ou a uma parte de uma dada chave de roteamento

- Headers: Roteia com base em uma correspondência de cabeçalhos de mensagem com os cabeçalhos esperados pela _binding queue_.