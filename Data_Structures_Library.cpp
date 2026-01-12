//////////////////////////////////////////////////////////////////////////////////////////////////////
//                              Generalised Data Structures Library
//////////////////////////////////////////////////////////////////////////////////////////////////////

/*
-------------------------------------------------------------------------------------------------------------------------
Type               |  Name of class for node            |  Name of class for functionality              |   Status
-------------------------------------------------------------------------------------------------------------------------
Singly Linear      |     SinglyLLLnode                  |     SinglyLLL                                 |    Done
Singly Circular    |     SinglyCLLnode                  |     SinglyCLL                                 |    Done
Doubly Linear      |     DoublyLLLnode                  |     DoublyLLL                                 |    Done
Doubly Circular    |     DoublyCLLnode                  |     DoublyCLL                                 |    Done
Stack              |     Stacknode                      |     Stack                                     |    Done
Queue              |     Queuenode                      |     Queue                                     |    Done
-------------------------------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                      Singly Linear Linked List using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public :
        SinglyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();

        void Display();
        int Count();

        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no) 
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next=this->first;
    this->first=newn;
    
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at Last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while (temp ->next != NULL)
        {
            temp = temp -> next;
        }
        
        temp->next = newn;

    }
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first -> next;
        delete temp;
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteLast
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }

        delete temp ->next;
        temp->next = NULL;

    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input :             Nothing
//      Output :            Data of nodes
//      Description :       Used to display data of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input :             Nothing
//      Output :            Count of nodes
//      Description :       Used to count number of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input :             Data and position of node
//      Output :            Nothing
//      Description :       Used to insert node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertAtPos(T no , int pos)
{

    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt =1; iCnt < pos-1; iCnt++)
        {
            temp = temp ->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input :             Position of node
//      Output :            Nothing
//      Description :       Used to delete node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt =1; iCnt < pos-1; iCnt++)
        {
        temp = temp ->next;
        }

        target = temp->next;

        temp->next = target ->next;
        delete target;

        this->iCount--;

    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//                      Doubly Linear Linked List using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();

};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input :             Data and position of node
//      Output :            Nothing
//      Description :       Used to insert node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL; 
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (pos == 1)
    {
        this->InsertFirst(no);
    }
    else if (pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
      
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteLast
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;
    if(this->first == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input :             Position of node
//      Output :            Nothing
//      Description :       Used to delete node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if (pos == 1)
    {
        this->DeleteFirst();
    }
    else if (pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for(iCnt = 1; iCnt < pos-1 ; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input :             Nothing
//      Output :            Data of nodes
//      Description :       Used to display the data of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;
    temp = this->first;

    cout<<"\nNULL<=>";
    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input :             Nothing
//      Output :            Count of nodes
//      Description :       Used to count number of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               06/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                      Singly Circular Linked List using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> *first;
        SinglyCLLnode<T> *last;
        int iCount;

    public:
        SinglyCLL();

        void InsertFirst(T);
        void InsertLast(T);

        void DeleteFirst();
        void DeleteLast();

        void Display();
        int Count();

        void InsertAtPos(T , int);
        void DeleteAtPos(int);
};

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"Object of SinglyCLL gets Created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    this->last->next = this->first;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> *newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->last->next = this->first;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
        this->last->next = this->first;
    }

    this->iCount--;
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteLast
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> *temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if (this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        while (temp->next != this->last)
        {
            temp = temp->next;
        }
        delete this->last;
        this->last = temp;
        
        this->last->next = this->first;
    }

    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input :             Nothing
//      Output :            Data of nodes
//      Description :       Used to display the data of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: Display()
{
    do
    {
        cout<<"| "<<this->first->data<<" |->";
        this->first = this->first->next;
    } while (first != last->next);
    cout<<"\n";   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input :             Nothing
//      Output :            Count of nodes
//      Description :       Used to count number of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input :             Data and position of node
//      Output :            Nothing
//      Description :       Used to insert node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no , int pos)
{
    SinglyCLLnode<T> *newn = NULL;
    SinglyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp= temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input :             Position of node
//      Output :            Nothing
//      Description :       Used to delete node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    SinglyCLLnode<T> *temp = NULL;
    SinglyCLLnode<T> *target = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp= temp->next;
        }
        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                      Doubly Circular Linked List using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> *first;
        DoublyCLLnode<T> *last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T , int);
        void DeleteAtPos(int);

};

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertFirst
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last; 

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertLast
//      Input :             Data of node
//      Output :            Nothing
//      Description :       Used to insert node at last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last; 

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteFirst
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at first position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next;
        delete this->first->prev;

        this->last->next = this->first;
        this->first->prev = this->last; 
    }
    this->iCount--;
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteLast
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete node at last position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if (this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;
        delete this->last->next;

        this->last->next = this->first;
        this->first->prev = this->last; 
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input :             Nothing
//      Output :            Data of nodes
//      Description :       Used to display the data of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    cout<<"\n<=>";
    do
    {
        cout<<"| "<<this->first->data<<" |<=>";
        this->first = this->first->next;
    } while (this->first != this->last->next);
    cout<<"\n";
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input :             Nothing
//      Output :            Count of nodes
//      Description :       Used to count number of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      InsertAtPos
//      Input :             Data and position of node
//      Output :            Nothing
//      Description :       Used to insert node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no , int pos)
{
    DoublyCLLnode<T> *newn = new DoublyCLLnode<T>(no);
    DoublyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if (pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      DeleteAtPos
//      Input :             Position of node
//      Output :            Nothing
//      Description :       Used to delete node at given position
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               07/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        
    }
    this->iCount--;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  Stack using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(1)
template<class T>

class Stacknode
{
    public:
        T data;
        Stacknode<T> *next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();
        void push(T);
        T pop();
        T peep();
        void Display();
        int Count();
};

template<class T>
Stack<T> :: Stack()
{
    cout<<"Stack gets created Succesfully.....\n";
    this->first = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Push
//      Input :             Data of nodes
//      Output :            Nothing
//      Description :       Used to insert nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> *newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Pop
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      peep
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to read the nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input :             Nothing
//      Output :            Data of nodes
//      Description :       Used to display the data of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
    
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input :             Nothing
//      Output :            Count of nodes
//      Description :       Used to count the nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  Queue using Generic Approach
//////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();
        void enqueue(T);
        T dequeue();
        void Display();
        int Count();
};

template<class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created Succesfully.....\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      enqueue
//      Input :             Data of nodes
//      Output :            Nothing
//      Description :       Used to insert the data into queue
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }
    
    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      dequeue
//      Input :             Nothing
//      Output :            Nothing
//      Description :       Used to delete the data from queue
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Display
//      Input :             Nothing
//      Output :            Data of nodes
//      Description :       Used to display the data of nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name:      Count
//      Input :             Nothing
//      Output :            Count of nodes
//      Description :       Used to count the nodes
//      Author :            Hariom Dhanraj Tirkamte
//      Date:               08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////// End Of Library ////////////////////////////////////////////////// 

int main()
{
    SinglyLLL<int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->InsertAtPos(105 , 4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    obj->DeleteAtPos(4);

    obj->Display();
    iRet = obj->Count();
    cout<<"Number of nodes are :"<<iRet<<"\n";

    cout<<"\n";

    delete obj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyLLL<char> *cobj = new DoublyLLL<char>();

    cobj->InsertFirst('A');
    cobj->InsertFirst('B');
    cobj->InsertFirst('C');

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";
    

    cobj->InsertLast('X');
    cobj->InsertLast('Y');
    cobj->InsertLast('Z');

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->DeleteFirst();

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->DeleteLast();

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->InsertAtPos('$' , 4);

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cobj->DeleteAtPos(4);

    cobj->Display();
    cout<<"Number of nodes are :"<<cobj->Count()<<"\n";

    cout<<"\n";

    delete cobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    SinglyCLL<float> *fobj = new SinglyCLL<float>();
    int fRet = 0;

    fobj->InsertFirst(12.13);
    fobj->InsertFirst(7.43);
    fobj->InsertFirst(5.2);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of nodes are :"<<fRet<<"\n";

    fobj->InsertLast(24.64);
    fobj->InsertLast(45.13);
    fobj->InsertLast(85.5);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of nodes are :"<<fRet<<"\n";

    fobj->DeleteFirst();

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of nodes are :"<<fRet<<"\n";

    fobj->DeleteLast();

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of nodes are :"<<fRet<<"\n";

    fobj->InsertAtPos(100.89 , 4);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of nodes are :"<<fRet<<"\n";

    fobj->DeleteAtPos(4);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of nodes are :"<<fRet<<"\n";

    cout<<"\n";

    delete fobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyCLL<double> *dobj = new DoublyCLL<double>();

    dobj->InsertFirst(51.475686);
    dobj->InsertFirst(21.243835);
    dobj->InsertFirst(11.645627);

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    dobj->InsertLast(101.967);
    dobj->InsertLast(111.63856);
    dobj->InsertLast(121.5302649);

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n"; 

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n"; 

    dobj->InsertAtPos(105.64925 , 4);

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n"; 

    dobj->DeleteAtPos(4);

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n"; 

    delete dobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Stack<char> *sobj = new Stack<char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');

    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"return value of peep is :"<<sobj->peep()<<"\n";

    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";

    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    sobj->push('e');

    sobj->Display();
    cout<<"Number of elements in stack are :"<<sobj->Count()<<"\n";

    delete sobj;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.57958);
    qobj->enqueue(21.37395);
    qobj->enqueue(51.03875);
    qobj->enqueue(101.43957);

    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";

    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    qobj->enqueue(121.45385);

    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
}

/////////////////////////////////////////////////// End Of main //////////////////////////////////////////////////