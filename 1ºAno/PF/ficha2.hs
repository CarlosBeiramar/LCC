--2 ficha 2 de 17/18 em conjunto com ficha 2 de 18/19
import Data.Char

--a) 

dobros :: [Float] -> [Float]
dobros [] = []
dobros (h:t) = 2*h : dobros t

--b)

numOcorre :: Char -> String -> Int
numOcorre c [] = 0
numOcorre c (h:t) = if c==h then 1 + numOcorre c t else numOcorre c t

--c)

positivos :: [Int] -> Bool
positivos (h:t) = if (h>0) then positivos t else False

--d)

soPos :: [Int] -> [Int] 
soPos [] = []
soPos (h:t) = if (h>0) then h: soPos t else soPos t

--e)

somaNeg :: [Int] -> Int
somaNeg [] = 0
somaNeg (h:t) = if (h<0) then h + somaNeg t else somaNeg t

--f)

tresUlt :: [a] -> [a]
tresUlt [] = []
tresUlt (h:t) = if (length (h:t) <= 3) then (h:t) else tresUlt t

--g)

primeiros :: [(a,b)] -> [a]
primeiros [] = []
primeiros ((h1,h2):t) = h1: primeiros t

--3

--a)

soDigitos :: [Char] -> [Char]
soDigitos [] = []
soDigitos (h:t) = if (isDigit' h == True) then h: soDigitos t else soDigitos t

isDigit' :: Char -> Bool
isDigit' x = if (ord x >= ord '0' && ord x <= ord '9') then True else False

--b)

minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (h:t) = if (isLower h == True) then 1 + minusculas t else minusculas t

--c)

nums :: String -> [Int]
nums [] = []
nums (h:t) |isDigit' h = h: nums t 
           |otherwise = nums t


--4

--a)

segundos :: [(a,b)] -> [b]
segundos [] = []
segundos ((h1,h2):t) = h2:segundos t

--b)

nosPrimeiros :: (Eq a) => a -> [(a,b)] -> Bool
nosPrimeiros x [] = False
nosPrimeiros x ((h1,h2):t) = if (x==h1) then True else nosPrimeiros x t

--c)

minFst :: (Ord a) => [(a,b)] -> a
minFst [(x,y)] = x
minFst ((h1,h2):(a1,a2):t) = if (h1 < a1) then minFst ((h1,h2):t) else minFst ((a1,a2):t)

--d)

sndMinFst :: (Ord a) => [(a,b)] -> b
sndMinFst [(x,y)] = y
sndMinFst ((h1,h2):t) = if (h1 == minFst ((h1,h2):t)) then h2 else sndMinFst t 

--e)

sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)
sumTriplos [(x,y,z)]=(x,y,z)
sumTriplos ((h1,h2,h3):(a1,a2,a3):t)= sumTriplos ((sumTriplos_aux (h1,h2,h3) (a1,a2,a3)):t)

sumTriplos_aux :: (Num a, Num b, Num c) => (a,b,c) -> (a,b,c) -> (a,b,c)
sumTriplos_aux (x,y,z) (w,t,r) = (x+w,y+t,z+r)

--f)

maxTriplo :: (Ord a, Num a) => [(a,a,a)] -> a
maxTriplo [] = 0
maxTriplo [(x,y,z)]= x+y+z
maxTriplo ((x,y,z):(h,w,m):t) = if (soma_aux (x,y,z) > soma_aux (h,w,m)) then maxTriplo ((x,y,z):t) else maxTriplo ((h,w,m):t)

soma_aux :: Num a => (a,a,a) -> a
soma_aux (x,y,z) = x+y+z

--4

type Polinomio = [Monomio]
type Monomio = (Float,Int)

--a)

conta :: Int -> Polinomio -> Int
conta x [] = 0
conta x ((h1,h2):t) = if (x==h2) then 1 + conta x t else conta x t

--b)

grau :: Polinomio -> Int
grau [] = 0
grau [(x,y)] = y
grau ((h1,h2):(a1,a2):t) = if (h2>a2) then grau ((h1,h2):t) else grau ((a1,a2):t)

--c)

selgrau :: Int -> Polinomio -> Polinomio
selgrau x [] = []
selgrau x ((h1,h2):t)= if (x==h2) then (h1,h2):selgrau x t else selgrau x t 

--d)
deriv :: Polinomio -> Polinomio
deriv [] = []
deriv ((h1,h2):t) = (h1*(fromIntegral h2),h2-1):deriv t


--e)

calcula :: Float -> Polinomio -> Float
calcula x [] = 0
calcula x ((h1,h2):t) = h1 * x^h2 + calcula x t

--f)

--simp :: Polinomio -> Polinomio

--g)

mult :: Monomio -> Polinomio -> Polinomio
mult (x,y) [] = []
mult (x,y) ((h1,h2):t) = (h1*x,y+2):mult (x,y) t

--h)

normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza [(x,y)] = [(x,y)]
normaliza ((h1,h2):t) = normaliza_aux (h1,h2) (normaliza t)

normaliza_aux :: Monomio -> Polinomio -> Polinomio
normaliza_aux (x,y) [] = [(x,y)]
normaliza_aux (x,y) ((h1,h2):t) = if (y == h2) then (x+h1,h2):t else (h1,h2): normaliza_aux (x,y) t

--i)

soma :: Polinomio -> Polinomio -> Polinomio
soma [] [] = []
soma l [] = l
soma [] l = l
soma l l1 =normaliza (l ++ l1)

--j)

produto :: Polinomio -> Polinomio -> Polinomio
produto [] [] = []
produto l [] = []
produto [] l = []
produto ((h1,h2):t) l2 = normaliza ((produto_aux (h1,h2) l2) ++ (produto t l2))

produto_aux :: Monomio -> Polinomio -> Polinomio
produto_aux (x,y) [] = []
produto_aux (x,y) ((h1,h2):t) = (h1*x,y+h2): produto_aux (x,y) t


--k)
ordena :: Polinomio -> Polinomio
ordena [] = []
ordena [(x,y)] = [(x,y)]
ordena ((h1,h2):t)= (maior ((h1,h2):t)) : ordena(delete' (maior ((h1,h2):t)) t)

maior :: Polinomio -> Monomio
maior [(x,y)] = (x,y)
maior ((h1,h2):(a1,a2):t) = if (h2 > a2) then maior ((h1,h2):t) else maior ((a1,a2):t)

delete' :: Monomio -> Polinomio -> Polinomio
delete' (x,y) [] = []
delete' (x,y) ((h1,h2):t) = if (x==h1 && y==h2) then t else (h1,h2):delete' (x,y) t

--l)

equiv :: Polinomio -> Polinomio -> Bool
equiv [] [] = True
equiv l [] = False
equiv [] l = True
equiv ((h1,h2):t) l2 = if (equiv_aux (h1,h2) l2 == True) then equiv t l2 else False

equiv_aux :: Monomio -> Polinomio -> Bool
equiv_aux (x,y) [] = False
equiv_aux (x,y) ((h1,h2):t) = if (x==h1 && y==h2) then True else equiv_aux (x,y) t











