#define _USE_MATH_DEFINES //Always includes when using <cmath> library
#include <cmath> //The math library
#include <iostream>
#include <cassert>

//Code development strategies:
//1.Author all the functions first with parameters and return value of zero
//2.Add any assertions on the parameters
//3.Add any additional functions that simplifies the program (Use more functions!)
//4.Focus on authoring one function at a time, start with the easier one if you can
//5.Compile after each step! and repeat!


////Declaring a function
////double sin( double x );//A function that takes an argument float x, do the sin and return a float
////double pow( double x, double y);//Takes 2 float arguments x and y and calculates x to the power of y
////double hypot( double x, double y);//Calculates sqrt of x squared plus y squared
////double abs( double x ); //Takes the absolute value of the value x
//
//int main();
//
//int main() {
//
//std::cout << std::sin(1) << std::endl;//Calculates the sin
//std::cout << std::atan(1) << std::endl;//Calculates the inverse tangent
//std::cout << std::sqrt(1) << std::endl;//Calculates the sqrt
//std::cout << std::cbrt(1) << std::endl;//Calculates the cbrt
//
//}
//Lecture on Writing Functions
int main();
double my_abs(double x);
double max(double x, double y);
double w(double x);
double max(double x, double y, double z);
int get_value_no_less_than(std::string text, int lower_bound);
int factorial (int n);
int binomial (int n, int k);
double arithmetic(double a, double d, int n);
double arithmeticefficient(double a, double d, int n);
double geometric(double a, double r, int n);
double running_average();
bool is_even(int n);
bool is_prime(int n);
void reflect(int n);
int gcd(int m, int n);
void print_array(double *array, std::size_t const cap);
std::size_t find(double const array[], std::size_t const capacity, double const value);
std::size_t is_sorted(double const array[], std::size_t const capacity);
std::size_t binary_search(double const array[], std::size_t const capacity, double const value);
void selection_sort(double array[], std::size_t capacity);
void insert(double array[], std::size_t capacity);
void insertion_sort(double array[], std::size_t capacity);
void print_subsets( bool membership_array[], std::size_t capacity, std::size_t current_index);

double my_abs( double x ){//Declares the function my_abs with parameter x as a float
	double result{};//Declares local variable result{}
	if (x >= 0) {//Function body
		result = x;
	}else {
		result = -x;
	}

	return result;//Returns result
}

double max(double x, double y){//A max function that takes two floats and returns the greater value
	if (x >= y) {
		return x;
	}else{
		return y;
	}
}

double w(double x) {//Declares a function w
	return my_abs(my_abs(3.0*x) - 3.0); //Includes another function in this function w
}

double max (double x, double y, double z){
	return max(max(x,y),z);
}
//A function that asks the user to input value no less than lower_bound
int get_value_no_less_than(std::string text, int lower_bound){
	int n{};
	std::cout << text;
	std::cin >> n;

	while (n < lower_bound) {
		std::cout << text;
		std::cin >> n;
	}
	return n;
}
//A factorial function
int factorial (int n) {
	if (n < 0){ //Instead of this, we can use assert(n >= 0); which restricts n to be >= 0 and return as error
		return 0;//when it's not zero
	}else{//assert( (n>=0) && (n<=12) ); blc any factorial greater than 12 returns a wrong value
		int result{1};

		for (int k{2}; k <=n; ++k){
			result *= k;
		}
		return result;
	}
}
//A binomial function
int binomial (int n, int k){
	if (n < 0 || k < 0 || k > n){
		return 0;
	}else{
		return factorial(n)/factorial(k)/factorial(n-k);
	}
}
//A falling factorial function that only takes factorial up to n-k+1
int falling_factorial(int n, int k){

	if (k == 0){
		return 1;
	}else if (k < 0){
		return 0;
	}else{
		int result{1};
		for (int i{n}; i >= n - k + 1; --i){
			result *= i;
		}
	return result;
	}
}

//Arithmetic series a + (a+d) + (a+2d) + ... + (a+nd)
double arithmetic(double a, double d, int n){
	if (n <= 0){
		return 0.0;
	}else{
		double result{0.0};
		for (int c{0}; c <= n; c++){
			result += a + c*d;
		}
		return result;
	}
}

//A more efficient/easier function of arithmetic series
double arithmeticefficient(double a, double d, int n){
	if (n <= 0){
		return 0.0;
	}else{
		return a*(n+1) + d*((n*(n+1))/2);//Divide by integer may truncate the decimal places, but it's okay
		} 								//in this case blc n*(n+1) is going to be an even integer
	}

//Geometric series
double geometric(double a, double r, int n){
	if (n<0){
		return 0.0;
	}else if (r == 0){
		return a*(n + 1);
	}else{
		return (a*(1.0-std::pow(r,n+1)))/(1.0-r);
	}
}
//Calculates the running average of continuous user inputs
double running_average(){
	double running_sum{0.0};

	for (int k{1}; true; ++k){
	double value{};
	std::cout << "Enter a number: ";
	std::cin >> value;

	running_sum += value;

	std::cout << running_sum/k << std::endl;

	if (value == 0){
		return running_sum/k;
	}
}
}

bool is_even(int n){
	return (n%2 == 0);
}

//function that checks if the user input is prime
bool is_prime(int n){ //sets an boolean variable is_prime to true
	bool is_prime(true);
	if (n%2 == 0 ){ //Takes the user input and % by 2 and check the remainder, if remainder = 0, the input
		is_prime = false;//is an even number and even number can't be prime so is_prime = false

	}else{ //Now checks the odd number to see if it's prime
		for (int k{3}; k*k <= n; k += 2 ){ //sets k to 3 and loops when its less than the user input
			if (n%k == 0){ //if user input(An odd number)'s remainder is zero
				is_prime = false; //The number is then not prime
		}
	}
}
if (is_prime) { //if is_prime is true then
	return true;
}else{ //Else is_prime is false then
	return false;
}
}
//Reflects the argument number over a pipe "|"
void reflect(int n){
	if (n == 0){
		std::cout << "0|0" << std::endl;
		return;
	}

	std::cout << n << "|";

	bool is_negative(false);

	if (n<0){
		n = -n;
		is_negative = true;
	}

	while (n != 0){
		std::cout << (n%10);
		n /= 10;
	}

	if (is_negative){
		std::cout << "-";
	}

	std::cout << std::endl;
	return;
}
//Greatest Common Divisor
int gcd(int m, int n){
	if (m == 0){
		return n;
	}else if (n==0){
		return m;
	}

	while (n!=0){
		int r{m%n};
		m=n;
		n=r;
	}
	return m;
}

//Prints a dynamically allocated array
void print_array(double *array, std::size_t const cap){
	if (cap == 0){
		return;
	}else{
		std::cout << array[0];

		for (int k{1}; k < cap; k++){
			std::cout << ", " << array[k];
		}
	}
	std::cout << std::endl;
}

std::size_t find(double const array[], std::size_t const capacity, double const value){
	for (int k{}; k < capacity; k++){
		if (array[k] == value){
			return k; //return the current index when the value is found
		}
	}
	return capacity; //Return capacity when the value we are looking for is not within the array
}

//If not sorted: outputs the index where the array is not sorted, if sorted: return capacity
std::size_t is_sorted(double const array[], std::size_t const capacity){
	for (int k{}; k < capacity - 1; k++){
		if (array[k] > array[k+1]){
			return k+1;
		}
	}
	return capacity;
}

//Searching a SORTED array, if array is not sorted then linear search is needed
std::size_t binary_search(double const array[], std::size_t const capacity, double const value){
	assert (is_sorted(array, capacity) == capacity); //Make sure that the array is sorted

	std::size_t lower_index{0};
	std::size_t upper_index{capacity - 1};

	while (lower_index <= upper_index && upper_index < capacity){
		std::size_t average((lower_index + upper_index)/ 2);

		if (average == value){
			return average;
		}else if (array[average] < value){
			lower_index = average + 1;
		}else{
			upper_index = average - 1;
		}
	}
	return capacity; //return capacity if the value has not been found
}

//Selection sort: Select the index with the biggest value and swaps it with the last index, loop until sorted
void selection_sort(double array[], std::size_t capacity){
	for (std::size_t k{capacity - 1}; k > 0; k--){
		std::size_t max_index{0}; //Assume that the max index is 0

		for (std::size_t j{1}; j <= k; j++){ //Find the biggest index and set it to max_index
			if (array[j] > array[max_index]){
				max_index = j;
			}
		}

		//Swaps last index with the biggest index found
		double tmp{array[max_index]};
		array[max_index] = array[k];
		array[k] = tmp; //Move the biggest value to the current unsorted end
	}
}

//Insert function: For the last index to be unsorted
void insert(double array[], std::size_t capacity){
	assert(is_sorted(array, capacity-1) == (capacity - 1)); //Make sure everything before the last value is sorted

	double value{array[capacity - 1]}; //The last value in the array (Assuming to be unsorted)

	std::size_t k{};

	for (k = capacity - 1; (k > 0) && (array[k-1] > value); k--){
		array[k] = array[k - 1]; //Move the indices that have larger value to the right
	}

	array[k] = value; //Insert the unsorted value into the correct index in the array
}

void insertion_sort(double array[], std::size_t capacity){
	for (std::size_t k{2}; k <= capacity; ++k){
		insert(array, k);
	}

	assert(is_sorted(array, capacity) == capacity);
}

//A recursive implementation of printing out all subsets of a given set array
void print_subsets( bool membership_array[], std::size_t capacity, std::size_t current_index){
	//when current_index exceeds the number of elements in the array, we print out index+1 of all elements that are true
	if (current_index == capacity){
		for (unsigned int k{0}; k < capacity; ++k){
			if (membership_array[k]) {
				std::cout << (k+1) << " ";
			}
		}

		std::cout <<std::endl;
	}else{
		membership_array[current_index] = true;
		print_subsets( membership_array, current_index+1, capacity);
		membership_array[current_index] = false;
		print_subsets( membership_array, current_index+1, capacity);
	}
}

int main() {

	bool membership_array[2];

	print_subsets(membership_array, 2, 0);

}

