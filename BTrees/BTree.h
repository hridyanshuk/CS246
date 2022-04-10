#include "Block.h"

class BTree
{
    Block root;
    int dataNodeCapacity;
    int indexNodeCapacity;
    
    public:
    BTree(int, int);
    int insertData(Datatype);

};

BTree::BTree(int dnc, int inc)
{
    dataNodeCapacity=dnc;
    indexNodeCapacity=inc;
}
