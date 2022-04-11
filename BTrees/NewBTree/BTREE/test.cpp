#include <bits/stdc++.h>
#include "btree.h"
using namespace std;

int main()
{
    int d, i;
    cin>>d>>i;
    BTree b(d, i);
    int c;
    do
    {
        cin>>c;
        int x;
        switch(c)
        {
            case 1:
                cin>>x;
                b.insert(x);
                break;
            case 2:
                cout<<b.iNode<<" "<<b.dNode<<" ";
                b.root->print();
        }
    }while(c!=3);
    return 0;
}