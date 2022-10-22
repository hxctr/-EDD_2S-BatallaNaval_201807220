#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Info
{
public:
    int id;
    Info(int id)
    {
        this->id = id;
    }

protected:
private:
};

class NodoAVL
{
public:
    Info *info;
    int height;
    NodoAVL *left;
    NodoAVL *right;
    NodoAVL(Info *info)
    {
        this->info = info;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }

protected:
private:
};

class AVLTree
{
public:
    NodoAVL *root;

    int contador = 0;

    AVLTree()
    {
        this->root = NULL;
    }

    // OBTENER LA ALTURA DE UN NODO EN ESPECÍFICO
    int height(NodoAVL *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        else
        {
            return n->height;
        }
    }

    // FUNCION MAXIMO
    int maximo(int a, int b)
    {
        return (a > b) ? a : b;
    }

    NodoAVL *rotacionDerecha(NodoAVL *y)
    {
        NodoAVL *x = y->left;
        NodoAVL *t2 = x->right;
        x->right = y;
        y->left = t2;
        y->height = maximo(height(y->left), height(y->right)) + 1;
        x->height = maximo(height(x->left), height(x->right)) + 1;
        return x;
    }

    NodoAVL *rotacionIzquierda(NodoAVL *x)
    {
        NodoAVL *y = x->right;
        NodoAVL *t2 = y->left;
        y->left = x;
        x->right = t2;
        x->height = maximo(height(x->left), height(x->right)) + 1;
        y->height = maximo(height(y->left), height(y->right)) + 1;
        return y;
    }

    int obtenerFE(NodoAVL *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        else
        {
            return height(n->left) - height(n->right);
        }
    }

    void addToTree(Info *info)
    {
        this->root = insertarNodo(this->root, info);
    }

    NodoAVL *insertarNodo(NodoAVL *raiz, Info *info)
    {
        if (raiz == NULL)
        {
            return new NodoAVL(info);
        }
        if (info->id < raiz->info->id)
        {
            raiz->left = insertarNodo(raiz->left, info);
        }
        else if (info->id > raiz->info->id)
        {
            raiz->right = insertarNodo(raiz->right, info);
        }
        raiz->height = 1 + maximo(height(raiz->left), height(raiz->right));
        int balance = obtenerFE(raiz);
        // CASO 1 DE BALANCE: IZQUIERDA IZQUIERDA
        if (balance > 1 && info->id < raiz->left->info->id)
        {
            return rotacionDerecha(raiz);
        }
        // CASO 2 DE BALANCE DERECHA DERECHA
        if (balance < -1 && info->id > raiz->right->info->id)
        {
            return rotacionIzquierda(raiz);
        }
        // CASO 3 IZQUIERDA DERECHA
        if (balance > 1 && info->id > raiz->left->info->id)
        {
            raiz->left = rotacionIzquierda(raiz->left);
            return rotacionDerecha(raiz);
        }
        // CASO 4 DERECHA IZQUIERDA
        if (balance < -1 && info->id < raiz->right->info->id)
        {
            raiz->right = rotacionDerecha(raiz->right);
            return rotacionIzquierda(raiz);
        }
        // EN CUALQUIER OTRO CASO:
        return raiz;
    }

    void graphTree()
    {
        this->contador = this->contador++;
        ofstream archivo;
        archivo.open("alvtree.dot");

        archivo << "digraph g {" << std::endl;
        graficaRamas(archivo, this->root);
        archivo << "}";
        archivo.close();
    }

    void graficaRamas(std::ofstream &archivo, NodoAVL *raiz)
    {
        if (raiz != NULL)
        {
            archivo << "\"id: " << raiz->info->id << "\";" << std::endl;
            if (raiz->left != NULL)
            {
                archivo << "\"id: " << raiz->info->id << "\"->\"id: " << raiz->left->info->id << "\";" << std::endl;
            }
            if (raiz->right != NULL)
            {
                archivo << "\"id: " << raiz->info->id << "\"->\"id: " << raiz->right->info->id << "\";" << std::endl;
            }
            graficaRamas(archivo, raiz->left);
            graficaRamas(archivo, raiz->right);
        }
    }

    NodoAVL *sucesor(NodoAVL *nodo)
    {
        NodoAVL *aux = nodo;
        while (aux->left != NULL)
        {
            aux = aux->left;
        }
        return aux;
    }

private:
};