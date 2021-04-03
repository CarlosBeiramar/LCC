'''

O objectivo deste problema é determinar o tamanho do maior continente de um planeta.
Considera-se que pertencem ao mesmo continente todos os países com ligação entre si por terra. 
Irá receber uma descrição de um planeta, que consiste numa lista de fronteiras, onde cada fronteira
é uma lista de países que são vizinhos entre si. 
A função deverá devolver o tamanho do maior continente.

'''

def dfs(adj,o):
    return dfs_aux(adj,o,set(),{})

def dfs_aux(adj,o,vis,pai):
    vis.add(o)
    for d in adj[o]:
        if d not in vis:
            pai[d] = o
            dfs_aux(adj,d,vis,pai)
    return len(vis)

def build(arestas):
    adj = {}
    for o,d in arestas:
        if o not in adj:
            adj[o] = set()
        if d not in adj:
            adj[d] = set()
        adj[o].add(d)
        adj[d].add(o)
    return adj

def maior (vizinhos):
    adj={}
    lista2=[]
    for lista in vizinhos:
        adj[lista[0]]=set()
        for i in range(1,len(lista)):
            adj[lista[0]].add(lista[i])
    for k,v in adj.items():
        for key in v:
            lista2.append((k,key))
    aux = 0
    maximo = 0
    dic = build(lista2)
    for k,v in dic.items():
        aux = dfs(dic,k)
        if aux>maximo:
            maximo=aux
    return maximo
