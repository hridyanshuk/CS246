#include <bits/stdc++.h>
#include "Block.h"

using namespace std;

int main()
{
    int m;
    cin>>m;
    Block b(m,'i');
    Node n, n_int;
    Datatype d={
        .blockAddr=new Block(m, 'i')
    };
    n.insert(d, 'b');
    b.ptrs->insertValueLeft(n);
    Datatype d_int={.i=4};
    n_int.insert(d_int, 'i');

    b.ptrs->search(0)->value().DVdata.blockAddr->values->insertValueLeft(n_int);
    d.blockAddr=new Block(m, 'i');
    n.insert(d, 'b');
    b.ptrs->insertValueLeft(n);
    

    b.values->insertValueLeft(n_int);
    n_int.modify('+', 1);
    b.ptrs->search(0)->value().DVdata.blockAddr->values->insertValueLeft(n_int);
    b.ptrs->search(1)->value().DVdata.blockAddr->values->insertValueLeft(n_int);
    b.values->insertValueLeft(n_int);
    n_int.modify('+', 1);
    b.values->insertValueLeft(n_int);
    n_int.modify('+', 1);
    b.values->insertValueLeft(n_int);
    n_int.modify('+', 1);
    b.values->insertValueLeft(n_int);
    cout<<"root node values:\n";
    b.values->printAll();
    cout<<"pointer location 1 values:\n";
    b.ptrs->search(0)->value().DVdata.blockAddr->values->printAll();
    cout<<"pointer location 2 values:\n";
    b.ptrs->search(1)->value().DVdata.blockAddr->values->printAll();
    Block b1(m, 'i');
    b.splitValues(&b1, 1);
    b.values->printAll();
    b1.values->printAll();
    return 0;
}