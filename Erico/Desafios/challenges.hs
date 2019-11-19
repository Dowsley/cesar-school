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

rmLarN :: [Int] ->
