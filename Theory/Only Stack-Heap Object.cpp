// CPP Program to restrict dynamic
// allocation of objects in C++
#include <iostream>
using namespace std;

// Objects of Test can not be
// dynamically allocated
class Test {
	// new operator function is private
	void* operator new(size_t size);
	int x;

public:
	Test()
	{
		x = 9;
		cout << "Constructor is called\n";
	}
	void display() { cout << "x = " << x << "\n"; }
	~Test() { cout << "Destructor is executed\n"; }
};

// Driver Code
int main()
{

	// Test* obj=new Test(); -> Uncommenting this line would
	// cause a compile time error.
	Test t; // Ok, object is allocated at compile time
	t.display();
	// object goes out of scope, destructor will be called
	return 0;
}



#include <iostream>
using namespace std;
  
// A class whose object can only be dynamically created
class Test
{
private:
    ~Test() { cout << "Destroying Object\n"; }
public:
     Test() { cout << "Object Created\n"; }
friend void destructTest(Test* );
};
  
// Only this function can destruct objects of Test
void destructTest(Test* ptr)
{
    delete ptr;
    cout << "Object Destroyed\n";
}
  
int main()
{
    /* Uncommenting following following line would cause compiler error */
    // Test t1;
  
    // create an object
    Test *ptr = new Test;
  
    // destruct the object to avoid memory leak
    destructTest(ptr);
  
    return 0;
}
