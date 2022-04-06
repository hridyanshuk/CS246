// class datatype{};
#include <stdio.h>
typedef int datatype;
class Node
{
    datatype data;
    public:
    void insert(datatype);
    void modify(char, int);
    datatype value();
    int key;
    Node* right;
    Node* left;
    
};

void Node::insert(datatype d)
{
    data=d;
}
void Node::modify(char op, int operand)
{
    switch(op)
    {
        case '+':
            data+=operand;
            break;
        case '-':
            data-=operand;
            break;
        case '*':
            data*=operand;
            break;
        case '/':
            data/=operand;
            break;
        case '%':
            data%=operand;
            break;
    }
}
datatype Node::value()
{
    return data;
}


class LinkedList
{
    int size;
    int maxSize;
    Node* start;
    Node* end;
    public:
        LinkedList(int);
        void initialise();
        void insertValueLeft(Node, Node*); // Inserts a node with data in function argument on left
        void insertValueRight(Node, Node*);// Inserts a node with data in function argument on right
        Node deleteLast();      // Deletes the last node
        Node deleteFirst();     // Deletes the first node
        // void insertLeft();      // Inserts a node with data values 0 on left
        // void insertRight();     // Inserts a node with data values 0 on right
        // void deleteValue(Node); // Searches a value and deletes the node
        // void deleteValue(int);  // Searches a key and deletes the node
        // void search(Node);      // Searches a value
        // void search(int);       // Searches a value by it's key
        // void sort(bool);        // Sorts ascending or descending
        void printAll();
};

LinkedList::LinkedList(
    int m
)
{
    maxSize=m;
    initialise();
}

void LinkedList::initialise()
{
    start=nullptr;
    end=nullptr;
    size=0;
}

void LinkedList::insertValueLeft(Node value, Node *node=nullptr)
{
    if(size<maxSize)
    {
        if(node==nullptr)
        {    
            size++;
            if(start==nullptr)
            {
                Node *temp=new Node;
                start=temp;
                start->left=start->right=nullptr;
                temp->insert(value.value());// Insert value in temp
                end=start;
            }
            else
            {
                Node *temp=new Node;
                temp->insert(value.value());// Insert value in temp
                temp->right=start;
                temp->left=nullptr;
                start->left=temp;
                start=temp;
            }
        }
        else
        {
            Node *temp=new Node;
            temp->insert(value.value());// Insert value in temp
            temp->right=node;
            temp->left=node->left;
            node->left->right=temp;
            node->left=temp;
        }
    }
}


void LinkedList::insertValueRight(Node value, Node *node=nullptr)
{
    if(size<maxSize)
    {
        if(node==nullptr)
        {    
            size++;
            if(start==nullptr)
            {
                Node *temp=new Node;
                start=temp;
                start->left=start->right=nullptr;
                temp->insert(value.value());// Insert value in temp
                end=start;
            }
            else
            {
                Node *temp=new Node;
                temp->insert(value.value());// Insert value in temp
                temp->left=end;
                temp->right=nullptr;
                end->right=temp;
                end=temp;
            }
        }
        else
        {
            Node *temp=new Node;
            temp->insert(value.value());// Insert value in temp
            temp->left=node;
            temp->right=node->right;
            node->right->left=temp;
            node->right=temp;
        }
    }
}

Node LinkedList::deleteLast()
{
    Node temp=*end;
    Node *tempL=end->right;
    if(end->left!=nullptr)
        end->left->right=nullptr;
    end=end->left;
    if(size==1)
    {
        start=nullptr;
    }
    size--;
    delete tempL;
    return temp;
}

Node LinkedList::deleteFirst()
{
    Node temp=*start;
    Node *tempR=start->right;
    if(start->right!=nullptr)
    {
        start->right->left=nullptr;
    }
    start=start->right;
    if(size==1)
    {
        end=nullptr;
    }
    size--;
    delete tempR;
    return temp;
}

void LinkedList::printAll()
{
    Node *temp=start;
    while(temp!=end && temp!=nullptr)
    {
        printf("%d <=> ",temp->value());
        temp=temp->right;
    }
    printf("%d\n", temp->value());
}