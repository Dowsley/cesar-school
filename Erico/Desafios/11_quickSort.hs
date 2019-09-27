-- Quicksort
quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) = quicksort (small xs x) ++ (x : quicksort(large xs x))

-- ATIVIDADE (DESAFIO 11): CRIE UMA FUNÇÃO SMALL E UMA LARGE PARA FAZER O QUICKSORT FUNCIONAR
-- DICA: USE COMPREENSÃO DE LISTA

small :: [Int] -> Int -> [Int]   -- Retorna tudo que é menor que x na lista xs
small xs x = [i | i <- xs, i < x]

large :: [Int] -> Int -> [Int]   -- Retorna tudo que é maior que x na lista xs
large xs x = [i | i <- xs, i > x]

-- Feito.