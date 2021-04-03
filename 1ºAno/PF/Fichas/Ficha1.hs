module Ficha1 where
--Ficha 1
isDigit' :: Char -> Bool
isDigit' x = x>= '0' && x<='9'
--1.

--a)
perimetro :: Double -> Double
perimetro x = 2 * pi * x

--b)
dist:: (Double,Double) -> (Double,Double) -> Double
dist (x,y) (w,z) = sqrt ((w-x)^2 + (z-y)^2)

--c)
primUlt:: [a] -> (a,a)
primUlt l = (head l, last l)

--d)
--multiplo :: Int -> Int -> Bool
--multiplo m n = if mod (m n == 0) then True else False

--e)
--truncaImpar :: [a] -> [a]
--truncaImpar [] = []
--truncaImpar l = if multiplo (length l) 2 then l else tail l

--f)
max2 :: Int -> Int -> Int
max2 x y = if x>y then x else y
 
--g)
max3 :: Int -> Int -> Int -> Int
max3 x y z = (max2 (max2 x y) z)

--2.
--a)
nRaizes :: Double -> Double -> Double -> Int
nRaizes a b c = if b^2 - 4 * a * c > 0 then 2 else (if b^2 -4 * a * c == 0 then 1 else 0)

--b)
--raizes :: Double -> Double -> Double -> [Int]
--raizes x y z = 

--3.

type Hora = (Int,Int)

--a) 
testa :: Hora -> Bool
testa (h,m) = if h >= 0 && h<24 && m>=0 && m<60 then True else False 

--b)
testa2 :: Hora -> Hora -> Bool
testa2 (h1,m1) (h2,m2) = if h1>h2 then True else (if h1 == h2 && m1>m2 then True else False)

--c)
converte :: Hora -> Int
converte (h,m) = h * 60 + m

--d)
converte2 :: Int -> Hora
converte2 m = (div m 60,mod m 60)

--e)
diferenca :: Hora -> Hora -> Int
diferenca h1 h2 = abs ((converte h2)-(converte h1))

--f)
add :: Int -> Hora -> Int
add x h1 = converte h1 + x 

--5.

data Semaforo = Verde | Amarelo | Vermelho deriving (Show,Eq)

--a)
next :: Semaforo -> Semaforo
next Verde = Amarelo
next Amarelo = Vermelho
next Vermelho = Verde 

--b)
stop :: Semaforo -> Bool
stop Verde = False
stop Amarelo = False
stop Vermelho = True

--c)
safe :: Semaforo -> Semaforo -> Bool
safe Vermelho Vermelho = False
safe Vermelho Amarelo = True
safe Vermelho Verde = True
safe Verde Vermelho = True
safe Amarelo Vermelho = True

--6.

data Ponto = Cartesiano Double Double | Polar Double Double
             deriving (Show,Eq)

--a) 
posx :: Ponto -> Double
posx (Cartesiano x y) = abs x

--b)
posy :: Ponto -> Double
posy (Cartesiano x y) = abs y

--c)
raio :: Ponto -> Double
raio (Cartesiano x y) = abs ((x-0)^2+(y-0)^2)