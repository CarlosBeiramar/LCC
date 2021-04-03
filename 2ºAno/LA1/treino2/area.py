mapa = ["..*..",
                ".*.*.",
                "*....",
                ".*.*.",
                "..*.."]
    
def ligacoes(mapa):
    dic={}
    for x in range(0,len(mapa)):
        for y in range(1,len(mapa)):
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
            if d not in vis and mapa[d[0]][d[1]]=='.':
                vis.add(d)
                pai[d] = v
                queue.append(d)
    return len(vis)

def area(p,mapa):
    d = (p[0]-1,p[0]-1)
    dic = ligacoes(mapa)
    vis = bfs(dic,d,mapa)
    return vis


area((3,2),mapa)