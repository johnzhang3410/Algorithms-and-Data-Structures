/*****************************************
 * UW User ID:  f232zhan (John Zhang) #20877763
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Fall) 2021
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#ifndef DOUBLE_SENTINEL_LIST_H
#define DOUBLE_SENTINEL_LIST_H

#include <iostream>
#include "Exception.h"

template <typename Type>
class Double_sentinel_list {
	public:
		class Double_node {
			public:
				Double_node( Type const & = Type(), Double_node * = nullptr, Double_node * = nullptr );

				Type value() const;
				Double_node *previous() const;
				Double_node *next() const;

				Type         node_value;
				Double_node *previous_node;
				Double_node *next_node;
		};

		Double_sentinel_list();	//Constructor
		Double_sentinel_list( Double_sentinel_list const & ); //Copy constructor
		Double_sentinel_list( Double_sentinel_list && ); //Move constructor (no need to implement)
		~Double_sentinel_list(); //Destructor

		// Accessors

		int size() const;
		bool empty() const;

		Type front() const;
		Type back() const;

		Double_node *begin() const;
		Double_node *end() const;
		Double_node *rbegin() const;
		Double_node *rend() const;

		Double_node *find( Type const & ) const;
		int count( Type const & ) const;

		// Mutators

		void swap( Double_sentinel_list & );
		Double_sentinel_list &operator=( Double_sentinel_list );
		Double_sentinel_list &operator=( Double_sentinel_list && );

		void push_front( Type const & );
		void push_back( Type const & );

		void pop_front();
		void pop_back();

		int erase( Type const & );

	private:
		Double_node *list_head;
		Double_node *list_tail;
		int list_size;

		// List any additional private member functions you author here
	// Friends

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Double_sentinel_list<T> const & );
};

/////////////////////////////////////////////////////////////////////////
//                      Public member functions                        //
/////////////////////////////////////////////////////////////////////////

//Constructor for the list class, Creates double nodes for the 2 sentinels
template <typename Type>
Double_sentinel_list<Type>::Double_sentinel_list():
list_head( new Double_node{Type(), nullptr, nullptr} ), //list_head is the first sentinel
list_tail( new Double_node{Type(), list_head, nullptr} ), //list_tail is back sentinel
list_size( 0 )
{
	list_head->next_node = list_tail; 
}

//Copy constructor (optional)
template <typename Type>
Double_sentinel_list<Type>::Double_sentinel_list( Double_sentinel_list<Type> const &list ):
// Updated the initialization list here
list_head( new Double_node{Type(), nullptr, list_tail} ), //List head and list tail points to the 2 sentinel nodes
list_tail( new Double_node{Type(), list_head, nullptr} ),
list_size( 0 )
{
	for (Double_node *p_node{list.list_head->next()}; p_node != list_tail; p_node = p_node->next()){
		push_back(p_node->value());
	}	
	
}

//Move Constructor (optional)
template <typename Type>
Double_sentinel_list<Type>::Double_sentinel_list( Double_sentinel_list<Type> &&list ):
// Updated the initialization list here
list_head( nullptr ),
list_tail( nullptr ),
list_size( 0 )
{

}

//Destructor - Delete all nodes including the sentinels
template <typename Type>
Double_sentinel_list<Type>::~Double_sentinel_list() {
	
	//Keep popping front while the list is not empty
	while(!empty()){
		pop_front();
	} 
	
	//deletes the 2 sentinel nodes since those are not deleted using pop_front()
	delete list_head;
	list_head = nullptr;
	
	delete list_tail;
	list_tail = nullptr;
}

//Size Accessor
template <typename Type>
int Double_sentinel_list<Type>::size() const {
	
	return list_size;
}

//Empty Accessor (Returns true if empty, else returns false)
template <typename Type>
bool Double_sentinel_list<Type>::empty() const {
	// list_head points to the sentinel, list is empty when its next points to the end sentinel
	return (list_head->next() == list_tail);
}

//Retrieves the object stored in the node pointed to by the next pointer of the head sentinel, throws underflow if list is empty
template <typename Type>
Type Double_sentinel_list<Type>::front() const {
	if (empty()){
		throw underflow();
	}else{
		return (list_head->next_node->value());
	}		
}

//Retrieves the object stored in the node pointed to by the previous pointer of the tail sentinel, throws underflow if list is empty
template <typename Type>
Type Double_sentinel_list<Type>::back() const {
	if (empty()){
		throw underflow();
	}else{
		return (list_tail->previous()->value());
	}
}

//returns the address stored by the next pointer of the head sentinel node
template <typename Type>
typename Double_sentinel_list<Type>::Double_node *Double_sentinel_list<Type>::begin() const {
	return (list_head->next());
}

//Returns the address of the tail sentinel node
template <typename Type>
typename Double_sentinel_list<Type>::Double_node *Double_sentinel_list<Type>::end() const {
	return (list_tail);
}

//Returns the address stored by the previous pointer of the tail sentinel node
template <typename Type>
typename Double_sentinel_list<Type>::Double_node *Double_sentinel_list<Type>::rbegin() const {
	return (list_tail->previous());
}

//Returns the address of the head sentinel node
template <typename Type>
typename Double_sentinel_list<Type>::Double_node *Double_sentinel_list<Type>::rend() const {
	return list_head;
}

//Returns the address of the first node in the linked list storing a value equal to the argument; if none is found, return end()
//Assumption: also returns end() if list is empty
template <typename Type>
typename Double_sentinel_list<Type>::Double_node *Double_sentinel_list<Type>::find( Type const &new_value ) const {
	
	Double_node *new_head{list_head->next_node}; //Created a double node new_head to traverse the list with
	
	//Traverse the list, and returns the address of new_head if value match, else update new_head to next()
	while (new_head != list_tail){
		
		if (new_head->value() == new_value){
			return new_head;
		}	
			
		new_head = new_head->next();
	}	
	
	return end();
}

//Returns the number of nodes in the linked list storing a value equal to the argument
template <typename Type>
int Double_sentinel_list<Type>::count( Type const &value ) const {
	
	std::size_t count{};
	
	//if list if not empty, travserse the list and add to count if values match, then return count at the end
	if (empty()){
		return 0;
	}else{
		Double_node *head{list_head};
			
		while(head->next_node != list_tail){
			if (head->next_node->value() == value){
				count++;
			}	
		
			head = head->next_node;
		}
	}		
	return count;
}

//Swaps all member variables of this linked list with those of the argument list
template <typename Type>
void Double_sentinel_list<Type>::swap( Double_sentinel_list<Type> &list ) {
	// This is done for you
	std::swap( list_head, list.list_head );
	std::swap( list_tail, list.list_tail );
	std::swap( list_size, list.list_size );
}

// The assignment operator
template <typename Type>
Double_sentinel_list<Type> &Double_sentinel_list<Type>::operator=( Double_sentinel_list<Type> rhs ) {
	// This is done for you
	swap( rhs );

	return *this;
}

// The move operator
template <typename Type>
Double_sentinel_list<Type> &Double_sentinel_list<Type>::operator=( Double_sentinel_list<Type> &&rhs ) {
	// This is done for you
	swap( rhs );

	return *this;
}

//pushes a new node to the front of the list with value new_value
template <typename Type>
void Double_sentinel_list<Type>::push_front( Type const &new_value ) {
	
	//Creates a new node and link it to the front, updated linkage between nodes accordingly
	if (empty()){
		list_head->next_node = new Double_node{new_value, list_head, list_tail};
		
		list_tail->previous_node = list_head->next_node;
	}else{	
	
		//Insert a new node after the first sentinel, its previous node points to the sentinel and next points to the original node after the sentinel 
		list_head->next_node = new Double_node{new_value, list_head, list_head->next_node};
		
		list_head->next_node->next_node->previous_node = list_head->next_node;
	}
	//add to list size since new node got pushed in
	++list_size;
	
}

//Push a new node with value of new_value to the back of the list
template <typename Type>
void Double_sentinel_list<Type>::push_back( Type const &new_value ) {
	//if the list is empty, we just push_front (result is the same)
	if (size() == 0){
		push_front(new_value);
	}else{
		//inserting the new node before sentinel with its previous node being the node before original list tail and next node being the sentinel
		list_tail->previous_node = new Double_node{new_value, list_tail->previous_node, list_tail};
		list_tail->previous_node->previous_node->next_node = list_tail->previous_node; //link original previous's next to the new node
		
		++list_size;
	}	
}

//Delete first non-sentinel node and updates any pointers/linkage as necessary, throw underflow if empty
template <typename Type>
void Double_sentinel_list<Type>::pop_front() {
	if (!empty()){ //not empty is list_head->next() != list_tail
		Double_node *old_head{list_head->next_node}; //old_head points to the first non-sentinel node
		
		list_head->next_node = list_head->next_node->next_node; //first non-sentinel node gets updated with second node
		list_head->next_node->previous_node = list_head; 
		
		--list_size;
		
		delete old_head;
		old_head = nullptr;
	}else{
		throw underflow();
	}		
}

//Delete last non-sentinel node in the list, throw underflow if empty
template <typename Type>
void Double_sentinel_list<Type>::pop_back() {
	if (empty()){
		throw underflow();
	//if there is only one node in the list, pop_back() is the same as pop_front()
	}else if (size()==1){
		pop_front();
	}else{
		Double_node *old_tail{list_tail->previous_node};
		
		//link while ignoring the last non-sentinel node
		list_tail->previous_node->previous_node->next_node = list_tail; 
		list_tail->previous_node = list_tail->previous_node->previous_node;
		
		//deletes the last (ignored) non-sentinel node
		delete old_tail;
		old_tail = nullptr;
		
		--list_size;
	}			
}

//Delete all nodes that has the same value as check_value
template <typename Type>
int Double_sentinel_list<Type>::erase( Type const &check_value ) {
	
	std::size_t count{};
	
	Double_node *new_head{list_head->next_node};
	
	//traverse the list, and delete nodes that holds the same value as check_value
	while (new_head != list_tail){
		
		if (new_head->value() == check_value){
			Double_node *old_node{new_head};
			
			new_head->previous_node->next_node = new_head->next_node;
			new_head->next_node->previous_node = new_head->previous_node;
				
			new_head = new_head->next_node;
				
			delete old_node;
			old_node = nullptr;
			
			++count;
			--list_size;	
		}else{	
			//if values doesn't match, just point to the next node	
			new_head = new_head->next_node;
		}	
	}
	
	return count;
}

//Constructor for the double node class
//nv stands for node value, pn stands for previous node and nn is for next node
template <typename Type>
Double_sentinel_list<Type>::Double_node::Double_node(
	Type const &nv,
	typename Double_sentinel_list<Type>::Double_node *pn,
	typename Double_sentinel_list<Type>::Double_node *nn ):
//Default initializations	
node_value( Type() ), 
previous_node( nullptr ),
next_node( nullptr )
{
	node_value = nv;
	previous_node = pn;
	next_node = nn;
}

//Accessor for the value at a node
template <typename Type>
Type Double_sentinel_list<Type>::Double_node::value() const {
	
	return node_value;
}

//Accessor for a node's previous node
template <typename Type>
typename Double_sentinel_list<Type>::Double_node *Double_sentinel_list<Type>::Double_node::previous() const {

	return previous_node;
}

//Accessor for a node's next node  
template <typename Type>
typename Double_sentinel_list<Type>::Double_node *Double_sentinel_list<Type>::Double_node::next() const {

	return next_node;
}

/////////////////////////////////////////////////////////////////////////
//                      Private member functions                       //
/////////////////////////////////////////////////////////////////////////

// If you author any additional private member functions, include them here

/////////////////////////////////////////////////////////////////////////
//                               Friends                               //
/////////////////////////////////////////////////////////////////////////

// You can modify this function however you want:  it will not be tested

template <typename T>
std::ostream &operator<<( std::ostream &out, Double_sentinel_list<T> const &list ) {
	out << "head";

	for ( typename Double_sentinel_list<T>::Double_node *ptr = list.rend(); ptr != nullptr; ptr = ptr->next() ) {
		if ( ptr == list.rend() || ptr == list.end() ) {
			out << "->S";
		} else {
			out << "->" << ptr->value();
		}
	}

	out << "->0" << std::endl << "tail";

	for ( typename Double_sentinel_list<T>::Double_node *ptr = list.end(); ptr != nullptr; ptr = ptr->previous() ) {
		if ( ptr == list.rend() || ptr == list.end() ) {
			out << "->S";
		} else {
			out << "->" << ptr->value();
		}
	}

	out << "->0";

	return out;
}

#endif
