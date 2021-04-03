import Data.List

--1

insert' :: Ord a => a -> [a] -> [a]
insert' x [] = [x]
insert' x (h:t) |x<h = x:h:t
                |otherwise = h:insert' x t

--2

catMaybes :: [Maybe a] -> [a]
catMaybes [] = []
catMaybes ((Nothing):t) = catMaybes t
catMaybes ((Just h):t) = h: catMaybes t

--3)

data Exp a = Const a
         | Var String
         | Mais (Exp a) (Exp a)
         | Mult (Exp a) (Exp a)



expande :: (Show a) => Exp a -> String
expande (Const a) = show a
expande (Var x) = x
expande (Mais x y) = "(" ++ expande x ++ "+" ++ expande y ++ ")"
expande (Mult x y) = "(" ++ expande x ++ "*" ++ expande y ++ ")" 

instance (Show a) => Show (Exp a) where
      show x = expande x

--4)

sortOn :: Ord b => (a -> b) -> [a] -> [a]
sortOn f [] = []
sortOn f (h:t) = insere h (sortOn f t)
              where insere h [] = [h]
                    insere h (x:xs) | f h <= f x = h:x:xs
                                    |otherwise = x:insere h xs
--5)

--a)

amplitude :: [Int] -> Int
amplitude [] = 0
amplitude (h:t) = amplitudeaux (h:t)
          where 
             amplitudeaux l = maximum l - minimum l

--b)

minimos :: Int -> [Int] -> [Int]
minimos x [] = []
minimos 2 l = []
minimos x l = minimum l: minimos (x+1) (delete (minimum l) l)  
--minimos 0 l

delete' :: [Int] -> [Int] -> [Int]
delete' [] [] = []
delete' [] l = l
delete' l [] = []
delete' (h:t) (x:xs) |h==x = delete' t xs
                     |otherwise = x:delete' (h:t) xs

parte :: [Int] -> ([Int],[Int])
parte [] = ([],[])
parte (h:t) = (minimos 0 (h:t),(delete' (minimos 0 (h:t)) (h:t)))

--6)

data Imagem = Quadrado Int
            | Mover (Int,Int) Imagem
            | Juntar [Imagem]


conta :: Imagem -> Int
conta (Quadrado x) = 1
conta (Mover (x,y) l) = conta l
conta (Juntar []) = 0
conta (Juntar (h:t)) = sum(map conta (h:t))


















