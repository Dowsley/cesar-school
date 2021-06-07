# Questão 2:

Sistemas distribuídos podem apresentar características conhecidas como transparências.
Explique, com suas próprias palavras, as transparências de localização, migração e relocação. Detalhe, principalmente, a relação entre elas.

## Resposta:
- Localização: Um usuário qualquer do sistema (distribuído, claro) não pode, em nenhum momento, saber onde está a localização física de um recurso.

- Migração: Um usuário qualquer do sistema não deve ter conhecimento sobre a capacidade de um recurso se mover para um local diferente. Seja este endereço lógico, ou físico.

- Relocação: Ao ocorrer a relocação de um recurso - isto é, sua movimentação de um local para outro - esta ação devee ser imperceptível para o usuário.

Todos estes tipos de transparência estão ligados à interação entre o recurso e o usuário final. Elas garantem que apenas o recurso em si seja exibido para o usuário final, e não informações irrelevantes (ou potencialmente perigosas), como por exemplo a forma que o sistema lida com o recurso.