#ifndef CIRCLE_H_
#define CIRCLE_H_

#define pi 3.14159
#include <iostream>

class Circle{

	private: 
		double radius;

	public:
		
		Circle(){
			this->radius = 0;
		}

		Circle( double radius ){
			this->radius = radius;
		}

		double area(){
			return pi*radius*radius;	
		}

		double circumference(){
			return 2*pi*radius;
		} 

};
#endif

using namespace std;
int main(){
	Circle *c1 = new Circle( 2.0 );
	Circle *c2 = new Circle( 3.0 );
	cout << "c1: area = " << c1->area() <<
	        " circumference = " << c1->circumference() << endl;
	cout << "c2: area = " << c2->area() <<
	        " circumference = " << c2->circumference() << endl;
	return 0;
}
