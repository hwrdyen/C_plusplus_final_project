/* Do the shuffle
Howard Yen
May 22, 2018
Write a program to simulate the music player,
your program should repeatedly ask for two intergers,
the first is the butto that is pressed (b)
and the second is the number of times it is pressed (n).
Button 1: Moves the first song to the
				  end of the playlist
				  ex. A B C D E ==> B C D E A
		Button 2: Moves the last song to the
				  beginning of the playlist
				  ex. A B C D E ==> E A B C D
		Button 3: Swaps the first two songs of
				  the playlist
				  ex. A B C D E ==> B A C D E
		Button 4: Stops rearranging songs and
				  outputs the current playlist
	Have the user enter the button number, then
	the numbr of times they wish to press the
	button */

#include <iostream> //include header iostream
using namespace std; //using namespace std::

void button1(int);//moves the first song to the end of the playlist
void button2(int);//moves the last song to the beginning of the playlist
void button3(int);//swaps the first two songs
void button4();//displays the current playlist

char playlist[7]={'A','B','C','D','E'};

int main() //beginning of the program
{
	int button; //integer button
	int times; //integer time

	cout << "This playlist holds 5 songs: A, B, C, D, and E" << "\n"; //explain the rules
	cout << "In order to shuffle this playlist, you can use the following 3 buttons:" << "\n"; //explain the rules
	cout << "Button 1, which moves the first song to the end of the playlist" << "\n"; //explain the rules
	cout << "A B C D E ==> B C D E A" << "\n"; //explain the rules
	cout << "Button 2, which moves the last song to the beginning of the playlist" << "\n"; //explain the rules
	cout << "A B C D E ==> E A B C D" << "\n"; //explain the rules
	cout << "Button 3, which swaps the the first two songs in the playlist" << "\n"; //explain the rules
	cout << "A B C D E ==> B A C D E" << "\n"; //explain the rules
	cout << "In order to stop shuffling and output the playlist, press button 4" << "\n"; //explain the rules

	do {
		do {
			cout<<"Enter the button you wish to press(1-4): "; //ask the user to enter button you wish to press(1-4)
			cin >> button;//read button
		} while (button<1 || button>4); //re-do the program if button is less than 1 or larger than 4

		do {
			cout << "Enter the number of times you wish to press button: "; //ask the user to enter the number of times you wish to press button
			cin >> times; //input times
		} while (times<=1); //re-do the program if times is less and equal to 1

		if (button==4){
			while (times!=1){//while times is not 1
				cout << "You can only press button 4 once, enter 1 to continue: ";//display message
				cin >> times;//read in new answer
			}
		}
		if (button==1){//if button is 1
			button1(times);//call function button1 (sending variable times)
		}
		else if (button==2){//if button is 2
			button2(times);//call function button2 (sending variable times)
		}
		else if (button==3){//if button is 3
			button3(times);//call function button3 (sending variable times)
		}
	} while (button!=4); //re-do the program when button is not equal to 4

	button4(); //transfered to button 4's function

	return(0); //end of the program
}

void button1 (int x){

	for (int counter=0;counter<x;counter++){
		playlist[5]=playlist[0];

		for (int counter2=0;counter2<5;counter2++){
			playlist[counter2]=playlist[counter2+1];
		}
		for (int i = 0; i < 5; i++) {
			cout<<playlist[i]<<" ";
		}//show the progress
		cout<<endl;
	} //change the sequence
} //button 1's function

void button2 (int x){

	for (int counter=0;counter<x;counter++){
		for (int counter2=5;counter2>0;counter2--){
			playlist[counter2]=playlist[counter2-1];
		}

		playlist[0]=playlist[5];
		for (int i = 0; i < 5; i++) {
			cout<<playlist[i]<<" ";
		} //show the progress
		cout<<endl;
	} //change the sequence
} //button 2's function

void button3 (int x){


	for (int counter=0;counter<x;counter++){
		playlist[5]=playlist[1];
		playlist[1]=playlist[0];
		playlist[0]=playlist[5];
		for (int i = 0; i < 5; i++) {
			cout<<playlist[i]<<" ";
		} //show the progress
		cout<<endl;
	} //change the sequence
} //button 3's function

void button4 (){
	for (int counter=0;counter<5;counter++){
		cout<<playlist[counter]<<" ";
	} 

	cout<<"\n";
} //button 4's function