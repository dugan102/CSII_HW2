#include <iostream>
using namespace std;
//Jackson Dugan 5755661

template <typename T>
class LLData {
private:
    T data;
    LLData *next;
    LLData() {}
public:
    LLData(T d, LLData *nxt) {
        data = d;
        next = nxt;
    }
    T getData() { return data; }
    LLData* getNext() { return next; }
    void setData(T d) { data = d; }
    void setNext(LLData* nxt) { next = nxt; }
};
template <typename T>
class LinkedList {
private:
    LLData<T>* first;
public:
    LinkedList() { first = NULL; }
    LLData<T> *getFirst() { return first; }
    void addItem(T d) {
        first = new LLData(d,first);
    }
    void showList() {
        LLData<T> *curr = getFirst();
        while (curr != NULL) {
            cout << curr->getData() << " -> ";
            curr = curr->getNext();
        }
        cout << endl;
    }
    void addItemAtEnd(T d) {
        if (first == NULL) {
            first = new LLData(d,first);
        }
        else {
            LLData<T>* curr = first;
            while (curr->getNext() != NULL) {
                curr = curr->getNext();
            }
            curr->setNext(new LLData(d,curr->getNext()));
        }
    }
};

int main() {
    LinkedList<int> myList;
    myList.addItem(1);
    myList.addItemAtEnd(2);
    myList.addItem(3);
    myList.addItemAtEnd(4);
    myList.showList();
    myList.addItem(5);
    myList.addItemAtEnd(6);
    myList.showList();

    LinkedList<string> myStringyList;
    myStringyList.addItem("Pow");
    myStringyList.addItemAtEnd("Cow");
    myStringyList.showList();
    myStringyList.addItemAtEnd("Pumpkin");
    myStringyList.showList();
    return 0;

}