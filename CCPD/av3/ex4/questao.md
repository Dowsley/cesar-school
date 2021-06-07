# Questão 4
## Podemos implementar, nos sistemas distribuídos, o controle de mudança de estado com duas abordagens distintas: o algoritmo de Paxos (e derivados) e os relógios vetoriais. Explique as principais diferenças dessas duas abordagens, focando principalmente nos aspectos relacionados à consistência e o desempenho.

## Resposta:
Relógios Vetoriais são melhores uusados para armazenamento distribuído sem líder. Você pode usar relógios vetoriais para o mesmo (embora seja um pior ajuste; o artigo também sugere que você o use para instantâneos consistentes, para implementar ordenação causal em geral sistemas distribuídos etc). Já Paxos é melhor usado para um líder único ou multi-líder distribuídos.
