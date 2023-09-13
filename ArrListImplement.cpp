#include <iostream>
using namespace std;
class ArrayList {
private:
    int arr[5];
    int length;
    // int index;
    int size;
    int* ptr;
    int* ptr2;

public:
    ArrayList() : ptr(arr), ptr2(arr), length(0), size(5) {}
    void add(int);
    void show();
    int getElement(int);
    void remove(int);
};

void ArrayList::add(int element) {
    if (length < size) {
        *ptr = element;
        ptr = ptr + 1;
        length += 1;
    }
    else {
        size = size * 2;
        int* temp = new int[size];
        int i;
        for (i = 0; i < length; i++) {
            temp[i] = *ptr2;
            ptr2 += 1;
        }
        temp[i++] = element;
        ptr2 = temp;
        ptr = &temp[i];
        length += 1;
    }
}

void ArrayList::show() {
    int i;
    for (i = 0; i < length-1; i++) {
        cout << *ptr2 << " ";
        ptr2 += 1;
    }
    cout << endl;
    ptr2 -= i;
}

int ArrayList::getElement(int indx) {
    if (indx < 0 || indx > length - 1) {
        // cout << "Invalid Index Entered !!!!!" << endl;
        return -1;
    }
    else {
        int i;
        for (i = 0; i < indx; i++) {
            ptr2 += 1;
        }
        int element = *ptr2;
        ptr2 -= i;
        return element;
    }
}

void ArrayList::remove(int indx)
{
    int* tempArr = new int[size - 1];
    int i;
    for (i = 0; i < indx; i++) {
        tempArr[i] = *ptr2;
        ptr2 += 1;
    }
    ptr2 += 1;
    while (i < length)
    {
        tempArr[i] = *ptr2;
        ptr2 += 1;
        i += 1;
    }
    length -= 1;

    ptr2 = &tempArr[0];
    int* ptr3 =&tempArr[0];
    for (int i = 0; i < length-1; i++)
    {
        ptr3 += 1;
        ptr = ptr3;
    }
}
int main() {

    ArrayList l1;
    for (int i = 0; i < 7; i++) {
        cout << "Enter Element : " << endl;
        int ele;
        cin >> ele;
        l1.add(ele);
    }
    l1.show();
    // l1.add(987);
    // l1.show();

    cout << "Enter The Index To Get The Element : " << endl;
    int index;
    cin >> index;
    if (l1.getElement(index) != -1)
    {
        cout << l1.getElement(index) << endl;
    }
    else
    {
        cout << "Invlaid Index Entered!!!" << endl;
    }
    l1.add(8);
    l1.show();
    cout << "Enter The Index TO Find The Element" << endl;
    int index2;
    cin >> index2;
    if (l1.getElement(index2) != -1)
    {
        cout << l1.getElement(index2) << endl;
    }
    else
    {
        cout << "Invlaid Index Entered!!!" << endl;
    }

    l1.remove(5);
    l1.show();
    l1.add(45);
    l1.show();
    l1.add(234);
    l1.show();
    l1.remove(7);
    l1.show();
}