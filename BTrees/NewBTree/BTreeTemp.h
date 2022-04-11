#include <cstdlib>
class IndexNode;
class Node;
union Pointer
{
    Node* blockAddr;
    IndexNode* indexNodeAddr;
};
#include "Block.h"

class IndexNode
{
    bool dataChild;
    int maxKeyCount;
    int keysInserted;
    public:
    Pointer *ptrs;
    IndexNode *parent;
    int *keys;
    IndexNode(int, bool);
    bool insert(int);
    void insertPointer(Pointer);
    int returnKeyCount();
};
int IndexNode::returnKeyCount()
{
    return keysInserted;
}
IndexNode::IndexNode(int inc, bool dataChild=false)
{
    this->dataChild=dataChild;
    keysInserted=0;
    maxKeyCount=inc;
    ptrs=(Pointer *)calloc(sizeof(Pointer), inc+1);
    keys=(int*)calloc(sizeof(int), inc);
}
bool IndexNode::insert(int newKey)
{
    if(keysInserted<maxKeyCount)
    {
        keys[keysInserted]=newKey;
        keysInserted++;
        return true;
    }
    return false;
}



class BTree
{
    IndexNode *root;
    public:
    // insert();

};