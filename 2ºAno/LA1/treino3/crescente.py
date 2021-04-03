list1 = [-15,-27,-14,-38,-26,-55,-46,-65,-85]

def aux(indice,list1):
    x=list1[indice]
    ant=x
    res=0
    if x>=0:
        for numbers in range(indice,len(list1)):
            if(list1[numbers]>=x and list1[numbers]>=ant):
                ant=list1[numbers]
                res+=1
    else:
        for numbers in range(indice,len(list1)):
            if(list1[numbers]<=x and list1[numbers]<=ant):
                ant=list1[numbers]
                res+=1

    return res

def crescente(list1):
    soma = 0
    for number in range(0,len(list1)):
        soma = max(aux(number,list1),soma)
    return soma

aux(0,list1)