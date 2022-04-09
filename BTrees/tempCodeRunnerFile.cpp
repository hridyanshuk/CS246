#include <bits/stdc++.h>
#include "./LinkedList.h"
using namespace std;


int main()
{
    int m;
    cin>>m;
    LinkedList l(m);
    datatype d=5;
    Node n;
    n.insert(d);
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
    l.printAll();
    cout<<l.deleteLast().value()<<endl;
    cout<<l.deleteLast().value()<<endl;
    cout<<l.deleteLast().value()<<endl;
    cout<<l.deleteFirst().value()<<endl;
    l.printAll();
    l.insertValueRight(n);
    n.modify('+',1);
    l.insertValueLeft(n);
    l.printAll();
    cout<<l.deleteFirst().value()<<endl;
    l.printAll();

    Node* temp=l.search(3);
    cout<<"Value at key 3 is "<<temp->value()<<endl;
    Node s;
    s.insert(10);
    temp=l.search(s);
    cout<<"Key of 10 Node is "<<temp->key<<endl;
    return 0;
}