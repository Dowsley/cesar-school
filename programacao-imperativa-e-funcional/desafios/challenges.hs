{-
1. Split words (first argument) based on the second argument
-}
sw :: [Char] -> Char -> [[Char]]
sw [] _ = []
sw w s = (stopOn w s) : (sw (startOn w s) s)

-- Receives a string and a char, and returns the substring before the first ocurrence of the char.
-- the char argument is the same as sw`s
-- sw will concatenate all cases
stopOn :: [Char] -> Char -> [Char]
stopOn [] _ = []
stopOn (c:cs) s | s == c = []
                | otherwise = c : (stopOn cs s)

-- startOn, on the other hand, will return the substring that comes after.
startOn :: [Char] -> Char -> [Char]
startOn [] _ = []
startOn (c:cs) s | s == c = cs
                 | otherwise = startOn cs s

{-
2. rmLarN
-}

remLarN :: Int -> [Int] -> [Int]
remLarN _ [] = []
remLarN x y = listaTup (removeN (rMaior x (tupLista 0 y)) (tupLista 0 y))

removeN :: Int -> [(Int, Int)] -> [(Int, Int)]
removeN _ [] = []
removeN y (x:xs) | y == (snd x) = xs
                 | otherwise = x : removeN y xs  

tupLista :: Int -> [Int] -> [(Int, Int)]
tupLista _ [] = []
tupLista l (x:xs) = (x,l) : tupLista (l+1) xs

rMaior :: Int -> [(Int, Int)] -> Int
rMaior _ [] = 0
rMaior 1 x = (snd (maximum x))
rMaior y x = rMaior (y-1) (removeN (snd (maximum x)) x)

listaTup :: [(a, Int)] -> [a]
listaTup [] = []
listaTup (x:xs) = (fst x) : listaTup xs

{-
3. prod
Recebe duas listas de inteiros, retorna uma tupla com 2 coisas: 1. lista de tuplas (cada uma é uma combinação entre as 2 listas iniciais), 2. Um inteiro com a soma de todos os pares.
-}
prod :: [Int] -> [Int] -> ([(Int, Int)], Int)
prod [] _ = ([], 0)
prod _ [] = ([], 0)
prod xs ys = (combine xs ys, sumEven (combine xs ys))

combine :: [Int] -> [Int] -> [(Int, Int)]
combine xs ys = [(x, y) | x<-xs, y<-ys]

sumEven :: [(Int, Int)] -> Int
sumEven [] = 0
sumEven (t:ts) = neutral(fst t) + neutral(snd t) + sumEven ts

neutral :: Int -> Int
neutral x | (mod x 2) == 0 = x
          | otherwise = 0

-- DA PRA FAZER SEM COMPREENSAO DE LISTA!
prod' :: [Int] -> [Int] -> ([(Int, Int)], Int)
prod' [] _ = ([], 0)
prod' _ [] = ([], 0)
prod' xs ys = (combineAll xs ys, sumEven(combineAll xs ys))

combineAll :: [Int] -> [Int] -> [(Int, Int)]
combineAll [] _ = []
combineAll (x:xs) ys = (combine' x ys) ++ (combineAll xs ys)

combine' :: Int -> [Int] -> [(Int, Int)]
combine' _ [] = []
combine' x (y:ys) = (makeTuple x y) : combine' x ys

makeTuple :: Int -> Int -> (Int, Int)
makeTuple x y = (x,y)

{-
4. Exercicio q dave mandou aí
-}

-- Recebe as tuplas e retorna a resposta: Main
sortT :: [(Int, Int)] -> [Int]
sortT ts = getOrder (ts) (smol ts)

-- Procura tuplas de acordo com um índice (sempre o menor), recursivamente.
getOrder :: [(Int, Int)] -> Int -> [Int]
getOrder [] _ = []
getOrder ts s = addTerm ts s : getOrder (rmTerm ts s) (smol (rmTerm ts s))

-- Remove uma tupla da lista de tuplas de acordo com o indice desejado.
rmTerm :: [(Int, Int)] -> Int -> [(Int, Int)]
rmTerm [] _ = []
rmTerm (t:ts) x | (snd t) == x = rmTerm ts x
                | otherwise = t : rmTerm ts x

-- Recebe uma lista de tuplas e retorna a chave no indice desejado.
addTerm :: [(Int, Int)] -> Int -> Int
addTerm (t:ts) x | (snd t) == x = fst t
                 | otherwise = addTerm ts x

-- Recebe a lista de tuplas e diz qual o menor índice presente nela. 
smol :: [(Int, Int)] -> Int
smol [] = -1
smol [x] = snd x
smol (t:ts) = min (snd t) (smol ts)

{-
6. Usando lambda, foldr (ou foldl), crie a função remove que dada uma lista de listas,
em que as sub-listas individualmente não apresentam elementos repetidos, retorne uma lista
que contém todos os elementos das sub-listas da lista de entrada, removendo duplicação,
mantendo sempre o último da duplicação que aparecer, e os não duplicados devem aparecer na
saída na mesma ordem em que aparecem nas sub-listas de entrada.

*Main> remove [[1..10], [5..20], [6, 8.. 15]]
[1,2,3,4,5,7,9,11,13,15,16,17,18,19,20,6,8,10,12,14]
-}