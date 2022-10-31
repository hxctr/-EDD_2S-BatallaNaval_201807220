import hashlib
import math

class NodoData:
    def __init__(this, data, id) -> None:
        this.data = data
        this.id = id
        this.izquierdo = None
        this.derecho = None

class NodoHash:
    def __init__(this, hash) -> None:
        this.hash = hash
        this.izquierdo = None
        this.derecho = None

class Merkle:
    def __init__(this) -> None:
        this.topHash = None
        this.datablock = list()
        this.index = 0
        this.dot = ""
        this.count = 0
    
    def add(this, data):
        this.datablock.append(NodoData(data, this.count))
        this.count += 1
    
    def createTree(this, exponente):
        this.topHash = NodoHash(0)
        this._createTree(this.topHash, exponente)
    
    def _createTree(this, nodoHashTmp:NodoHash, exponente):
        if (exponente > 0):
            nodoHashTmp.izquierdo = NodoHash(0)
            nodoHashTmp.derecho = NodoHash(0)
            this._createTree(nodoHashTmp.izquierdo, exponente - 1)
            this._createTree(nodoHashTmp.derecho, exponente - 1)
    
    def generarHash(this, nodoHashTmp:NodoHash, n):
        if (nodoHashTmp is not None):
            this.generarHash(nodoHashTmp.izquierdo, n)
            this.generarHash(nodoHashTmp.derecho, n)

            if (nodoHashTmp.izquierdo is None and nodoHashTmp.derecho is None):
                indice = n - (this.index)
                nodoHashTmp.izquierdo = this.datablock[indice]
                this.index -= 1
                nodoHashTmp.hash = hashlib.sha256(str(nodoHashTmp.izquierdo.data).encode('utf-8')).hexdigest()
            else:
                nodoHashTmp.hash = hashlib.sha256(((nodoHashTmp.izquierdo.hash) + (nodoHashTmp.derecho.hash) ).encode('utf-8')).hexdigest() 

    def autenticacion(this):
        exponente = 1
        while(math.pow(2, exponente) < len(this.datablock)):
            exponente += 1
        
        cantidadBloques = int(math.pow(2, exponente))
        for i in range(len(this.datablock), cantidadBloques):
            dataBalanceo = (i * 100)
            this.datablock.append(NodoData(str(dataBalanceo), this.count))
            this.count += 1
        
        this.index = cantidadBloques
        this.createTree(exponente)
        this.generarHash(this.topHash, this.index)
    
    def enlazar(this, tmp):
        enlaces = ""
        if (tmp is not None):
            enlaces += this.enlazar(tmp.izquierdo)
            enlaces += this.enlazar(tmp.derecho)

            if(tmp.izquierdo is not None):
                if (tmp.izquierdo is not None):
                    if (isinstance(tmp.izquierdo, NodoData)):
                        enlaces += "\tnodo" + str(tmp.hash) + '->nodo' + str(tmp.izquierdo.id) + "[dir=\"back\"];\n"

                    if (isinstance(tmp.izquierdo, NodoHash)):
                        if (tmp is not None):
                            enlaces += "\tnodo" + tmp.hash + '->nodo' + tmp.izquierdo.hash + "[dir=\"back\"];\n"

            if (tmp.derecho  is not None):
                if (isinstance(tmp.derecho, NodoData)):
                    enlaces += "\tnodo" + tmp.hash + '->nodo' + tmp.derecho.id + "[dir=\"back\"];\n"              

                if (isinstance(tmp.derecho, NodoHash)):
                    if (tmp.derecho is not None):
                        enlaces += "\tnodo" + tmp.hash + '->nodo' + tmp.derecho.hash + "[dir=\"back\"];\n"
        return enlaces
    
    def generarNodos(this, tmp:NodoHash):
        nodos = ""

        if (tmp is not None):
            if (isinstance(tmp, NodoData)):
                nodos += "\tnodo" + str(tmp.id) + "[label=\"" + str(tmp.data) + "\"];\n"
            
            if (isinstance(tmp, NodoHash)):
                if (tmp is not None):
                    nodos += "\tnodo" + tmp.hash + "[label=\"" + tmp.hash + "\"];\n"
            
            nodos += this.generarNodos(tmp.izquierdo)
            nodos += this.generarNodos(tmp.derecho)
        return nodos
    
    def graficar(this):
        dotMerkle = "digraph MerkleTree {\n\tlabel= \"Arbol Merkle\"; \n node[shape=box];\n"
        dotMerkle += this.generarNodos(this.topHash) + "\n";
        dotMerkle += this.enlazar(this.topHash) + "\n}";
        return dotMerkle