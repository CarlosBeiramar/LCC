import itertools

palavras = ["o","oga","ga","gato","gatom","mia","eava","ava","e","a","va","vaca","mu","muge"]
frase="ogatomiaeavacamuge"

def dist(a,b): 
    m = {}
    for j in range(len(b)+1):
        m[(0,j)] = j
    for i in range(len(a)+1):
        m[(i,0)] = i
    for j in range(1,len(b)+1):
        for i in range(1,len(a)+1):
            if a[i-1] == b[j-1]:
                m[(i,j)] = m[(i-1,j-1)]
            else:
                m[(i,j)] = min(1+m[(i,j-1)],
                    1+m[(i-1,j)],
                    1+m[(i-1,j-1)])
        for i in range(0,len(a)+1):
            del m[(i,j-1)]
    return m[(len(a),len(b))]

def estaca(frase,palavras):
    res=[]
    while frase:
        lista=[]
        aux=[]
        for x in palavras:
            if x[0]==frase[0]:
                lista.append(x)
        for z in lista:
            aux.append((z,dist(frase,z)))
        aux.sort(key=lambda x:x[1])
        res.append(aux[0][0])
        tamanho = len(aux[0][0])
        frase = frase[tamanho:]
    final = " ".join(x for x in res)
    return final
              
print(estaca(frase,palavras)) ##Nao passa aos 13 testes da bb, so passa a 9 de 13
