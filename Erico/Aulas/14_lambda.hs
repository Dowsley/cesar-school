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
-- Talvez seja mais eficiente executar isto no console: map (\(a, _) -> a) [("abc", 2)]


foldr' f z [] = z
foldr' f z (x:xs) = f x (foldr' f z xs)