import Data.List
import Data.Char
import Data.Either
import Data.Maybe
--1)
enumFromTo' :: Int -> Int ->[Int]
enumFromTo' x y = if (x>y) then [] else (if (x==y) then [x] else (x:enumFromTo' (x+1) y))

--2)
enumFromThenTo' :: Int -> Int -> Int -> [Int]
enumFromThenTo' x y z | x==z = [x]
                      | x>z = []
                      | otherwise = x:(enumFromThenTo' (x+(y-1)) y z)

--3)
junta :: [a] -> [a] -> [a]
junta [] [] = []
junta [] l2 = l2
junta l1 l2 = l1++l2

--4)

posicao :: [a] -> Int -> a
posicao (h:t) 0 = h
posicao (h:t) x = posicao t (x-1)

--5)

reverse' :: [a] -> [a]
reverse' [] = []
reverse' (h:t) = reverse' t ++ [h]

--6)

take' :: Int -> [a] -> [a]
take' x [] = []
take' 0 l = []
take' x (h:t) = h: take' (x-1) t

--7)

drop' :: Int -> [a] -> [a]
drop' x [] = []
drop' 0 l = l
drop' x (h:t) = drop' (x-1) t

--8)

zip' :: [a] -> [b] -> [(a,b)]
zip' [] [] = []
zip' [] l = []
zip' l [] = []
zip' (h:t) (x:xs) = (h,x):(zip' t xs)

--9)

elem' :: Eq a => a -> [a] -> Bool
elem' x [] = False
elem' x (h:t)= if (x==h) then True else elem' x t

--10)

replicate' :: Int -> a -> [a]
replicate' 0 y = []
replicate' x y = y:replicate' (x-1) y

--11)

intersperse' :: a -> [a] -> [a]
intersperse' x [] = []
intersperse' x [t] = [t] 
intersperse' x (h:t) = h:x:intersperse' x t

--12)

group' :: Eq a => [a] -> [[a]]
group' [] = [[]]
group' [x] = [[x]]
group' (h:t) = (group_aux2 h (h:t)): group' (filter (/=h) (h:t))


group_aux2 :: Eq a => a -> [a] -> [a]
group_aux2 x [] = []
group_aux2 x [h] = []
group_aux2 x (h:t) = if (x==h) then h:group_aux2 x t else group_aux2 x t 
   
--13)

concat' :: [[a]] -> [a]
concat' [] = []
concat' (h:t) = h ++ concat' t

--14)

inits' :: [a]->[[a]]
inits' [] = [[]]
inits' (h:t) = reverse (inits_aux (h:t))

inits_aux :: [a] -> [[a]]
inits_aux [] = [[]]
inits_aux l = l:inits_aux (take' (length l -1) l)

--15)

tails' :: [a]->[[a]]
tails' [] = [[]]
tails' (h:t) = (h:t): tails' t

--16)

isPrefixOf' :: Eq a => [a]-> [a] -> Bool
isPrefixOf' [] [] = True
isPrefixOf' [] l = False
isPrefixOf' l [] = True
isPrefixOf' (h:t) (x:xs) = if (h==x) then isPrefixOf' t xs else False

--17)

isSuffixOf' :: Eq a => [a] -> [a] -> Bool
isSuffixOf' [] [] = True
isSuffixOf' [] l = False
isSuffixOf' l [] = False
isSuffixOf' l l1 = isPrefixOf' (reverse' l) (reverse' l1)

--18)

isSubsequenceOf2 :: Eq a => [a] -> [a] -> Bool
isSubsequenceOf2 [] [] = True 
isSubsequenceOf2 l  [] = False
isSubsequenceOf2 [] l  = True
isSubsequenceOf2 (h:t) (x:xs) = if (h==x) then isSubsequenceOf2 t xs else isSubsequenceOf2 (h:t) xs

--19)

elemIndices' :: Eq a => a -> [a] -> [Int]
elemIndices' x [] = []
elemIndices' x (h:t) = elemIndices_aux 0 x (h:t)

elemIndices_aux :: Eq a => Int -> a -> [a] -> [Int]
elemIndices_aux p x [] = []
elemIndices_aux p x (h:t) | x==h = p: elemIndices_aux (p+1) x t
                          |otherwise = elemIndices_aux (p+1) x t
 
--20)

nub' :: Eq a => [a] -> [a]
nub' [] = []
nub' (h:t) = h:(nub'(nub_aux h t))

nub_aux :: Eq a => a -> [a] -> [a]
nub_aux x [] = []
nub_aux x (h:t) = if (x==h) then nub_aux x t else h:nub_aux x t

--21)

delete' :: Eq a => a -> [a] -> [a]
delete' x [] = []
delete' x (h:t) = if (x==h) then t else h:delete' x t

--22)

remov_sec :: Eq a =>[a]->[a] -> [a]
remov_sec [] [] = []
remov_sec [] l = []
remov_sec l [] = l
remov_sec (h:t) (x:xs) = remov_sec (delete x (h:t)) xs

--23)
union' :: Eq a => [a] -> [a] -> [a]
union' [] [] = []
union' l [] = l
union' [] l = l
union' (h:t) (x:xs) = union' (insere' x (h:t)) xs

insere' :: Eq a => a -> [a] -> [a]
insere' x [] = [x]
insere' x (h:t) = if (elem' x (h:t)==False) then h:insere' x t else (h:t)

--24)
intersect' :: Eq a => [a] -> [a] -> [a]
intersect' [] [] = []
intersect' l [] = l
intersect' [] l = []
intersect' (h:t) (x:xs) = if (elem h (x:xs)==False) then intersect' t (x:xs) else h:intersect' t (x:xs)

--25)
insert' :: Ord a => a -> [a] -> [a]
insert' x [] = [x]
insert' x (h:t) = if (x<h) then x:h:t else h:insert' x t

--26)
unwords' :: [String] -> String
unwords' [] = []
unwords' [x] = x
unwords' (h:t) = h ++ " " ++ unwords' t

--27)
unlines' :: [String] -> String
unlines' [] = []
unlines' (h:t) = h ++ "\n" ++ unlines' t

--28)

pMaior :: Ord a => [a] -> Int
pMaior [x] = 0
pMaior (h:t) = pMaior_aux 0 (maximum (h:t)) (h:t)

pMaior_aux :: Eq a => Int -> a -> [a] -> Int
pMaior_aux p x (h:t) | x==h = p
                     | otherwise = pMaior_aux (p+1) x t

--29)

temRepetidos :: Eq a => [a] -> Bool
temRepetidos [] = False
temRepetidos [x] = False
temRepetidos (h:h1:t) = if (h==h1) then True else temRepetidos (h:t) 

--30)

algarismos :: [Char] -> [Char]
algarismos [] = []
algarismos (h:t) = if (isDigit' h == True) then h:algarismos t else algarismos t

isDigit' :: Char -> Bool
isDigit' x = if ord x >= ord '0' && ord x <= ord '9' then True else False

--31)

posImpares :: [a] -> [a]
posImpares [] = []
posImpares [x] = []
posImpares (h:h1:t) = h1:posImpares t

--32)

posPares :: [a] -> [a]
posPares [] = []
posPares [x] = [x]
posPares (h:h2:t) = h:posPares t

--33)

isSorted' :: Ord a => [a] -> Bool
isSorted' [] = True
isSorted' [x] = True
isSorted' (h:h1:t) = if (h>h1) then False else isSorted' (h1:t) 

--34)

iSort' :: Ord a => [a] -> [a]
iSort' [] = []
iSort' l = minimum l: iSort'(delete (minimum l) l)


--35)
menor :: String -> String -> Bool
menor [] [] = False
menor l1 l2 = if (contapal l1 < contapal l2) then True else False


contapal :: String -> Int
contapal [] = 0
contapal (h:t) = 1 + contapal t

--36)

elemMSet :: Eq a => a -> [(a,Int)] -> Bool
elemMSet x [] = False
elemMSet x ((h1,i1):t) = if (x==h1) then True else elemMSet x t 

--37)

lengthMSet :: [(a,Int)] -> Int
lengthMSet [] = 0
lengthMSet ((x,i):t) = i + lengthMSet t 

--38)
converteMSet :: [(a,Int)] -> [a]
converteMSet [] = []
converteMSet ((x,i):t) = (replicate i x) ++ (converteMSet t)

 --39)

insereMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
insereMSet x [] = [(x,1)]
insereMSet x ((x2,i):t) = if (x==x2) then (x2,i+1):t else (x2,i):insereMSet x t

--40)

removeMSet :: Eq a => a -> [(a,Int)] -> [(a,Int)]
removeMSet x [] = []
removeMSet x ((x2,i):t) = if (x==x2) then (x2,i-1):t else (x2,i):removeMSet x t

--41)

constroiMSet :: Ord a => [a] -> [(a,Int)]
constroiMSet [] = []
constroiMSet [h] = [(h,1)]
constroiMSet (h:t) = (h,numero):constroiMSet (filter (/=h) t)
               where numero=1+constroiMSet_aux h t

constroiMSet_aux ::Eq a => a -> [a] -> Int
constroiMSet_aux x [] = 0
constroiMSet_aux x (h:t) = if (x==h) then 1 + constroiMSet_aux x t else constroiMSet_aux x t


--42)
partitionEithers' :: [Either a b] -> ([a],[b])
partitionEithers' [] = ([],[])
partitionEithers' l = (lefts l , right l ) where
    right [] = []
    right ((Right x) :t) = x: right t
    right ((Left x) : t) = right t
--43)

catMaybes' :: [Maybe a] -> [a]
catMaybes' [] = []
catMaybes' (Just x:t) = x: catMaybes' t
catMaybes' (Nothing:t) = catMaybes' t

--44)
data Movimento = Norte | Sul | Este | Oeste
                  deriving Show

posicao' :: (Int,Int)->[Movimento]->(Int,Int)
posicao' (x,y) [] = (x,y)
posicao' (x,y) (Norte:t) = posicao' (x,y+1) t
posicao' (x,y) (Sul:t) = posicao' (x,y-1) t
posicao' (x,y) (Este:t) = posicao' (x+1,y) t
posicao' (x,y) (Oeste:t) = posicao' (x-1,y) t

--45)

caminho :: (Int,Int) -> (Int,Int) -> [Movimento]
caminho (x,y) (z,w) | x>z = Oeste: caminho (x-1,y) (z,w)
                    | x<z = Este: caminho (x+1,y) (z,w)
                    | y<w = Norte: caminho (x,y+1) (z,w)
                    | y>w = Sul: caminho (x,y-1) (z,w)

--46)

vertical :: [Movimento] -> Bool
vertical [] = True
vertical (Norte:t)=vertical t
vertical (Sul:t) = vertical t
vertical (Este:t) = False
vertical (Oeste:t) = False

--47)
data Posicao = Pos Int Int
               deriving Show


maisC :: [Posicao] -> Posicao
maisC [(Pos x y)] = Pos x y
maisC ((Pos x y):(Pos a b):t) = if (aux_C x y <= aux_C a b) then maisC ((Pos x y):t) else maisC ((Pos a b):t)

aux_C :: Int -> Int -> Int
aux_C x y = x^2 + y^2
--48)


vizinhos :: Posicao -> [Posicao] -> [Posicao]
vizinhos x [] = []
vizinhos (Pos x y) ((Pos w z):xs) | (x == (w-1)) || (x == (w + 1)) || (y == (z-1)) || (y== (z+1)) = (Pos w z ) : (vizinhos (Pos x y) xs)
                                  | otherwise = vizinhos (Pos x y) xs

--49)

mesmaOrdenada :: [Posicao] -> Bool
mesmaOrdenada [x] = True
mesmaOrdenada (Pos x y:Pos z w:t) = if (y==w) then mesmaOrdenada(Pos x y:t) else False

--50)

data Semaforo = Verde | Amarelo | Vermelho
              deriving Show


interseccaoOK :: [Semaforo] -> Bool
interseccaoOK [] = True
interseccaoOK l = (interseccaoOK_aux l) <=1

interseccaoOK_aux :: [Semaforo] -> Int
interseccaoOK_aux (Vermelho:t) = interseccaoOK_aux t
interseccaoOK_aux (Verde:t) =1+ interseccaoOK_aux t
interseccaoOK_aux (Amarelo:t)= 1+ interseccaoOK_aux t
