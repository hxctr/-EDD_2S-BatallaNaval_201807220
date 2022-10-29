class Node:
    def __init__(self, id, name) -> None:
        self.id = id
        self.name = name
    
    def getId(self):
        return self.id
    
    def getName(self):
        return self.name

# class Nodo:
#     def __init__(this, valor) -> None:
#         this.valor = valor
#         this.hash = None

class ClosedHashing():
    def __init__(this, size, minimum, maximum, shape, collision):
        this.table = None
        this.size = size
        this.minimum = minimum
        this.maximum = maximum
        this.shape = shape
        this.collision = collision
        this.added = 0
        this.fillTable()
    
    def fillTable(this):
        this.added = 0
        newTable = [None] * this.size

        for i in range(this.size):
            newTable[i] = -1
        
        this.table = newTable

    def hashFunction(this, id):
        return int(id % this.size)
    
    def insert(this, node:Node):

        position = this.hashFunction(node.id)
        i = 1
        while (this.table[position] != -1):
            position = this.collisions(node.id, i)
            i += 1
        this.table[position] = node
        this.added += 1
        load_factor = float(this.added / this.size)
        print('factor ahorita',load_factor)

        if load_factor > 0.80:
            print('Haciendo rehashing')
            this.rehashing()
    
    def collisions(this, id, i):
        newpos = (id + (i * i)) % this.size
        return newpos

    def rehashing(this):
        newarray = this.table
        prevsize = this.size
        
        newsize = (this.size * 20) /100

        this.size = this.size + int(newsize)

        this.fillTable()

        for i in range(prevsize):
            if newarray[i] != -1:
                this.insert(newarray[i])
    
    def getGraph(this):
        graph = """
        digraph g{
        fontname="Helvetica,Arial,sans-serif"
        node [fontname="Helvetica,Arial,sans-serif"]
        edge [fontname="Helvetica,Arial,sans-serif"]
        a0 [shape=none label=< <TABLE border="1" ><TR><TD>Indice</TD><TD>ID</TD><TD>Nombre</TD></TR>
        """
        for i in range(len(this.table)):
            if this.table[i] != -1:
                graph += "<TR><TD>"+str(i)+"</TD><TD>"+str(this.table[i].getId())+"</TD><TD>"+this.table[i].getName()+"</TD></TR>"
                print(i,this.table[i].getId(), this.table[i].getName())
        
        graph += "</TABLE>>];}"
        print(graph)

hashTable = ClosedHashing(13, 20, 80, "Division", "cuadratica")
a1 = Node(5, "hola")
a2 = Node(9, "hola")
a3 = Node(408, "hola")
a4 = Node(25, "hola")
a5 = Node(89, "hola")
a6 = Node(50, "hola")
a7 = Node(58, "hola")
a8 = Node(69, "hola")
a9 = Node(452, "hola")
a10 = Node(408, "hola")
a11= Node(965, "hola")

# a7 = Node(96, "hola")



hashTable.insert(a1)#5 --
hashTable.insert(a2)#9 --
hashTable.insert(a3)#5--xxx
hashTable.insert(a4)#12---///
hashTable.insert(a5)#11---xxxx
hashTable.insert(a6)#11---////
hashTable.insert(a7)
hashTable.insert(a8)
hashTable.insert(a9)
hashTable.insert(a10)
# hashTable.insert(a11)
# hashTable.insert(a7)#5 --////
"""
hashTable.insert(5)#5 --
hashTable.insert(9)#9 --
hashTable.insert(408)#5--xxx
hashTable.insert(25)#12---///
hashTable.insert(89)#11---xxxx
hashTable.insert(50)#11---////
hashTable.insert(96)#5 --////
"""
# hashTable.insert(25)
# hashTable.insert(36)
# hashTable.insert(15)
hashTable.getGraph()