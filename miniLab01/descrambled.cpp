// A descrambled program (program description should be first thing in document)
//#include <iostream> // preprocessor include commands should come before any of there functions, easiest way to guarentee this is to place them before their use in function
using namespace std; // must come before using cout otherwise the std::cout notation is required
#include <iostream>
int main()
{
	cout << "Q"; // within main function, before return statement, so it will run
		// does not require std::cout since following the namespace command
	return 0; // must come within main function after any code that is executed
}
