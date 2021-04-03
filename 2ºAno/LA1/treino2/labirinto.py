mapa = ['   ',
        ' # ',
        '   ']
    
def ligacoes(mapa):
    dic={}
    for x in range(0,len(mapa)):
        for y in range(0,len(mapa)):
            dic[(x,y)] = set()
            if x-1>=0:
                dic[(x,y)].add((x-1,y))
            if x+1<len(mapa):
                dic[(x,y)].add((x+1,y))
            if y+1 < len(mapa):
                dic[(x,y)].add((x,y+1))
            if y-1 >= 0:
                dic[(x,y)].add((x,y-1))
    return dic

def bfs(adj,o,mapa):
    pai = {}
    vis = {o}
    queue = [o]
    while queue:
        v = queue.pop(0)
        for d in adj[v]:
           if d not in vis and mapa[d[0]][d[1]]==" ":
                vis.add(d)
                pai[d] = v
                queue.append(d)
    return pai


def caminho_curto(adj,o,d,mapa):
    pai = bfs(adj,o,mapa)
    caminho = [d]
    lista = []
    while d in pai:
        a=pai[d]
        if d[0] == a[0] and d[1]==a[1]+1:
            lista.append('E')
        elif d[0]==a[0] and d[1]==a[1]-1:
            lista.append('O')
        elif d[0]==a[0]+1 and d[1]==a[1]:
            lista.append('S')
        elif d[0]==a[0]-1 and d[1]==a[1]:
            lista.append('N')
        d = pai[d]
        caminho.insert(0,d)
    return lista

def caminho2(mapa):
    dic = ligacoes(mapa)
    lista = caminho_curto(dic,(0,0),(len(mapa)-1,len(mapa)-1),mapa)
    lista2 = lista[::-1]
    res=""
    for x in lista2:
        res+=x
    return res
caminho2(mapa)
