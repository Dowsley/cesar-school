-- 6. Defina a função ordenaTripla que recebe uma tripla de inteiros e ordena a mesma.

--ordenaTripla :: (Int, Int, Int) -> (Int, Int, Int)
--ordenaTripla (x, y, z) |



{-
7. Crie uma função que recebe uma lista de listas de valores de um tipo t que podem ser
comparados para saber se são iguais e devolve uma lista de pares (t, Int) onde o
primeiro elemento é um valor do tipo t que existe em pelo menos uma das sub-listas da
entrada e o segundo é o número de ocorrências desse valor nas sub-listas:

*Main> group [[4,2,4,3,4,4,4,5,4,6], [1,2,3,4,5], [2]]
[(4,7),(2,3),(3,2),(5,2),(6,1),(1,1)]
-}

group :: [t] -> [(t, Int)]
group xs = [(xs !! 0, 2)]