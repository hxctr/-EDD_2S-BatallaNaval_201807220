#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
private:
public:
    int x;
    int y;
    Node *next;

    Node(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->next = nullptr;
    }

    int getX()
    {
        return this->x;
    }

    int getY()
    {
        return this->y;
    }
};

class AuxList
{
private:
public:
    Node *start;
    int size;
    AuxList()
    {
        this->start = nullptr;
        this->size = 0;
    }

    void insert(int x, int y)
    {
        Node *node = new Node(x, y);
        if (this->start == nullptr)
        {
            this->start = node;
        }
        else
        {
            Node *temp = this->start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        this->size++;
    }

    bool seachPos(int x, int y){
        Node *temp = this->start;
        while (temp != nullptr)
        {
            if (temp->x == x && temp->y == y)
            {
                return true;
            }
            temp = temp->next;
            
        }
        return false;
        
    }

    int getSize(){
        return this->size;
    }

    void display()
    {
        Node *temp = this->start;

        if (temp == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "---------" << endl;
            while (temp != nullptr)
            {
                cout << "X: " + to_string(temp->x) + ", Y: " + to_string(temp->y) + "\n";
                temp = temp->next;
            }
        }
    }


    void deleteByGivenInfo(int x, int y)
    {
        Node *temp = start;
        Node *prev = nullptr;

        while ( temp != nullptr && ((temp->x != x) || (temp->y != y)) )
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            if (prev == nullptr)
            {
               start = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            size--;
            delete temp;
        }
    }

    vector<string> sendXsToPY(){
        Node *temp = this->start;
        vector<string> xvec;

        while (temp != nullptr)
        {
            xvec.push_back(to_string(temp->x));
            temp = temp->next;
        }
        return xvec;
    }

    vector<string> sendYsToPY(){
        Node *temp = this->start;
        vector<string> yvec;

        while (temp != nullptr)
        {
            yvec.push_back(to_string(temp->y));
            temp = temp->next;
        }
        return yvec;
    }
};

