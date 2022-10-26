#include <iostream>
#include <string>
using namespace std;

class Coordinates
{
private:
public:
    Coordinates *next;
    string first;
    string last;
    int index;

    Coordinates(string first, string last, int index)
    {
        this->first = first;
        this->last = last;
        this->index = index;
        this->next = nullptr;
    }

    string getFirst()
    {
        return first;
    }

    string getLast()
    {
        return last;
    }

    int getindex()
    {
        return index;
    }
};

class Edge
{
private:
public:
    string content;
    Coordinates *top;

    Edge()
    {
        top = nullptr;
    }

    void insert(string coordinate1, string coordinate2, int index)
    {
        Coordinates *newv = new Coordinates(coordinate1, coordinate2, index);
        Coordinates *Search = search(coordinate1, coordinate2, top);

        if (Search != nullptr)
        {
            return;
        }

        if (top == nullptr)
        {
            top = newv;
        }
        else
        {
            Coordinates *temp = top;

            while (temp->next != nullptr)
            {

                temp = temp->next;
            }

            temp->next = newv;
        }
    }

    Coordinates *search(string coordinate1, string coordinate2, Coordinates *first)

    {
        Coordinates *aux = first;

        while (aux != nullptr)
        {
            if (aux->getFirst() == coordinate1 && aux->getLast() == coordinate2)
            {
                return aux;
            }
            else
            {
                aux = aux->next;
            }
        }
        return nullptr;
    }
};

class Vertex
{
private:
public:
    Vertex *next;
    string coordinate;
    int position;
    Edge *edge;

    Vertex(string coordinate)
    {
        this->edge = new Edge();
        this->coordinate = coordinate;
        this->next = nullptr;
        this->position = -1;
    }

    Vertex()
    {
    }

    string getCoordinate()
    {
        return coordinate;
    }

    int getPosition()
    {
        return position;
    }

    void addEdge(string coordinate1, string coordinate2, int index)
    {
        edge->insert(coordinate1, coordinate2, index);
    }
};

class VertexesList
{
private:
public:
    Vertex *top;
    string content;
    int counter;
    int pos = 0;

    VertexesList()
    {
        top = nullptr;
    }

    void insert(string coordinate)
    {
        Vertex *newv = new Vertex(coordinate);
        newv->position = pos;
        Vertex *Search = search(coordinate, top);

        if (Search != nullptr)
        {
            return;
        }
        if (top == nullptr)
        {
            top = newv;
            pos++;
        }
        else
        {
            Vertex *temp = top;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newv;
            pos++;
        }
    }

    Vertex *search(string coordinate, Vertex *first)
    {
        Vertex *aux = first;

        while (aux != nullptr)
        {
            if (aux->getCoordinate() == coordinate)
            {
                return aux;
            }
            else
            {
                aux = aux->next;
            }
        }

        return nullptr;
    }

    void insertEdge(Vertex *top, Vertex *add)
    {
        Vertex *aux = top;

        while (aux != nullptr)
        {
            if (aux->getCoordinate() == add->getCoordinate())
            {
                aux->edge = add->edge;
                return;
            }
            aux = aux->next;
        }
    }

    string graphAdjacentList()
    {
        counter = 1;
        content = "digraph G {\n rankdir=LR \n node[shape=box];\n";
        content = content + bodyStructure(top) + "\n";
        content = content + bodyEdge(top) + "\n";
        content = content + "}";
        return content;
    }

    string bodyStructure(Vertex *top)
    {
        string datag;
        Vertex *temp = top;

        datag = temp->getCoordinate() + "[ label = \"" + temp->getCoordinate() + "\", fontsize=12]; \n";
        temp = temp->next;

        while (temp != nullptr)
        {
            datag = datag + temp->getCoordinate() + "[ label = \"" + temp->getCoordinate() + "\", fontsize=12];\n";
            temp = temp->next;
        }

        temp = top;

        while (temp != nullptr)
        {
            if (temp->next != nullptr)
            {

                datag = datag + temp->getCoordinate() + "->" + temp->next->getCoordinate() + "[constraint=false];\n";
            }
            temp = temp->next;
        }

        return datag;
    }

    string bodyEdge(Vertex *top) // en este metodo esta el error
    {
        string datag = "";
        Vertex *temp = top;

        while (temp != nullptr)
        {
            Coordinates *aux = temp->edge->top;

            while (aux != nullptr)
            {
                datag = datag + aux->getLast() + to_string(counter) + "[ label = \"" + aux->getLast() + "\", fontsize=12]; \n"; // error this
                counter++;

                aux = aux->next;
            }
            temp = temp->next;
        }

        datag = datag + "\n";

        temp = top;
        counter = 1;
        bool flag = true;

        while (temp != nullptr)
        {
            Coordinates *aux = temp->edge->top;

            while (aux != nullptr)
            {
                if (flag == true)
                {
                    datag = datag + temp->getCoordinate() + "->" + aux->getLast() + to_string(counter) + ";\n";
                    flag = false;
                }

                if (aux->next != nullptr)
                {
                    int counte = counter;
                    datag = datag + aux->getLast() + to_string(counte) + "->" + aux->next->getLast() + to_string(++counter) + ";\n";
                }
                aux = aux->next;
            }

            temp = temp->next;

            if (flag == false)
            {
                flag = true;
                counter++;
            }
        }

        return datag;
    }

    string getGraph()
    {
        content = "digraph G {\nrankdir=LR;\n";
        content = content + bodyGraph(top) + "\n";
        content = content + "}";
        return content;
    }

    string bodyGraph(Vertex *top)
    {
        string datag = "";
        Vertex *temp = top;

        while (temp != nullptr)
        {
            Coordinates *aux = temp->edge->top;

            while (aux != nullptr)
            {
                datag = datag + aux->getFirst() + "->" + aux->getLast() + ";\n";
                aux = aux->next;
            }

            temp = temp->next;
        }
        return datag;
    }
};