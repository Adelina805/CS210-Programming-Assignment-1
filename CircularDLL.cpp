#include <iostream>
#include <sstream>

using namespace std;


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
public:
    Node<T> *head;
    Node<T> *tail;
    int length;

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

    // Get the index
    Node<T> *get(int index) {
        // if invalid index return nullptr
        if (index < 0 || index >= length) {
            return nullptr;
        }

        // if index is 0, return head
        if (index == 0) {
            return head;
        }

        // if index is the last element, return tail
        if (index == length - 1) {
            return tail;
        }

        // traverse the list to find the node at the given index
        Node<T> *current = head->next;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }

        return current;
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
        newNode->next = head; // set newNodes next to head
        tail->next = newNode; // make the tails next to newNode
        head->prev = newNode; // make the heads prev to newNode
        tail = newNode; // make tail equal newNode
        length++; // increment length
    }

    // Delete process at given index
    void deleteProcess(int index) {
        // if invalid index return
        if (index < 0 || index >= length) {
            return;
        }

        // delete head
        if (index == 0) {
            Node<T> *temp = head;
            if (length == 1) {
                head = tail = nullptr;
            } else {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
            delete temp;
            length--; // decrement length
            return;
        }

        Node<T> *prev = get(index - 1);
        Node<T> *temp = prev->next;

        prev->next = temp->next;
        temp->next->prev = prev;
        if (temp == tail) {
            tail = prev;
        }
        delete temp;
        length--; // decrement length
    }

    // Check if the list is empty
    bool isEmpty() {
        return length == 0;
    }
};


// Process Data Class: This is what goes inside your Node
class Process {
public:
    string processName;
    int totalTime;

    // Constructor
    Process(const string &processName, int totalTime) {
        this->processName = processName;
        this->totalTime = totalTime;
    }

    // traverse and update the totalTime of each process node in the list
    void updateRunTime(CircularDLL<Process> &list, int quan) {
        Node<Process> *temp = list.head; // temporary node starting at head

        while (temp != nullptr) {
            temp->data->totalTime -= quan; // subtract quan from totalTime
            temp = temp->next; // go to the next node

            if (temp == list.head) { // if back to head, break the loop
                break;
            }
        }
    }

    // print name of process and the time left
    void print() const {
        cout << "Process " << processName << " " << totalTime << "seconds" << endl;
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

    // create first process object
    Process *p1 = new Process("A", 10);

    // create and prepopulate list with rest of processes
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
        cin.ignore(); // clear the new line

        // if no, run the cycle, incrementing the time and cycle number each time
        if (YNinput == "N") {
            cout << "Running Cycle " << cycleNum << endl;

            // traverse the list and update each time in the process list
            p1->updateRunTime(*list, quanTime);

            // cycle completed and list updated, print the results
            cout << "After cycle " << cycleNum << " – " << currTime
                 << " second elapses – state of processes is as follows:" << endl;

            // check if the list is empty, if so cycle finished
            if (list->isEmpty()) {
                cout << "All processes are completed." << endl;
                return 0; // completely done
            }

            list->printList(); // print the updated list
            currTime = currTime + quanTime; // update total time passed
            cycleNum++; // update cycle number
            continue;
        }

        // if YES: ask for name and time
        if (YNinput == "Y") {
            cout << "Enter New Process Name: ";
            cin >> pName; // new process name
            cin.ignore(); // clear the new line

            // error handle: only accept number for time
            while (true) {
                cout << "Enter Total Process Time: ";
                getline(cin, input); // new time

                // use stringstream to convert the input to a number
                istringstream iss(input);
                if (!(iss >> pTime)) {
                    cout << "Invalid input. Please enter a number." << endl;
                } else {
                    break;
                }
            }

            // add the process and continue
            Process *newP = new Process(pName, pTime); // create new process
            list->insertProcess(newP); // add new process
            cout << "Process Added." << endl; // confirmation
            continue;
        }

        // error handle: input is NOT Y or N
        if (YNinput != "Y" && YNinput != "N") {
            cout << "Invalid input. Please enter Y or N: ";
            continue;
        }
    }
}