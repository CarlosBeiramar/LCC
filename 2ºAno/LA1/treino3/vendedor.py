produtos = [("Verde",4,12),("Azul",2,2),("Cinzento",2,1),("Laranja",1,1),("Amarelo",10,4)]
capacidade = 15

def trocar(capacidade,produtos):
    d = {}
    d[0] = 0
    n=""
    cores_peso={}
    for x in produtos:
        cores_peso[x[0]] = x[1]
    aux = {}
    aux[0] = []
    pesos = [x[2] for x in produtos]
    for v in range(1,capacidade+1):
        r=0
        for nome,valor,peso in produtos:
            if peso <= v:
                if valor+d[v-peso]>r:
                    n=nome
                r = max(r,valor+d[v-peso])
        d[v] = r
        aux[r] = [n]
        if v >= max(pesos):
            del d[v-max(pesos)]
    lucro = d[capacidade]
    lista = []
    while lucro>0:
        res = aux[lucro][0]
        lista.append(res)
        lucro-=cores_peso[res]
    lista= sorted(lista)
    return d[capacidade],lista

print(trocar(capacidade,produtos))