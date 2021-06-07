# Questão 2
## 1. Na disciplina vimos que o processo de marshalling tem um papel muito importante no projeto e implementação de sistemas distribuídos. Compare as estratégias de marshalling binário e textual, focando nas vantagens e desvantagens de se usar dois dos principais representantes de cada categorias, respectivamente o ProtoBuf e o JSON.

## Resposta:
O Marshalling binário precisa entender quais são os data-types, onde começam e acabam, e quais seus tamanhos. Isto tudo é fornecido por headers que vem anterior a cada informação. O Marshalling textual é mais simples, pois usa o clássico text parsing, que envolve buscar chaves de começo e fim. Porém, é dito que o text marshalling, em específico o JSON parsing, é menos robusto a recuperação de erros do que binary marshalling.
