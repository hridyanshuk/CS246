#include <iostream>
class Node
{
    public:
    int data;
    Pointer *parent;
};

class Block
{
    IndexNode *parent;
    
    int maxDataCount;
    int dataInserted;
    public:
    Node *values;
    Block(int);
    bool insert(Node);
    
};
Block::Block(int dnc)
{
    dataInserted=0;
    maxDataCount=dnc;
    values=(Node*)calloc(sizeof(Node),maxDataCount);
}
bool Block::insert(Node node)
{
    if(dataInserted<maxDataCount)
    {
        int index;
        for(int i=0 ; i<dataInserted ; i++)
        {
            index=i;
            if(values[i].data>node.data)
            {
                break;
            }
        }
        std::cout<<index<<std::endl;
        for(int i=dataInserted-1 ; i>index; i--)
        {
            values[i]=values[i-1];
        }
        values[index]=node;
        dataInserted++;
        return true;
    }
    return false;
}