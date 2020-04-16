{- ====================== CLASS 10 ====================== -}
				{- INTRODUÇAO A HASKELL -}

-- Declara entrada e saída de inteiros, retorna a entrada vezes 4.
mult4 :: Int -> Int   
mult4 x  = 4*x


-- Input de 3 inteiros, output de 1 Bool. Retorna se todos os números são iguais.
allEqual :: Int -> Int -> Int -> Bool
allEqual n m p = (n == p) && (m == p)


-- Input de 2 inteiros. Saída de inteiro. Retorna o maior número.
max2 :: Int -> Int -> Int
max2 n m | n >=m = n
         | otherwise = m -- "|" se chama Pipe


-- Input de 3 inteiros, saída de inteiro. Retorna o maior número entre os 3.
max3 :: Int -> Int -> Int -> Int
max3 a b c | (a>=b) && (a>=c) = a
           | (b>=c) && (b>=a) = b
           | otherwise = c


-- Constantemente retorna "n" vezes o fatorial do número -1, e só para a recursão quando...
-- ...o "n" é zero, onde o resultado é 1.
fac :: Int -> Int
fac 0 = 1
fac n = n * fac(n-1)


-- Retorna "x" vezes a recursão e decrementa y, só para quando o y chega em 0 e retorna 1, termo neutro também.
power :: Int -> Int -> Int
power _ 0 = 1
power x y = x * power x (y-1)


{- ====================== CLASS 11 ====================== -}
					   {- LISTAS -}

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
quicksort (x:xs) = quicksort (small xs x ) ++ (x : quicksort (large xs x))


-- ATIVIDADE (DESAFIO 11): CRIE UMA FUNÇÃO SMALL E UMA LARGE PARA FAZER O QUICKSORT FUNCIONAR
-- DICA: USE COMPREENSÃO DE LISTA


small :: [Int] -> Int -> [Int]   -- Retorna tudo que é menor que x na lista xs
small xs x = [i | i <- xs, i < x]

small' :: [Int] -> Int -> [Int]
small' [] y = []
small' (x:xs) y | x < y = x:small' xs y
                | otherwise = small' xs y

large :: [Int] -> Int -> [Int]   -- Retorna tudo que é maior que x na lista xs
large xs x = [i | i <- xs, i > x]

large' :: [Int] -> Int -> [Int]
large' [] y = []
large' (x:xs) y | x > y = x:large' xs y
                | otherwise = large' xs y
-- Feito.


{- ====================== CLASS 12 ====================== -}
					{- TUPLAS E TIPOS -}

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

uncurry' :: (a -> b -> c) -> (a,b) -> c
uncurry' (op) (x,y) = op x y
--FEITO!


{- ====================== CLASS 13 ====================== -}
				{- FUNÇOES DE ALTO NÍVEL -}

-- Elemento 1 é aplicado a todos os elementos da lista, por uma operação opcional.
operList :: a -> (a -> b -> c) -> [b] -> [c]
operList c op xs = [c `op` x | x <- xs]

-- Versão recursiva
operlist' :: t1 -> (t1 -> t2 -> a) -> [t2] -> [a]
operlist' n bop [] = []
operlist' n bop (x:xs) = n `bop` x : operlist' n bop xs

-- Não possui entradas, apenas chama operList com as 2 primeiras entradas já definidas.
-- A outra, que será inserida pelo usuário, continuará na mesma posição.
doubleList''' = operList 2 (*)


-- Filtra elementos de uma lista por condição booleana.
filter' :: (a -> Bool) -> [a] -> [a]
filter' c xs = [ x | x <- xs, c x ]

filter'' :: (a -> Bool) -> [a] -> [a]
filter'' c [] = []
filter'' c (x:xs) | c x = x: filter'' c xs
                  | otherwise = filter'' c xs

allEqual' :: Int -> Int -> Int -> Bool
allEqual' n m p = (n == p) && (m == p)

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ _ [] = []
zipWith' _ [] _ = []
zipWith' op (a:as) (b: bs) = (op a b):zipWith' op as bs

map' :: (a->b) -> [a] -> [b]
map' _ [] = []
map' op (x:xs) = (op x):(map' op xs)

{-
zipWith filter (zipWith allEqual [1,2,3] [1,1,1]) [[1,2,1],[3,4]]

zipWith filter [allEqual 1 1, allEqual 2 1, allEqual 3 1] [[1,2,1], [3,4]]

[filter (allEqual 1 1) [1,2,1], filter (allEqual 2 1) [3,4]]

[[1,1],[]]
-}


{- ====================== CLASS 14 ====================== -}
				  {- LAMBDA FUNCTIONS -}

maxPairList :: [(Int, Int)] -> [Int]
maxPairList [] = []
maxPairList ts = [ max (fst t) (snd t) | t <- ts]

maxPairList' :: [(Int, Int)] -> [Int]
maxPairList' a = map (uncurry max) a
{- Função map aplica uma funçao a cada elemento da lista "a"
- Função uncurry aplica uma função a cada elemento de uma tupla. Que no caso, é o max, q n funcionaria em tupla.
-}

--                  i  ->  o -> run
{- LAMBDA EXEMPLO: (\x -> x+2)  3 -}

lambda :: [(a, a)] -> [a] -- Função que replica o efeito que um map teria.
lambda [] = []
lambda (t:ts) = (\x -> fst(x)) t : lambda ts
-- Talvez seja mais eficiente executar isto no console: map (\[(a, _)] -> a) [("abc", 2)]


foldr' f z [] = z
foldr' f z (x:xs) = f x (foldr' f z xs)