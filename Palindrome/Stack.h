#pragma once
#include <stdexcept>
#include <iostream>
#include <cctype>// pour la fonction isspace()
#include <string>

using namespace std;
template <class MyType>
class Stack
{
private:
    MyType* values;
    int sommet;
    int capacity;
public:
    Stack();
    bool isEmpty() const;
    bool isFull();
    void resize();
    void Push(MyType object);
    MyType Pop();
    MyType Top() const;


    bool isPalindrome(std::string& exp);

    void PrintStack();

    ~Stack();
};


template<class MyType>
inline Stack<MyType>::Stack() : sommet(-1), capacity(2)
{
    this->values = new MyType[2];
}

template<class MyType>
inline bool Stack<MyType>::isEmpty() const
{
    return (sommet == -1);
}

template<class MyType>
inline bool Stack<MyType>::isFull()
{

    return (this->sommet == (this->capacity - 1));
}

// redimentionner la pile
template <class MyType>
void Stack<MyType>::resize() {
    this->capacity *= 2;
    MyType* NewStack = new MyType[this->capacity];
    for (int i = 0; i <= this->sommet; i++) {
        NewStack[i] = this->values[i];
    }
    delete[] this->values;
    this->values = NewStack;
}


// empiler un elemnet
template<class MyType>
inline void Stack<MyType>::Push(MyType object)
{
    if (isFull())
    {
        this->resize();
    }
    this->values[++this->sommet] = object;

}


// depiler un element
template<class MyType>
inline MyType Stack<MyType>::Pop()
{

    if (this->isEmpty()) {
        throw std::underflow_error("\nImpossible de dépiler : la pile est vide");
    }
    return this->values[this->sommet--];

}

template<class MyType>
inline MyType Stack<MyType>::Top() const
{
    if (isEmpty())
    {
        throw std::underflow_error("Top, la pile est vide");
    }
    return this->values[this->sommet];
}


// verifier si une chaine de caractere est un palyndrome
template<class MyType>
inline bool Stack<MyType>::isPalindrome(std::string& exp)
{
    Stack<MyType> stack1, stack2;// deux piles
    int lg = exp.length();// longueur de l'expression

    //verifier la validité de l'expression
    if (lg <= 0)
    {
        throw std::invalid_argument("La chaine est vide!!!");
    }

    // mettre la premiere moitié dans la pile 1
    for (int i = 0; i < lg / 2; i++)
    {
        if(!isspace(exp[i]))//ignorer les espaces
            stack1.Push(tolower(exp[i]));
    }
    
    // mettre la 2e moitié dans la pile 2
    for (int i = lg - 1; i >= (lg + 1) / 2; i--)
    {
        if (!isspace(exp[i]))
            stack2.Push(tolower(exp[i]));
    }

    // comparer chaque element des deux piles
    while (!stack1.isEmpty() && !stack2.isEmpty())
    {
        if (stack1.Pop() != stack2.Pop())
            return false;
    }

    return true;
}


template<class MyType>
inline void Stack<MyType>::PrintStack()
{
    if (this->isEmpty()) {
        std::cout << "La pile est vide" << std::endl;
        return;
    }
    for (int i = this->sommet; i >= 0; i--)
    {
        cout << this->values[i] << " ";
    }

    std::cout << std::endl;

}

template<class MyType>
inline Stack<MyType>::~Stack()
{
    delete[] this->values;
}

