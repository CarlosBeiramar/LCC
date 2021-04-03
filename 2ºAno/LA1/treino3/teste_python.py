# -*- coding: utf-8 -*-
import math

##mapa = [(0,2,1,2),(1,1,2,1),(0,3,0,4)]
#mapa = [(0,0,1,1),(3,0,4,0),(3,2,3,3),(3,3,4,3)]
#mapa = [(3,0,5,0),(2,2,2,3),(0,3,0,5),(4,3,5,5),(0,5,2,5)]
mapa = [(-1,-1,-1,-2),(-3,-1,-5,-1),(-7,-1,-7,1),(4,3,5,5),(0,1,0,2),(-1,3,1,3),(-3,3,-2,3)]
#mapa = [(-1,3,1,3),(-2,2,-2,3)]
posicao_inicial = (5,0)
##dic_predios coloca num dicionario a coordenada inferior esquerda como key
##e coloca a coordenada superior direita como value

def dic_predios(mapa):
    dic={}
    lista = []
    for coordenadas in mapa:
        if (coordenadas[0],coordenadas[1]) not in lista:
            dic[(coordenadas[0],coordenadas[1])]=[]
            dic[(coordenadas[0],coordenadas[1])].append((coordenadas[2],coordenadas[3]))
            lista.append((coordenadas[2],coordenadas[3]))
        else:
            for k,v in dic.items():
                for x in v:
                    if (coordenadas[0],coordenadas[1]) == x:
                        v.append((coordenadas[2],coordenadas[3]))
    return dic


#completa predios coloca todas a posicoes dos predios numa lista nas suas 
#respetivas keys(coordenada inferior esquerda)
# Funciona para todos os casos.

def completa_predios(mapa):
    dic = dic_predios(mapa)
    predios = {}
    for k,v in dic.items():
        predios[k] = set()
        k_anterior = k
        for x in v:
            x_chave = k[0]
            y_chave = k[1]
            if x_chave>=0:
                if x_chave < x[0]:
                    while x_chave < x[0]:
                        x_chave +=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x_chave,x[1])!=(x_chave,y_chave):
                            predios[k_anterior].add((x_chave,x[1]))
                elif x_chave > x[0]:
                    while x_chave > x[0]:
                        x_chave -=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x_chave,x[1])!=(x_chave,y_chave):
                            predios[k_anterior].add((x_chave,x[1]))   
            if x_chave<=0:
                if x_chave > x[0]:
                    while x_chave > x[0]:
                        x_chave-=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x_chave,x[1])!=(x_chave,y_chave):
                            predios[k_anterior].add((x_chave,x[1]))
                if x_chave < x[0]:
                    while x_chave < x[0]:
                        x_chave+=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x_chave,x[1])!=(x_chave,y_chave):
                            predios[k_anterior].add((x_chave,x[1]))
            if y_chave>=0:
                x_chave=k[0]
                if y_chave < x[1]:
                    while y_chave < x[1]:
                        y_chave+=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x[0],y_chave)!=(x_chave,y_chave):
                            predios[k_anterior].add((x[0],y_chave))
                elif y_chave > x[1]:
                    while y_chave > x[1]:
                        y_chave-=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x[0],y_chave)!=(x_chave,y_chave):
                            predios[k_anterior].add((x[0],y_chave))
            if y_chave<=0:
                x_chave=k[0]
                if y_chave > x[1]:
                    while y_chave > x[1]:
                        y_chave-=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x[0],y_chave)!=(x_chave,y_chave):
                            predios[k_anterior].add((x[0],y_chave))
                elif y_chave < x[1]:
                    while y_chave < x[1]:
                        y_chave+=1
                        predios[k_anterior].add((x_chave,y_chave))
                        if (x[0],y_chave)!=(x_chave,y_chave):
                            predios[k_anterior].add((x[0],y_chave))
            k = (x[0],x[1])
    #verificar se se intercetam
    return predios

def adjacentes (mapa,posicao_inicial):
    dic = completa_predios(mapa)
    bloqueados = []
    adj = {}
    ## todas as coordenadas dos predios vao para a lista bloqueados
    for k,v in dic.items():
        bloqueados.append(k)
        for x in v:
            bloqueados.append(x)
    ## a partir da lista bloqueados vamos buscar os adjacentes
    for k in bloqueados:
        adj[k]=[]
        x = k[0]
        y = k[1]
        if(x+1,y) not in bloqueados:
            adj[k].append((x+1,y))
        if(x-1,y) not in bloqueados:
            adj[k].append((x-1,y))
        if(x,y+1) not in bloqueados:
            adj[k].append((x,y+1))
        if(x,y-1) not in bloqueados:
            adj[k].append((x,y-1))
    bloqueados.append(posicao_inicial)
    return adj,bloqueados


def intersetam2(mapa,posicao_inicial):
    bloqueados = adjacentes(mapa,posicao_inicial)[1]
    aux = completa_predios(mapa)
    predios = completa_predios(mapa)

    for k,v in aux.items():
        if (k[0],k[1]+1) in bloqueados and (k[0],k[1]+1) not in v and k in predios.keys():
            if (k[0],k[1]+1)!=posicao_inicial:
                for k1,v1 in aux.items():
                    if(k1[0],k1[1])==(k[0],k[1]+1):
                        predios[k].add(k1)
                        for x in v1:
                            predios[k].add(x)
                        if k1 in predios.keys():
                            del predios[k1]
                    else:
                        for x in v1:
                            if(x[0],x[1])==(k[0],k[1]+1):
                                predios[k1].add(k)
                                for y in v:
                                    predios[k1].add(y)
                                if k in predios.keys():
                                    del predios[k]
        if (k[0],k[1]-1) in bloqueados and (k[0],k[1]-1) not in v and k in predios.keys():
            if (k[0],k[1]-1)!=posicao_inicial:
                for k1,v1 in aux.items():
                    if (k1[0],k1[1])==(k[0],k[1]-1):
                        predios[k1].add(k)
                        for x in v:
                            predios[k1].add(x)
                        if k in predios.keys():
                            del predios[k]
                    else:
                        for x in v1:
                            if(x[0],x[1])==(k[0],k[1]-1):
                                predios[k1].add(k)
                                for y in v:
                                    predios[k1].add(y)
                                if k in predios.keys():
                                    del predios[k]
        if(k[0]+1,k[1]) in bloqueados and (k[0]+1,k[1]) not in v and k in predios.keys():
            if (k[0]+1,k[1])!=posicao_inicial:
                for k1,v1 in aux.items():
                    if (k1[0],k1[1])==(k[0]+1,k[1]):
                        predios[k].add(k1)
                        for x in v1:
                            predios[k].add(x)
                        if k1 in predios.keys():
                            del predios[k1]
                    else:
                        for x in v1:
                            if (x[0],x[1])==(k[0]+1,k[1]):
                                predios[k1].add(k)
                                for y in v:
                                    predios[k1].add(y)
                                if k in predios.keys():
                                    del predios[k]
        if (k[0]-1,k[1]) in bloqueados and (k[0]-1,k[1]) not in v and k in predios.keys():
            if (k[0]-1,k[1])!=posicao_inicial:
                for k1,v1 in aux.items():
                    if (k1[0],k1[1])==(k[0]-1,k[1]):
                        predios[k1].add(k)
                        for x in v:
                            predios[k1].add(x)
                        if k in predios.keys():
                            del predios[k]
                    else:
                        for x in v1:
                            if (x[0],x[1])==(k[0]-1,k[1]):
                                predios[k1].add(k)
                                for x in v:
                                    predios[k1].add(x)
                                if k in predios.keys():
                                    del predios[k]
    return predios

# devolve as coordenadas máximas e as coordenadas mínimas do mapa

def maximos_minimos(mapa):
    maximoX = float("-Inf") 
    maximoY = float("-Inf")
    minimoX = float("Inf")
    minimoY = float("Inf")
   
    for x in mapa:
        aux_maxX = max(x[0],x[2])
        aux_minX = min(x[0],x[2])
        aux_minY = min(x[1],x[3])
        aux_maxY = max(x[1],x[3])
        if aux_maxX > maximoX:
            maximoX = aux_maxX
        if aux_minX < minimoX:
            minimoX = aux_minX
        if aux_maxY > maximoY:
            maximoY = aux_maxY
        if aux_minY < minimoY:
            minimoY = aux_minY
    
    return maximoX,maximoY,minimoX,minimoY

# constroi o mapa entre as duas coordenadas anteriores, ou seja
# poe na lista todas as coordenada livres, q nao estao bloqueadas.

def constroi_mapa(mapa,posicao_inicial):
    lista = []
    bloqueados = adjacentes(mapa,posicao_inicial)[1]
    maximoX = maximos_minimos(mapa)[0]
    maximoX = max(maximoX,posicao_inicial[0])
    maximoX +=2
    minimoX = maximos_minimos(mapa)[2]
    minimoX = min(minimoX,posicao_inicial[0])
    minimoX -=2
    maximoY = maximos_minimos(mapa)[1]
    maximoY = max(maximoY,posicao_inicial[1])
    maximoX +=2
    minimoY = maximos_minimos(mapa)[3]
    minimoY = min(minimoY,posicao_inicial[1])
    minimoY -=2

    y=minimoY
    while y <= maximoY:
        x=minimoX
        while x <= maximoX:
            if (x,y) not in bloqueados:
                lista.append((x,y))
            x+=1
        y+=1
    return lista

def build(mapa,posicao_inicial):
    lista = constroi_mapa(mapa,posicao_inicial)
    lista.append(posicao_inicial) # inserir a posicao inicial pq vai dar jeito na bfs
    adj = {}
    for x in lista:
        adj[x]=set()
        for y in lista:
            if (y[0],y[1])==(x[0]+1,x[1]):
                adj[x].add(y)
            if (y[0],y[1])==(x[0]-1,x[1]):
                adj[x].add(y)
            if (y[0],y[1])==(x[0],x[1]+1):
                adj[x].add(y)
            if (y[0],y[1])==(x[0],x[1]-1):
                adj[x].add(y)
    return adj

def bfs(mapa,posicao_inicial):
    pai = {}
    vis = {posicao_inicial}
    bloqueados= adjacentes(mapa,posicao_inicial)[1]
    adj = build(mapa,posicao_inicial)
    queue = [posicao_inicial]
    while queue:
        v = queue.pop(0)
        if v in adj.keys():
            for d in adj[v]:
                if d not in vis:
                    vis.add(d)
                    pai[d] = v
                    queue.append(d)
    return pai

def caminho(adj,o,d):
    pai = bfs(adj,o)
    caminho = [d]
    while d in pai:
        d = pai[d]
        caminho.insert(0,d)
    lista = []
    lista.append(caminho[0])
    lista.append(len(caminho)-1)
    lista.append(caminho[-1])
    return lista

def rota(mapa,posicao_inicial):
    entregas = len(mapa)-1
    predios = intersetam2(mapa,posicao_inicial)
    adj= adjacentes(mapa,posicao_inicial)[0]
    coordenadas_mapa = constroi_mapa(mapa,posicao_inicial)
    lista_final = [posicao_inicial]
    if entregas==0:
        return []
    else:
        while entregas >0:
            maior_area=0
            new=[]
            custo=[]
            aux=[]
            lista=[]
            for k,v in predios.items():
                a = len(v)+1
                if a>maior_area:
                    maior_area =a
                    maior_predio=k
            for k,v in predios.items():
                if len(v) == maior_area-1:
                    aux.append(k)
                    for x in v:
                        aux.append(x)
            for k,v in adj.items():
                for x in aux:
                    if x==k:
                        for y in v:
                            if y in coordenadas_mapa:
                                lista.append(y)
            for i in lista:
                new = caminho(mapa,posicao_inicial,i)
                if new[1]!=0:
                    custo.append(caminho(mapa,posicao_inicial,i))
            custo.sort(key=lambda k:k[2][1])
            custo.sort(key=lambda k:k[2][0])
            custo.sort(key=lambda k:k[1])
            lista_final.append(custo[0][1])
            posicao_inicial = (custo[0][2])
            lista_final.append(posicao_inicial)
            del predios[maior_predio]
            entregas-=1
    return lista_final

print(rota(mapa,posicao_inicial))