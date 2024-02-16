#include <iostream>
#include <sstream>

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

    // update totalTime of the process
    void updateRunTime(int quan) {
        this->totalTime = this->totalTime - quan;
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

    // get index
    Node<T> *get(int index) {
        if (index < 0 || index >= length)
            return nullptr;
        Node<T> *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
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

    // Delete at index
    void deleteProcess(int index) {
        if (index < 0 || index >= length) {
            return;
        }

        Node<T> *prev = get(index - 1);
        Node<T> *temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }
};

// Main
int main() {
    string YNinput; // Yes or No input
    string input; // number user input
    int quanTime; // quantum time
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

    // ask user for quantum time, print initial list
    while (true) {
        cout << "Enter Quantum Time: ";
        getline(cin, input);

        // error handle: use stringstream to convert the input to a number
        istringstream iss(input);
        if (!(iss >> quanTime)) {
            cout << "Invalid input. Please enter a number." << endl;
        } else {
            currTime = quanTime; // set starting time to quanTime
            cout << "Prepopulating with processes" << endl;
            list->printList(); // print initial list
            break;
        }
    }

    // input + output loop, breaks when process finishes
    for (;;) {
        // ask user if they want to add a process
        cout << "Add new process? (Enter Y/N) ";
        cin >> YNinput;

        // if no, run the cycle, incrementing the time and cycle number each time
        if (YNinput == "N") {
            cout << "Running Cycle " << cycleNum << endl;

            // update the times in the process list
            p1->updateRunTime(quanTime);
            
            //list->deleteProcess(0); // test delete head
            //list->deleteProcess(1); // test delete
            //list->deleteProcess(3); // test delete
            // if totalTime = 0 delete the process

            // cycle complete and list updated, print results
            cout << "After cycle " << cycleNum << " – " << currTime
                 << " second elapses – state of processes is as follows:" << endl;
            list->printList(); // print the updated list
            currTime = currTime + quanTime; // update total time passed
            cycleNum++; // update cycle number

            //if () { // check if list is empty
            // break }
            // else {

            continue;
        }

        // if YES: ask for name and time
        if (YNinput == "Y") {

            cout << "Enter New Process Name: ";
            cin >> pName; // new process name
            cin.ignore(); // Clear the new line

            while (true) {
                cout << "Enter Total Process Time: ";
                //cin >> pTime;
                getline(cin, input);

                // error handle: use stringstream to convert the input to a number
                istringstream iss(input);
                if (!(iss >> pTime)) {
                    cout << "Invalid input. Please enter a number." << endl;
                } else {
                    break;
                }
            }

            // add the process and continue
            Process *newP = new Process(pName, pTime);
            list->insertProcess(newP);
            cout << "Process Added." << endl;
            continue;
        }

        // error handle: if input is not Y or N
        if (YNinput != "Y" && YNinput != "N") {
            cout << "Invalid input. Please enter Y or N: ";
            continue;
        }
    }
    cout << "All processes are completed.";
    return 0;
}