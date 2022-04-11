class Block;
union Datatype{
    int i;
    char c;
    float f;
    Block* blockAddr;
};

#include "LinkedListTemp.h" 

class SplitLinkedLists
{
    public:
    LinkedList* split1;
    LinkedList* split2;
};

class Block
{
    
    char type;
    bool index;
    public:
    IndexNode* parent;
    // Block *ptrs;
    LinkedList *values;
    Block(int, char, bool);
    SplitLinkedLists splitValues(Block*, int);
    // SplitLinkedLists splitPtrs(Block*, int);
    bool insertValue();
    void splitParent(int);
};

Block::Block(int numNodes, char t, bool index=true)
{
    this->index=index;
    parent=nullptr;
    type=t;
    if(index)
    {}
        // ptrs = new LinkedList(numNodes+1, 'b');
    // else ptrs=nullptr;
    values = new LinkedList(numNodes, type);
}

SplitLinkedLists Block::splitValues(Block* newBlock, int k)
{
    while(values->returnSize()!=k)
        newBlock->values->insertValueLeft(values->deleteLast());
    SplitLinkedLists returnValue={
        .split1=values,
        .split2=newBlock->values
    };
    return returnValue;
}