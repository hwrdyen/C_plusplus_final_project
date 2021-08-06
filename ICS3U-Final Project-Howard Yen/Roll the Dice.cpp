/* Roll the Dice
Howard Yen
May 29, 2018
Create a program that simulates the rolling of N die,
where N is a number specified by the user.
The program should dispay the roll of each die and the total of the dice.
For example, if the user requested 3 rolls
Roll 1 = 4
Roll 2 = 5
Roll 3 = 1
Total = 10
Allow the user to specify how many sides are n the die.
If the user specifies too many rolls, then just report the final results of all the rolls
For large numbers of rolls, report the ones/ twos/ threes/ etc as percentages. */

#include <iostream> //include header iostream
#include <ctime> //include ctime
using namespace std; //using namespace std

int main() //beginning of the program
{
	srand(time(0)); //rand time
	int N; //N is an integer
	int roll; //roll is an integer
	int total = 0; //total is an integer
	int sides; //sides are integers

	do {
		cout << "How many sides of dice do you want to roll (at least 4 sides)\n"; //ask the user how many sides of dice do you want to roll
		cin >> sides; //input sides
	} while (sides<4); //re-do the program if the sides are less than 4

	int array[sides];
	
	cout << "How many " << sides << "-sided dice do you want to roll?\n"; //ask the user how many dices they want to roll 
	cin >> N; //input N

	if (roll<=15) {
		for (int counter=1; counter < N+1; counter++) {
			roll = rand()%sides+1; //random number between 1 and sides
			cout << "Roll " << counter << " = " << roll << "\n";
			total+=roll; //total equals to total plus roll
		} //for loop counts from 1 to N+1
	} //if roll is less or equals to 15
	else {
		int array [sides];
		for (int counter=1; counter < N+1; counter++) {
			roll = rand()%sides+1; //random number between 1 and sides
			total+=roll; //total equals to total plus roll
			array [roll-1]++;
		} //for loop count from 1 to N+1
		if (roll>=15&&roll<=50) {
			for (int counter=0; counter<sides; counter++) {
				cout << "There are " << array[counter] << " "<< counter+1<<"s"; //display message
			} //for loop counts from 0 to sides
		} //if the roll is bigger than 15 and less than 50
		else if (roll>50) {
		for (int counter=0; counter<sides; counter++) {
			double percent = array[counter]*100.0/total;
			cout << "There are " << percent << "% " << counter+1 <<"s"; //display message
			} //for loop counts from 0 to sides
		} //else if the roll is bigger than 50
	}
	cout << "Total = " << total << "\n"; //output the total

return(0); //end of the program
}
