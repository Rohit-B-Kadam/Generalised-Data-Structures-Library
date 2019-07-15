#include<iostream>
#include "SharedFile.h"

using namespace std;

SingleLL::SingleLL()
{
    head = NULL;
}

SingleLL::~SingleLL()
{
    if (head== NULL)
        return;
    
    PNODE temp1,temp2;
    temp1 = head;

    while(temp1 == NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
}

void SingleLL::InsertFirst(int no)
{
    // Create new node
    PNODE newnode = new NODE;
    newnode->data =  no;
    newnode->next = NULL;

    newnode->next = head;
    head = newnode;
}

void SingleLL::InsertLast(int no)
{
    // Create new node
    PNODE newnode = new NODE;
    newnode->data =  no;
    newnode->next = NULL;

    PNODE temp = head;
    // traverse till last node
    while( temp->next != NULL )
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void SingleLL::DeleteFirst()
{
    if (head == NULL)
        return;
    
    PNODE temp = head;
    head = head->next;
    delete temp;
}    

void SingleLL::DeleteLast()
{
    PNODE temp = head;
    PNODE delNode;

    // traverse till Second last node
    while( temp->next->next != NULL )
    {
        temp = temp->next;
    }

    delNode = temp->next;
    temp->next = NULL;
    delete delNode;
}


// Basic Operation of LinkList
void SingleLL::Insert(int pos, int no)
{
    int count = Count();

    if( pos <= 0 || pos >= count + 1)
    {
        cout<<"Invalid Position";
        return;
    }

    if( pos == 1)
        InsertFirst(no);
    else if (pos == count + 1)
        InsertLast(no);
    else
    {
        // Create new node
        PNODE newnode = new NODE;
        newnode->data =  no;
        newnode->next = NULL;

        PNODE temp = head;
        while(pos-2 != 0)
        {
            temp = temp->next;
            pos--;
        }

        // logic
        newnode->next = temp->next;
        temp->next = newnode;
    }

    
}

void SingleLL::Delete(int pos)
{
    int count = Count();

    if( pos <= 0 || pos >= count + 1)
    {
        cout<<"Invalid Position";
        return;
    }

    if( pos == 1)
        DeleteFirst();
    else if (pos == count + 1)
        DeleteLast();
    else
    {
        PNODE temp = head;
        PNODE delNode = NULL;

        while(pos-2 != 0)
        {
            temp = temp->next;
            pos--;
        }

        // logic
        delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}

int SingleLL::Count()
{
    int count = 0;
    PNODE temp = head;

    // traverse full list node
    while( temp != NULL )
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int SingleLL::Find(int no)
{
    int pos = -1;           // -1 not found
    int count = 0;
    PNODE temp = head;

    // traverse full list node
    while( temp != NULL )
    {
        count++;
        if(temp->data == no)
        {
            pos = count;
            break;
        }
        temp = temp->next;
    }
    return pos;
}

void SingleLL::Display()
{
    cout<<"Data Contains:";
    PNODE temp = head;

    while(temp != NULL)
    {
        cout<< "[" << temp->data << "]--->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}



// Object Creater Function

extern "C"
{
    SingleLL* CreateSingleLL()
    {
        return new SingleLL();
    }

    void DestroySingleLL(SingleLL* p)
    {
        delete p;
    }
}