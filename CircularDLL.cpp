#include <iostream>

using namespace std;

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
    void updateRunTime(int time) {

    }

    // print name of process and the time left
    void print() {
        cout << "Process " << processName << " " << totalTime << "seconds" << endl;
    }
};


// Node Class: Node for the DoublyLinkedList
template<typename T>
class Node {
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
template<typename T>
class CircularDLL {
private:
    Node<T> *curr;
    Node<T> *head;
    Node<T> *tail;
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
            nextNode = head->next;
            delete temp;
            temp = nextNode;
            if (temp == head) {
                break;
            }
        }
    }

    // Print the list
    void printList() {
        int number = 1;
        if (!head) {
            return;
        }
        Node<T> *temp = head;
        do {
            cout << number << ". ";
            temp->print();
            temp = temp->next;
            number++;
        } while (temp != head);
    }

    // Insert a process at the end
    void insertProcess(T *data) {
        Node<T> *newNode = new Node<T>(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
        length++;
    }

    // Delete a Process at the end
    void deleteProcess() {
        if (length == 0)
            return;
        Node<T> *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
        length--;
    }
};

// Main Class
int main() {
    int userNum;
    char YNinput;
    string pName;
    int pTime;

    // create first data object
    Process *p1 = new Process("A", 10);

    // create and prepopulate list with rest of objects
    CircularDLL<Process> *list = new CircularDLL<Process>(p1);
    list->insertProcess(new Process("B", 12));
    list->insertProcess(new Process("C", 8));
    list->insertProcess(new Process("D", 5));
    list->insertProcess(new Process("E", 10));

    // ask user for quantum time
    cout << "Enter Quantum Time: ";
    cin >> userNum;
    cout << "Prepopulating with processes" << endl;

    // print initial list
    list->printList();

    // ask user if they want to add a process
    for (;;) {
        cout << "Add new process? (Enter Y/N) ";
        cin >> YNinput;
        if (YNinput != 'Y') {
            cout << "Running Cycle 1 " << endl;
            // call the update function
            cout << "After cycle 1 – 5 second elapses – state of processes is as follows:" << endl;
            list->printList();
            break;
        }
        if (YNinput == 'Y') {
            cout << "Enter New Process Name: ";
            cin >> pName;
            cout << "Enter Total Process Time: ";
            cin >> pTime;
            Process *newP = new Process(pName, pTime);
            list->insertProcess(newP);
            cout << "Process Added." << endl;
            continue;
        }
    }

    return 0;
}