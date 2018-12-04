#include "pch.h"
#include "class_Creature.h"

class Human {
	private:
		std::string str_name;
	public:
		Human();
		Human(std::string);
		~Human();
		virtual void speak();
		std::string getName();
};


class Person: public Human, public class_creature::Creature {
	// Because of the pure abstract method that has Creature, 
	// Its method must be implemented for instantiate a Person.  
	public:
		Person();
		// Copy constructor is a constructor which creates an 
		// object by initializing it with an object of the same class.
		Person(const Person &obj);

		// Initialization list
		Person(unsigned short int age) : usi_age(age) {}

		~Person();
		int getAge();
		void setAge(int);
		void speak();

		void operator() ();
		void move() override;
	private:
		unsigned short int usi_age;
};
