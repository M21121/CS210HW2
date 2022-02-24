#include "List.h"
#include "Stack.h"
//#include "Queue.h"

#include <stdlib.h>
#include <vector>
#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree bst;
    Employee a = Employee(5, 30, "Alice");
    auto b = Employee(1, 30, "Bob");
    auto c = Employee(2, 30, "Charley");
    auto d = Employee(3, 30, "David");
    bst.insert(a);
    bst.insert(b);
    bst.insert(c);
    bst.insert(d);
    //bst.find(1);


}