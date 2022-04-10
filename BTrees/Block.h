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
    public:
    LinkedList *ptrs;
    LinkedList *values;
    Block(int, char);
    SplitLinkedLists splitValues(Block*, int);
    SplitLinkedLists splitPtrs(Block*, int);
    bool insertValue();
};

Block::Block(int n, char t)
{
    type=t;
    ptrs = new LinkedList(n+1, 'b');
    values = new LinkedList(n, type);
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

SplitLinkedLists Block::splitPtrs(Block* newBlock, int k)
{
    while(ptrs->returnSize()!=k)
        newBlock->ptrs->insertValueLeft(ptrs->deleteLast());
    SplitLinkedLists returnValue={
        .split1=ptrs,
        .split2=newBlock->ptrs
    };
    return returnValue;
}