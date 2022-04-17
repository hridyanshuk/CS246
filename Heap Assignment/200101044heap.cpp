#include <bits/stdc++.h>
using namespace std;
class Page
{
    public:
    int id;
    int size;
    int remainingSpace;
    vector<int> recordPtr;
    vector<int> primaryKeys;
    Page* previous;
    Page* next;
    int nofRec;
    int freeSpacePtr;
    Page(int);
    bool insert(int, int);
    bool exists(int, int*);
};
bool Page::exists(int pKey, int* slotId)
{
    for(int i=0 ; i<freeSpacePtr ; i++)
    {
        if(primaryKeys[i]==pKey)
        {
            *slotId=i;
            return true;
        }
    }
    return false;
}
Page::Page(int size)
{
    this->size=size;
    nofRec=0;
    freeSpacePtr=0;
    remainingSpace=size-4-4-4-4;
    previous=NULL;
    next=NULL;
}
bool Page::insert(int size, int pKey)
{
    if(remainingSpace<size+4)
    {
        return false;
    }
    nofRec++;
    recordPtr.push_back(freeSpacePtr);
    primaryKeys.push_back(pKey);
    freeSpacePtr++;
    remainingSpace=remainingSpace-4-size;
    return true;
}

class Heap
{
    public:
    Page* start;
    Page* end;
    int nofPages;
    Heap(int);
    int pageSize;
    void insert(int, int);
    void createNewPage();
    void search(int);
    void status();
};
void Heap::status()
{
    cout<<nofPages;
    if(nofPages>0)
    {
        cout<<" ";
        Page* temp=start;
        while(temp->next!=NULL)
        {
            cout<<temp->nofRec<<" ";
            temp=temp->next;
        }
        cout<<temp->nofRec;
    }
    cout<<endl;
}
void Heap::search(int pKey)
{
    Page* temp=start;
    int pageId=-1;
    int slotId=-1;
    while(temp!=NULL)
    {
        if(temp->exists(pKey, &slotId)==true)
        {
            pageId=temp->id;
            break;
        }
        temp=temp->next;
    }
    cout<<pageId<<" "<<slotId<<endl;
}
void Heap::insert(int size, int pKey)
{
    if(start!=NULL && end!=NULL)
    {
        Page* temp=start;
        while(temp!=end)
        {
            if(temp->insert(size, pKey)==true)
                return;
            temp=temp->next;
        }
        if(end->insert(size, pKey)==false)
        {
            createNewPage();
            end->insert(size, pKey);
        }
    }
    else
    {
        createNewPage();
        end->insert(size, pKey);
    }
}
void Heap::createNewPage()
{
    if(start==NULL)
    {
        start=new Page(pageSize);
        end=start;
        start->id=0;
        nofPages+=1;
        return;
    }
    Page* temp=new Page(pageSize);
    end->next=temp;
    temp->previous=end;
    end=temp;
    end->id=end->previous->id+1;
    nofPages+=1;
}
Heap::Heap(int size)
{
    start=NULL;
    end=NULL;
    
    nofPages=0;
    pageSize=size;
}
int main()
{
    int pageSize;
    cin>>pageSize;
    Heap h(pageSize);
    int input=0;
    do
    {
        cin>>input;
        int x, y, z;
        switch (input)
        {
        case 1:
            cin>>x>>y;
            h.insert(x,y);
            break;
        case 2:
            h.status();
            break;
        case 3:
            cin>>z;
            h.search(z);
            break;
        }
    } while (input!=4);
    
    return 0;
}