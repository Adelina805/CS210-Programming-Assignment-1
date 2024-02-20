#include <iostream>
#include <sstream>

using namespace std;


// Node Class: Node for the DoublyLinkedList
template<typename T>
class Node {
public:
    T *data; // data
    Node<T> *next; // next pointer
    Node<T> *prev; // previous pointer

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
    void deleteProcess(Node<T> *node) {
        // if processNode is nullptr or not in the list, return
        if (!node || node->next == nullptr || node->prev == nullptr) {
            return;
        }

        // if deleting the head
        if (node == head) {
            head = head->next;
        }

        // update the next and prev pointers
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // if deleting the tail, update tail
        if (node == tail) {
            tail = node->prev;
        }

        delete node; // delete the node
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

    // traverse and delete any processes with totalTime less than or equal to zero
    void traverseAndDelete(CircularDLL<Process> &list) {
        Node<Process> *current = list.head; // start at the head of the list
        vector<Node<Process> *> nodesToDelete; // stores nodes to be deleted

        while (current != nullptr) {
            Node<Process> *temp = current; // save the current node
            current = current->next; // go to the next node before potentially deleting

            if (temp->data->totalTime <= 0) {
                nodesToDelete.push_back(temp); // add node to be deleted to the temporary list
            }

            if (current == list.head) { // if back to the head, break the loop
                break;
            }
        }

        // delete nodes after traversal is complete
        for (Node<Process> *node: nodesToDelete) {
            list.deleteProcess(node);
        }
    }

    // print name of process and the time left
    void print() {
        cout << "Process " << processName << " " << totalTime << "seconds" << endl;
    }
};


// Main program
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

    // infinite input + output loop, breaks when the process is finished
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

            // traverse the list and delete any expired totalTimes
            p1->traverseAndDelete(*list);

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