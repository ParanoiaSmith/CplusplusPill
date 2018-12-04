#include "pch.h"
#include "class_Human.h"


Human::Human() { 
	// THIS keyword it's not required and is usually omitted
	// It's programmers preference. It's just something to 
	// distinguish from foreign parameters as'_' (_age)

	this->str_name = ""; 
	std::cout << "Human created\n";
}
Human::Human(std::string name) {
	this->str_name = name;
}
Human::~Human() {
	std::cout << "Human removed\n";
}
std::string Human::getName()
{
	return this->str_name;
}
// This method can be overload by derived classes
void Human::speak() {
	std::cout << "Hello!" << std::endl;
}






Person::Person() { this->usi_age = 0; }

// Copy constructor vs assignment operator 
Person::Person(const Person &obj) {
	std::cout << "Copy constructor allocated" << std::endl;
	this->usi_age = obj.usi_age;
}


Person::~Person() {std::cout << "Person killed!\n";}
int Person::getAge(){return usi_age;}
void Person::setAge(int age) { usi_age = age; }
// A virtual function is defined by prototype but it doesn't implement the logic
// When a class has a virtual function It can be instantiate as an object 
// and derived classes can be instantiated too. 

// Derived classes can override a virtual function so many classes could have 
// the same function with different behaviours. This is polimorphism

// BUT if a virtual function ends with "=0" means It's a pure virtual function
// If a class has at least one pure virtual function it's considered an
// abstract class, that means it could not be instantiated as an object.
// Only derived classes that override ALL this type of functions could be 
// instantiated otherwise it will be a second abstract class
void Person::speak() { std::cout << "Buenas tardes\n"; } //Polimorphism

// A functor is the () operator overloaded and lets 
// you create objects which "look like" a function
void Person::operator()(){
	std::cout << "I'm not a fuction, i'm an object acting as a function!" << std::endl;
}

// In a member function declaration or definition, override:
// 1. Shows the reader of the code that "this is a virtual method, 
//	  that is overriding a virtual method of the base class
// 2. Indicate the compiler to knows that it's an override, so it can "check" 
//	  that you are not altering/adding new methods that you think are overrides
// INT Person::move() override {} will cause an error 
void Person::move() { std::cout << "I'm walking on sunshine!\n"; } // See its prototype





