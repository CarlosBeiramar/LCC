--1
--a)
intersperse :: a -> [a] -> [a] 
intersperse x [] = []
intersperse x (h:t) = h:x: intersperse x t

--b)

inits2:: [a] -> [[a]]
inits2 [] = [[]]
inits2 l = reverse (inits2Aux2 l) where
	inits2Aux [x] = []
	inits2Aux (x:xs) = x : inits2Aux xs 
	inits2Aux2 [] = [[]]
	inits2Aux2 l = (l:(inits2Aux2 (inits2Aux l)))

--2

type Aluno = (Numero,Nome,Classificacao)
type Numero = Int
type Nome = String
data Classificacao = Aprov Int | Rep | Faltou
data Turma = Vazia | Nodo Aluno Turma Turma

--a)

inscNum :: Numero -> Turma -> Bool
inscNum x Vazia = False
inscNum x (Nodo (n,_,_) y z) | x==n = True
                             | x<n = inscNum x y
                             | x>n = inscNum x z

--b)

aprovAv :: Turma -> Float
aprovAv Vazia = 0
aprovAv l = quantosaprovados l / comprimentoarvore l

quantosaprovados :: Turma -> Float
quantosaprovados Vazia = 0
quantosaprovados (Nodo (_,_,Aprov x) y z) = 1 + quantosaprovados y + quantosaprovados z
quantosaprovados (Nodo (_,_,Rep) y z) = quantosaprovados y + quantosaprovados z
quantosaprovados (Nodo (_,_,Faltou) y z) = quantosaprovados y + quantosaprovados z
 
comprimentoarvore :: Turma -> Float
comprimentoarvore Vazia = 0
comprimentoarvore (Nodo x y z) = 1 + comprimentoarvore y + comprimentoarvore z

--c)

melhorNota :: Turma -> Maybe Int
melhorNota Vazia = Nothing
melhorNota l = Just (maximum (notas (listarvore l)))


listarvore :: Turma -> [Classificacao]
listarvore Vazia = []
listarvore (Nodo (_,_,c) x y) = c : (listarvore x ++ listarvore y)

notas :: [Classificacao] -> [Int]
notas [] = []
notas (Aprov x:t) = x : notas t
notas (Rep:t) = notas t
notas (Faltou:t) = notas t

type Polinomio = [Coeficiente]
type Coeficiente = Float

--3

--a)

adicaoPoli :: Polinomio -> Polinomio -> Polinomio
adicaoPoli [] [] = []
adicaoPoli [] l = l
adicaoPoli l [] = l
adicaoPoli (h:t) (x:y) = h+x : adicaoPoli t y







