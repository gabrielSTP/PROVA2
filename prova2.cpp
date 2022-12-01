#include <stdio.h>
#include <iostream>
using namespace std;

typedef int dado;

struct No
{
    dado valor;
    No *prox;

    No(dado _valor)
    {
        valor = _valor;
        prox = NULL;
    }
};

struct Node
{
    dado valor;
    Node *prox;

    Node()
    {
        prox = NULL;
    }

    Node(dado _valor)
    {
        valor = _valor;
        prox = NULL;
    }

    void print()
    {
        printf("%d -> ", valor);
    }
};

struct Pilha
{

    No *cabeca;
    int s;

    Pilha()
    {
        cabeca = NULL;
        s = 0;
    }

    bool empty()
    {
        return (cabeca == NULL);
    }

    int size()
    {
        return s;
    }

    void push(dado e)
    {
        if (empty())
        {
            cabeca = new No(e);
        }
        else
        {
            No *novo = new No(e);
            novo->prox = cabeca;
            cabeca = novo;
        }
        s++;
    }

    void pop()
    {
        if (!empty())
        {
            No *aux = cabeca;
            cabeca = cabeca->prox;
            delete (aux);
            s--;
        }
    }

    dado top()
    {
        if (!empty())
        {
            cout << cabeca->valor;
        }
        else
        {
            return 0;
        }
    }
};

struct Fila
{

    Node *cabeca, *cauda;
    int size;

    Fila()
    {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    bool empty()
    { // O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node *enqueue(dado valor)
    { // O(1) - push back
        Node *novo = new Node(valor);
        if (empty())
        {
            cabeca = novo;
            cauda = novo;
        }
        else
        {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node *dequeue()
    { // O(1) -- pop front
        if (!empty())
        {
            if (cabeca == cauda)
            { // Apenas 1 elemento
                delete (cabeca);
                cabeca = NULL;
                cauda = NULL;
            }
            else
            {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete (tmp);
            }
            size--;
        }
        return cabeca;
    }

    dado front()
    {
        if (!empty())
        {
            return cabeca->valor;
        }
        else
        {
            return 0;
        }
    }

    void printQueue()
    {
        Node *tmp = cabeca;
        if (empty())
        {
            cout << "Fila vazia!" << endl;
        }
        else
        {
            while (tmp != NULL)
            {
                cout << tmp->valor << endl;
                tmp = tmp->prox;
            }
        }
    }

    void invertqueue()
     {
         if (!empty())
         {
             Pilha p;
             if (cabeca == cauda)
             {
                cout<<"Impossivel inverter fila de apenas um elemento!";
             }
             else
             {
                 Node *tmp = cabeca;
                 while (tmp->prox != NULL)
                 {
                     cabeca = cabeca->prox;
                     p.push(tmp->valor);
                     delete(tmp);
                     tmp = cabeca;
                 }
             }
             No *tmp = p.cabeca;
             while(p.cabeca != NULL){
                p.cabeca = p.cabeca->prox;
                enqueue(tmp->valor);
                delete (tmp);
                tmp = p.cabeca;
             }
         }
     }
};

int main()
{ 
     
    Fila f;

    f.enqueue(1);
    f.enqueue(2);
    f.enqueue(3);
    f.enqueue(4);
    f.enqueue(5);
    f.enqueue(6);
    f.enqueue(7);
    f.printQueue();
    cout<<"\n";//Apenas para separar as duas filas
    f.invertqueue();
    cout<<"\n";
    f.printQueue();
    
    return 0;
}