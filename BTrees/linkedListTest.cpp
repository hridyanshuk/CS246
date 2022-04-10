#include <bits/stdc++.h>
#include "./LinkedListTemp.h"
using namespace std;


int main()
{
    int m;
    cin>>m;
    LinkedList l(m, 'i');
    Datatype d={.i=5};
    Node n;
    n.insert(d, 'i');
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    // l.printAll();
    cout<<l.deleteLast().value().DVdata.i<<endl;
    cout<<l.deleteLast().value().DVdata.i<<endl;
    cout<<l.deleteLast().value().DVdata.i<<endl;
    cout<<l.deleteFirst().value().DVdata.i<<endl;
    // l.printAll();
    l.insertValueRight(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    // l.printAll();
    // cout<<l.deleteFirst().value()<<endl;
    // l.printAll();
    // l.sort();
    n.modify('+',1);
    l.insertValueLeft(n, l.search(0));
    // cout<<l.search(0)->value()<<endl;
    l.printAll();
    // cout<<"Size is "<<l.size<<endl;
    l.sort();
    l.deleteValue(3);
    l.printAll();
    // Node* temp=l.search(3);
    // cout<<"Value at key 3 is "<<temp->value()<<endl;
    // Node s;
    // s.insert(10);
    // temp=l.search(s);
    // cout<<"Key of 10 Node is "<<temp->key<<endl;

    return 0;
}