{-
2. Defina a função teste::[Int]->[Int] que recebe uma lista de inteiros e devolve: o
primeiro número da lista original, o segundo número da lista original e todos os números de
posição i na lista original, que forem maiores do que o número da posição i-2 da lista original.
Use compreensão de listas, caso não seja possível, explique porque e implemente sem.

Prelude> teste [3,4,2,3,5,7,4,6,2,5]
[3,4,5,7]
Prelude>
-}

teste :: [Int]->[Int]
teste xs = (head xs): (xs !! 1):[ xs !! i | i<-[2..(length xs - 1)], (xs !! i) > (xs !! (i-2))]

{-
3. Defina uma função splitAndMult :: [Int] -> Int -> [[Int], [Int]], a qual
recebe uma lista de números inteiros, e retorna uma tupla com 2 listas: a da esquerda com os
números pares da lista da entrada, e a da direita os números ímpares da lista de entrada
multiplicados pelo número passado como segundo argumento. Os números devem estar na
mesma ordem da lista original. Exemplo:

Prelude> separarEMultiplicarNumeros [2, 93, 7, 29, 62, 49, 47, 31, 94] 3
[[2, 62, 94], [279, 21, 87, 147, 141, 93]]
Prelude>
-}

splitAndMult :: [Int] -> [Int] -> [[Int], [Int]]
