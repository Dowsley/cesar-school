doubleList :: [Int] -> [Int]
doubleList as | as == [] = []      
              | otherwise = (head as)*2 : doubleList (tail as)

doubleList' :: [Int] -> [Int]
doubleList' [] = []
doubleList' (a:as) = a*2 : doubleList' as

maxList :: [Int] -> [Int]
maxList [] = []
maxList (a:[]) = [a]
maxList (a:as) | a > head(maxList as) = [a]
               | otherwise = maxList as

doubleList'' :: [Int] -> [Int]
doubleList'' [] = []
doubleList'' a = [b*2| b <- a]

quicksort :: [Int] -> [Int]
quicksort [] = []
quicksort (x:xs) = 
quicksort (small xs x ) ++ (x : quicksort (large xs x))


-- ATIVIDADE (DESAFIO 11): CRIE UMA FUNÇÃO SMALL E UMA LARGE PARA FAZER O QUICKSORT FUNCIONAR
-- DICA: USE COMPREENSÃO DE LISTA