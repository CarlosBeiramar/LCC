lista = [-2,1,-3,4,-1,2,1,-5,4]

def maxsoma(lista):
    res=0
    maximo = 0
    for x in lista:
        maximo = max(0,maximo+x)
        res = max(res,maximo)
    return res


maxsoma(lista)