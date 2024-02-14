#include <iostream>
using namespace std;

// Main Class
int main() {
    int userNum;
    // create and prepopulate list
    CircularDLL<int> list;
    list.insertProcess(10);
    list.insertProcess(12);
    list.insertProcess(8);
    list.insertProcess(5);
    list.insertProcess(10);

    // ask user for quantum time
    cout << "Enter Quantum Time: ";
    cin >> userNum;
    // print the prepopulated list
    cout << "Prepopulating with processes" << endl;
    list.printList();
    //cout << "Add new process? (Enter Y/N) " << endl;
    // add new process function

    return 0;
}


// Data Class: This is what goes inside your Node
class Process {
public:
    string processName;
    int totalTime;

    // Constructor
    Process(string processName, int totalTime) {
        this->processName = processName;
        this->totalTime = totalTime;
    }

    // update totalTime after each quantum cycle
    void updateRunTime() {
//write method to update totalTime after each quantum cycle.
    }

    // print name of process and the time left
    void print() {
        cout << "Process " << processName << " " << totalTime << "seconds" << endl;
    }
};


// Node Class: Node for the DoublyLinkedList
template<typename T>class Node {
public:
    T *data;
    Node<T> *next;
    Node<T> *prev;

    // Constructor
    Node(T *data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    // Print
    void print() {
        data->print();
    }
};


// CircularDoublyLinkedList Class: Container for Nodes
template<typename T>class CircularDLL {
private:
    Node<T> *curr;
    Node<T> *head;
    Node<T> * tail;
    int length;

public:
    // Constructor
    CircularDLL(T *data) {
        Node<T> *newNode = new Node<T>(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
        length = 1;
    }

    // Destructor
    ~CircularDLL() {
        Node<T> *temp = head;
        Node<T> *nextNode;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    // Print the list
    void printList() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            temp->print();
            temp = temp->next;
        }
    }

    //Insert a process at the end
    void insertProcess(T *data) {
        Node<T>* newNode = new Node<T>(data);
        if (length == 0) {
            head = newNode;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
        length++;
    }

    //Delete a Process
    void deleteProcess() {
//write code to delete process here
    }
};