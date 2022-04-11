#include <bits/stdc++.h>
#include "BTreeTemp.h"
using namespace std;

int main()
{
    IndexNode i1(3);
    i1.insert(3);
    i1.insert(6);
    i1.insert(4);
    Block b1(4);
    Node n;
    n.data=3;

    b1.insert(n);
    n.data=7;
    b1.insert(n);
    n.data=4;
    b1.insert(n);
    n.data=10;
    b1.insert(n);
    for(int i=0 ; i<3 ; i++)
    {
        // cout<<i1.keys[i]<<" ";
        cout<<b1.values[i].data<<" ";
    }
    cout<<endl;
    return 0;
}