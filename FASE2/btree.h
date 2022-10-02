#include <stddef.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#define null 0
using namespace std;

class NodoB
{
public:
    int id;
    NodoB *siguiente;
    NodoB *anterior;
    NodoB *derecha;
    NodoB *izquierda;

    NodoB(int valor)
    {
        id = valor;
        siguiente = NULL;
        anterior = NULL;
        derecha = NULL;
        izquierda = NULL;
    }

private:
};

class ArbolB
{
private:
public:
    int orden_arbol = 5;
    NodoB *raiz;
    ArbolB()
    {
        raiz = NULL;
    }

    void insertar(int id)
    {
        NodoB *nodo = new NodoB(id);
        if (raiz == NULL)
        {
            raiz = nodo;
        }
        else
        {
            pair<NodoB *, pair<bool, bool>> ret = insertarCrearRama(nodo, raiz);
            NodoB *obj = ret.first;
            if ((ret.second.first || ret.second.second) && obj != NULL)
            {  
                 
                raiz = obj;
            }
        }
    }

    pair<NodoB *, pair<bool, bool>> insertarCrearRama(NodoB *nodo, NodoB *rama)
    {
        pair<NodoB *, pair<bool, bool>> ResultadoRama;
        ResultadoRama.first = NULL;          
        ResultadoRama.second.first = false; 
        ResultadoRama.second.second = false; 
        if (esHoja(rama))
        {                                                                
            pair<NodoB *, bool> resultado = insertarEnRama(rama, nodo);  
            ResultadoRama.first = resultado.first;                       
            ResultadoRama.second.second = resultado.second;              
            if (contador(resultado.first) == orden_arbol)
            {  
                 
                ResultadoRama.first = dividir(resultado.first);  
                ResultadoRama.second.first = true;               
            }
        }
        else
        {  
            NodoB *temp = rama;
            do
            {
                if (nodo->id == temp->id)
                {  
                     
                    return ResultadoRama;
                }
                else if (nodo->id < temp->id)
                {
                    pair<NodoB *, pair<bool, bool>> ResultadoInsert = insertarCrearRama(nodo, temp->izquierda);
                    if (ResultadoInsert.second.second && ResultadoInsert.first != NULL)
                    {  
                        ResultadoRama.second.second = true;
                        temp->izquierda = ResultadoInsert.first;
                    }
                    if (ResultadoInsert.second.first)
                    {  
                        pair<NodoB *, bool> auxInsert = insertarEnRama(rama, ResultadoInsert.first);
                        rama = auxInsert.first;
                        if (auxInsert.second)
                        {
                            ResultadoRama.first = rama;
                        }
                        if (contador(rama) == orden_arbol)
                        {
                            ResultadoRama.first = dividir(rama);
                            ResultadoRama.second.first = true;
                        }
                    }
                    return ResultadoRama;
                }
                else if (temp->siguiente == NULL)
                {
                    pair<NodoB *, pair<bool, bool>> ResultadoInsert = insertarCrearRama(nodo, temp->derecha);
                    if (ResultadoInsert.second.second && ResultadoInsert.first != NULL)
                    {  
                        ResultadoRama.second.second = true;
                        temp->derecha = ResultadoInsert.first;
                    }
                    if (ResultadoInsert.second.first)
                    {  
                        pair<NodoB *, bool> auxInsert = insertarEnRama(rama, ResultadoInsert.first);
                        rama = auxInsert.first;
                        if (auxInsert.second)
                        {
                            ResultadoRama.first = rama;
                        }
                        if (contador(rama) == orden_arbol)
                        {
                            ResultadoRama.first = dividir(rama);
                            ResultadoRama.second.first = true;
                        }
                    }
                    return ResultadoRama;
                }
                temp = temp->siguiente;
            } while (temp != NULL);
        }
        return ResultadoRama;
    }

    NodoB *dividir(NodoB *rama)
    {
        int val = -999;
        NodoB *temp = NULL;
        NodoB *Nuevito = NULL;
        NodoB *aux = rama;

        NodoB *rderecha = NULL;
        NodoB *rizquierda = NULL;

        int cont = 0;
        while (aux != NULL)
        {
            cont++;
             
            if (cont < 3)
            {
                val = aux->id;
                temp = new NodoB(val);
                temp->izquierda = aux->izquierda;
                if (cont == 2)
                {
                    temp->derecha = aux->siguiente->izquierda;
                }
                else
                {
                    temp->derecha = aux->derecha;
                }
                rizquierda = insertarEnRama(rizquierda, temp).first;
            }
            else if (cont == 3)
            {
                val = aux->id;
                Nuevito = new NodoB(val);
            }
            else
            {
                val = aux->id;
                temp = new NodoB(val);
                temp->izquierda = aux->izquierda;
                temp->derecha = aux->derecha;
                rderecha = insertarEnRama(rderecha, temp).first;
            }
            aux = aux->siguiente;
        }
        Nuevito->derecha = rderecha;
        Nuevito->izquierda = rizquierda;
        return Nuevito;
    }

    pair<NodoB *, bool> insertarEnRama(NodoB *primero, NodoB *nuevo)
    {
        pair<NodoB *, bool> ret;
        ret.second = false;
        if (primero == NULL)
        {
             
            ret.second = true;
            primero = nuevo;
        }
        else
        {
             
            NodoB *aux = primero;
            while (aux != NULL)
            {
                if (aux->id == nuevo->id)
                {  
                     
                    break;
                }
                else
                {
                    if (aux->id > nuevo->id)
                    {
                        if (aux == primero)
                        {  
                            aux->anterior = nuevo;
                            nuevo->siguiente = aux;
                             
                            aux->izquierda = nuevo->derecha;
                            nuevo->derecha = NULL;
                            ret.second = true;
                            primero = nuevo;
                            break;
                        }
                        else
                        {  
                            nuevo->siguiente = aux;
                             
                            aux->izquierda = nuevo->derecha;
                            nuevo->derecha = NULL;

                            nuevo->anterior = aux->anterior;
                            aux->anterior->siguiente = nuevo;
                            aux->anterior = nuevo;
                            break;
                        }
                    }
                    else if (aux->siguiente == NULL)
                    {  
                        aux->siguiente = nuevo;
                        nuevo->anterior = aux;
                        break;
                    }
                }
                aux = aux->siguiente;
            }
        }
        ret.first = primero;

        return ret;
    }

    bool esHoja(NodoB *primero)
    {
        NodoB *aux = primero;
        while (aux != NULL)
        {
             
            if (aux->izquierda != NULL || aux->derecha != NULL)
            {
                return false;
            }
            aux = aux->siguiente;
        }
         
        return true;
    }

    int contador(NodoB *primero)
    {
        int contador = 0;
        NodoB *aux = primero;
        while (aux != NULL)
        {
            contador++;
            aux = aux->siguiente;
        }
        return contador;
    }

     
     

    string Grafo()
    {
        string dotFull = "";
        string dot="";
         

        dotFull += "digraph G {\n";
        dotFull += "node[shape=record]\n";
        dotFull += "\t\t\n";
        dotFull += GrafoArbolAbb(raiz);
         
        dotFull += "\t\t\n";
        dotFull += GrafoConexionRamas(raiz);

        dotFull += "}";
        return dotFull;
    }

    string GrafoArbolAbb(NodoB *rama)
    {
        string dot = "";
        if (rama != NULL)
        {
             
            dot += GrafoRamas(rama);
             
            NodoB *aux = rama;
            while (aux != NULL)
            {
                if (aux->izquierda != NULL)
                {
                    dot += GrafoArbolAbb(aux->izquierda);
                }
                if (aux->siguiente == NULL)
                {
                    if (aux->derecha != NULL)
                    {
                        dot += GrafoArbolAbb(aux->derecha);
                    }
                }
                aux = aux->siguiente;
            }
        }
        return dot;
    }

    string GrafoRamas(NodoB *rama)
    {
        string dot = "";
        stringstream auxTXT;
        if (rama != NULL)
        {
             
            NodoB *aux = rama;
            auxTXT.str("");
            auxTXT << rama;
            dot = dot + "R" + auxTXT.str() + "[label=\"";
            int r = 1;
            while (aux != NULL)
            {
                if (aux->izquierda != NULL)
                {
                    dot = dot + "<C" + to_string(r) + ">|";
                    r++;
                }
                if (aux->siguiente != NULL)
                {
                    dot = dot + to_string(aux->id) + "|";
                }
                else
                {
                    dot = dot + to_string(aux->id);
                    if (aux->derecha != NULL)
                    {
                        dot = dot + "|<C" + to_string(r) + ">";
                    }
                }
                aux = aux->siguiente;
            }
            dot = dot + "\"];\n";
        }
        return dot;
    }

    string GrafoConexionRamas(NodoB *rama)
    {
        string dot = "";
        stringstream auxTXT;
        if (rama != NULL)
        {
             
            NodoB *aux = rama;
            auxTXT << rama;
            string actual = "R" + auxTXT.str();
            int r = 1;
            while (aux != NULL)
            {
                if (aux->izquierda != NULL)
                {
                    auxTXT.str("");
                    auxTXT << aux->izquierda;
                    dot += actual + ":C" + to_string(r) + "->" + "R" + auxTXT.str() + ";\n";
                    r++;
                    dot += GrafoConexionRamas(aux->izquierda);
                }
                if (aux->siguiente == NULL)
                {
                    if (aux->derecha != NULL)
                    {
                        auxTXT.str("");
                        auxTXT << aux->derecha;
                        dot += actual + ":C" + to_string(r) + "->" + "R" + auxTXT.str() + ";\n";
                        r++;
                        dot += GrafoConexionRamas(aux->derecha);
                    }
                }
                aux = aux->siguiente;
            }
        }
        return dot;
    }
};
