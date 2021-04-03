from itertools import combinations_with_replacement
listas = [[8,1,7,3,3,6,3,5],[1,1,1,2,3,1,2],[3,3,3,3]]
soma=10

def validas(soma,listas):
    res = []
    for lista in listas:
        for x in range(1,len(lista)+1):
            y=set([sum(comb) for comb in combinations_with_replacement(lista,x)])
            if soma in y:
                res.append(lista)
                break
            y.clear()
    return res