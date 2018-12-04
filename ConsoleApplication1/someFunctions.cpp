#include "pch.h"
#include "someFunctions.h"
#include "class_Human.h"

// MACRO preporcessing
#define Matrix(current_height, current_width)  arr[ (current_width)+(current_height)*(width) ]
#define AREA_CIRCLE(radius) (PI * (std::pow(radius, 2)))
#define PI 3.1415926


/********************************************************
*
* types and their spaces 
*
*********************************************************/
void typeNotes() {
	const double E = 2.71828182;
	bool b_Married = false;
	char c_MyGrade = 'A';
	unsigned short int usi_Age = 24;
	short int si_Weight = 70;
	int i_Days = 28;
	long l_BigNum = 99999999;
	float f_Pi = 3.1415;
	double d_BigFloat = 9.999999999;
	long double ld_Pi = 3.141592;
	auto a_Whatever = true;
	enum colors { red, blue, yellow, green };
	colors myFavouriteColor = green; // If cout will show 3

	std::cout << "Min bool " << (std::numeric_limits<unsigned short int>::max)() << std::endl;
	std::cout << "Min bool " << sizeof(unsigned short int) << std::endl;
	std::string s_Question("I'm going to cast strings to ints");
	std::cout << (std::stoi("4a2e")) << std::endl; //String to int -> 4
	std::cout << (std::stod("4.55555558")) << std::endl; //String to int -> 4
	std::string s_Age = "";

	// Another way to cin & cout
	getline(std::cin, s_Age);
	printf("You age is: %c \n", s_Age);


	// Global variable, be careful with const (see wiki)
	extern int i_global;
	std::cout << i_global << std::endl;


	// Creating scope 1
	{
		int j = 0;
		{ // Creating scope 2
			int k = 2;
		}
		// At this point k is unaccesible
	}
	// At this point j is unaccesible


	// Unsing a typedef only creates an alias for a specific type
	typedef int entero;
	entero num = 77;
	std::cout << num << std::endl;
}


/********************************************************
*
* Parameters by reference and recursivity, short if
*
*********************************************************/
int recursiveFactorial(int num) { 
	return (num == 1)? 1 : num * recursiveFactorial(num - 1);
}
void infinitySum(int &value) {
	// When a function is called, There are an overhead of memory because
	// a copy of variables and elements are stored in other place in the memory

	// It's preferred passing reference value because the program doesn't need 
	// to make a copy of the variable to return the value of that copy and waste memory

	// Why reference over pointers?
	// 1. References are generally implemented using pointers
	// 2. A reference is same object/type, just with a different name  
	// 3. References can’t be NULL, they are safer to use
	// 4. A pointer can be re-assigned while reference cannot
	// 5. Pointers can iterate over an array while reference cannot

	std::cout << "Hello, please enter two integers: " << std::endl;
	int firstNumber, secondNumber;
	// This loops breaks when reads not an integer
	while (std::cin >> firstNumber >> secondNumber) {
		std::cout << "The sum is:  " << firstNumber + secondNumber << std::endl;
		// Short if: (condition) ? (if_true) : (if_false)
	}
	// The reference is used as an alias
	value = 999;
	
	std::cout << recursiveFactorial(5) << std::endl;
	return void();
}


/********************************************************
*
* Matrices and POINTERS Notes
*
*********************************************************/
void printMatrices_int(int* arr, int height, int width) {
	std::cout << std::endl << "{ ";
	for (int i = 0; i < height; i++) {
		for (int ii = 0; ii < width; ii++) {
			// std::cout << arr[i*height + ii] << ", ";
			std::cout << Matrix(i, ii) << ", ";
		}
		std::cout << std::endl;
	}
	std::cout << " }" << std::endl;

	// Actually it does not have sense print tensors of more than 3 dim
	// Func: (int* arr, int* arr_descrip, int arr_descrip_size)
	// arr_descrip_size has to be a passed variable. 
	// It can't be calculated inside the function because of pointers
	//for (int i = 0; i < arr_descrip_size; i++) { // dimensions
	//	for (int ii = 0; ii < *(arr_descrip+i); ii++) { // dimension size
	//		std::cout << *(arr + ii) << ", ";
	//	}
	//	std::cout << std::endl;
	//}
}
void matricesNotes( int* arr ) { // *arr == arr[SIZE] == arr[]

	// http://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_pointerreference.html
	
	// Be careful:
	// If the value is destroyed with a destructor or delete, 
	// the other pointer will have invalid memory direction 
	// this is called a dangling pointer

	int Age = 24;
	int *pAge;
	pAge = &Age; // now pAge has the direction of Age
	std::cout << pAge << std::endl; // address
	std::cout << *pAge << std::endl; // variable

	// Value of the firts element 
	std::cout << *arr << std::endl; // 0x008EEF64
	// Memory dir. of the first element
	std::cout << arr << std::endl; // or arr[] // 4
	// Value of the second/following element
	std::cout << *(arr + 1) << std::endl; //5		*(arr + 1) == arr[1]							
	// Memory dir. of the second/following element
	std::cout << arr + 1 << std::endl; // 0x008EEF68
	// Edit array, so in main would change too
	arr[1] = 777;

	// MULTI-DIMENSIONAL
	// Iteration order: down-right
	int arr3D[2][3][4] = {
							{
								{1,2,3,4},
								{5,6,7,8},
								{1,2,3,4}
							},
							{
								{1,2,3,4},
								{5,6,7,8},
								{1,2,3,4}
							}
	};
	// Get the size of each dimension
	static const unsigned int arr3D_ndim = 3; // 'static const' is necessary
	unsigned int arr3D_size_dim[arr3D_ndim];
	float divisor = 1;
	for (int i = 0; i < arr3D_ndim; i++) {
		arr3D_size_dim[i] = (sizeof(arr3D[0][0]) / sizeof(arr3D[0][0][0])) / divisor; // **arr3D == arr3D[0][0]
		divisor = arr3D_size_dim[i] / divisor;
		std::cout << "Dimension " << i << " has size: " << arr3D_size_dim[i] << std::endl;
		//// What it would be
		//arr3D_size_dim[i] = ( sizeof(**arr3D) / sizeof(arr3D[0][0][0]) ) / divisor;
		//arr3D_size_dim[i] = ( sizeof(*arr3D) / sizeof(arr3D[0][0][0]) ) / divisor;
		//arr3D_size_dim[i] = ( sizeof(arr3D) / sizeof(arr3D[0][0][0]) ) / divisor;
	}
	// To print it it's necessary iterate over it
	for (int i = 0; i < 2; i++) {
		for (int ii = 0; ii < 3; ii++) {
			for (int iii = 0; iii < 4; iii++) {
				std::cout << arr3D[i][ii][iii];
			} std::cout << std::endl;
		} std::cout << std::endl;
	}

	// To sum up, better use pseudo-multidimensional arrays
	// Multi-dim. arrays are just an abstraction for programmers
	#define HEIGHT 7	
	#define WIDTH 2
	int arr_sequential[HEIGHT * WIDTH] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	printMatrices_int(arr_sequential, HEIGHT, WIDTH);
	return void();
}


/********************************************************
*
* Struct Notes
*
*********************************************************/
// enum needs to be defined out of the struct because of the scope
enum type { mamal, insect, plant };
struct Creature {
	// struct is almost identical to a class compatibility c/c++ using a typedef class struct
	type e_type;
	char c_name[50];
	int i_age;
	Creature() : i_age(3), x(5) {}  // initialization list
	Creature(int age, int j) : i_age(age), x(j) {
		strcpy_s(c_name, "Noa"); e_type = mamal;
	}
	~Creature() { std::cout << "Creature dead\n"; } 
	void printMe() {
		std::cout << i_age << std::endl;
		std::cout << e_type << std::endl;
		std::cout << c_name << std::endl;
		std::cout << x << std::endl;
	}
	// All variables are public by default
	private: 
		int x; // must be here, the last line idk"
};
// It can inherit from a struct
struct Dog : Creature {
	// Override the constructor
	// You also use this with structs
	Dog( const char _name[]) {
		strcpy_s(c_name, _name);
		i_age = 3;
		e_type = mamal;
	}
	~Dog() { std::cout << "Dog dead\n"; } 

	// Overriding form parent
	void printMe() {
		std::cout << i_age << std::endl;
		std::cout << e_type << std::endl;
		std::cout << c_name << std::endl;
	}
};
void printStruct(Creature *s_creature) {
	// (*moneyWasted_func).euros == moneyWasted_func->euros
	std::cout << (*s_creature).i_age << std::endl;
	std::cout << s_creature->e_type << std::endl;
	std::cout << s_creature->c_name << std::endl;
	// ERR: std::cout << s_creature->x << std::endl; // X is inaccesible, It's necessary a 'getter' func
}
void structNotes() {
	Creature s_creature;
	strcpy_s(s_creature.c_name, "Yako");
	s_creature.i_age = 15;
	s_creature.e_type = mamal;

	// 2 different way for doing the same
	s_creature.printMe();
	printStruct( &s_creature);

	Creature s_creature2(55, 77);
	s_creature2.printMe();

	Dog myDog("Chispi");
	myDog.printMe();
}


/********************************************************
*
* STD containers: Vector
*
*********************************************************/
void vectorNotes() {
	std::vector<int> vec_RandNums(1);
	vec_RandNums[0] = 42;
	vec_RandNums.push_back(7);
	std::cout << "Last index number: " << vec_RandNums[vec_RandNums.size() - 1] << std::endl;
	std::vector<int> vec_myVec(15);
	//std::iota(std::begin(vec_myVec), std::end(vec_myVec), 0);
	std::srand(time(NULL)); //seed to give rand() randomness
	std::generate(vec_myVec.begin(), vec_myVec.end(), []() { return std::rand() % 100; } );
	std::random_shuffle(vec_myVec.begin(), vec_myVec.end(), [](int max) { return std::rand() % max; });
	std::sort(vec_myVec.begin(), vec_myVec.end(), [](int x, int y) { return (x < y); });
	// There are: copy_if, for_each

	// To iterate over a vector, 3 ways:
	//for (int i = 0; i < vec_myvec.size(); i++)
	//	std::cout << vec_myvec[i] << std::endl;

	for (auto y : vec_myVec) std::cout << y << std::endl;
	std::cout << "\n\n\n\n";

	// With a special pointer
	std::vector<int>::iterator itr = vec_myVec.begin();
	advance(itr, 2);
	std::cout << *itr << "\n";
	itr = next(itr, 1);			//like advance but returns an iterator
	std::cout << *itr << "\n";
	itr = prev(itr, 1);			//like next 
	std::cout << *itr << "\n";
}



/********************************************************
*
* Write & read files
*
*********************************************************/
void ioFilesNotes() {
	std::ofstream writeToFile;
	std::ifstream readFromFile;
	std::string txtToWrite = "";
	std::string txtFromFile = "";

	// We open the file by providing a name and then either
	// ios::app : Append to the end of the file
	// ios::trunc : If the exists delete content
	// ios::in : Open file for reading
	// ios::out : Open file for writing
	// ios::ate : Open writing and move to the end of the file
	writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
	if (writeToFile.is_open()) {
		// You can write with the stream insertion operator
		writeToFile << "Beginning of File\n";
		// You can write data in a string
		std::cout << "Enter data to write : ";
		getline(std::cin, txtToWrite);
		writeToFile << txtToWrite;
		// Close the file 
		writeToFile.close();
	}

	// Open the file for reading
	readFromFile.open("test.txt", std::ios_base::in);
	if (readFromFile.is_open()) {
		// Read text from file
		while (readFromFile.good()) {
			getline(readFromFile, txtFromFile);
			// Print text from file
			std::cout << txtFromFile << "\n";
		}
		readFromFile.close();
	}
}



/********************************************************
*
* Classes
*
*********************************************************/
void classesNotes() {
	// Could be understood as a struct
	//class Box {
	//public:
	//	double volume;
	//} box1;

	Person p1(24);
	// Functions of the father can be used in sons
	std::cout << p1 << std::endl;
	std::cout << p1.getNumCreatures() << std::endl;
	p1.speak();

	Human h1("Javier"); // We can instantiate fathers if not abstract
	h1.speak(); // Polimorphism



	// copy constructor vs assignment operator
	// By default, the compiler generates implicitly a copy constructor
	// Generating a copy constructor explicitly is a way to force it.
	// It not makes a reference to the same memory, justs copy it.
	Human h2;
	h2 = h1;
	std::cout << h1.getName() << std::endl;
	std::cout << h2.getName() << std::endl;
	h1.~Human();
	std::cout << h2.getName() << std::endl;

	// With a explicit copy constructor is the same
	Person p2(p1);
	std::cout << p2.getAge() << std::endl;
	std::cout << p1.getAge() << std::endl;
	p1.~Person();
	std::cout << p2.getAge() << std::endl;

	// Calling a functor, see Person implementation
	p1();
}



/********************************************************
*
* Deduction Types. Templates & auto type
*
*********************************************************/
// Function template prototype
template<typename T, typename U>
int whatever(T t, U u);

// Class template
template <typename T, typename U>
class Animal {
public:
	T height;
	U weight;
	static int numOfPeople;
	Animal(T h, U w) {
		height = h, weight = w;
		numOfPeople++;
	}
	void GetData() {
		std::cout << "Height : " << height <<
		   " and Weight : " << weight << "\n";
	}
};
// Initialization static class members
template<typename T, typename U> 
int Animal<T, U>::numOfPeople;

void deductionNotes() {
	int pipi, caca;
	pipi = caca = 45;
	auto copy = caca;
	whatever<int>(copy, pipi); // or whatever(copy, pipi);
	// template specialization
	// template <> 
	// class mycontainer <char> { ... };
	// 'class' & 'typename' are equivalent

	Animal<float, double> yo(1.75, 71.8);
	yo.GetData();
}

template<typename T, typename U>
int whatever(T t, U u) {
	std::cout << t +  u << std::endl;
	return 0;
};



/********************************************************
*
* Functions as modules (advanced)
*
*********************************************************/
// Compiler replaces the definition of inline 
// functions at compile time instead of 
// referring function definition at runtime.
// All func. of a class are inline implicitly.
// Bad pract. I/O (cin/cout) in this type of func.
inline int add2Numbers(int a, int b) {
	return (a + b);
}

// An ordinary function, just to manage it
int multx2( int num ) {
	return (num*2);
}
// A function as a parameter
int multx4( std::function<int(int)> funcx2, int num ) { // std::function<returType(parametersType)> name
	return ( funcx2(num) * 2 );
}
void functionNotes() {
	// A function ca be stored in a 'auto' variable
	auto function1 = multx2;
	std::cout << function1(5) << std::endl;
	// A function can be used without parameters
	std::cout << multx4(function1, 5) << std::endl;
	// Could exist an aggregations of functions
	std::vector< std::function<int(int)> > vec_functions(2);
	vec_functions[0] = multx2;
	std::cout << vec_functions[0](5) << std::endl;
	//vec_functions[1] = multx4; // err: vec_functions espects only this(function<int(int)>) func-type

	// So, Could exist a function that returns a function and needs as param
	// a vector of functions and a function... and so on

	// Inline function
	std::cout << add2Numbers(5, 9) << std::endl;
}


/********************************************************
*
* Memory management, allocation & smart pointers
*
*********************************************************/
void memoryNotes() {
	//// Dynamic memory (HEAP/UP)
	//// The malloc() function from C, still exists in C++,
	//// but it is recommended to avoid it. Better 'new' !!!
	//double *d_Matrix;
	//d_Matrix = (double *)malloc(m*n * sizeof(double));
	//// Check if memory was allocated
	//if (d_Matrix != NULL) {
	//	// Fill array(Matrix)
	//	for (int i = 0; i < (m*n); i++) {
	//		std::cin >> d_Matrix[i];
	//	}
	//}
	//free(d_Matrix); //delete d_Matrix;

	// Smart pointers 1 UNIQUE
	int m, n;
	m = n = 3; // for example...
	std::unique_ptr<double[]> d_Matrix( new double[m*n] ); 
	// Check if memory was allocated
	if (d_Matrix != NULL) {
		// Fill array(Matrix)
		for (int i = 0; i < (m*n); i++) {
			std::cin >> d_Matrix[i];
		}
	}

	// Smart pointers 2 SHARED
	{ //Scope1
		std::shared_ptr<Human> e0;
		{ //Scope2
			// Unique can't be copyed as std::unique_ptr<int> i_ptrUnique2 = i_ptrUnique; 
			// because when the ptr dies all ptr must to reference to somewhere
			//std::unique_ptr<Human> i_ptrUnique = std::make_unique<Human>();

			// Shared ptr maintain a count reference of ptrs. Until the last 
			// ptr don't die, the value is not free/deleted
			// They have an overhead for take care of the references
			std::shared_ptr<Human> i_ptrShared = std::make_shared<Human>();

			// e0 = i_ptrUnique; //ERROR
			e0 = i_ptrShared;
		} // Here i_ptrShared dies but the e0 remains. i_ptrUnique dies too
	} // Here e0 dies and the data in heap is deleted

	// Smart pointers 3 WEAK
	{
		// Normally used to maintain an ownership in the main ptr
		std::weak_ptr<Human> e0;
		{ 
			std::shared_ptr<Human> i_ptrShared = std::make_shared<Human>();
			e0 = i_ptrShared;
		} // Here i_ptrShared dies and so e0 is weak dies too, the value is deleted.
	} 
}