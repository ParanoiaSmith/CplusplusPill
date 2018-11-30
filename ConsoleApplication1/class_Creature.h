#include <iostream>

// namespace is useful when the word 'creature' collide with the same
// in this case with a struct in someFunctions.cpp
namespace class_creature {
	class Creature {
	private:
		float f_weight;
		float f_volume;
		// The value is common to all instances
		static unsigned int sui_numCreatures;
	public:
		Creature();
		~Creature();
		void setWeight(int f_weight);
		float getWeight();
		void setvolume(int f_volume);
		float getVolume();
		virtual void move() = 0; // Pure virtual function
		// Only static functions can acces static (just) static variables
		static int getNumCreatures() {
			return sui_numCreatures; // this-> is not allowed
		}
		// Operators overloaded must be inside the namespace, if not: error 
		friend std::ostream& operator<< (std::ostream &out, Creature &a) {
			out << "Criature weight: " << a.getWeight() << std::endl;
			out << "Criature volume: " << a.getVolume() << std::endl;
			return out;
		}
	};
}