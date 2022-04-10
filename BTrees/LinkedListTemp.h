#include <stdio.h>
#include <string.h>
// typedef int datatype;
// union Datatype{
    // int i;
    // char c;
    // float f;
// };
const Datatype MAX_datatype_i={
    .i=__INT_MAX__
};
struct DatatypeValue
{
    Datatype DVdata;
    char DVtype;
};
// const Datatype MAX_datatype=__INT_MAX__;
char lt[]="<";
char le[]="<=";
char gt[]=">";
char ge[]=">=";
char eq[]="==";

int datatypeComparator(Datatype d1, Datatype d2, char *operation, char type)
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
    else if(strcmpi)
        op=4;
    switch (op)
    {
        case 0:
            if(type='i')
            {
                if(d1.i<d2.i) // To be changed
                    return 1;
                else
                    return 0;
            }
            break;
        case 1:
            if(type='i')
            {
                if(d1.i>d2.i) // To be changed
                    return 1;
                else
                    return 0;
            }
        case 2:
            if(type='i')
            {
                if(d1.i<=d2.i) // To be changed
                    return 1;
                else
                    return 0;
            }
            break;
        case 3:
            if(type='i')
            {
                if(d1.i>=d2.i) // To be changed
                    return 1;
                else
                    return 0;
            }
        case 4:
            if(type='i')
            {
                if(d1.i==d2.i) // To be changed
                    return 1;
                else
                    return 0;
            }
        default:
            break;
    }
    return 10;
}
class Node
{
    char type;
    Datatype data;
    public:
    void insert(Datatype, char);
    void modify(char, int);
    DatatypeValue value();
    int key;
    Node* right;
    Node* left;
    
};

void Node::insert(Datatype d, char t)
{
    type=t;
    data=d;
}

void Node::modify(char op, int operand)
{
    if(type=='i')
    {
        switch(op)
        {
            case '+':
                data.i+=operand;
                break;
            case '-':
                data.i-=operand;
                break;
            case '*':
                data.i*=operand;
                break;
            case '/':
                data.i/=operand;
                break;
            case '%':
                data.i%=operand;
                break;
        }
    }
}
DatatypeValue Node::value()
{
    DatatypeValue dv;
    dv.DVtype=this->type;
    dv.DVdata=data;
    return dv;
}


class LinkedList
{
    char type;
    int maxSize;
    Node* start;
    Node* end;
    int size;

    public:
        LinkedList(int, char);
        void initialise();
        bool insertValueLeft(Node, Node*);  // Inserts a node with data in function argument on left
        bool insertValueRight(Node, Node*); // Inserts a node with data in function argument on right
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
        int returnSize();
};

LinkedList::LinkedList(
    int m,
    char type
)
{
    this->type=type;
    maxSize=m;
    initialise();
}

void LinkedList::initialise()
{
    start=nullptr;
    end=nullptr;
    size=0;
}

bool LinkedList::insertValueLeft(Node value, Node *node=nullptr)
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
                temp->insert(value.value().DVdata, type);// Insert value in temp
                end=start;
            }
            else
            {
                Node *temp=new Node;
                temp->insert(value.value().DVdata, type);// Insert value in temp
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
            temp->insert(value.value().DVdata, type);// Insert value in temp
            temp->right=node;
            temp->left=node->left;
            if(node->left!=nullptr)
                node->left->right=temp;
            node->left=temp;
            
        }
        setKeys();
        return true;
    }
    return false;
}


bool LinkedList::insertValueRight(Node value, Node *node=nullptr)
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
                temp->insert(value.value().DVdata, type);// Insert value in temp
                end=start;
                start->key=0;
            }
            else
            {
                int key=end->key;
                Node *temp=new Node;
                temp->insert(value.value().DVdata, type);// Insert value in temp
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
            temp->insert(value.value().DVdata, type);// Insert value in temp
            temp->left=node;
            temp->right=node->right;
            if(node->right!=nullptr)
                node->right->left=temp;
            node->right=temp;
            
            setKeys();

        }
        return true;
    }
    return false;
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
        if(datatypeComparator(temp1->value().DVdata,value.value().DVdata, eq, type))
            return temp1;
    }
    while(temp1!=temp2 && temp1!=temp2->right)
    {
        if(datatypeComparator(temp1->value().DVdata,value.value().DVdata, eq, type))
        {
            return temp1;
        }
        else if(datatypeComparator(temp2->value().DVdata,value.value().DVdata, eq, type))
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

void LinkedList::sort(bool ascending=true)// for integer types
{
    if(ascending)
    {
        if(type=='i')
        {
            for(int i=0 ; i<size ; i++)
            {
                Datatype min;
                min=MAX_datatype_i;//check
                Node *minNode;
                int mindex;
                for(int j=i ; j<size ; j++)
                {
                    Node *temp=search(j);
                    if(datatypeComparator(min,temp->value().DVdata,gt, type)==1)
                    {
                        mindex=j;
                        min=temp->value().DVdata;
                        minNode=temp;
                    }
                }
                if(i!=mindex)
                {
                    Node temp=*minNode;
                    deleteNode(minNode);          
                    insertValueLeft(temp, search(i));
                    min=MAX_datatype_i;//change
                }
            }
        }
    }
}

void LinkedList::printAll()
{
    Node *temp=start;
    while(temp!=end && temp!=nullptr)
    {
        printf("[%d  %d] --- ",temp->key, temp->value().DVdata.i);
        temp=temp->right;
    }
    printf("[%d  %d]\n",temp->key, temp->value().DVdata.i);
}

int LinkedList::returnSize()
{
    return size;
}