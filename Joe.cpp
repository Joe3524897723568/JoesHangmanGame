#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

//debug paste " cout << "CHEAT: " << anser << endl; " into gap on l44


using namespace std;

int main()
{
int wrongtry = 0;
string letter,str;
vector<string> words;
srand(time(NULL));




ifstream infile("jhg.txt");

if (!infile)
{
    cout << "Source file not found." << endl;
    return -1;
}

while (getline(infile,str))

{
	
	words.push_back(str);
}
random_shuffle ( words.begin(), words.end() );
string anser = words.at(1);
string finalanser = anser;
string unknown(anser.length(),'*');
int numtries = anser.length();
cout << "Welcome to Hangman by Joe" << endl;

cout << "You have " << numtries << " tries remaining" << endl;
cout << "Each letter is an asterix, please do not guess more than one letter and do not use UPPER CASE" << endl;
cout << unknown << endl;




while (numtries - wrongtry > 0 && finalanser!=unknown )
{
	cout << "Guess a letter" << endl;
	cin >> letter;
	
	if( letter.length() > 1)
	{
	cout << "Error you have entered more than one digit" << endl;
	wrongtry++;
	cout << "You have " << numtries-wrongtry   << " tries remaining" << endl;
	cout << unknown << endl;
}

int poo=anser.find(letter) ;

if (poo == -1 && letter.length()==1)
{
	cout << "the word does not contain the letter " << letter << " please try again" << endl;
	wrongtry++;
	cout << "You have " << numtries-wrongtry << " tries remaining" << endl;
	cout << unknown << endl;
}

else if (letter.length()==1)
{
 	cout << "Yes the word does contain at least 1 '" <<letter<< "' keep it up" << endl;
	
	int found = anser.find(letter);
	cout << "You have " << numtries-wrongtry << " tries remaining" << endl;


	
	while (found != -1 ) 

	{
		unknown.replace(anser.find(letter),1,letter);
		anser.replace(anser.find(letter),1,"1");
		found = anser.find(letter);
 				
	}
	
	cout << unknown << endl;
   
}


}



	if (unknown==finalanser)
	{
	
	cout << "Well Done! you got it the correct answer was " << finalanser << endl;
}
	

else {

cout << "You did not win the word was " << finalanser << endl;
}
system("pause");
return 0;



}
