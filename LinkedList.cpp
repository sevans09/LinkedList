/*
 * LinkedList.cpp
 * 
 * Implementation for Linked List of Green Line Extension Stations
 * This file creates a linked list of Station objects from station
 * class and uses several functions to modify the linked list -
 * from inserting and removing objects printing them out.
 * It is also able to access the next node and reset the
 * private variable curr_pos so that get_next_station can be 
 * accurately invoked again.
 */

#include "LinkedList.h"
#include "Station.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Default constructor
LinkedList::LinkedList()
{
    length = 0;
    head = NULL;
    curr_pos = NULL;
}

// Destructor
LinkedList::~LinkedList() 
{
    NodeType* curr = head;
    while (curr != 0)
    {
        NodeType* next = curr->next;
        delete curr;
        curr = next;
    }
    head = 0;
}

// Assignment operator
LinkedList & LinkedList::operator = (const LinkedList &l)
{
    NodeType *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    length = l.length;
    curr_pos = NULL;
    if (l.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Function: get_length
// Input: nothing
// Returns: the length
// Does: returns the length of the LL
int LinkedList::get_length() const
{
    return length;
}

// Function: insert_station
// Input: Station object
// Returns: None
// Does: Inserts the station into the 
//       head of the linked list.
void LinkedList::insert_station(Station s)
{
    NodeType* node = new NodeType;
    node->info = s;
    node->next = head;
    head = node;
    length++;
}

// Function: remove_station
// Input: Station object
// Returns: None
// Does: Removes a station from the linked list
//       if it is found to be equal to the 
//       inputted station. Deallocates memory.
void LinkedList::remove_station(Station s)
{
    NodeType* curr = head;
    // if head is null, there is no list. return if this is the case
    if (head == NULL)
        return;
    // if the list contains only the head value and the head value 
    // is equal to the input, delete it.
    else if (head->next == NULL && s.is_equal(head->info)){
        NodeType* temphead = head;
        delete temphead;
        length--;
        return;
    }
    // if the value of head is equal to the input and the value after
    // head is not null, create a temp for head and delete the temp,
    // shorten the linked list.
    else if (s.is_equal(head->info) && head->next != NULL){
        NodeType* temphead = head;
        head = head->next;
        delete temphead;
        length--;
        return;
    }
    // if the input is equal to the current node, delete the node and
    // shorten the linked list and return. keep iterating through the 
    // linked list until a match is found.
    while (curr->next != NULL)
    {
        if (s.is_equal(curr->next->info)){
            NodeType* temp = curr->next;
            curr = curr->next->next;
            delete temp;
            length--;
            return; 
        }
        else
            curr = curr->next;
    }    
}


// Function: get_next_station
// Input: none
// Returns: station object
// Does: Navigates through linked list. Iterates
//       through the linked list and returns each
//       element.
Station LinkedList::get_next_station()
{
    if (length == 0)
    {
        Station s;
        return s;
    }
    if (curr_pos == NULL)
    {
        curr_pos = head;
    }
    else
        curr_pos = curr_pos->next;
    return curr_pos->info;
}

// Function: reset_curr_pos
// Input: none
// Returns: none
// Does: resets private variable curr_pos to null
//       so that get_next_station can be invoked
//       again and report the first station.
void LinkedList::reset_curr_pos()
{
   curr_pos = NULL;
}

// Function: make_empty
// Input: none
// Returns: none
// Does: deletes elements in the list and
//       deallocates memory.
void LinkedList::make_empty()
{
    NodeType* curr = head;
    while (curr != 0)
    {
        NodeType* next = curr->next;
        delete curr;
        curr = next;
    }
    head = 0;
}



// Function: print
// Input: ostream pointer
// Returns: none
// Does: prints all stations in the list
//       and distance to final stop.
void LinkedList::print(ostream &out)
{
    NodeType* node = head;
    int count = length;
    while (node != NULL)
    {
        (node->info).print(out);
        cout << " " << count;
        cout << " stops to final destination.";
        cout << " == ";
        count--;
        node = node->next;
    }
    cout << endl << endl;
}



