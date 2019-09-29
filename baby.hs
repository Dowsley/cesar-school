-- Gera uma pilha de  "n" vezes o fatorial dele mesmo menos 1, e só para a recursão quando...
-- ...o "n" é zero, onde o resultado é 1.
fac :: Int -> Int
fac 0 = 1
fac n = n * fac(n-1)


-- Retorna "x" vezes a recursão e decrementa y, só para quando o y chega em 0 e retorna 1, termo neutro também.
power :: Int -> Int -> Int
power _ 0 = 1
power x y = x * power x (y-1)


-- (A) Retorna 2 elevado a x, utilizando recursão e (x == 0) como ponto de parada.
-- De certa forma diz a qtd de possibilidades de um número de X bits.
bits :: Int -> Int
bits 0 = 1
bits x = 2 * bits (x-1)