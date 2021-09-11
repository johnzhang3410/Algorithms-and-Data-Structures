#include <iostream>
#include <set>

//Sets and Multisets automatically sorts their elements
int main() {
	//multiset allows duplicates
	std::multiset<int> ints;

	for (int i = -10; i <= 10; i++){
		ints.insert(i*i);	
	}	
	
	//print 21
	std::cout << "Size of ints is: " << ints.size() << std::endl;
	
	ints.erase(100);
	//print 19, erased both 100 from the multiset
	std::cout << "Size of ints is: " << ints.size() << std::endl;
	
	//Using the iterator to print out the multiset
	std::multiset<int>::iterator it;
	std::cout << "{";
	for (it = ints.begin(); it != ints.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "}";
	
	return 0;
}
