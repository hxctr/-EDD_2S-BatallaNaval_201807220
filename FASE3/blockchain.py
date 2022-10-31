from math import fabs
from multiprocessing.dummy import Array
import time
import hashlib

class Bloque:
    def __init__(this, indice, data, previusHash, rootMerkle):
        this.indice = indice;
        this.data = data;
        this.timeStamp = this.calcularTimeStamp();
        this.previusHash = previusHash;
        
        this.nonce = 0;
        this.rootMerkle = rootMerkle;
        this.hash = this.crearHash();

        
    
    def calcularTimeStamp(this):
        fecha = time.strftime("%d/%m/%y")
        hora = time.strftime("%H:%M:%S")
        tiempo = str(fecha)+"::"+str(hora)
        return tiempo
    
    def crearHash(this):
        return hashlib.sha256((str(this.indice)+this.timeStamp+this.previusHash+this.rootMerkle).encode('utf-8')).hexdigest()
    
    def pruebaTrabajo(this, dificultad):
        flag = True
        while(flag):
            print(this.hash, type(this.hash))

            
            this.hash = this.crearHash()
            if (this.hash[0:1] == "00"):
                flag = False
            this.nonce += 1
    
class NodoBloque():
    def __init__(this, bloque) -> None:
        this.bloque = bloque
        this.next = None

class Cadena:
    def __init__(this) -> None:
        this.indice = 0
        this.cadena = list()
    
    def bloqueGenesis(this, data, rootMerkle):
        genesis = Bloque(this.indice, data, "0000", rootMerkle)
        this.cadena.append(genesis)
        this.indice += 1
    
    def agregar(this, data, rootmerkle):
        nuevo = Bloque(this.indice, data, this.cadena[this.indice - 1].hash, rootmerkle)
        this.indice += 1
        this.cadena.append(nuevo)
    
    def graficarBlockchain(this):
        stringfile = ""
        conexiones = ""
        nodos = ""
        cadena = "digraph Blockchain{\nlabel = \"Blockchain\";\nnode [shape=box];\n"

        if (this.indice == 0):
            pass
        else:
            for i in range(len(this.cadena)):
                stringfile += '\n{\n"INDEX": "'+str(i)+'",\n"TIMESTAMP": "'+str(this.cadena[i].timeStamp)+'",\n"DATA": "'+this.cadena[i].data+'",\n"PREVIOUSHASH": "'+str(this.cadena[i].previusHash)+'",\n"ROOTMERKLE": "'+ str(this.cadena[i].rootMerkle)+'",\n"HASH": "'+str(this.cadena[i].hash)+'"\n}'


        with open('blockchain.json', 'w') as textwrite:
            textwrite.write(stringfile)