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

    // Print the list
    void printList() {
        int number = 1; // number
        if (!head) { // if empty do nothing
            return;
        }
        Node<T> *temp = head; // start temp at head
        do {
            cout << number << ". "; // print number.
            temp->print(); // call node's print
            temp = temp->next; // go to next node
            number++; // increment number
        } while (temp != head); // stop if back to head
    }

    // Insert new process node at the end of list
    void insertProcess(T *data) {
        Node<T> *newNode = new Node<T>(data); // create new node
        newNode->prev = tail; // set newNodes prev to tail
        newNode->next = head; // set newNodes next to head
        tail->next = newNode; // set the tails next to newNode
        head->prev = newNode; // set the heads prev to newNode
        tail = newNode; // make tail equal newNode
        length++; // increment length
    }

    // Delete the process node at the given index
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


// Process Class: the data that goes inside the node
class Process {
public:
    string processName;
    int totalTime;

    // Constructor
    Process(const string &processName, int totalTime) {
        this->processName = processName;
        this->totalTime = totalTime;
    }

    // Traverse and update the totalTime of each process node in the list
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

    // Traverse and delete any processes with totalTime less than or equal to zero
    void traverseAndDelete(CircularDLL<Process> &list) {
        Node<Process> *current = list.head; // start at the head of the list
        vector<Node<Process> *> nodesToDelete; // temporary list that stores nodes to be deleted

        while (current != nullptr) {
            Node<Process> *temp = current; // save the current node
            current = current->next; // go to the next node before potentially deleting

            if (temp->data->totalTime <= 0) {
                nodesToDelete.push_back(temp); // store node to be deleted in the temporary list
            }
            if (current == list.head) { // if back to the head, break the loop
                break;
            }
        }
        // delete the nodes stored after traversal is complete
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
    string input; // user input
    int quanTime; // quantum time
    int currTime; // total time passed
    string pName; // new process name
    int pTime; // new process time
    int cycleNum = 1; // cycle counter

    // create the first process object
    Process *p1 = new Process("A", 10);

    // create the list and add the first process
    CircularDLL<Process> *list = new CircularDLL<Process>(p1);

    // add the rest of the process objects
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

    // cycle loop: breaks when all processes are finished
    while (true) {
        // ask user if they want to add a process
        cout << "Add new process? (Enter Y/N) ";
        cin >> YNinput; // yes or no answer
        cin.ignore(); // clear the new line

        // if NO: run the cycle
        if (YNinput == "N") {
            cout << "Running Cycle " << cycleNum << endl;

            // traverse the list and update each time in the process list
            p1->updateRunTime(*list, quanTime);

            // traverse the list and delete any expired totalTimes
            p1->traverseAndDelete(*list);

            // cycle is completed and list updated; print the results
            cout << "After cycle " << cycleNum << " – " << currTime
                 << " second elapses – state of processes is as follows:" << endl;

            // check if the list is empty, if so cycle is finished
            if (list->isEmpty()) {
                cout << "All processes are completed." << endl;
                return 0; // completely done !
            }

            list->printList(); // print the updated list
            currTime = currTime + quanTime; // update total time passed
            cycleNum++; // update cycle number
            continue;
        }

        // if YES: add a new process
        if (YNinput == "Y") {
            // ask user for name and time
            cout << "Enter New Process Name: ";
            cin >> pName; // new process name
            cin.ignore(); // clear the new line

            // error handle: only accept number for time
            while (true) {
                cout << "Enter Total Process Time: ";
                getline(cin, input); // get the total time
                istringstream iss(input); // use stringstream to convert the input to a number
                if (!(iss >> pTime)) { // if no number at all, ask again
                    cout << "Invalid input. Please enter a number." << endl;
                } else {
                    break;
                }
            }
            // add the new process and continue
            Process *newP = new Process(pName, pTime); // create new process
            list->insertProcess(newP); // add the new process
            cout << "Process Added." << endl;
            continue;
        }

        // if NEITHER: error handle input is NOT Y or N
        if (YNinput != "Y" && YNinput != "N") {
            cout << "Invalid input. Please enter Y or N: ";
            continue;
        }
    }
}