objectos = [("microondas",30,6),("jarra",14,3),("giradiscos",16,4),("radio",9,2)]


def ladrao(capacidade,objetos):
    pesos = [x[2] for x in objetos]
    matriz = [[0 for x in range(capacidade+1)]for y in range (len(objetos)+1)]

    for i in range(len(objetos)+1):
        for j in range(capacidade+1):
            if i==0 or j==0:
                matriz[i][j] = 0
            elif pesos[i-1] <= j:
                matriz[i][j] = max(objetos[i-1][1] + matriz[i-1][j-pesos[i-1]],matriz[i-1][j])
            else:
                matriz[i][j] = matriz[i-1][j]

    return matriz[len(objetos)][capacidade]

ladrao(10,objectos)