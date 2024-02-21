# CS210-Programming-Assignment-1
Circular Doubly Linked List w/Process

Name of Project: Programming Assignment 1
Author: Adelina Martinez
Date of Completion: 2/23/2024
Code description:


// Node : template node container

PUBLIC MEMBER VARIABLES
   T *data; - data for node
   Node<T> *next; - pointer to the next node
   Node<T> *prev; - pointer to the previous node

CONSTRUCTORS
   Node(T *data) - default constructor, creates new node with given data and sets both pointers to null

PUBLIC MEMBER FUNCTIONS
   void print()
      print : calls the print function of the data stored in the node, no input or output
      Precondition: data stored in the node is valid and can be printed
      Postcondition: the print function is called and data is printed


// CircularDLL : template Circular Doubly Linked List container for the nodes

PUBLIC MEMBER VARIABLES
   Node<T> *head; - pointer for the head node of the list
   Node<T> *tail; - pointer for the tail node of the list
   int length; - length, number of nodes in list

CONSTRUCTORS
   CircularDLL(T *data) - default constructor, creates a new list with one node with the given data, tail's next points to head and head's previous points to tail, making it CDL
   Destructor - default destructor, deletes all nodes in the list and frees memory

PUBLIC MEMBER FUNCTIONS
   void printList()
      printList : prints the data of all nodes in the list in the format "number." + the printed process, no input or output
      Precondition: data stored in the node is valid and can be printed
      Postcondition: calls Node's print and prints the process with the number in front

   void insertProcess(T *data)
      insertProcess : inserts a new node with the given data at the end of the list, input is the data
      Precondition: data is valid, list exists and is circular doubly linked
      Postcondition: the list contains a new node at the end with the given data

   void deleteProcess(Node<T> *node)
      deleteProcess : deletes the given node from the list, input is the node to be deleted
      Precondition: the node is a valid node in the list
      Postcondition: the node is removed from the list and memory is freed

   bool isEmpty()
      isEmpty : checks if the list is empty, no input or output
      Precondition: list exits
      Postcondition: none


// Process : the data that goes inside the node

PUBLIC MEMBER VARIABLES
   string processName; - name of the process
   int totalTime; - total time needed for the process to complete

CONSTRUCTORS
   Process(const string &processName, int totalTime) - creates a new process with the given name and total time

PUBLIC MEMBER FUNCTIONS
   void updateRunTime(CircularDLL<Process> &list, int quan)
      updateRunTime : updates the total time of each process in the list by subtracting quan, input is the list and the quan number
      Precondition: list contains valid process nodes
      Postcondition: total time of each process is updated

   void traverseAndDelete(CircularDLL<Process> &list)
      traverseAndDelete : deletes processes with total time less than or equal to zero from the list by storing in temp list, input is the list
      Precondition: list contains valid process nodes
      Postcondition: processes with total time less than or equal to zero are deleted from the list

   void print() - prints the process in the format "name of the process + the total time", no input or output
      Precondition: data stored in the node is valid and can be printed
      Postcondition: calls CircularDLL's print which calls Node's print which prints the process


// Main : the main program

VARIABLES
   string YNinput; - user input for adding new processes (Y/N)
   string input; - user input for quantum time and process name
   int quanTime; - quantum time for the simulation
   int currTime; - total time passed in the simulation
   string pName; - name of the new process to be added
   int pTime; - total time of the new process to be added
   int cycleNum; - number of cycles completed in the simulation

LOGIC
   First, the first process object is created, a list is created using the first process object, and the rest of the process objects are added.
   Next, a while loop asking for the quantum time is run, only numbers are accepted, then the initial list is printed.
   Next, the cycle loop runs until all processes are completed:
      the while loop starts by prompting the user if they want to add a process
         if NO: the cycle runs, the times in the process list are updated, any expired processes are deleted, if the list is empty- the cycle is finished, otherwise print the updated list, and update currTime and cycleNum. then continue
         if YES: the user enters a new name, the user enters a new time only accepting numbers, and the new process is added. then continue
         if NEITHER: only accept Y or N, error message. then continue
      
