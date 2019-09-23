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