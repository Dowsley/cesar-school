-------------------- Aula 12 --------------------
-- Soma elementos de uma tupla
addPair :: (Int, Int) -> Int
addPair (x,y) = x + y

-- Soma elementos de diversas tuplas. Pode ser feito com recursão.
addPairs :: [(Int, Int)] -> [Int]
addPairs [] = []
addPairs ls = [ (fst x) + (snd x) | x <- ls ] -- ou addPairs ls = [ a+b | (a,b) <- ls ]

addPairs' :: [(Int, Int)] -> [Int]
addPairs' [] = []
addPairs' (x:xs) = (addPair x) : addPairs' xs

-- Retorna os caracteres q sao digitos
digits :: String -> String
digits lc = [ c | c <- lc, c `elem` ['0'..'9'] ]

digits' :: String -> String
digits' [] = []
digits' (l:ls) | l `elem` "0123456789" = l: digits' ls
              | otherwise = digits' ls

-- Retorna tamanho
len :: [a] -> Int
len [] = 0
len (x:xs) = 1 + len xs


--------------------- DESAFIO 12: FAZER UMA FUNÇÃO "ZIP" e "TAKE"
zip' :: [a] -> [b] -> [(a,b)]
zip' la lb = [  (la !! y, lb !! y) | y <- [0..((min (length la) (length lb)) - 1)]]
-- NOTA: A função acima trava quando uma das entradas é infinita.
-- Enquanto a função abaixo não

zip'' :: [t] -> [u] -> [(t,u)]
zip'' (a:as) (b:bs) = (a,b):zip'' as bs
zip'' _ _ = []

take' :: Int -> [a] -> [a]
take' 0 _ = []
take' _ [] = []
take' n (x:xs) = x : take' (n-1) xs
-- NÃO QUEBRA COM LISTA INFINITA!

-- 
curry' :: ((a,b) -> c) -> a-> b -> c
curry' f a b = f (a,b)

-- DESAFIO 12.2: FAZER FUNÇAO UNCURRY (RECEBE UM OPERADOR E UMA TUPLA, DEPOIS FAZ OPERAÇÃO --> (*) (3,2) == 6)