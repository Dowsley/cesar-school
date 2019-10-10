-- Elemento 1 é aplicado a todos os elementos da lista, por uma operação opcional.
operList :: a -> (a -> b -> c) -> [b] -> [c]
operList c op xs = [c `op` x | x <- xs]

-- Não possui entradas, apenas chama operList com as 2 primeiras entradas já definidas.
-- A outra, que será inserida pelo usuário, continuará na mesma posição.
doubleList = operList 2 (*)

-- Filtra elementos de uma lista por condição booleana.
filter' :: (a -> Bool) -> [a] -> [a]
filter' c xs = [ x | x <- xs, c x ]

zipWith filter [True, False, False] [[1,2,1], [3,4,1]]