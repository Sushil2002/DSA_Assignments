/*Consider telephone book database of N client . Make use of a hash table implementation to quickly look up client‘s telephone number. Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers (use linear probing with replacement and without replacement)
 */
#include <bits/stdc++.h>
#include <iostream>
#define size 10
typedef long long ll;

using namespace std;
class Hash
{
    ll phone;
    string Name;
    public:
    Hash()
    {
        phone = 0;
        Name = "";
    }
    friend class DataBase;
};
class DataBase
{
    Hash HashTable_withoutRlc[size];
    Hash HashTable_withrepalcement[size];

public:
    DataBase()
    {
        for (int i = 0; i < size; i++)
        {
            HashTable_withoutRlc[i].phone = 0;
            HashTable_withoutRlc[i].Name = "";
            HashTable_withrepalcement[i].phone = 0;
            HashTable_withrepalcement[i].Name = "";
        }
    }
    int hashkey(ll phn)
    {
        return (phn) % size;
    }
    void Insert_withoutrepalcement(ll phn, string name)
    {
        int key = hashkey(phn);
        if (HashTable_withoutRlc[key].phone == 0)
        {
            HashTable_withoutRlc[key].phone = phn;
            HashTable_withoutRlc[key].Name = name;
        }
        else
        {
            while (HashTable_withoutRlc[key].phone != 0)
            {

                if (key == size - 1)
                {
                    key = 0;
                }
                else
                {
                    key++;
                }
            }
            HashTable_withoutRlc[key].phone = phn;
            HashTable_withoutRlc[key].Name = name;
        }
    }
    void Inser_withreplacement(ll phn, string name)
    {
        int key = hashkey(phn);
        if (HashTable_withrepalcement[key].phone == 0)
        {
            HashTable_withrepalcement[key].phone = phn;
            HashTable_withrepalcement[key].Name = name;
        }
        else
        {
            int x = (HashTable_withrepalcement[key].phone) % 10;
            if (key == x)
            {
                while (HashTable_withrepalcement[key].phone != 0)
                {

                    if (key == size - 1)
                    {
                        key = 0;
                    }
                    else
                    {
                        key++;
                    }
                }
                HashTable_withrepalcement[key].phone = phn;
                HashTable_withrepalcement[key].Name = name;
            }
            else
            {
                int a = HashTable_withrepalcement[key].phone;
                string b = HashTable_withrepalcement[key].Name;
                HashTable_withrepalcement[key].phone = phn;
                HashTable_withrepalcement[key].Name = name;
                while (HashTable_withrepalcement[key].phone != 0)
                {
                    key++;
                }
                HashTable_withrepalcement[key].phone = a;
                HashTable_withrepalcement[key].Name = b;
            }
        }
    }
    void Display_withoutreplacement()
    {
        for (int i = 0; i < size; i++)
        {
            cout << HashTable_withoutRlc[i].Name << "  ==>  " << HashTable_withoutRlc[i].phone << endl;
        }
    }
    void Display_withrepalcement()
    {
        for (int i = 0; i < size; i++)
        {
            cout << HashTable_withrepalcement[i].Name << " ==>  " << HashTable_withrepalcement[i].phone << endl;
        }
    }
    void Search_withoutreplacement(ll phn)
    {
        bool flag = false;
        int key = hashkey(phn);
        int key1 = key - 1;
        int cnt = 0;
        while (!flag)
        {
            cnt++;
            if (HashTable_withoutRlc[key].phone == phn)
            {
                cout << HashTable_withoutRlc[key].Name << "  <==>  " << HashTable_withoutRlc[key].phone << endl;
                cout << "Number of Comparision - " << cnt << endl;
                flag = true;
            }
            else if (key1 == key)
            {
                cout << "Invalid Data!" << endl;
                break;
            }
            else
            {
                key = (key + 1) % size;
            }
        }
    }
    void Search_withReplacement(ll phn)
    {
        int key = hashkey(phn);
        int key1 = key - 1;
        bool flag = false;
        int cnt = 0;
        while (!flag)
        {
            cnt++;
            if (HashTable_withrepalcement[key].phone  == phn)
            {
                cout << HashTable_withrepalcement[key].Name  << "  <==>  " <<HashTable_withrepalcement[key].phone  << endl;
                cout << "Number of Comparision - " << cnt << endl;
                flag = true;
            }
            else if (key1 == key)
            {
                cout << "Invalid Data!" << endl;
                break;
            }
            else
            {
                key = (key + 1) % size;
            }
        }
    }
};
int main()
{
    DataBase d1, d2;
    int ch;
    ll phn;
    string s;
    do
    {
        cout << "\n1.Insert Data For Hashing Without Replacement - " << endl;
        cout << "2.Insert Data For Hashing With Replacement - " << endl;
        cout << "3.Display Data For Without Replacement Probing - " << endl;
        cout << "4.Display Data For With Replacement Probing - " << endl;
        cout << "5.Search In Without Replacement Table - " << endl;
        cout << "6.Search In With Replacement Table - " << endl;
        cout << "\nEnter the Choice - ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter the Phone Number - ";
            cin >> phn;
            cout << "\nEnter the Name - ";
            cin >> s;
            cout << "\nData Added Successfully!" << endl;
            d1.Insert_withoutrepalcement(phn, s);
            break;
        case 2:
            cout << "\nEnter the Phone Number - ";
            cin >> phn;
            cout << "\nEnter the Name - ";
            cin >> s;
            cout << "\nData Added Successfully!" << endl;
            d2.Inser_withreplacement(phn, s);
            break;
        case 3:
            d1.Display_withoutreplacement();
            break;
        case 4:
            d2.Display_withrepalcement();
            break;
        case 5:
            cout << "\nEnter the Phone Need to Be Search(WithoutRepalcemt) - ";
            cin >> phn;
            d1.Search_withoutreplacement(phn);
            break;
        case 6:
            cout << "\nEnter the Phone Need to Be Search(WithRepalcement) - ";
            cin >> phn;
            d2.Search_withReplacement(phn);
            break;
        default:
            break;
        }
    } while (ch != 0);

    return 0;
}
