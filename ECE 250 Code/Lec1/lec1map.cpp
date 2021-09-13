#include <iostream>
#include <map>

//Map and multimap automatically sorts based on the key
int main() {
	//Map doesn't allow duplicates
	std::map<int, int> ints;
	std::map<char, int> charints;

	for (int i = -10; i <= 10; i++){
		ints.insert(std::pair<int, int>(i, i*i));	//insert 21 pairs of int into the map
	}	
	
	//print 21
	std::cout << "Size of ints is: " << ints.size() << std::endl;
	
	ints.erase(100);
	//print 21
	std::cout << "Size of ints is: " << ints.size() << std::endl;
	
	ints.erase(0);
	//print 20
	std::cout << "Size of ints is: " << ints.size() << std::endl;
	
	ints.erase(ints.begin(), ints.find(-7));
	//print 17
	std::cout << "Size of ints is: " << ints.size() << std::endl;
	
	ints.insert(std::pair<int,int>(-1,1));
	//print 17 since no duplicates allowed
	std::cout << "Size of ints is: " << ints.size() << std::endl;
	
	charints.insert(std::pair<char,int>('a',9999));
	//print 1
	std::cout << "Size of charints is: " << charints.size() << std::endl;
	
	//uses an iterator it1 to print out map charints
	std::map<char, int>::iterator it1;
	for (it1 = charints.begin(); it1 != charints.end(); ++it1){
		std::cout << it1->first << '\t' << it1->second << std::endl;
	}
	
	//Using the iterator to print out the map
	std::map<int, int>::iterator it;
	std::cout << "{";
	for (it = ints.begin(); it != ints.end(); ++it) {
		std::cout << it->first << '\t' << it->second << std::endl;
	}
	std::cout << "}";
	
	return 0;
}
