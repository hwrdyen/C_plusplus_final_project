/* Nasty Numbers
Howard Yen
May 23, 2018
Write a program that lets you enter two integers
and that prints the greatest common divisor of these integers.*/

#include <iostream> //include header iostream
using namespace std; //using namespace std::

int main() //beginning of the program
{
	int a; //integer a
	int b; //integer b
	int x; //integer x

	do {
		cout << "Please enter two positive integers."; //ask the user to enter two positive integers
		cin >> a; //input a positive integer a
		cin >> b; //input a positive integer b
	} while (a<=0 || b<=0); //re-do the program if a less than zero or b less than zero

	if (b>a) {
		x=a;
		a=b;
		b=x;
	} //if b is smaller than a then do this program

	do {
		x=a;
		a=b;
		b=x%a;
	} while (b!=0); //re-do this program if be is not zero

	cout << a << "\n"; //output the integer a
	return(0); //end of the program
}
