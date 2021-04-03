# -*- coding: utf-8 -*-


exemplo = [("OPO","LIS"),("OPO","FAO"),
 ("LIS","FAO"),("MAD","OPO"),
 ("LIS","LON"),("FRA","OPO"),
 ("LIS","NRT"),("LON","NRT"),
 ("LON","FRA"),("LIS","FRA")]

exemplo2 = [("OPO","LIS",100), ("OPO","FAO",150),
 ("LIS","FAO",100), ("MAD","OPO",200),
 ("LIS","LON",300), ("FRA","OPO",300),
 ("LIS","NRT",1200),("LON","NRT",800),
 ("LON","FRA",200), ("LIS","FRA",150)]


## cria um dicionario, percorre o exemplo e verifica se os elementos dos pares
## estao no dicionario, se estiverem adiciona os nos set de cada key
## caso contrario cria uma key com esses elementos

def build (exemplo):
    adj = {}
    for o,d in exemplo:
        if o not in adj:
            adj[o] = set()
        if d not in adj:
            adj[d] = set()
        adj[o].add(d)
        adj[d].add(o)
    ##print(adj)
    return adj


def dfs(adj,o):
    return dfs_aux(adj,o,set(),{})

def dfs_aux(adj,o,vis,pai):
    vis.add(o)
    for d in adj[o]:
        if d not in vis:
            pai[d] = o
            dfs_aux(adj,d,vis,pai)
    print(pai)
    return pai


## o dicionario pai vai devolver todos os caminhos possiveis a partir de uma certa cidade

def bfs(adj,o):
    pai ={}
    vis = {o}
    queue = [o]
    while queue:
        v = queue.pop(0)
        for d in adj[v]:
            if d not in vis:
                vis.add(d)
                pai[d]=v
                queue.append(d)
    return pai

print(bfs(build(exemplo),"MAD"))

##bfs(build(exemplo),"MAD")

## caminho mais curto para uma certa viagem

def caminho(adj,o,d):
    pai = bfs(adj,o)
    caminho = [d]
    while d in pai:
        d=pai[d]
        caminho.insert(0,d)
    return caminho



## vai criar um dicionario dentro de outro dicionario com tds os caminhos possiveis
## e os seus pesos

def build2 (exemplo2):
    adj = {}
    for o,d,p in exemplo2:
        if o not in adj:
            adj[o]={}
        if d not in adj:
            adj[d]={}
        adj[o][d]=p
        adj[d][o]=p
    return adj



# devolve um dicionario q tem na key as cidades e nos value o peso desde a cidade
# origem que é passada por argumento

def dijkstra (adj,o):
    pai = {}
    dist = {}
    dist[o] = 0
    orla = {o}
    while orla:
        v = min(orla,key= lambda x:dist[x])
        orla.remove(v)
        for d in adj[v]:
            if d not in dist:
                orla.add(d)
                dist[d] = float("inf")
            if dist[v] + adj[v][d] < dist[d]:
                pai[d] = v
                dist[d] = dist[v] + adj[v][d]
    return pai


'''  cria um dicionario de dicionarios organizado com as cidades nas keys
e cada key com um set com o custo para cada cidade.
'''

def fw(adj):
    dist = {}
    for o in adj:
        dist[o] = {}
        for d in adj:
            if o == d:
                dist[o][d] = 0
            elif d in adj[o]:
                dist[o][d] = adj[o][d]
            else:
                dist[o][d] = float("inf")
    for k in adj:
        for o in adj:
            for d in adj:
                if dist[o][k] + dist[k][d] < dist[o][d]:
                    dist[o][d] = dist[o][k] + dist[k][d]
    print(dist)
    return dist
