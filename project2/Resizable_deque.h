/*****************************************
 * UW User ID:  f232zhan
 * Submitted for ECE 250
 * Semester of Submission:  (Fall) 2021
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided  code.
 *****************************************/

#ifndef DYNAMIC_DEQUE_H
#define DYNAMIC_DEQUE_H

#include "Exception.h"

template <typename Type>
class Resizable_deque {
	public:
		Resizable_deque( int = 16 );
		Resizable_deque( Resizable_deque const & );
		Resizable_deque( Resizable_deque && );
		~Resizable_deque();

		Type front() const;
		Type back() const;
		int size() const;
		bool empty() const;
		int capacity() const;
		Type initial_capacity() const;

		void swap( Resizable_deque & );
		Resizable_deque &operator=( Resizable_deque const& );
		Resizable_deque &operator=( Resizable_deque && );
		void push_front( Type const & );
		void push_back( Type const & );
		void pop_front();
		void pop_back();
		void clear();

	private:
		// Your member variables
		
		Type *array;
		int ifront;
		int iback;
		int deque_size;
		int initial_array_capacity;
		int array_capacity;

		// Any private member functions
		//   - helper functions for resizing your array?
		

	// Friends

	template <typename T>
	friend std::ostream &operator<<( std::ostream &, Resizable_deque<T> const & );
};

/////////////////////////////////////////////////////////////////////////
//                   Constructors and Destructors                      //
/////////////////////////////////////////////////////////////////////////

// Constructor
//Allocates memory for the given capacity (Default 16 and at least 16)
template <typename Type>
Resizable_deque<Type>::Resizable_deque( int n )
// Your initalization list
{
	if (n < 16){
		n = 16;
	}
	
	array = new Type[n];
	ifront = -1;
	iback = 0;
	deque_size = 0;
	initial_array_capacity = n;
	array_capacity = n;		
		
}

// Copy Constructor
//Creates new instance of deque, and copy everything from deque over
template <typename Type>
Resizable_deque<Type>::Resizable_deque( Resizable_deque const &deque )
// Your initalization list
{
	
	/*Resizable_deque<Type> dq2(deque.capacity());
	
	dq2.ifront = deque.ifront;
	dq2.iback = deque.iback;
	dq2.deque_size = deque.deque_size;
	dq2.initial_array_capacity = deque.initial_array_capacity;
	
	for (int i{}; i < deque.size(); i++){
		
		push_back(deque.front());
	}	*/
	
	
	//New array has same size as deque
	Type *new_array;
	new_array = new Type[deque.capacity()];
	
	ifront = deque.ifront;
	iback = deque.iback;
	
	for (int i{}; i < deque.size(); i++){
		
		if (ifront == deque.capacity()){
			ifront = 0;
		}	
		
		new_array[ifront] = deque.front();
		++ifront;
	}	
	
	array_capacity = deque.capacity();
	initial_array_capacity = deque.initial_array_capacity;
	deque_size = deque.size();
		
}

// Move Constructor, creates an empty deque and calls swap
template <typename Type>
Resizable_deque<Type>::Resizable_deque( Resizable_deque &&deque )
// Your initalization list
{
	//Type *new_array;
	//new_array = new Type[deque.capacity()];
	
	Resizable_deque<Type> dq2(deque.capacity());
	dq2.ifront = -1;
	dq2.iback = -1;
	dq2.initial_array_capacity = deque.initial_array_capacity;
	dq2.deque_size = 0;
	
	swap(deque);
	
}

// Destructor
template <typename Type>
Resizable_deque<Type>::~Resizable_deque() {
	
	delete[] array;
	array = nullptr;
		
}

/////////////////////////////////////////////////////////////////////////
//                     Public Member Functions                         //
/////////////////////////////////////////////////////////////////////////

//Accessor that return the number of elements currently stored in the deque
template <typename Type>
int Resizable_deque<Type>::size() const {
	
	return deque_size;
}

//Return the current capacity of the deque
template <typename Type>
int Resizable_deque<Type>::capacity() const {
	
	return array_capacity;
}

//Return true if deque is empty, else return false
template <typename Type>
bool Resizable_deque<Type>::empty() const {
	
	return (size() == 0);
}

//Accessor that return the object at the front of deque
template <typename  Type>
Type Resizable_deque<Type>::front() const {
	
	if (empty()){
		throw underflow();
	}
	
	return array[ifront];	
		
}

//Accessor that return the object at the back of deque
template <typename  Type>
Type Resizable_deque<Type>::back() const {
	
	if (empty()){
		throw underflow();
	}
	
	return array[iback];
}

template <typename  Type>
Type Resizable_deque<Type>::initial_capacity() const {
	return initial_array_capacity;
}	

//swaps all member variables of this deque with those of the arugument
template <typename Type>
void Resizable_deque<Type>::swap( Resizable_deque<Type> &deque ) {
	// Swap the member variables
	//     std::swap( variable, deque.variable );

	std::swap(ifront, deque.ifront);
	std::swap(iback, deque.iback);
	std::swap(deque_size, deque.deque_size);
	std::swap(initial_array_capacity, deque.initial_array_capacity);
	std::swap(array_capacity, deque.array_capacity);
	
}

//Make a copy of the argument and swap the copy with this node
template <typename Type>
Resizable_deque<Type> &Resizable_deque<Type>::operator=( Resizable_deque<Type> const &rhs ) {
	// This is done for you...
	Resizable_deque<Type> copy( rhs );
	swap( copy );

	return *this;
}

//Moves the argument array to this array, leaving the argument empty
template <typename Type>
Resizable_deque<Type> &Resizable_deque<Type>::operator=( Resizable_deque<Type> &&rhs ) {
	// This is done for you...
	swap( rhs );

	return *this;
}

//Insert new element at the front of deque. If the array is full before push_front, then double the capacity of array
template <typename Type>
void Resizable_deque<Type>::push_front( Type const &obj ) {
	
	//When the array is full, double the capacity and copy everything after ifront to the end of the expanded array
	if (size() == capacity()){
		
		Type *new_array = new Type[array_capacity * 2]; //Create a new array with double the capacity
		
		//size from ifront to the end of array
		int new_size = deque_size - iback - 1;
		
		int new_capacity = array_capacity * 2;
		
		int index{deque_size - 1};
		
		//Moving everything from ifront to the end of the array to the back of new_array
		for (int i{new_capacity - 1}; i != new_capacity - new_size - 1; i--){
			
			new_array[i] = array[index];
			
			--index;
		}	
		
		//Copy everything from front of the array to iback to the front of the new_array
		for (int i{iback}; i >= 0; i--){
			new_array[i] = array[i];
				
		}	
			
		//Update ifront with its new index
		ifront = new_capacity - new_size;
			
		if (ifront == new_capacity){
			ifront = 0;	
		}
		
		//Delete the original array and replace its content with the new_array		
		delete[] array;	
		array = new_array;
		
		array_capacity *= 2;
		
	}
	
	//if the size of the array is 0, then index of front and back are the same and we push to the front index
	if (ifront == -1){
		ifront = 0;
		array[ifront] = obj;
		deque_size++;
	}else{
		//if the first index is zero, then we move the front index to the back and push the element onto it
		if (ifront == 0){
			ifront = capacity() - 1;
			array[ifront] = obj;
			deque_size++;
		}else{
			ifront--;
			array[ifront] = obj;
			deque_size++;
		}		
	}			
	
}

//Push to the back of deque. if full before insert, capacity of array is doubled
template <typename Type>
void Resizable_deque<Type>::push_back( Type const &obj ) {
	
		//When the array is full, double the capacity and copy everything after ifront to the end of the expanded array
	if (size() == capacity()){
		
		Type *new_array = new Type[array_capacity * 2]; //Create a new array with double the capacity
		
		//size from ifront to the end of array
		int new_size = deque_size - iback - 1;
		
		int new_capacity = array_capacity * 2;
		
		int index{deque_size - 1};
		
		//Moving everything from ifront to the end of the array to the back of new_array
		for (int i{new_capacity - 1}; i != new_capacity - new_size - 1; i--){
			
			new_array[i] = array[index];
			
			--index;
		}	
		
		//Copy everything from front of the array to iback to the front of the new_array
		for (int i{iback}; i >= 0; i--){
			new_array[i] = array[i];
				
		}	
			
		//Update ifront with its new index
		ifront = new_capacity - new_size;
			
		if (ifront == new_capacity){
			ifront = 0;	
		}
		
		//Delete the original array and replace its content with the new_array		
		delete[] array;	
		array = new_array;
		
		//Update array capacity
		array_capacity *= 2;
		
	}
	
	if (ifront == -1){
		ifront = 0;
		array[iback] = obj;
		deque_size++;
	}else{
		if (iback == capacity() - 1){
			iback = 0;
			array[iback] = obj;
			deque_size++;
		}else{	
			iback++;
			array[iback] = obj;
			deque_size++;
		}
	}		
		
	
}

//Removes the front element. If array is 1/4 full or less after the element is removed and the array capacity is greater
//than the initial capacity, then half the capacity. May throw a underflow.
template <typename Type>
void Resizable_deque<Type>::pop_front() {
	
	if (empty()){
		throw underflow();
	}else{
		//Update index to the beginning of array if at the end (since we are using circular array)
		if (ifront == array_capacity - 1){
			ifront = -1;
		}
		
		++ifront;
		--deque_size;	
		
	}
	
	if ((deque_size <= array_capacity/4) && (array_capacity > initial_array_capacity)){
		
		if(ifront > iback){
		
			Type *new_array = new Type[array_capacity / 2]; //Create a new array with half the capacity
		
			int new_capacity = array_capacity / 2;
		
			int new_size = deque_size - iback - 1;
		
			int index{array_capacity - 1};
		
			//Moving everything from ifront to the end of the array to the back of new_array
			for (int i{new_capacity - 1}; i != new_capacity - new_size - 1; i--){
			
				new_array[i] = array[index];
					
				--index;
			}	
		
			//Copy everything from front of the array to iback to the front of the new_array
			for (int i{iback}; i >= 0; i--){
				new_array[i] = array[i];
				
			}	
			
			//Update ifront with its new index
			ifront = new_capacity - new_size;
				
			if (ifront == new_capacity){
				ifront = 0;	
			}
		
			//Delete the original array and replace its content with the new_array		
			delete[] array;	
			array = new_array;
		
			array_capacity /= 2;
		}else{
			
			Type *new_array = new Type[array_capacity / 2]; //Create a new array with half the size
			
			int counter{};
			
			//copy everything in between ifront and iback to the beginning of the new array
			for(int i{ifront}; i <= iback; i++){
				
				new_array[counter] = array[i];
				
				counter++; 	
			}	
			
			delete[] array;
			array = new_array;
			
			array_capacity /= 2;
			ifront = 0;
			iback = deque_size - 1;
			
		}	
		
	}		
			
}

//Removes the back element, If array is 1/4 full or less after the element is removed and the array capacity is greater
//than the initial capacity, then half the capacity. May throw a underflow.
template <typename Type>
void Resizable_deque<Type>::pop_back() {
	
	if (empty()){
		throw underflow();
	}else{
		
		if (iback == 0){
			iback = array_capacity;
		}
		
		--iback;
		--deque_size;	
	}		
	
	if ((deque_size <= array_capacity/4) && (array_capacity > initial_array_capacity)){
		
		if (ifront > iback){
		
			Type *new_array = new Type[array_capacity / 2]; //Create a new array with half the capacity
		
			int new_capacity = array_capacity / 2;
		
			int new_size = deque_size - iback - 1;
		
			int index{array_capacity - 1};
		
			//Moving everything from ifront to the end of the array to the back of new_array
			for (int i{new_capacity - 1}; i != new_capacity - new_size - 1; i--){
			
				new_array[i] = array[index];
			
				--index;
			}	
		
			//Copy everything from front of the array to iback to the front of the new_array
			for (int i{iback}; i >= 0; i--){
				new_array[i] = array[i];
				
			}	
			
			//Update ifront with its new index
			ifront = new_capacity - new_size;
			
			if (ifront == new_capacity){
				ifront = 0;	
			}
		
			//Delete the original array and replace its content with the new_array		
			delete[] array;	
			array = new_array;
			
			array_capacity /= 2;
		}else{
			
			Type *new_array = new Type[array_capacity / 2]; //Create a new array with half the size
			
			int counter{};
			
			//copy everything in between ifront and iback to the beginning of the new array
			for(int i{ifront}; i <= iback; i++){
				
				new_array[counter] = array[i];
				
				counter++; 	
			}	
			
			delete[] array;
			array = new_array;
			
			array_capacity /= 2;
			ifront = 0;
			iback = deque_size - 1;
			
		}	
	}	
}

//Empties the deque by resetting the member variables, the array is resized to the initial capacity
template <typename Type>
void Resizable_deque<Type>::clear() {
	
	if (array_capacity != initial_array_capacity){
		delete[] array;
		array = new Type[initial_array_capacity];
	}
	
	array_capacity = initial_array_capacity;
	ifront = -1;
	iback = 0;
	deque_size = 0;
	
}
/////////////////////////////////////////////////////////////////////////
//                      Private member functions                       //
/////////////////////////////////////////////////////////////////////////

// Enter any private member functios (helper functions) here


/////////////////////////////////////////////////////////////////////////
//                               Friends                               //
/////////////////////////////////////////////////////////////////////////

// You can modify this function however you want:  it will not be tested

template <typename T>
std::ostream &operator<<( std::ostream &out, Resizable_deque<T> const &list ) {
	out << "not yet implemented";

	return out;
}

#endif
