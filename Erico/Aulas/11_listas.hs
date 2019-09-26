-- Retorna o maior elemento de uma lista, usa recursividade.
maxList :: [Int] -> Int
maxList [] = 0
maxList (a:as) | a > maxList as = a
               | otherwise = maxList as


-- Quicksort
quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) = quicksort (small xs x) ++ (x : quicksort(large xs x))


-- ATIVIDADE (DESAFIO 11): CRIE UMA FUNÇÃO SMALL E UMA LARGE PARA FAZER O QUICKSORT FUNCIONAR
-- DICA: USE COMPREENSÃO DE LISTA