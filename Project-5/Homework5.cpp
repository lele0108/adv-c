// Jimmy Liu
// Project 5
// 4 Nov. 2015
// XCode 7.0

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Question.h"
using namespace std;

Question* readThisFile(Question*);
void randomize(Question*, int);
bool playGame(Question*, int);
bool askQuestion(Question*, int);
int getSize();

// Returns a random number for the shuffle
int myrandom (int i) { return std::rand()%i;}

// Main function of the program 
int main() {
	srand(time(0));
	Question *questions;
	questions = readThisFile(questions);
	if (questions == NULL) {
		cout << "There was an error reading the Trivia Questions from the file" << endl;
		return 0;
	}
	int size = getSize();
	randomize(questions, size);
	while (playGame(questions, size)) {
		randomize(questions, size);
	}
	return 0;
}

// Reads the file of the TriviaQuestions and puts into array
Question* readThisFile(Question *questions) {
	string line;
  	ifstream myfile ("TriviaQuestions.txt");
  	if (myfile.is_open()) {
	  	getline (myfile, line);
	  	int num = atoi(line.c_str());
	  	questions = new Question[num];
	  	for (int i = 0; i < num; i++) {
	  		getline (myfile, line);
	  		questions[i].setQuestion(line);
	  		string temp[4];
	  		for (int j = 0; j < 4; j++) {
	  			getline(myfile, line);
	  			temp[j] = line;
	  		}
	  		questions[i].setAnswers(temp);
	  	}
		return questions;
	} else {
		return NULL;
	}
}

// Returns the size of the Questions array
int getSize() {
	string line;
  	ifstream myfile ("TriviaQuestions.txt");
  	getline (myfile, line);
  	int num = atoi(line.c_str());
  	return num;
}

// Randomizes the question array via random_shuffle
void randomize(Question *questions, int size) {
	random_shuffle(&questions[0], &questions[size-1], myrandom);
	for (int i = 0; i < size; i++) {
		questions[i].randomize();
	}
}

// Prompts the two users to play the game
bool playGame(Question *questions, int size) {
	string player1, player2;
	cout << "Enter name of first player: " << endl;
	cin >> player1;
	if (player1 == "#")
		return false;
	cout << "Enter name of second player: " << endl;
	cin >> player2;
	if (player2 == "#")
		return false;
	cout << endl;

	int count = 0;
	int score1 = 0, score2 = 0;
	for (int i = 0; i < 3; i++) {
		//player 1
		cout << player1 << " it is your turn:" << endl;
		if (askQuestion(questions, count)) {
			cout << "Congratulations!" << "\n\n";
			score1++;
		} else {
			string *temp = questions[count].getAnswers();
			cout << "Sorry, the correct answer is: " << temp[questions[count].getCorrect() - 1] << "\n\n";
		}
		count++;
		//player 2
		cout << player2 << " it is your turn:" << endl;
		if (askQuestion(questions, count)) {
			cout << "Congratulations!" << "\n\n";
			score2++;
		} else {
			string *temp = questions[count].getAnswers();
			cout << "Sorry, the correct answer is: " << temp[questions[count].getCorrect() - 1] << "\n\n";
		}
		count++;
	}

	if (score1 > score2) {
		cout << player1 << " won the game this round." << endl;
	} else if (score2 > score1) {
		cout << player2 << " won the game this round." << endl;
	} else {
		cout << "The two players tied this round" << endl;
	}

	return true;
}

// Asks the users the questions, returns false/true
bool askQuestion(Question *questions, int count) {
	cout << questions[count].getQuestion() << ":" << endl;
	string *temp = questions[count].getAnswers();
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ". " << temp[i] << endl;
	}
	cout << "The correct answer is: " << endl;
	int hold;
	cin >> hold;
	if (hold == questions[count].getCorrect())
		return true;
	return false;
}
/*
MacBook-Pro-3:project-5 jimmyliu$ ./Homework5
Enter name of first player: 
Jack
Enter name of second player: 
Jill

Jack it is your turn:
Some programmers refer to mutators as:
1. Setter functions
2. Getter functions
3. Change functions
4. Accessor functions
The correct answer is: 
1
Congratulations!

Jill it is your turn:
What are local variables:
1. Variables that reside in the state of California
2. A variable declared within the body of a function defination
3. Things you can buy from your local supermarket
4. Variables that can pay in-state tuition
The correct answer is: 
1
Sorry, the correct answer is: A variable declared within the body of a function defination

Jack it is your turn:
Why are Strings better than CStrings:
1. CStrings are prone to out of bound errors
2. No one uses CStrings anymore
3. CStrings are annoying to use
4. They have to be null terminated
The correct answer is: 
1
Congratulations!

Jill it is your turn:
Data hiding refers to an object’s ability to:
1. Hide its data from code that is inside the object
2. Hide its data
3. Hide its data from code that is outside the object
4. Hide its procedures
The correct answer is: 
1
Sorry, the correct answer is: Hide its data from code that is outside the object

Jack it is your turn:
Some programmers refer to accessors as:
1. Change functions
2. Getter functions
3. Setter functions
4. Mutators functions
The correct answer is: 
1
Sorry, the correct answer is: Getter functions

Jill it is your turn:
The complete name of the operator that identifies the function as a member of a class is:
1. Scope operator
2. Scope resolution operator
3. Identification operator
4. Scope identification operator
The correct answer is: 
1
Sorry, the correct answer is: Scope resolution operator

Jack won the game this round.
Enter name of first player: 
Bob
Enter name of second player: 
Carrie

Bob it is your turn:
What are local variables:
1. Variables that reside in the state of California
2. A variable declared within the body of a function defination
3. Things you can buy from your local supermarket
4. Variables that can pay in-state tuition
The correct answer is: 
1
Sorry, the correct answer is: A variable declared within the body of a function defination

Carrie it is your turn:
Some programmers refer to accessors as:
1. Setter functions
2. Change functions
3. Getter functions
4. Mutators functions
The correct answer is: 
1
Sorry, the correct answer is: Getter functions

Bob it is your turn:
What is a seed:
1. Stuff in whole grain bread
2. What a plant grows from
3. Determines sequence of pseudorandom numbers
4. Thing used in Minecraft
The correct answer is: 
1
Sorry, the correct answer is: Determines sequence of pseudorandom numbers

Carrie it is your turn:
Is the random number generator actually random:
1. No
2. Yes
3. Maybe
4. Who knows
The correct answer is: 
1
Congratulations!

Bob it is your turn:
An object is, conceptually, a self-contained unit consisting of:
1. Attributes
2. Procedures
3. Attributes(data) and procedures(functions)
4. Data
The correct answer is: 
1
Sorry, the correct answer is: Attributes(data) and procedures(functions)

Carrie it is your turn:
What language is this program written in:
1. Javascript
2. Python
3. Cplusplus
4. English
The correct answer is: 
1
Sorry, the correct answer is: Cplusplus

Carrie won the game this round.
Enter name of first player: 
#
*/