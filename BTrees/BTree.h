#include "Block.h"

class BTree
{
    Block *root;
    int dataNodeCapacity;
    int indexNodeCapacity;
    int indexNodeCount;
    int dataNodeCount;
    public:
    BTree(int, int);
    int insertData(Datatype);

};

BTree::BTree(int dnc, int inc)
{
    dataNodeCapacity=dnc;
    indexNodeCapacity=inc;
    indexNodeCount=1;
    dataNodeCount=0;
    root=new Block(dnc, 'i');
}

int BTree::insertData(Datatype data, char type)
{
    if(dataNodeCount==0)
    {   
        Block *newDataBlock=new Block(dnc, type, false);
        root->ptrs->insertValueRight(newDataBlock);
        newDataBlock->values->insertValueLeft(data);
        newDataBlock->parent=root;
        dataNodeCount++;
    }
    else
    {
        Block *temp=root;
        while(temp->index!=false)
        {
            bool t=false;
            for(int i=0 ; i<temp->ptrs->returnSize() ; i++)
            {
                Node n;
                Block* tempI=temp->values->search(i);
                Block* tempIN=temp->ptrs->search(i);
                if(datatypeComparator(data, tempI->value().DVdata, lt))
                {
                    temp=tempIN;
                    t=true;
                    break;
                }
            }
            if(!t)
                temp=temp->ptrs->search(temp->ptrs->returnSize()-1);
        }
        Node *traverse=temp->values->search(0);
        bool t=false;
        for(int i=0 ; i<temp->values->returnSize() ; i++)
        {
            if(datatypeComparator(traverse->value, data, gt))
            {
                t=true;
                break;
            }
            traverse=traverse->right;
        }
        if(t)
        {
            if(temp->values->insertValueLeft(data, traverse)!=true)
            {
                Node lastNode=temp->values->deleteLast();
                temp->values->insertValueLeft(data, traverse);
                Block *newDataSplit=new Block(dnc, type, false);
                Block *newIndexSplit=new Block(inc, type, true);
                Node addressNode;
                addressNode.insert({.blockAddr=newDataSplit}, 'b');
                newDataSplit->values->insertValueLeft(lastNode);
                newDataSplit->parent=newIndexSplit;
                int split;
                if(dnc%2==0)
                    split=(dnc+1)/2;
                else
                    split=(dnc+1)/2;
                temp->splitValues(newDataSplit, split);
                temp->parent->splitValues(newIndexSplit, )
                for(int i=0 ; i<split ; i++)
                {
                    temp->ptrs->deleteLast();
                    newIndexSplit->ptrs->insertValueRight(addressNode);
                }
                while(temp!=root)
                {

                }
            }
            else
            {
                temp->parent->ptrs->insertValueRight(temp);
            }
        }
    }
    return 0;
}
