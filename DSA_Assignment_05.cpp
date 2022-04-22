/*
Implement all the functions of a dictionary (ADT) using hashing and handle collisions using separate chaining using linked list.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique. Standard Operations: Insert (key, value), Find(key), Delete(key).
*/

#include <bits/stdc++.h>
#include <iostream>
#define size 10
typedef long long ll;
using namespace std;
class Node
{
    ll phone;
    string Name;
    Node *next;

public:
    Node()
    {
        phone = 0;
        Name = "";
        next = NULL;
    }
    friend class DataBase;
};
class DataBase
{
    Node *HashTable[size];

public:
    DataBase()
    {
        for (int i = 0; i < size; i++)
        {
            HashTable[i] = NULL;
        }
    }
    int hashkey(ll phn)
    {
        return (phn) % size;
    }
    void Insert(ll phn, string name)
    {
        int key = hashkey(phn);
        Node *newnode = new Node;
        newnode->phone = phn;
        newnode->Name = name;
        bool flag = false;
        if (HashTable[key] == NULL)
        {
            HashTable[key] = newnode;
        }
        else
        {
            Node *ptr = HashTable[key];
            while (ptr->next != NULL)
            {
                if (ptr->phone == phn)
                {
                    flag = true;
                }
                ptr = ptr->next;
            }
            if (!flag)
            {
                ptr->next = newnode;
            }
            else
            {
                cout << "Duplicate Elements are not allowed!" << endl;
            }
        }
    }
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " |  ";
            Node *temp = HashTable[i];
            if (temp == NULL)
            {
                cout << endl;
                continue;
            }
            while (temp != NULL)
            {
                cout << temp->Name << "->" << temp->phone << "   ||   ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void Search(ll phn)
    {
        int key = hashkey(phn);
        Node *temp = HashTable[key];
        bool flag = false;
        if (HashTable[key] == NULL)
        {
            cout << "\nInvalid Data!" << endl;
        }
        else
        {
            while (temp->phone != phn)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "\nInvalid Data!" << endl;
            }
            else
            {
                cout << "\nData Found!" << endl;
                cout << temp->Name << "-->" << temp->phone << endl;
            }
        }
    }
    void Delete(ll phn)
    {
        int key = hashkey(phn);
        Node *ptr1 = HashTable[key];

        if (ptr1 == NULL)
        {
            cout << "Invalid Data!" << endl;
        }
        else if (ptr1->phone == phn)
        {
            Node *temp = ptr1;
            ptr1 = ptr1->next;
            delete temp;
        }
        else
        {
            Node *ptr2 = HashTable[key]->next;
            while (ptr2->phone != phn)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            if (ptr2 == NULL)
            {
                cout << "Inavlid Data!" << endl;
            }
            else
            {
                ptr1->next = ptr2->next;
                delete ptr2;
                cout << "\nNode Deleteed Successfully!" << endl;
            }
        }
    }
};
int main()
{
    DataBase d;
    int ch;
    string s;
    ll x;
    do
    {
        cout << "\n1.Insert Data In HashTable - " << endl;
        cout << "2.Display HashTable - " << endl;
        cout << "3.Search For Element In HashTable - " << endl;
        cout << "4.Delete Block In HashTable - " << endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the Phone Number - ";
            cin >> x;
            cout << "\nEnter the Name - ";
            cin >> s;
            d.Insert(x, s);
            break;
        case 2:
            d.Display();
            break;
        case 3:
            cout << "\nEnter the Phone Number Need To be Searched - ";
            cin >> x;
            d.Search(x);
            break;
        case 4:
            cout << "Enter the Element Need to be Deleted - ";
            cin >> x;
            d.Delete(x);
            break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}