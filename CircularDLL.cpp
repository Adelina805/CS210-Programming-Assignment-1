#include <iostream>

using namespace std;

// Data Class: This is what goes inside your Node
class Process {
public:
    string processName;
    int totalTime;

    // Constructor
    Process(const string &processName, int totalTime) {
        this->processName = processName;
        this->totalTime = totalTime;
    }

    // update totalTime after each quantum cycle
    void updateRunTime() {
        // traverse the list and subtract quantum time from totalTime
        
        // if totalTime = 0, delete the process
    }

    // print name of process and the time left
    void print() const {
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

// Main
int main() {
    char YNinput; // Yes or No input
    int quanTime; // input quantum time
    int currTime; // total time passed
    string pName; // new process name
    int pTime; // new process time
    int cycleNum = 1; // cycle counter

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
    cin >> quanTime;
    currTime = quanTime;
    cout << "Prepopulating with processes" << endl;

    // print initial list
    list->printList();

    // input + output loop, breaks when processs finishes
    for (;;) {
        // ask user if they want to add a process
        cout << "Add new process? (Enter Y/N) ";
        cin >> YNinput;

        // if no, run the cycle, incrementing the time and cycle number each time
        if (YNinput != 'Y') {
            cout << "Running Cycle " << cycleNum << endl;
            p1->updateRunTime(); // update the times in the process list
            cout << "After cycle " << cycleNum << " – " << currTime
                 << " second elapses – state of processes is as follows:" << endl;
            list->printList(); // print the updated list
            currTime = currTime + quanTime; // update time
            cycleNum++; // update cycle number
            continue;
        }

        // if yes, ask for name and time, add the process, and continue
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
}