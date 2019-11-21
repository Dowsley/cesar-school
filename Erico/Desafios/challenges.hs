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
