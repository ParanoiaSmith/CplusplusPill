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
};


class Person: public Human, public class_creature::Creature {
	// Because of the pure abstract method that has Creature, 
	// Its method must be implemented for instantiate a Person.  
	public:
		Person();
		// Copy constructor (not defined here):is a constructor 
		// which creates an object by initializing it with 
		// an object of the same class.
		~Person();
		int getAge();
		void setAge(int);
		void speak();
		void move();
	private:
		unsigned short int usi_age;
};
