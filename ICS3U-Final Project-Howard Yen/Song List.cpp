/* Song List
Howard Yen
May 28, 2018
	Create a program that asks
	for a maximum of 20 songs
	and then calculates the
	total play time.
	Input:
		A (add songs)
			name of song (no spaces)
			minutes of song
			seconds of song
		L (list songs)
		Q (quit program)
	Output:
		(if L)
			song name    time
			    :          :
			    :          :
			    :          :
			  total        :*/

#include <iostream>//include header iostream
#include <locale>//include header locale
#include <cstring>//include string function library
using namespace std;//avoid typind std::

char songlist[20][31];//list of song names
int songtimes[20][2];//list of song times
int songs=0;//number of songs entered

void addsong();//add a song to the list
void listsongs();//display list

int main(){//beginning of program
	char ans;//answer to questions (a/l/q)

	cout << "sTunes" << "\n";
	 
	do {//perform action
		cout<<"Enter A to add a song, L to list songs, or Q to quit the program: ";//display message
		cin>>ans;//read in answer

		while (toupper(ans)!='A' && toupper(ans)!='L' && toupper(ans)!='Q'){//while answer is invalid
			cout<<"Enter A to add a song, L to list songs, or Q to quit the program: ";//display message
			cin>>ans;//read in new answer
		}

		if (toupper(ans)=='A'){//if answer is a/A
			if (songs<20){//is songs is less than 20
				addsong();//call to functon addsong
			}
			else {//if there are 20 songs
				cout<<"You have reached the maximum of 20 songs\n";//display message
			}
		}
		else if (toupper(ans)=='L'){//if answer is l/L
			listsongs();//call to function listsongs
		}
	} while (toupper(ans)!='Q');//while answer is not q/Q

	return(0);//end of program
}

void addsong(){//void function addsong
	cout<<"What is the name of the song?: ";//display message
	cin.ignore();//ignore previous 'enter'
	gets(songlist[songs]);//read in answer

	cout<<"Enter the minutes of the song: ";//display message
	cin>>songtimes[songs][0];//read in answer

	while (songtimes[songs][0]<0){//while answer is invalid
		cout<<"Minutes can't be negative, try again: ";//display message
		cin>>songtimes[songs][0];//read in new answer
	}

	cout<<"Enter the seconds of the song: ";//display message
	cin>>songtimes[songs][1];//read in answer

	while (songtimes[songs][1]>=60 || songtimes[songs][1]<0){//while answer is invalid
		cout<<"Seconds must be from 0-60, try again: ";//display message
		cin>>songtimes[songs][1];//read in new answer
	}

	songs++;//add 1 to songs

	cout<<"Song entry successful!\n\n";//display message
}

void listsongs(){//void function listsongs
	int mintotal=0;//total number of minutes
	int sectotal=0;//total number of seconds

	cout<<"Song Title                     Time\n";//display message
	for (int counter=0;counter<songs;counter++){//for loop (initialize counter at 0;while counter is less than songs;add 1 to counter)
		cout<<songlist[counter];//display song name

		for (int counter2=0;counter2<31-(strlen(songlist[counter]));counter2++){//for loop (initialize counter2 at 0;while counter is less than 31 minus the length of the song name;add 1 to counter2)
			cout<<" ";//display space
		}

		cout<<songtimes[counter][0]<<":";//display minutes
		if (songtimes[counter][1]<10){//if seconds is less than 0
			cout<<"0";//display 0
		}
		cout<<songtimes[counter][1]<<endl;//display seconds

		mintotal+=songtimes[counter][0];//add minutes to mintotal
		sectotal+=songtimes[counter][1];//add seconds to sectotal
	}

	cout<<"Total                          ";//display message
	cout<<mintotal+(sectotal/60)<<":";//display total minutes
	if (sectotal%60<10){//if total seconds is less than 10
		cout<<"0";//display 0
	}
	cout<<sectotal%60<<endl;//display total seconds
}