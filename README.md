# CS210-Programming-Assignment-1
Circular Doubly Linked List w/Process

Name of Project: Programming Assignment 1
Author: Adelina Martinez
Date of Completion: 2/23/2024
Code description:

# Node : node container for a Circular Doubly Linked List

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


# CircularDLL : container for the nodes in a Circular Doubly Linked List

PUBLIC MEMBER VARIABLES
   Node<T> *head; - pointer for the head node of the list
   Node<T> *tail; - pointer for the tail node of the list
   int length; - length, number of nodes in list

CONSTRUCTORS
   CircularDLL(T *data) - default constructor, creates new list with one node with given data, tail's next points to head and head's previous points to tail, making it CDL
   Destructor - default destructor, deletes all nodes in the list and frees memory

PUBLIC MEMBER FUNCTIONS
   void printList()
   printList : prints the data of all nodes in the list
      Precondition: None
      Postcondition: None

   void insertProcess(T *data)
   insertProcess : inserts a new node with the given data at the end of the list
      Precondition: None
      Postcondition: List contains a new node with the given data at the end

   void deleteProcess(Node<T> *node) - Deletes the given node from the list
   Precondition: Node is a valid node in the list
   Postcondition: Node is removed from the list, memory is freed

   bool isEmpty() - Checks if the list is empty
   Precondition: None
   Postcondition: None

return_type Function_Name (parameter_list)
Function_Name: brief description of the purpose of this function, it's input, and its output. Also include a brief
description of how the function works if the algorithm is non-trivial.
Precondition: State of Program before member function is run
Postcondition: State of Program after member function is run


Process : Description of the role or purpose of objects of this class goes here.
PUBLIC MEMBER VARIABLES
data_type Variable_Name; - Purpose of the variable
CONSTRUCTORS
Brief description of the purpose of this constructor; for example, default constructor, copy constructor
Destructor if any. Describe the destructor
PUBLIC MEMBER FUNCTIONS
return_type Function_Name (parameter_list)
Function_Name: brief description of the purpose of this function, it's input, and its output. Also include a brief
description of how the function works if the algorithm is non-trivial.
Precondition: State of Program before member function is run
Postcondition: State of Program after member function is run


Main : Description of the role or purpose of objects of this class goes here.
PUBLIC MEMBER VARIABLES
data_type Variable_Name; - Purpose of the variable
CONSTRUCTORS
Brief description of the purpose of this constructor; for example, default constructor, copy constructor
Destructor if any. Describe the destructor
PUBLIC MEMBER FUNCTIONS
return_type Function_Name (parameter_list)
Function_Name: brief description of the purpose of this function, it's input, and its output. Also include a brief
description of how the function works if the algorithm is non-trivial.
Precondition: State of Program before member function is run
Postcondition: State of Program after member function is run