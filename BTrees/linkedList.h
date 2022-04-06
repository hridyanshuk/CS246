class node
{
    //datatype data;
    int key;
    node* right;
    node* left;
};
class linkedList
{
    int size;
    int max;
    node* start;
    node* end;
    public:
        linkedList(int);
        void initialise();
        void insertValueLeft(); // Inserts a node with data in function argument on left
        void insertValueRight();// Inserts a node with data in function argument on right
        void deleteLast();      // Deletes the last node
        void deleteFirst();     // Deletes the first node
        void insertLeft();      // Inserts a node with data values 0 on left
        void insertRight();     // Inserts a node with data values 0 on right
        void deleteValue(node); // Searches a value and deletes the node
        void deleteValue(int);  // Searches a key and deletes the node
        void search(node);      // Searches a value
        void search(int);       // Searches a value by it's key
        void sort(bool);        // Sorts ascending or descending
};

linkedList::linkedList(
    int maxSize
)
{
    maxSize=m;
}

void linkedList::initialise()
{
    start=nullptr;
    end=nullptr;
    size=0;
}