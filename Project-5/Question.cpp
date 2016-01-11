// Jimmy Liu
// Project 5
// 4 Nov. 2015
// XCode 7.0

#include "Question.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

// Constructor for program
Question::Question() {
	correct = 1;
}

// Returns the correct answer indecy + 1
int Question::getCorrect() const {
	return correct;
}

// Returns a question string
string Question::getQuestion() const {
	return question;
}

// Returns the answers array
string* Question::getAnswers() {
	return answers;
}

// Sets the question
void Question::setQuestion(string temp) {
	question = temp;
}

// Sets the answers array
void Question::setAnswers(string *temp) {
	for (int i = 0; i < 4; i++) {
		answers[i] = temp[i];
	}
}

// Randomizes the answers array and updates correct integer
void Question::randomize() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	string answer = answers[correct -1];
	random_shuffle(&answers[0], &answers[3]);
	for (int i = 0; i < 4; i++) {
		if (answers[i] == answer)
			correct = i + 1;
	}
}