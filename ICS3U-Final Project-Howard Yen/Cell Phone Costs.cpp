/* Cell Phone Costs
Howard Yen
May 28, 2018
	Write a program to decide
	which phone plan will be
	cheaper to use.
	Plan A:
		Daytime Cost: 100 free minutes, then 15 cents per minute
		Evening Cost: 20 cents per minute
		Weekend Cost: 25 cents per minute
	Plan B:
		Daytime Cost: 250 free minutes, then 35 cents per minute
		Evening Cost: 25 cents per minute
		Weekend Cost: 45 cents per minute
	Input:
		Daytime minutes
		Evening minutes
		Weekend minutes
	Output:
		Cost for Plan A
		Cost for Plan B
		Which one is cheaper(if they are the same, say so)*/

#include <iostream> //include header iostream
using namespace std; //using namespace std to avoid typing std::

int planA (int,int,int); //calculates cost for plan a
int planB (int,int,int); //calculates cost for plan b

int main(){ //beginning of program
	int daytime; //integer number of daytime minutes
	int evening; //integer number of evening minutes
	int weekend; //integer number of weekend minutes
	int a; //integer cost of plan a
	int b; //integer cost of plan b

	cout << "Plan A:\n"; //intro
	cout << "    Daytime Cost: 100 free minutes, then 15 cents per minute\n"; //intro
	cout << "    Evening Cost: 20 cents per minute\n"; //intro
	cout << "    Weekend Cost: 25 cents per minute\n"; //intro
	cout << "Plan B:\n"; //intro
	cout << "    Daytime Cost: 250 free minutes, then 35 cents per minute\n"; //intro
	cout << "    Evening Cost: 25 cents per minute\n"; //intro
	cout << "    Weekend Cost: 45 cents per minute\n\n"; //intro
	cout << "This program will calculate which plan is cheaper based on your phone usage\n\n"; //intro

	do {
		cout << "Enter the number of daytime minutes: "; //ask the user to enter the number of daytime minutes
		cin >> daytime; //input daytime
	} while (daytime<0); //re-do the program while daytime is less than 0

	do {
		cout << "Enter the number of evening minutes: "; //ask the user to enter the number of evening minutes
		cin >> evening; //input evening
	} while (evening<0); //re-do the program while even is less than 0

	do {
		cout << "Enter the number of weekend minutes: "; //ask the user to enter the number of weekend minutes
		cin >> weekend; //input weekend
	}while (weekend<0);

	a=planA(daytime,evening,weekend); //call to function planA (sending variables daytime, evening, weekend)
	b=planB(daytime,evening,weekend); //call to function planB (sending variables daytime, evening, weekend)

	cout.setf(ios::fixed); //fixed decimal places
	cout.precision(2); //set to 2 decimal places

	cout<<"Plan A costs $"<<a/100.0<<endl; //display cost of plan a
	cout<<"Plan B costs $"<<b/100.0<<endl; //display cost of plan b

	if (a==b){
		cout<<"Plan A and B are the same price\n";//display message
	} //if a equals b
	else {
		if (a<b){
			cout<<"Plan A is cheaper\n"; //output plan A is cheaper
		} //if a is less than b
		else {
			cout<<"Plan B is cheaper\n"; //output plan B is cheaper
		} //if a is greater than b
	} //if a does not equal b

	return(0); //end of the program
}

int planA (int d, int e, int w){ //int function planA (receiving integer variables d,e,w)
	int cost=0; //cost of plan

	if (d>100){ //if d is greater than 100
		cost+=(15*(d-100)); //add cost of daytime minutes to total
	}
	cost+=(20*e); //add cost of evening minutes to total
	cost+=(25*w); //add cost of weekend minutes to total

	return(cost); //return value cost
}

int planB (int d, int e, int w){ //int function planB (receiving integer variables d,e,w)
	int cost=0; //cost of plan

	if (d>250){ //if d is greater than 250
		cost+=(35*(d-250)); //add cost of daytime minutes to total
	}
	cost+=(25*e); //add cost of evening minutes to total
	cost+=(45*w); //add cost of weekend minutes to total

	return(cost); //return value cost
}