{- ====================== QUESTIONS CLASS 10 ====================== -}

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

combineList n k | k == 1 = [ [x] | x <- [0..(n-1)] ]
                | otherwise = [ xs ++ [x] | xs <- (combineList n (k-1)), x <- [((last xs)+1)..(n-1)] ]


{- ====================== QUESTIONS CLASS 11 ====================== -}
{-
2. Defina a função teste::[Int]->[Int] que recebe uma lista de inteiros e devolve: o
primeiro número da lista original, o segundo número da lista original e todos os números de
posição i na lista original, que forem maiores do que o número da posição i-2 da lista original.
Use compreensão de listas, caso não seja possível, explique porque e implemente sem.

Prelude> teste [3,4,2,3,5,7,4,6,2,5]
[3,4,5,7]
Prelude>
-}

teste :: [Int]->[Int]
teste xs = (head xs): (xs !! 1):[ xs !! i | i<-[2..(length xs - 1)], (xs !! i) > (xs !! (i-2))]

{-
3. Defina uma função splitAndMult :: [Int] -> Int -> [[Int], [Int]], a qual
recebe uma lista de números inteiros, e retorna uma tupla com 2 listas: a da esquerda com os
números pares da lista da entrada, e a da direita os números ímpares da lista de entrada
multiplicados pelo número passado como segundo argumento. Os números devem estar na
mesma ordem da lista original. Exemplo:

Prelude> separarEMultiplicarNumeros [2, 93, 7, 29, 62, 49, 47, 31, 94] 3
[[2, 62, 94], [279, 21, 87, 147, 141, 93]]
Prelude>
-}

splitAndMult :: [Int] -> Int -> ([Int], [Int])
splitAndMult x c = ([ xs | xs <- x, (xs `mod` 2) == 0 ], [ xs*c | xs <- x, (xs `mod` 2) /= 0 ])


{- ====================== QUESTIONS CLASS 12 ====================== -}

-- 6. Defina a função ordenaTripla que recebe uma tripla de inteiros e ordena a mesma.



{-
7. Crie uma função que recebe uma lista de listas de valores de um tipo t que podem ser
comparados para saber se são iguais e devolve uma lista de pares (t, Int) onde o
primeiro elemento é um valor do tipo t que existe em pelo menos uma das sub-listas da
entrada e o segundo é o número de ocorrências desse valor nas sub-listas:

*Main> group [[4,2,4,3,4,4,4,5,4,6], [1,2,3,4,5], [2]]
[(4,7),(2,3),(3,2),(5,2),(6,1),(1,1)]
-}



{- ====================== QUESTIONS CLASS 13 ====================== -}
{-
8. Defina uma função que dada uma lista de inteiros, remove da lista todos os elementos
que não sejam primos. Sua solução deve empregar filter.

*Main> notPrime [1,2,4,3,5,6]
[1,4,6]
*Main>
-}

primo :: Int -> Bool
primo k = length [ x | x <- [2..k], k `mod` x == 0] == 1
primeList :: [Int] -> [Int]
primeList l = filter primo l

{-
9. Implemente uma função mapFilter que, sem usar map nem filter, comporte-se
como a função map.filter
-}



{-
10. Dados uma lista de listas de números e um número n, devolver uma lista contendo
todas cujo comprimento seja maior que n. Use lambda.

filter (\x -> length x > 2)
-}



{- ====================== QUESTIONS CLASS 14 ====================== -}
{-
11. Defina uma função para, dada uma lista de listas de inteiros, remover da lista todas
as listas cujas somas dos elementos são menores que um certo valor, também fornecido
como argumento. Use filter e foldr para resolver esta questão.
-}



{-
12. Para a expressão abaixo, sem usar o computador, apresente uma entrada e a
saída associada de forma a não retornar uma função de alta ordem

map.((.) (foldr (++) (foldr (++) [] [[1], [2], [4,5,6], [3]])))
map.((.) (foldr (++) (foldr (++) [] [[1], [2], [4,5,6], [3]])))
$ ((++) [[10],[11,12]])) [[[22],[23,24]]]
[[10,11,12,22,23,24,1,2,4,5,6,3]]
-}