'''

Implemente uma função que calcula o preço mais barato para fazer uma viagem de
autocarro entre duas cidades. A função recebe (para além das duas cidades) uma
lista de rotas de autocarro, onde cada rota é uma sequência de cidades por onde
passa o autocarro, intercalada com o custo para viajar entre cada par de cidades.
Assuma que cada rota funciona nos dois sentidos.

'''
def build(arestas):
    adj = {}
    for o,d,p in arestas:
        if o not in adj:
            adj[o] = {}
        if d not in adj:
            adj[d] = {}
        adj[o][d] = p
        adj[d][o] = p
    return adj
    
def dijkstra(adj,o):
    pai = {}
    dist = {}
    dist[o] = 0
    orla = {o}
    while orla:
        v = min(orla,key=lambda x:dist[x])
        orla.remove(v)
        for d in adj[v]:
            if d not in dist:
                orla.add(d)
                dist[d] = float("inf")
            if dist[v] + adj[v][d] < dist[d]:
                pai[d] = v
                dist[d] = dist[v] + adj[v][d]
    return dist


def viagem(rotas,o,d):
    adj = []
    dic = {}
    for i in rotas:
        for j in range(0,len(i)):
            if (isinstance(i[j],str) and j+2<=len(i)):
                adj.append((i[j],i[j+2],i[j+1]))
                adj.append((i[j+2],i[j],i[j+1]))
    dic = build(adj)
    dic2 = dijkstra(dic,o)
    for k,v in dic2.items():
        if k == d:
            minimo = v
    return minimo