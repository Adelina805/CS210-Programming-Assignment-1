# CS210-Programming-Assignment-1

Circular Doubly Linked List

Name of Project: Programming Assignment 1
Author: Adelina Martinez
Date of Completion: 2/23/2024
Code description:

classname : Process
Description of the role or purpose of objects of this class goes here.
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

Sample Expected Output:
Enter Quantum Time: 5
Prepopulating with processes

1. Process A 10seconds
2. Process B 12seconds
3. Process C 8seconds
4. Process D 5seconds
5. Process E 10 seconds
   Add new process? (Enter Y/N) N
   Running Cycle 1
   After cycle 1 – 5 second elapses – state of processes is as follows:
1. Process A 5seconds
2. Process B 7seconds
3. Process C 3seconds
4. Process E 5 seconds
   Add new process? (Enter Y/N) Y
   Enter New Process Name: F
   Enter Total Process Time: 15
   Process Added.
   Add new process? (Enter Y/N) N
   Running Cycle 2
   After cycle 2 – 10 second elapses – state of processes is as follows:
1. Process B 2seconds
2. Process F 10seconds
   Add new process? (Enter Y/N) N
   Running Cycle 3
   After cycle 3 – 15 second elapses – state of processes is as follows:
1. Process F 5seconds
   Add new process? (Enter Y/N) N
   Running Cycle 4
   After cycle 4 – 15 second elapses – state of processes is as follows:
   All processes are completed.