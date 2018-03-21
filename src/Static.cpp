//============================================================================
// Name        : Static.cpp
/*
 * 		static int varName;
 *
 * 		static variable = EVERY object in this class shares this ONE value.
 * 				  (normally every instance (object) in a class gets
 * 				  its own value of that variable...
 * 				  with static what happens in one object changes the value
 * 				  for all the objects)
 *
 *
 * 		static void(or w/e) funcName()
 * 			{
 * 				bla bla bla here...
 * 			};
 *
 * 		static method = can only access STATIC VARIABLES
 *
 *
 *
 */
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;

// usually in the .h file

class Test
    {
    private:
	int id;
	int preID;
	static int count; //static variable
	static int preCount;

    public:
	Test() // constructor
	    {
	    id = count++; //when object created use current value of 'count' as 'id' then add 1 to 'count'
	    preID = ++preCount; //before object created add 1 to current value of 'preCount' then set as 'preID'
	    }

	int getID()
	    {
	    return id; //find value of 'id' and replace 'getID' with this value
	    }

	static void showInfo() //static method/function
	    {
	    cout << count << endl;
	    }

	int preGetID() //using to show difference between ++x and x++
	    {
	    return preID;
	    }

	static int const MAX = 56; //Tradition to use UPPERCASE for constants, const need to be defined here
    };
//----------------------------------


// usually in the .cpp file

int Test::count = 0;
int Test::preCount = 0;

//----------------------------------


int main()
    {

    cout << Test::MAX << endl;
    cout << "We are starting with count = " << flush;
    Test::showInfo(); //class being called, not a specific object made from "Test" class
    cout << "" << endl;

    Test x;	//create a new object, run constructor
    cout << "Using 'count++' first obj: " << x.getID() << endl;
    cout << "Using '++count' first obj: " << x.preGetID() << endl;

    Test y;	//create a new object, run constructor
    cout << "Using 'count++' second obj: " << y.getID() << endl;
    cout << "Using '++count' second obj: " << y.preGetID() << endl;

    cout << "" << endl;

    cout << "This is 'count' after 2 objects created in this class: " << flush;
    Test::showInfo();
    return 0;
    }
