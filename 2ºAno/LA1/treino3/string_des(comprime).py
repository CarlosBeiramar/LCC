# coding=utf-8
import itertools

mensagem = 'abc;2(a)2(b)s;a;5(a)'
mensagem2 = '10(a);aa5(a2(b))'
teste= '10(a);aa5(a2(b))'
padrao = 'a?*'
padrao2 = 'a?a*'

def descomprime(mensagem): 
    nums = [] 
    stringstack = [] 
    temp = "" 
    result = ""  
    i = 0
    while i < len(mensagem): 
        count = 0
  
        if mensagem[i].isdigit():
            while mensagem[i].isdigit():
                count = count * 10 + ord(mensagem[i]) - ord('0')  
                i += 1
            i -= 1
            nums.append(count) 
  
        elif mensagem[i] == ')': 
            temp = ""  
            count = 0
  
            if len(nums) != 0: 
                count = nums[-1]  
                nums.pop() 
  
            while (len(stringstack) != 0 and stringstack[-1] !='(' ): 
                temp = stringstack[-1] + temp  
                stringstack.pop() 
  
            if (len(stringstack) != 0 and stringstack[-1] == '('):  
                stringstack.pop()  
  
            for j in range(count): 
                result = result + temp  
  
            for j in range(len(result)): 
                stringstack.append(result[j])  
  
            result = "" 
  
        elif (mensagem[i] == '('): 
            if mensagem[i-1].isdigit():
                stringstack.append(mensagem[i])  
  
            else: 
                stringstack.append(mensagem[i])  
                nums.append(i) 
  
        else: 
            stringstack.append(mensagem[i]) 
          
        i += 1
  
    while len(stringstack) != 0: 
        result = stringstack[-1] + result  
        stringstack.pop() 
  
    return result 
    
def strrmatch(strr, pattern, n, m): 
      
    if (m == 0): 
        return (n == 0) 
          
    # matriz para guardar resultados de subproblemas 
    lookup = [[False for i in range(m + 1)] for j in range(n + 1)] 
      
    #padrao vazio,string vazia 
    lookup[0][0] = True
      
    # * pode corresponder a string vazia
    for j in range(1, m + 1): 
        if (pattern[j - 1] == '*'): 
            lookup[0][j] = lookup[0][j - 1] 
              
    for i in range(1, n + 1): 
        for j in range(1, m + 1): 

            if (pattern[j - 1] == '*'): 
                lookup[i][j] = lookup[i][j - 1] or lookup[i - 1][j] 
              
            elif (pattern[j - 1] == '?' or strr[i - 1] == pattern[j - 1]): 
                lookup[i][j] = lookup[i - 1][j - 1] 
                  
            else: 
                lookup[i][j] = False
      
    return lookup[n][m]
    


def filtra(mensagem,padrao):
    d = []
    s = descomprime(mensagem)
    palavras = []
    i = 0
    while i < len(s):
        aux = ''
        while i < len(s) and s[i] != ';':
            aux += s[i]
            i += 1
        
        if len(aux) > 0:
            palavras.append(aux)
        
        i += 1
    
    for pal in palavras:
        if strrmatch(pal, padrao, len(pal), len(padrao)):
            d.append((pal,len(pal)))
    
    return d

def contem(lista1,lista2): ##se os elementos da lista1 aparecem pelo menos uma vez na lista2
    res = True
    for x in lista1:
        if lista2.count(x)<1:
            res = False
    return res
 
def verifica_repeticoes(subset): ## verifica se uma lista so tem um elemento no repetido no maximo uma vez
    res = True
    for x in subset:
        if subset.count(x)>2:
            res=  False
    return res

def duplicados_seguidos(lista):
    res  = True
    duplicado = False
    i=0
    while i<len(lista)-1 and res:
        j = i+1
        if lista[i]==lista[j] and not duplicado:
            duplicado = True
            i+=2
        elif lista[i]==lista[j] and duplicado:
            res = False
        elif lista[i]!=lista[j]:
            duplicado = False
            i+=1
    return res

def duplica2 (mensagem,padrao):
    s =[]
    d = filtra(mensagem,padrao)
    lista_final=[]
    
    #dic = comprime(mensagem)
    
    lista1 = []
    lista2 = []
    
    for i in range (len(d)):
        if i % 2 == 0:
            lista1.append(d[i])
            lista1.append(d[i])
            lista2.append(d[i])
        
        elif i % 2 == 1:
            lista1.append(d[i])
            lista2.append(d[i])
            lista2.append(d[i])
    
    soma1 = 0
    soma2 = 0
    
    for pal,tam in lista1:
        soma1 += tam
    
    for pal,tam in lista2:
        soma2 += tam
            
    if soma1 > soma2:
        for i in range(len(lista1)):
            if i == len(lista1) - 1:
                s.append(lista1[i][0])
            else:
                s.append(lista1[i][0])
                
    else:
        for i in range(len(lista2)):
            if i == len(lista2) - 1:
                s.append(lista2[i][0])
            else:
                s.append(lista2[i][0])
    for x in s:
        if x !=";":
            lista_final.append((x,len(x)))
    return lista_final


def duplica(mensagem,padrao):
    d = filtra(mensagem,padrao)
    lista = []
    lista_final = []
    valor = 0
    res = 0
    lista_aux = duplica2(mensagem,padrao)
    maximo  = len(d)*2 - len(d)//2
    for x in (range(len(d),maximo+1)):
        for subset in itertools.combinations_with_replacement(d, maximo):
            if verifica_repeticoes(subset) and list(subset)not in lista and contem(d,subset) and duplicados_seguidos(subset): #and len(subset)==maximo:
                lista.append(list(subset))
    if lista_aux not in lista:
        lista.append(lista_aux)    
    for sublista in lista:
        for x in sublista:
            valor +=x[1]
        if valor>res:
            res = valor
            lista_final = sublista 
        
    lista_final = [x[0] for x in lista_final]
    return lista_final


def comprime(mensagem):
    d={}

    #passo 1 encontrar todos os padrões(sub-strings) e o seu numero de ocorrências
    for i in range(len(mensagem)):
        for j in range(i+1,len(mensagem)+1):
            d[mensagem[i:j]]=0

    for k in d.keys():
        i=0
        while i<len(mensagem):
            if k==mensagem[i:i+len(k)]:
                count=1
                p=i+len(k)
                while k==mensagem[p:p+len(k)]:
                    count+=1
                    p=p+len(k)
                if d[k]<count:
                    d[k]=count
                i=p
            else:
                i+=1

    #passo 2 eliminar os padrões que não compensam comprimir (com 1-4 ocorrências)
    vf=[]
    for k,v in d.items():
        if v==1 or v==2 or v==3 or v==4:
            vf.append(k)
    for v in vf:
        del d[v]

    #passo 3 encontrar o padrão com o maior numero de ocorrências e comprimi-lo
    res=''
    if d!={}:
        pdr=''
        count=0
        for k,v in d.items():
            if v>count:
                count=v
                pdr=k
        i=0
        while i<len(mensagem):
            if pdr==mensagem[i:i+len(pdr)]:
                c=1
                p=i+len(pdr)
                while pdr==mensagem[p:p+len(pdr)]:
                    c+=1
                    p=p+len(pdr)
                if c==count:
                    res+=str(count)+'('+pdr+')'
                else:
                    while c!=0:
                        res+=pdr
                        c-=1
                i=p
            else:
                res+=mensagem[i]
                i+=1
    else:
        res=mensagem

    return res


def processa(mensagem,padrao):
    lista  = duplica(mensagem,padrao)
    string_final = ""
    for x in lista:
        string_final += comprime(x)
        string_final +=";"
    string_final = string_final[:-1]
    
    return string_final

print(duplica(mensagem2,padrao2))