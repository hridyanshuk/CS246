#include <cstdlib>
#include <stdio.h>
class IndexNode
{
    public:
    IndexNode* parent;
    int* data;
    IndexNode*(*ptrs);
    int dataCapacity;
    int keyCapacity;
    int inserted;
    int ptrCapacity;
    bool dataNode;
    IndexNode(int, bool);
    void setChild();
    IndexNode* insert(int, int*, int*, IndexNode*);
    void print();
};
void IndexNode::print()
{
    for(int i=0 ; i<inserted-1 ; i++)
    {
        printf("%d ", data[i]);
    }
    printf("%d", data[inserted-1]);
}
IndexNode* IndexNode::insert(int value, int *iNode, int *dNode, IndexNode *n=nullptr)
{
    if(this->dataNode)
    {    
        if(inserted<dataCapacity)
        {
            int index=inserted;
            for(int i=0 ; i<inserted ; i++)
            {
                if(data[i]>value)
                {
                    index=i;
                }
            }
            for(int i=dataCapacity ; i>index ; i--)
            {
                data[i]=data[i-1];
                ptrs[i+1]=ptrs[i];
            }
            data[index]=value;
            if(n!=nullptr)
                ptrs[index+1]=n;
            inserted++;
            return nullptr;
        }
        else
        {
            *dNode=*dNode+1;
            IndexNode* temp=new IndexNode(this->dataCapacity, this->dataNode);
            int c;
            if(dataCapacity%2==0)
                c=dataCapacity/2;
            else
                c=(dataCapacity+1)/2;
            for(int i=dataCapacity-c ; i<dataCapacity ; i++)
            {
                temp->insert(this->data[i], iNode, dNode);
            }
            inserted-=c;
            IndexNode* p=this->parent;
            temp->parent=p;IndexNode* tempp;
            if(p==nullptr)
            {
                *iNode=*iNode+1;
                p=new IndexNode(keyCapacity);
                p->insert((this->data[inserted-1]+temp->data[(temp->inserted-1)])/2, iNode, dNode);
                p->ptrs[0]=this;
                p->ptrs[1]=temp;
                temp->parent=p;
                this->parent=p;
            }
            
            else
                tempp=p->insert((this->data[inserted-1]+temp->data[(temp->inserted-1)])/2, iNode, dNode, temp);
            if(tempp!=nullptr)
                return tempp;
            return p;
        }
    }
    else
    {
        if(inserted<dataCapacity)
        {
            int index=inserted;
            for(int i=0 ; i<inserted ; i++)
            {
                if(data[i]>value)
                {
                    index=i;
                }
            }
            for(int i=dataCapacity ; i>index ; i--)
            {
                data[i]=data[i-1];
                ptrs[i+1]=ptrs[i];
            }
            data[index]=value;
            if(n!=nullptr)
                ptrs[index+1]=n;
            inserted++;
            return nullptr;
        }
        else
        {
            *iNode=*iNode+1;
            IndexNode* temp=new IndexNode(this->dataCapacity, this->dataNode);
            int c;
            if(dataCapacity%2==0)
                c=dataCapacity/2;
            else
                c=(dataCapacity+1)/2;
            for(int i=dataCapacity-c ; i<dataCapacity ; i++)
            {
                temp->insert(this->data[i], iNode, dNode);
            }
            inserted-=c;
            IndexNode* p=this->parent;
            temp->parent=p;IndexNode* tempp;
            if(p==nullptr)
            {
                *iNode=*iNode+1;
                p=new IndexNode(keyCapacity);
                p->insert(this->data[inserted-1], iNode, dNode);
                this->inserted=this->inserted-1;
                p->ptrs[0]=this;
                p->ptrs[1]=temp;
                temp->parent=p;
                this->parent=p;
            }
            
            else
            {
                tempp=p->insert(this->data[inserted-1], iNode, dNode, temp);
                this->inserted=this->inserted-1;
            }
            if(tempp!=nullptr)
                return tempp;
            return p;
        }
    }
    return nullptr;
}
IndexNode::IndexNode(int dc, bool data=false)
{
    dataNode=data;
    dataCapacity=dc;
    ptrCapacity=dc+1;
    inserted=0;
    ptrs=(IndexNode*(*))calloc(sizeof(IndexNode*), ptrCapacity);
    if(data)
    {
        delete ptrs;
        ptrs=nullptr;
    }
    else
    {
        for(int i=0 ; i<ptrCapacity ; i++)
            ptrs[i]=nullptr;
    }

    data=(int*)calloc(sizeof(int), dataCapacity);
}

class BTree
{    
    public:
    int dataCapacity, keyCapacity;
    int iNode;
    int dNode;
    IndexNode *root;
    BTree(int, int);
    public:
    void insert(int);
};

BTree::BTree(int dnc, int knc)
{
    iNode=0;
    dNode=0;
    dataCapacity=dnc;
    keyCapacity=knc;
    root=new IndexNode(dnc, true);

    
};

void BTree::insert(int value)
{
    IndexNode *temp=root;
    while(!temp->dataNode)
    {
        for(int i=0 ; i<temp->inserted ; i++)
        {
            if(value<temp->data[i])
            {
                temp=temp->ptrs[i];
                break;
            }
            else
                temp=temp->ptrs[i+1];
        }
    }
    temp->insert(value, &iNode, &dNode);
    if(root->parent!=nullptr)
    {
        while(root->parent!=nullptr)
        root=root->parent;
    }
}