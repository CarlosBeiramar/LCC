# -*- Coding: UTF-8 -*-
#coding: utf-8


def fib(n):
    if n<2:
        return 1
    else:
        return fib(n-1)+fib(n-2)


## fib2, coloca num dicionario todos os valores de fibonacci desde 0 ate n

def fib2(n):
    return aux(n,{})

def aux(n,m):
    if n in m:
        return m[n]
    if n<2:
        m[n]=1
    else:
        m[n] = aux(n-1,m)+aux(n-2,m)
    return m[n]


# fibonacci com programacao dinamica, inserindo sempre no dicionario até n
def fib3(n):
    m={}
    m[0]=1
    m[1]=1
    for i in range(2,n+1):
        m[i] = m[i-1]+m[i-2]
    return m[n]



def trocar(valor,moedas):
    if valor == 0:
        return 0
    r=float("inf")
    for m in moedas:
        if m<= valor:
            r=min(r,1+trocar(valor-m,moedas))
    return r

## constroi um dicionario até q esteja na chave o valor e na key desse valor vão estar
## o numeros de moedas q é preciso utilizar para trocar

def trocar2 (valor,moedas):
    d = {}
    d[0] = 0
    for v in range(1,valor+1):
        r=float("inf")
        for m in moedas:
            if m <= v:
                r = min(r,1+d[v-m])
        d[v] = r
        if v>= max(moedas):
            del d[v-max(moedas)]
    return d[valor]

def dist(a,b):
    return aux1(a,len(a),b,len(b),{})

def aux1(a,i,b,j,m):
    if (i,j) in m:
        return m[(i,j)]
    if i == 0:
        m[(i,j)] = j
    elif j == 0:
        m[(i,j)] = i
    elif a[i-1] == b[j-1]:
        m[(i,j)] = aux1(a,i-1,b,j-1,m)
    else:
        m[(i,j)] = min(1+aux1(a,i,b,j-1,m),
                    1+aux1(a,i-1,b,j,m),
                    1+aux1(a,i-1,b,j-1,m))
    return m[(i,j)]

a = 'invention'
b = 'execution'

print(dist(a,b))