// Jimmy Liu
// Project 6
// 16 Nov. 2015
// XCode 7.0

// Specification file for the CountryList class
#ifndef CountryList_H
#define CountryList_H
using namespace std;

struct Data
{
    double value;
    char code[3];
    string name;
    string capital;
    int population;
    // other fields could be added here
};

class CountryList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      //double value;           // The value in this node
      Data data;
      ListNode *next;  // To point to the next node
   };

   ListNode *head;            // List head pointer

public:
   // Constructor
   CountryList()
      { head = NULL; }

   // Destructor
   ~CountryList();

   // Linked list operations
   void appendNode(Data);   //void appendNode(double);
   void insertNode(Data);   //void insertNode(double);
   bool deleteNode(char*);
   Data searchNode(char*);
   void displayList() const;

};
#endif
