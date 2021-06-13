#ifndef CODE_MANUALVECTOR_H
#define CODE_MANUALVECTOR_H

#include <bits/stdc++.h>

using namespace std;

template<class T>

class ManualVector {
private:
    T *elements;
    int numberOfElements;
    int capacity;
public:

    ManualVector() : elements(new T[1]), numberOfElements(0), capacity(1) {}     //Default Constructor
    ManualVector(int _sz)             // Constructor Gives Size
    {
        capacity = 1;
        while (capacity <= _sz)
            capacity *= 2;
        numberOfElements = _sz;
        elements = new T[capacity];
    }
    ManualVector(const ManualVector &temp)     //Copy Constructor
    {
        numberOfElements=temp.numberOfElements;
        capacity=temp.capacity;
        elements= new T[capacity];
        for(int i=0;i<numberOfElements;i++)
            elements[i]=temp.elements[i];
    }
    int getSize() const            //Function Returns the Current Size of the Vector
    {
        return numberOfElements;
    }

    int getCap()                   //Function Returns the Current Capacity of the Vector
    {
        return capacity;
    }

    bool empty()                   //Function tells either the vector is Empty or not
    {
        return numberOfElements == 0;
    }

    void push_Back(T x)           //Function adds an Element to the back of the Vector
    {
        if (numberOfElements == capacity) {
            capacity *= 2;
            T *t = new T[capacity];
            for (int i = 0; i < numberOfElements; i++)
                t[i] = elements[i];
            delete[]elements;
            elements = t;
            t = nullptr;
            delete[]t;
        } else if (numberOfElements > capacity) {
            cout << "Error1" << endl;
            return;
        }
        elements[numberOfElements] = x;
        numberOfElements++;
    }

    void pop_Back()              //function removes the last element of the vector
    {

        if (numberOfElements == 0) {
            cout << "There is no Elements" << endl;
            return;
        }
        numberOfElements--;
        if (numberOfElements < (capacity / 2)) {
            capacity /= 2;
            T *t = new T[capacity];
            for (int i = 0; i < numberOfElements; i++)
                t[i] = elements[i];
            delete[]elements;
            elements = t;
            t = nullptr;
            delete[]t;
        }

    }

    void insert(int idx, T val)   // Function insert an element in a specific index
    {
        if (numberOfElements == capacity) {
            capacity *= 2;
            T *t = new T[capacity];
            for (int i = 0; i < numberOfElements; i++)
                t[i] = elements[i];
            delete[]elements;
            elements = t;
            t = nullptr;
            delete[]t;
        }
        for (int i = numberOfElements + 1; i > idx; i--) {
            elements[i] = elements[i - 1];
        }
        elements[idx] = val;
        numberOfElements++;
    }

    void erase(int idx)         // Function Erases Element from a specific index
    {
        for (int i = idx; i < numberOfElements; i++) {
            elements[i] = elements[i + 1];
        }
        numberOfElements--;
        if (numberOfElements < (capacity / 2)) {
            capacity /= 2;
            T *t = new T[capacity];
            for (int i = 0; i < numberOfElements; i++)
                t[i] = elements[i];
            delete[]elements;
            elements = t;
            t = nullptr;
            delete[]t;
        }
    }

    T &operator[](int idx)      //Operator [] Override
    {
        return elements[idx];
    }

    T begin()                   // Function that returns the address of the First Element
    {
        return &elements[0];
    }

    T front()                   //Function That returns the First element of the Vector
    {
        return elements[0];
    }

    T back()                    //Function That returns the last element of the Vector
    {
        return elements[numberOfElements - 1];
    }

    void clear()                //Function Clears the Vector
    {
        delete[]elements;
        numberOfElements = 0;
        capacity = 1;
        elements=new T[capacity];
    }

    int opt()                   // Function that shows the Option Menu and Check the Input
    {
        cout << "What kind of operation would you like to perform?  \n";
        cout << "1. Add element. \n";
        cout << "2. Remove last element.  \n";
        cout << "3. Insert element at certain position. \n";
        cout << "4. Erase element from a certain position.  \n";
        cout << "5. Clear. \n";
        cout << "6. Display first element. \n";
        cout << "7. Display last element.  \n";
        cout << "8. Display element at certain position. \n";
        cout << "9. Display vector size.  \n";
        cout << "10. Display vector capacity. \n";
        cout << "11. Is empty? \n";
        cout<<"12. Write to File\n";
        int choice;
        cin >> choice;
        while (choice > 12 || choice < 1) {
            cout << "Enter Numbers Between 1~11!\n";
            cin >> choice;
        }
        return choice;
    }

    void opt(ManualVector<T> &vct) // Function that takes a ManualVector and does what the user Choose
    {
        reOpt:
        int opt1 = vct.opt();
        int idx, ret;
//        T element;
        switch (opt1) {
            case 1: {            //Adding Elements
                cout << "How many elements you would like to add?\n";
                cin >> ret;
                if (ret == 0) break;
                cout << "Enter Elements: ";
                for (int i = 0; i < ret; i++) {
                    T element;
                    cin >> element;
                    vct.push_Back(element);
                }
                break;
            }
            case 2:                  //Remove Last Element
                if (vct.getSize() == 0) {
                    cout << "There is No Elements\n";
                    break;
                }
                vct.pop_Back();
                break;
            case 3: {            //Insert Element
                T element;
                cout << "Element: ";
                cin >> element;
                cout << "Index: ";
                cin >> idx;
                while (idx >= vct.getSize() || idx < 0) {
                    cout << "Enter Valid Index\n";
                    cin >> idx;
                }
                vct.insert(idx, element);
                break;
            }
            case 4:                  //Erase Element
                if (vct.getSize() == 0) {
                    cout << "There is No Elements\n";
                    break;
                }
                cout << "Index: ";
                cin >> idx;
                while (idx >= vct.getSize() || idx < 0) {
                    cout << "Enter Valid Index\n";
                    cin >> idx;
                }
                vct.erase(idx);
                break;
            case 5:              //Clear Vector
                if (vct.getSize() == 0) {
                    cout << "There is No Elements\n";
                    break;
                }
                vct.clear();
                break;
            case 6:             //Display First
                if (vct.getSize() == 0) {
                    cout << "There is No Elements\n";
                    break;
                }
                cout << "Element: " << vct.front() << "\n";
                break;
            case 7:             //Display Last
                if (vct.getSize() == 0) {
                    cout << "There is No Elements\n";
                    break;
                }
                cout << "Element: " << vct.back() << "\n";
                break;
            case 8:             // Display Specific Element
                if (vct.getSize() == 0) {
                    cout << "There is No Elements\n";
                    break;
                }
                cout << "Index: ";
                cin >> idx;
                while (idx >= vct.getSize()) {
                    cout << "Enter Valid Index\n";
                    cin >> idx;
                }
                cout << "Element: " << vct[idx] << "\n";
                break;
            case 9:             //Display Vector Size
                if (vct.getSize() == 0) {
                    cout << "There is No Elements\n";
                    break;
                }
                cout << vct.getSize() << "\n";
                break;
            case 10:            // Display Vector Capacity
                cout << vct.getCap() << "\n";
                break;
            case 11:            // Is Empty
                cout << ((vct.empty()) ? "Yes" : "No") << "\n";
            case 12:
                for(int i=0;i<numberOfElements;i++)
                {
                    cout<<elements[i]<<endl;
                }
            default:
                break;
        }
        char re;
        cout << "Would you like to perform other operations? (Y/N)\n";
        cin >> re;
        while (toupper(re) != 'Y' && toupper(re) != 'N') {
            cout << "Enter Only (Y/N)\n";
            cin >> re;
        }
        if (toupper(re) == 'Y') goto reOpt;
    }
};

#endif //CODE_MANUALVECTOR_H
