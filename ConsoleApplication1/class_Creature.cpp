#include "pch.h"
#include "class_Creature.h"
#include <iostream>

unsigned int class_creature::Creature::sui_numCreatures = 0;

class_creature::Creature::Creature() {
	this->f_weight = 1;
	this->f_volume = 1;
	sui_numCreatures++;
}
class_creature::Creature::~Creature() {
	std::cout << "Creature removed\n";
}
void class_creature::Creature::setWeight(int f_weight) {
	this->f_weight = f_weight;
}
float class_creature::Creature::getWeight() {
	return this->f_weight;
}
void class_creature::Creature::setvolume(int f_volume) {
	this->f_volume = f_volume;
}
float class_creature::Creature::getVolume() {
	return this->f_volume;
}