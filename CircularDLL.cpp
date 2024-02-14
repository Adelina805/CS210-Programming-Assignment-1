#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

//Data Class: This is what goes inside your Node
class Process {
public:
    string processName;
    int totalTime;
    Process (String processName, int totalTime){
//Fill contructor here
    }
    void updateRunTime() {
//write method to update totalTime after each quantum cycle.
    }
    void print () {
//write print method to print the name of the process and the time left
    }
}
// Node Class: Node for the DoublyLinkedList
template <typename T> class Node {
public:
    T *data;
    Node<T> *next;
    Node<T> *prev;
    Node (T *data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    void print () {
        data->print ();
    }
};
//CircularDoublyLinkedList Class: Container for Nodes
template <typename T> class CircularDLL {
private:
    Node<T> *curr;
    int length;
public:
// Constructor
    CircularDLL(T *data) {
//Write constructor for the DLL here
    }
//Destructor
    ~CircularDLL() {
//Write code for destructor here
    }
    void printList() {
//Write code to print the list here.
    }
//Insert a process
    void insertProcess(T *data) {
//write code to insert process here
    }
//Delete a Process
    void deleteProcess() {
//write code to delete process here
    };//
// Created by Adelina Martinez on 2/13/24.
//
