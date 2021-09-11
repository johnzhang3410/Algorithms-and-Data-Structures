#include <iostream>
#include <set>

int main() {
	//Creating a set that stores integers (uniquely valued) and the set is called ints	
	std::set<int> ints; 
	
	//tries to insert duplicates into set ints (duplicates are just going to get ignored!)
	for ( int i = -10; i <= 10; i++){
		ints.insert(i*i);
	}	
	
	//Prints 11 (Since 100, 81, 64, 49, 36, 25, 16, 9, 4, 1, 0) gets inserted into the set
	std::cout << "Size of 'is': " << ints.size() << std::endl; 
	
	ints.erase(50); //Does nothing, there is no 50 in the set
	ints.erase(9); //erases 9 from the set ints
	std::cout << "Size of 'is': " << ints.size() << std::endl; //prints out 10
	
	//Defining an iterator it that iterates over a set with type int
	std::set<int>::iterator it;
	std::cout << "{";
	//it starts at the first element of set ints and iterates until the end of the set (note .begin() is a pointer to the first element of the array,
	//so it is a pointer. Therefore we access its value by dereferencing it with *)
	for (it = ints.begin(); it != ints.end(); ++it){
			std::cout << *it << std::endl;
	}	
	std::cout << "}";	
		
	return 0;	
}
