// Jimmy Liu
// Project 5
// 4 Nov. 2015
// XCode 7.0

#include "Question.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

Question::Question() {
	correct = 1;
}
/*
Question::Question(string a[], string q) {
	for (int i = 0; i < 4; i++) {
		answers[i] = a[i];
	}
	question = q;
}*/

int Question::getCorrect() const {
	return correct;
}

string Question::getQuestion() const {
	return question;
}

string* Question::getAnswers() {
	return answers;
}

void Question::setQuestion(string temp) {
	question = temp;
}

void Question::setAnswers(string *temp) {
	for (int i = 0; i < 4; i++) {
		answers[i] = temp[i];
	}
}

void Question::randomize() {
	string answer = answers[correct -1];
	random_shuffle(&answers[0], &answers[3]);
	for (int i = 0; i < 4; i++) {
		if (answers[i] == answer)
			correct = i + 1;
	}
}