// Jimmy Liu
// Project 5
// 4 Nov. 2015
// XCode 7.0

#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
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

int main() {
	Question *questions;
	questions = readThisFile(questions);
	int size = getSize();
	randomize(questions, size);
	while (playGame(questions, size)) {
		randomize(questions, size);
	}
	return 0;
}

Question* readThisFile(Question *questions) {
	string line;
  	ifstream myfile ("TriviaQuestions.txt");
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
}

int getSize() {
	string line;
  	ifstream myfile ("TriviaQuestions.txt");
  	getline (myfile, line);
  	int num = atoi(line.c_str());
  	return num;
}

void randomize(Question *questions, int size) {
	random_shuffle(&questions[0], &questions[size - 1]);
	for (int i = 0; i < size; i++) {
		questions[i].randomize();
	}
}

bool playGame(Question *questions, int size) {
	string player1, player2;
	cout << "Enter name 1: " << endl;
	cin >> player1;
	if (player1 == "#")
		return false;
	cout << "Enter name 2: " << endl;
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
			cout << "Sorry, the correct answer is: " << temp[questions[count].getCorrect()] << "\n\n";
		}
		count++;
		//player 2
		cout << player2 << " it is your turn:" << endl;
		if (askQuestion(questions, count)) {
			cout << "Congratulations!" << "\n\n";
			score2++;
		} else {
			string *temp = questions[count].getAnswers();
			cout << "Sorry, the correct answer is: " << temp[questions[count].getCorrect()] << "\n\n";
		}
		count++;
	}

	cout << score1 << score2 << endl;
	if (score1 > score2) {
		cout << player1 << " won the game this round." << endl;
	} else if (score2 > score1) {
		cout << player2 << " won the game this round." << endl;
	} else {
		cout << "The two players tied this round" << endl;
	}

	return true;
}

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