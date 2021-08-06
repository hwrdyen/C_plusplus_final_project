/* Multiple Choice
Howard Yen
May, 28 2018
	Create a program that marks
	multiple choice tests. The
	choices for all multiple
	choice answers are A, B, C,
	D, or E.
	Input:
		number of questions (N)
		N lines of student responses
		N lines of correct answers
	Output:
		the number of correct answers */

#include <iostream> //include header iostream
#include <locale> //include header locale
using namespace std; //using namespace std to avoid typing std::

int main(){ //beginning of program
	int questions; //the number of questions on the test
	int correct=0; //the number of correct answers

	do {
		cout << "Enter the number of questions that are on the test(1-10000): "; //ask the user to enter the number of questions that are on the test(1-10000)
		cin >> questions; //input questions
	} while (questions<1 || questions>10000);
	
	char responses[questions+1]; //array for student responses
	char answers[questions+1]; //array for answer key

	cout << "Enter the student's responses to each question, one at a time:\n"; //display message

	for (int counter=0;counter<questions;counter++){ //for loop (initialize counter at 0;while counter is less than questions;add 1 to counter)
		cout << counter+1 << ". " ;//display the number of the question the user is on
		cin >> responses[counter]; //input responses [counter]
		responses[counter]=toupper(responses[counter]); //change answer to uppercase

		while (responses[counter]!='A' && responses[counter]!='B' && responses[counter]!='C' && responses[counter]!='D' && responses[counter]!='E'){ //if answer is not valid
			cout << "Multiple choice answers must be A, B, C, D, or E\n"; //display message
			cout << "Please try again:\n"; //display message

			cout << counter+1 << ". "; //display the number of the question the user is on
			cin >> responses[counter]; //input responses [counter]
			responses[counter]=toupper(responses[counter]); //change answer to uppercase
		}
	}

	cout << "Enter the correct answers to each question, one at a time:\n"; //display message

	for (int counter=0;counter<questions;counter++){ //for loop (initialize counter at 0;while counter is less than questions;add 1 to counter)
		cout << counter+1 << ". "; //display the number of the question the user is on
		cin >> answers[counter]; //input answers [counter]
		answers[counter]=toupper(answers[counter]); //change answer to uppercase

		while (answers[counter]!='A' && answers[counter]!='B' && answers[counter]!='C' && answers[counter]!='D' && answers[counter]!='E'){ //if answer is not valid
			cout << "Multiple choice answers must be A, B, C, D, or E\n"; //display message
			cout << "Please try again:\n"; //display message

			cout << counter+1 << ". "; //display the number of the question the user is on
			cin >> answers[counter]; //input answers [counter]
			answers[counter]=toupper(answers[counter]); //change answer to uppercase
		}
	}

	for (int counter=0;counter<questions;counter++){//for loop (initialize counter at 0;while counter is less than questions;add 1 to counter)
		if (responses[counter]==answers[counter]){//if position counter in arrays responses and answers are the same
			correct++;//add 1 to correct
		}
	}

	cout << "\nNumber of correct answers: " << correct<<endl;//display the number of correct answers

	return(0); //end of program
}