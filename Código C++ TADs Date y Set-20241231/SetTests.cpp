#include <iostream>

using namespace std;

#include "Set1.h"
#include "Set2.h"
#include "Set.h"


void testSet(){
    char op;
    int n;
    Set<int> set;
    cout << set << endl;
    do{
        cout << "Choose option ((a)dd, (r)emove, (c)ontains, (s)ize, (e)xit)" << endl;
        cin >> op;
        if (op == 'a'){
            cin >> n;
            set.add(n);
        } else if (op == 'r'){
            cin >> n;
            set.remove(n);
        } else if (op == 'c'){
            cin >> n;
            cout << set.contains(n) << endl;
        } else if (op == 's'){
            cout << set.size() << endl;
        }
        cout << set << endl;
    } while (op != 'e');
    cout << "Program finished" << endl;
}

int main(){
    testSet();
}


