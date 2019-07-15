#include "SharedFile.h"
#include <iostream>

using namespace std;

int main()
{
    SingleLL *ptr = new SingleLL();
    ptr->InsertFirst(10);
    ptr->InsertFirst(20);
    ptr->InsertFirst(30);
    ptr->InsertFirst(40);
    ptr->InsertFirst(50);
    ptr->InsertFirst(60);
    ptr->Display();
    ptr->Delete(2);
    ptr->Display();
    ptr->Insert(2,70);
    ptr->Display();

    ptr->Delete(4);
    ptr->Display();
    ptr->Insert(3,80);
    ptr->Display();

    cout<<ptr->Find(80);
    return 0;
}
