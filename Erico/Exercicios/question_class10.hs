{-
1) Defina uma função recursiva log2 tal que log2 x retorne a aproximação inferior do logaritmo de x na base 2.
EXEMPLOS: > log2 16 = 4  ||  > log2 11 = 3  ||  >  log2 1 = 0
Dica: use a operação de divisão div
-}

log2 :: Int -> Int
log2 2 = 1
log2 1 = 0
log2 x = 1 + log2 (div x 2)


{-
2) Crie uma função que receba dois inteiros como argumento e gere todas as possíveis
combinações de K (segundo parâmetro) números distintos escolhidos de uma lista contendo de
0 até N-1 (primeiro parâmetro) números.
 
> combineList 4 3
[[0,1,2],[0,1,3],[0,2,3],[1,2,3]]
-}

arranjo n k = [ [x,y,z] | x <- [0..(n-1)], y <- [0..(n-1)], z <- [0..(n-1)], x /= y, y /= z, x /= z ]
-- [ [x,y,z] | x <- [0,1,2,3], y <- [0,1,2,3], z <- [0,1,2,3], x /= y, y /= z, x /= z ]