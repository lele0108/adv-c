// Jimmy Liu
// Project 5
// 4 Nov. 2015
// XCode 7.0

#ifndef QUESTION
#define QUESTION
#include <iostream>
#include <string>
using namespace std;

class Question {
	private:
		string question;
		string answers[4];
		int correct;
	public:
		Question();
		//Question(string[], string);
		int getCorrect() const;
		string getQuestion() const;
		string *getAnswers();
		void setQuestion(string);
		void setAnswers(string* );
		void randomize();
};
#endif