/* Survey Average
Howard Yen
May 28, 2018
	Write a program that calculates
	the averages for each of the 5
	questions of the survey(up to 15
	sets of answers):
		Q1: I am opposed to answering questions(0 = Yes, 10 = I love answering!):
		Q2: How do you like this class?(0 = Not at all, 10 = It's the best thing ever!):
		Q3: How much do you like winter?(0 = I hate it, 10 = Let it snow):
		Q4: Canada is the best country in the world(0 = Strongly disagree, 10 = Yes!):
		Q5: The best age in the world is 17(0 = Not even close, 10 = Yes!):
	Input:
		Name
		Q1-Q5
		A (answer set again)
		OR
		V (view results)
	Output:
		Q1-Q5(with averages)*/

#include <iostream> //include header iostream
#include <string> //include string library
#include <locale> //include header locale
#include <cstring> //include string function library
using namespace std; //usig namespace std to avoid typing std::

int main(){ //beginnning of program
	string name;//user's name
	int answers[5];//answers of current person
	double averages[5]={0,0,0,0,0};//averages of answers
	int total=0;//number of people who have taken the survey
	char ans;//answer to question (y/n)

	do {//perform action
		total++;//add 1 to total

		cout<<"\nPlease enter your name to continue to the survey: ";//display message
		cin.ignore();//ignore enter
		getline(cin,name);//read in name

		for (int counter=0;counter<5;counter++){//for loop (initialize counter at 0;while counter is less than 5;add 1 to counter)
			if (counter==0){//if counter is 0
				cout<<"I am opposed to answering questions(0 = Yes, 10 = I love answering!): ";//display question
			}
			else if (counter==1){//if counter is 1
				cout<<"How do you like this class?(0 = Not at all, 10 = It's the best thing ever!): ";//display question
			}
			else if (counter==2){//if counter is 2
				cout<<"How much do you like winter?(0 = I hate it, 10 = Let it snow!): ";//display question
			}
			else if (counter==3){//if counter is 3
				cout<<"Canada is the best country in the world(0 = Strongly disagree, 10 = Yes!): ";//display question
			}
			else {//if counter is 4
				cout<<"The best age in the world is 17(0 = Not even close, 10 = Yes!): ";//display question
			}

			cin>>answers[counter];//read in answers

			while (answers[counter]<0 || answers[counter]>10){//while answer is outside of given range
				cout<<"Your answer must be between 1 and 10, please try again: ";//display message
				cin>>answers[counter];//read in new answer
			}

			averages[counter]=(averages[counter]*(total-1)+answers[counter])/total;//calculate new average of question
		}

		if (total==15){//if total is 15
			cout<<"\nYou have reached the maximum amount of people\n";//display message
			break;//exit loop
		}
		else {//if total is not 15
			cout<<"Enter Y to redo the survey or N to show results: ";//display message
			cin>>ans;//read in answer

			while (toupper(ans)!='Y' && toupper(ans)!='N'){//if answer is not valid
				cout<<"Enter Y to redo survey of N to show results: ";//display message
				cin>>ans;//read in new answer
			}
		}
	} while (toupper(ans)=='Y');//while ans is y or Y

	cout<<"\nResults:\n";//display message

	for (int counter=0;counter<5;counter++){//for loop (initialize counter at 0;while counter is less than 5;add 1 to counter)
		if (counter==0){//if counter is 0
			cout<<"I am opposed to answering questions(0 = Yes, 10 = I love answering!): ";//display question
		}
		else if (counter==1){//if counter is 1
			cout<<"How do you like this class?(0 = Not at all, 10 = It's the best thing ever!): ";//display question
		}
		else if (counter==2){//if counter is 2
			cout<<"How much do you like winter?(0 = I hate it, 10 = Let it snow!): ";//display question
		}
		else if (counter==3){//if counter is 3
			cout<<"Canada is the best country in the world(0 = Strongly disagree, 10 = Yes!): ";//display question
		}
		else {//if counter is 4
			cout<<"The best age in the world is 17(0 = Not even close, 10 = Yes!): ";//display question
		}

		cout<<averages[counter]<<endl;//display final averages
	}

	return(0);//end of program
}