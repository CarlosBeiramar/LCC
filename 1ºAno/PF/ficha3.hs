--1

--a)

data Hora = H Int Int
          deriving Show

type Etapa = (Hora,Hora)
type Viagem = [Etapa]


etapa_true :: Etapa -> Bool
etapa_true (H x y, H z w) = if (x<z) then True else (if (x==z && y<w) then True else False)

--b)

viagem_valida :: Viagem -> Bool
viagem_valida [] = True
viagem_valida (((H x y,H z w)):t) = if (etapa_true (H x y, H z w) == True) then viagem_valida t else False

--c)

--d)

tempo_etapa :: Viagem -> Int
tempo_etapa [] = 0
tempo_etapa ((H x y, H z w):t) = abs (((60 * z + w) - (60 * x + y))+tempo_etapa t)

--e)

tempo_espera :: Viagem -> Int
tempo_espera [] = 0
tempo_espera ((H x y,H z w):(H e r,H c u):t) = ((60 * e + r)-(60 * z +w)) + tempo_espera t

--f)

tempo_total :: Viagem -> Int
tempo_total [] = 0 
tempo_total l = tempo_etapa l  + tempo_espera l


data Ponto = Cartesiano Double Double | Polar Double Double
            deriving (Show,Eq)

type Poligonal = [Ponto]

--2)

--a)
distancia_pontos :: Ponto -> Ponto -> Double
distancia_pontos (Cartesiano x y) (Cartesiano w z) = sqrt (((y-x)^2) + ((z-w) ^2))

compr_Polignal :: Poligonal -> Double
compr_Polignal [] = 0
compr_Polignal [Cartesiano x y] = 0
compr_Polignal ((Cartesiano x y):(Cartesiano w z):t) =numero + compr_Polignal ((Cartesiano w z):t) 
                                                        where numero =  distancia_pontos (Cartesiano x y) (Cartesiano w z)
--b)
compara_ponto :: Ponto -> Ponto -> Bool
compara_ponto (Cartesiano x y) (Cartesiano w z) = if (x==w && y==z) then True else False

ultimo :: Poligonal -> Ponto
ultimo [x] = x
ultimo l = head(reverse l)

linha_fechada :: Poligonal -> Bool
linha_fechada [] = False
linha_fechada ((Cartesiano x y):t) = if (compara_ponto (Cartesiano x y) (ultimo ((Cartesiano x y):t)) == True) then True else False

--c)
--d)
--e)
mover :: Poligonal -> Ponto -> Poligonal
mover [] (Cartesiano x y) = [Cartesiano x y]
mover ((Cartesiano z w):t) (Cartesiano x y) = ((Cartesiano x y):t)

--f)

zoom :: Double -> Poligonal -> Poligonal
zoom x [] = []
zoom d ((Cartesiano x y):t) = (Cartesiano x y): mult_ponto d t

mult_ponto :: Double -> Poligonal -> Poligonal
mult_ponto x [] = []
mult_ponto d ((Cartesiano x y):t) = (Cartesiano (x*d) (y*d)):mult_ponto d t

--3.

data Contacto = Casa Integer
              | Trab Integer
              | Tlm Integer
              | Email String
              deriving Show


--type Nome = String
type Agenda = [(Nome, [Contacto])]


--a)

acrescEmail :: Nome -> String -> Agenda -> Agenda
acrescEmail x e [] = [(x,[Email e])]
acrescEmail n e ((x,y):t) = if (n==x) then (x,[Email e]):t else acrescEmail n e t

--b)

verEmails :: Nome -> Agenda -> Maybe [String]
verEmails n [] = Nothing
verEmails n ((x,y):t) = if (n==x) then Just (aux y) else verEmails n t

aux :: [Contacto] -> [String]
aux [] = []
aux ((Email x):t) = x:aux t
aux (x:t) = aux t

--c)

consTelefs :: [Contacto] -> [Integer] 
consTelefs [] = []
consTelefs l = aux1 l ++ aux2 l

aux1 :: [Contacto] -> [Integer]
aux1 [] = []
aux1 ((Trab x):t) = x: aux1 t

aux2 :: [Contacto] -> [Integer]
aux2 [] = []
aux2 ((Tlm x):t) = x:aux2 t

--d)

casa :: Nome -> Agenda -> Maybe Integer
casa n [] = Nothing
casa n ((x,y):t) = if (n==x) then Just (aux3 y) else casa n t

aux3 :: [Contacto] -> Integer
aux3 [] = 0
aux3 ((Tlm x):t) = x
aux3 (x:t) = aux3 t

--4.

type Dia = Int
type Mes = Int
type Ano = Int
type Nome = String

data Data = D Dia Mes Ano
          deriving Show

type TabDN = [(Nome,Data)]


--a)

procura :: Nome -> TabDN -> Maybe Data
procura n [] = Nothing
procura n ((n1,d1):t) = if (n==n1) then Just (d1) else procura n t

--b)

idade :: Data -> Nome -> TabDN -> Maybe Int
idade (D x y z) n [] = Nothing
idade (D x y z) n ((n1,(D r q u)):t) = if (n==n1) then Just (z - u) else idade (D x y z) n t

--c)

anterior :: Data -> Data -> Bool
anterior (D d m a) (D d1 m1 a1) = if (a<a1) then True else (if (a==a1 && m<m1) then True else (if (a==a1 && m==m1 && d<d1) then True else False))

--d)

ordena :: TabDN -> TabDN
ordena [] = []
ordena (h:t) = insere h (ordena t)

insere :: (Nome,Data) -> TabDN -> TabDN
insere (n,d) [] = [(n,d)]
insere (n,d) ((n1,d1):t) = if (anterior d d1 == True) then (n,d):(n1,d1):t else (n1,d1): (insere (n,d) t)

--e)

--5)

--a)

data Movimento = Credito Float | Debito Float
                 deriving Show

--data Data = D Int Int Int
--            deriving Show

data Extracto = Ext Float [(Data, String, Movimento)]
                deriving Show


extValor :: Extracto -> Float -> [Movimento]
extValor (Ext x []) y = []
extValor (Ext x ((w,z,Credito y):t)) f = if (y>f) then (Credito y):extValor (Ext x t) f else extValor (Ext x t) f    
extValor (Ext x ((w,z,Debito y):t)) f = if (y>f) then (Debito y):extValor (Ext x t) f else extValor (Ext x t) f

--b)

filtro :: Extracto -> [String] -> [(Data,Movimento)]
filtro (Ext x []) l = []
filtro (Ext x ((w,z,y):t)) [] = []
filtro (Ext x ((w,z,y):t)) l | elem z l = (w,y):filtro (Ext x t) l
                           | otherwise = filtro (Ext x t) l


--c)

creDeb :: Extracto -> (Float,Float)
creDeb (Ext x []) = (0,0)
creDeb (Ext x l) = (credito (Ext x l),debito (Ext x l))

credito :: Extracto -> Float
credito (Ext x []) = 0
credito (Ext x ((w,z,Credito y):t)) = y + credito (Ext x t)
credito (Ext x ((w,z,Debito y):t)) = 0 + credito (Ext x t)

debito :: Extracto -> Float
debito (Ext x []) = 0
debito (Ext x ((w,z,Debito y):t)) = y+ debito (Ext x t)
debito (Ext x ((w,z,Credito y):t)) = 0 + debito (Ext x t)

--d

saldo :: Extracto -> Float
saldo (Ext x []) = 0
saldo (Ext x ((w,z,y):t)) = x + credito (Ext x ((w,z,y):t)) - debito (Ext x ((w,z,y):t))










