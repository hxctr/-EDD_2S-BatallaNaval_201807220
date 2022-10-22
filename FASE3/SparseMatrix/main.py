
from MatrizDispersa import MatrizDispersa

matriz = MatrizDispersa(0)

m = 11

#formula para calcular barcos

B_m = int(((m-1)/10) +1 )
Portaaviones = B_m * 1;
Submarinos = B_m * 2;
Destructores = B_m * 3;
Buques = B_m * 4;


print('Valor inicial de B:',B_m)
print('Cant. Portaaviones:',Portaaviones)
print('Cant. submarinos:',Submarinos)
print('Cant. destructores:',Destructores)
print('Cant. buques:',Buques)


def firstFill(tamaño):#11<= m <= 20
    #insertar portaaviones
    top1 = 9
    exceptions = (4,)
    for index in range(top1):
        if index not in exceptions:
            # print(index)#insert portaaviones
            matriz.insert(0, index, "P")
    
    #submarinos
    print("submarinos")
    top2 = 7
    except2 = (1, 3, 5)
    for index in range(top2):
        if index not in except2:
            # print(index)#insert portaaviones
            matriz.insert(int(tamaño / 4), index, "S")
            matriz.insert(1 + int(tamaño / 4), index, "S")
            matriz.insert(2 + int(tamaño / 4), index, "S")
    
    print("Destructores")
    top3 = 11
    except3 = (1, 3, 5, 7, 9,)
    for index in range(top3):
        if index not in except3:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*2), index, "D")
            matriz.insert(1+int((tamaño / 4)*2), index, "D")

    print("buques")
    top4 = 13
    except4 = (3, 5, 7, 9, 11,)
    for index in range(top4):
        if index not in except4:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*3), index, "B")

def secondFill(tamaño):#21<= m <= 30
    #insertar portaaviones
    top1 = 14
    exceptions = (4,9,)
    for index in range(top1):
        if index not in exceptions:
            # print(index)#insert portaaviones
            matriz.insert(0, index, "P")
    
    #submarinos
    print("submarinos")
    top2 = 11
    except2 = (1, 3, 5, 7, 9,)
    for index in range(top2):
        if index not in except2:
            # print(index)#insert portaaviones
            matriz.insert(int(tamaño / 4), index, "S")
            matriz.insert(1 + int(tamaño / 4), index, "S")
            matriz.insert(2 + int(tamaño / 4), index, "S")
    
    print("Destructores")
    top3 = 17
    except3 = (1, 3, 5, 7, 9, 11, 13, 15,)
    for index in range(top3):
        if index not in except3:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*2), index, "D")
            matriz.insert(1+int((tamaño / 4)*2), index, "D")

    print("buques")
    top4 = 21
    except4 = (3, 5, 7, 9, 11, 13, 15, 17, 19,)
    for index in range(top4):
        if index not in except4:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*3), index, "B")

def thirdFill(tamaño):#31<= m <= 40
    #insertar portaaviones
    top1 = 19
    exceptions = (4,9,14,)
    for index in range(top1):
        if index not in exceptions:
            # print(index)#insert portaaviones
            matriz.insert(0, index, "P")
    
    #submarinos
    print("submarinos")
    top2 = 15
    except2 = (1, 3, 5, 7, 9, 11, 13,)
    for index in range(top2):
        if index not in except2:
            # print(index)#insert portaaviones
            matriz.insert(int(tamaño / 4), index, "S")
            matriz.insert(1 + int(tamaño / 4), index, "S")
            matriz.insert(2 + int(tamaño / 4), index, "S")
    
    print("Destructores")
    top3 = 23
    except3 = (1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21,)
    for index in range(top3):
        if index not in except3:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*2), index, "D")
            matriz.insert(1+int((tamaño / 4)*2), index, "D")

    print("buques")
    top4 = 29
    except4 = (3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27,)
    for index in range(top4):
        if index not in except4:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*3), index, "B")

def fourthFill(tamaño):#41<= m <= 50
    #insertar portaaviones
    top1 = 24
    exceptions = (4,9,14,19,)
    for index in range(top1):
        if index not in exceptions:
            # print(index)#insert portaaviones
            matriz.insert(0, index, "P")
    
    #submarinos
    print("submarinos")
    top2 = 19
    except2 = (1, 3, 5, 7, 9, 11, 13,15,17,)
    for index in range(top2):
        if index not in except2:
            # print(index)#insert portaaviones
            matriz.insert(int(tamaño / 4), index, "S")
            matriz.insert(1 + int(tamaño / 4), index, "S")
            matriz.insert(2 + int(tamaño / 4), index, "S")
    
    print("Destructores")
    top3 = 29
    except3 = (1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21,23, 25,27,)
    for index in range(top3):
        if index not in except3:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*2), index, "D")
            matriz.insert(1+int((tamaño / 4)*2), index, "D")

    print("buques")
    top4 = 37
    except4 = (3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27,29, 31, 33, 35,)
    for index in range(top4):
        if index not in except4:
            # print(index)#insert portaaviones
            matriz.insert(int((tamaño / 4)*3), index, "B")


matriz.insert(2, 3, "x")
matriz.insert(0, 2, "x")

    


# firstFill(20)
# secondFill(30)
# thirdFill(31)
fourthFill(50)
matriz.graficarNeato("test")
    

