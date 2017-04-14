#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// linked list node
struct stock_node{
  string name;
  int cost;
  int shares;
  stock_node* next;
};


// the stock class: it's methods and variables
class Stock
{
public:
    stock_node* head;
    Stock(void);   // constructor
    bool stockLoad(std::string);  // function to load the data from file into linkedlist
    void insertNode(stock_node);  // function to insert data at the beginning of list
    void appendNode(stock_node);  // function to append the node at the end of the list
    void stockprint();			  // function to print the stock list
    void returnMiddleofList();    // function to print middle of the list
    void splitList();
    void printList(stock_node*);  // function to print list

    ~Stock(void);
};

#endif // STOCK_H
