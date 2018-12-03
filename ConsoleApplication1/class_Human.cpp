#include "pch.h"
#include "class_Human.h"


Human::Human() { 
	this->str_name = ""; 
	std::cout << "Human created\n";
}
Human::Human(std::string name) {
	this->str_name = name;
}
Human::~Human() {
	std::cout << "Human removed\n";
}
// This method can be overload by derived classes
void Human::speak() {
	std::cout << "Hello!" << std::endl;
}




Person::Person() { this->usi_age = 0; }
Person::~Person() {std::cout << "Person killed!\n";}
int Person::getAge(){return usi_age;}
void Person::setAge(int age) { usi_age = age; }
void Person::speak() { std::cout << "Buenas tardes\n"; } //Polimorphism
void Person::move() { std::cout << "I'm walking on sunshine!\n"; }


// Cuando una clase implementa una función virtual, se puede instanciar la 
// clase y las clases hijo pueden sobreescribir el método. Polimorfismo.

// Una clase que contiene al menos una función pura virtual (con el =0) 
// se considera una clase abstracta. Ya no se pueden instanciar objetos.
// Las clases derivadas de la clase abstracta deben implementar la 
// función virtual pura o deben ser también clases abstractas.
// You should use override to force the
// compiler to check if the base class
// virtual fucntion is the same as
// the subclass


