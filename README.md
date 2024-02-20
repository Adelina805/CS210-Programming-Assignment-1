# CS210-Programming-Assignment-1
Circular Doubly Linked List w/Process

Name of Project: Programming Assignment 1
Author: Adelina Martinez
Date of Completion: 2/23/2024
Code description:


// Node : node container for a Circular Doubly Linked List

PUBLIC MEMBER VARIABLES
   T *data; - Data for node
   Node<T> *next; - pointer to the next node
   Node<T> *prev; - pointer to the previous node

CONSTRUCTORS
   Node(T *data) - default constructor, creates new node with given data and sets both pointers to null

PUBLIC MEMBER FUNCTIONS
   void print()
      print : calls the print function of the data stored in the node. no input or output
      Precondition: data stored in the node is valid and can be printed
      Postcondition: the print function is called and data is printed


// CircularDLL : container for the nodes in a Circular Doubly Linked List

PUBLIC MEMBER VARIABLES
   Node<T> *head; - pointer for the head node of the list
   Node<T> *tail; - pointer for the tail node of the list
   int length; - length, number of nodes in list

CONSTRUCTORS
   CircularDLL(T *data) - default constructor, creates new list with one node with given data, tail's next points to head and head's previous points to tail, making it CDL
   Destructor - default destructor, deletes all nodes in the list and frees memory

PUBLIC MEMBER FUNCTIONS
   void printList()
      printList : prints the data of all nodes in the list in the format "number." + the printed process
      Precondition: data stored in the node is valid and can be printed
      Postcondition: the number is printed and the print function is called to print the process

   void insertProcess(T *data)
      insertProcess : inserts a new node with the given data at the end of the list
      Precondition: data is valid, list exists and is circular doubly linked
      Postcondition: the list contains a new node at the end with the given data

   void deleteProcess(Node<T> *node)
      deleteProcess : deletes the given node from the list
      Precondition: the node is a valid node in the list
      Postcondition: the node is removed from the list and memory is freed

   bool isEmpty()
      isEmpty : checks if the list is empty
      Precondition: none
      Postcondition: none


// Process : the data that goes inside the node

PUBLIC MEMBER VARIABLES
   string processName; - name of the process
   int totalTime; - total time needed for the process to complete

CONSTRUCTORS
   Process(const string &processName, int totalTime) - creates a new process with the given name and total time

PUBLIC MEMBER FUNCTIONS
   void updateRunTime(CircularDLL<Process> &list, int quan)
      updateRunTime : updates the total time of each process in the list by subtracting quan
      Precondition: list contains valid process nodes
      Postcondition: total time of each process is updated

   void traverseAndDelete(CircularDLL<Process> &list)
      traverseAndDelete : deletes processes with total time less than or equal to zero from the list by storing in temp list
      Precondition: list contains valid process nodes
      Postcondition: processes with total time less than or equal to zero are deleted from the list

   void print() - prints the process in the format "name of the process + the total time"
      Precondition: data stored in the node is valid and can be printed
      Postcondition: the process is printed


// Main : the main program

PUBLIC MEMBER VARIABLES
   string YNinput; - User input for adding new processes (Y/N)
   string input; - User input for quantum time and process name
   int quanTime; - Quantum time for the simulation
   int currTime; - Total time passed in the simulation
   string pName; - Name of a new process to be added
   int pTime; - Total time for a new process to be added
   int cycleNum; - Number of cycles completed in the simulation
