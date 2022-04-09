#include <stdio.h>
#include <string.h>
typedef int datatype;
// class datatype{};
const datatype MAX_datatype=INT_MAX;
char lt[]="<";
char le[]="<=";
char gt[]=">";
char ge[]=">=";
int datatypeComparator(datatype d1, datatype d2, char *operation)
{
    int op;
    if(strcmpi(operation, "<")==0)
    {
        op=0;
    }
    else if(strcmpi(operation, ">")==0)
    {
        op=1;
    }
    else if(strcmpi(operation, "<=")==0)
    {
        op=2;
    }
    else if(strcmpi(operation, ">=")==0)
    {
        op=3;
    }
    switch (op)
    {
    case 0:
        if(d1<d2) // To be changed
            return 1;
        else
            return 0;
        break;
    case 1:
        if(d1>d2) // To be changed
            return 1;
        else
            return 0;
    case 2:
        if(d1<=d2)
            return 1;
        else
            return 0;
        break;
    case 3:
        if(d1>=d2)
            return 1;
        else
            return 0;
    default:
        break;
    }
    return 10;
}
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
    
    int maxSize;
    Node* start;
    Node* end;
    public:
    int size;
        LinkedList(int);
        void initialise();
        void insertValueLeft(Node, Node*);  // Inserts a node with data in function argument on left
        void insertValueRight(Node, Node*); // Inserts a node with data in function argument on right
        Node deleteLast();                  // Deletes the last node
        Node deleteFirst();                 // Deletes the first node
        // void insertLeft();               // Inserts a node with data values 0 on left
        // void insertRight();              // Inserts a node with data values 0 on right
        Node deleteNode(Node *);            // Deletes a node
        Node deleteValue(Node);             // Searches a value and deletes the node
        Node deleteValue(int);              // Searches a key and deletes the node
        Node* search(Node);                 // Searches a value
        Node* search(int);                  // Searches a value by it's key
        void setKeys();                     // Assigns keys to all Nodes
        void sort(bool);                    // Sorts ascending or descending
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
            size++;
            Node *temp=new Node;
            if(start==node)
                start=temp;
            temp->insert(value.value());// Insert value in temp
            temp->right=node;
            temp->left=node->left;
            if(node->left!=nullptr)
                node->left->right=temp;
            node->left=temp;
            
        }
        setKeys();
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
                start->key=0;
            }
            else
            {
                int key=end->key;
                Node *temp=new Node;
                temp->insert(value.value());// Insert value in temp
                temp->key=key;
                temp->left=end;
                temp->right=nullptr;
                end->right=temp;
                end=temp;
            }
        }
        else
        {
            size++;
            Node *temp=new Node;
            if(end==node)
                end=temp;
            temp->insert(value.value());// Insert value in temp
            temp->left=node;
            temp->right=node->right;
            if(node->right!=nullptr)
                node->right->left=temp;
            node->right=temp;
            
            setKeys();

        }
    }
}

Node LinkedList::deleteLast()
{
    Node temp=*end;
    Node *tempL=end;
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
    Node *tempR=start;
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
    setKeys();
    return temp;
}

Node LinkedList::deleteNode(Node *node)
{
    if(start==node)
    {
        start=node->right;
    }
    if(end==node)
    {
        end=node->left;
    }
    if(node->left!=nullptr)
        node->left->right=node->right;
    if(node->right!=nullptr)
        node->right->left=node->left;
    Node returnNode=*node;
    delete node;
    size--;
    setKeys();
    return returnNode;
}

Node LinkedList::deleteValue(Node node)
{
    Node *temp=search(node);
    Node returnNode=*temp;
    deleteNode(temp);// Size already decremented
    return returnNode;
}

Node LinkedList::deleteValue(int key)
{
    Node *temp=search(key);
    Node returnNode=*temp;
    deleteNode(temp);
    return returnNode;
}

Node* LinkedList::search(Node value)
{
    Node* temp1=start;
    Node* temp2=end;
    if(temp1==temp2)
    {
        if(temp1->value()==value.value())
            return temp1;
    }
    while(temp1!=temp2 && temp1!=temp2->right)
    {
        if(temp1->value()==value.value())
        {
            return temp1;
        }
        else if(temp2->value()==value.value())
        {
            return temp2;
        }
        temp1=temp1->right;
        temp2=temp2->right;
    }
    return nullptr;
}

Node* LinkedList::search(int key)
{
    if(key>size)
    {
        return nullptr;
    }
    Node* temp;
    if(key<size-key-1)
    {
        temp=start;
        for(int i=0 ; i<key ; i++)
        {
            temp=temp->right;
        }
    }
    else
    {
        temp=end;
        for(int i=0 ; i<size-key-1 ; i++)
        {
            temp=temp->left;
        }
    }
    return temp;
}

void LinkedList::setKeys()
{
    int key=0;
    Node* temp=start;
    while(temp!=nullptr)
    {
        temp->key=key;
        key++;
        temp=temp->right;
    }
}

void LinkedList::sort(bool ascending=true)
{
    if(ascending)
    {
        for(int i=0 ; i<size ; i++)
        {
            datatype min=MAX_datatype;
            Node *minNode;
            int mindex;
            for(int j=i ; j<size ; j++)
            {
                Node *temp=search(j);
                if(datatypeComparator(min,temp->value(),gt)==1)
                {
                    mindex=j;
                    min=temp->value();
                    minNode=temp;
                }
            }
            if(i!=mindex)
            {
                Node temp=*minNode;
                deleteNode(minNode);          
                insertValueLeft(temp, search(i));
                min=MAX_datatype;
            }
        }
    }
}

void LinkedList::printAll()
{
    Node *temp=start;
    while(temp!=end && temp!=nullptr)
    {
        printf("[%d  %d] --- ",temp->key, temp->value());
        temp=temp->right;
    }
    printf("[%d  %d]\n",temp->key, temp->value());
}