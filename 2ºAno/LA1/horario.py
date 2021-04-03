'''

def test_horario_1(self):
        with test_timeout(self,1):
            ucs = {"la2": ("quarta",16,2), "pi": ("terca",15,1), "cp": ("terca",14,2),"so": ("quinta",9,3)}
            alunos = {5000: {"la2","cp"}, 2000: {"la2","cp","pi"},3000: {"cp","poo"}, 1000: {"la2","cp","so"}}
            self.assertEqual(horario(ucs,alunos),[(1000, 7), (5000, 4)])

'''

ucs = {"la2": ("quarta",16,2), "pi": ("terca",15,1), "cp": ("terca",14,2),"so": ("quinta",9,3)}
alunos = {5000: {"la2","cp"}, 2000: {"la2","cp","pi"},3000: {"cp","poo"}, 1000: {"la2","cp","so"}}


def compara_cadeiras(cadeira1, cadeira2):  
    if cadeira1 not in ucs:
        return False

    if cadeira2 not in ucs:
        return False
    
    dia1,hora1,tempo1 = ucs[cadeira1]
    dia2,hora2,tempo2 = ucs[cadeira2]
    
    if (dia1!=dia2): return True
    
    elif(dia1 == dia2):
        if (hora1 + tempo1 < hora2):
            return True
        elif(hora2 + tempo2 < hora1):
            return True
    
    return False   

def verifica(numero,alunos,ucs):
    cadeiras = alunos[numero]
    lista_aux = []
    comp = [] 
    for cadeira1 in cadeiras:
        comp.append(cadeira1)
        for x in cadeiras:
            if cadeira1 != x and x not in comp:
                lista_aux.append((cadeira1,x,compara_cadeiras(cadeira1,x)))
    return lista_aux
                    


def horario(ucs,alunos):
    alunos_poss = []
    final = []
    for numero, cadeira in alunos.items():
        lista = verifica(numero,alunos,ucs)
        if all(t == True for x,y,t in lista):
            alunos_poss.append(numero)
    
    for x in alunos_poss:
        horas = 0
        cadeiras = alunos[x]
        for y in cadeiras:
            dia,tempo,hora = ucs[y]
            horas += hora
        final.append((x,horas))
    
    final = sorted(final, key= lambda x : (-x[1], x[0]))
    return final
