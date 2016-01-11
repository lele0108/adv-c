// Homework Four (Resubmission)
// Jimmy (Sicong) Liu 20076260
// CIS 22B
// December 4th 2015
// XCode 7.0

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>
using namespace std;

// structure number, word is used to store the word, value is count. < is overloaded for sorting
struct number {
  string word;
  int value = 0;

  bool operator<(const number &a) const {
      return word.compare(a.word) < 0;
  }
};

string promptForFile();
int readThisFile(number* songWords, string name);
int printMap(number* songWords, int longest);
int countArray(number* songWords);
void writeToFile(number* songWords, int longest, int most, int count);

// Main function of the program
int main() {
  number songWords[100];
  string temp = promptForFile();
	int longest = readThisFile(songWords, temp);
	if (longest < 0)
		return 0;
  int size = sizeof(songWords)/sizeof(songWords[0]);
  sort(songWords, songWords+size);
	int most = printMap(songWords, longest);
  int count = countArray(songWords);
	writeToFile(songWords, longest, most, count);
	return 0;
}

// Gets the name of the file from the user
string promptForFile() {
  string temp;
  do {
    cout << "Please enter a song name: ";
    getline(cin, temp);
  } while (temp.empty());
  return temp;
}

// Reads the file into the array data structure and counts the number of repeat words, regex to clean
int readThisFile(number* songWords, string name) {
  int longest = 0;
  string line;
  regex e ("[.,]");
  ifstream myfile (name);
  if (myfile.is_open()) { 
    while ( getline (myfile,line) ) {
      string word;
      stringstream stream(line);
      while (stream >> word) {
      	word = regex_replace (word , e , "");
      	transform(word.begin(), word.end(), word.begin(), ::tolower);
      	if (word.length() > longest)
      		longest = word.length();
        for (int i = 0; i < 100; i++) {
          if (songWords[i].word == word) {
            songWords[i].value++;
            break;
          } else if (songWords[i].word.empty()) {
            songWords[i].word = word;
            songWords[i].value = 1;
            break;
          }
        }
      }
    }
    myfile.close();
    return longest;
  }
  else cout << "Unable to find and/or open file" << endl;
  return -1;
}


// Prints the array to display value to user
int printMap(number* songWords, int longest) {
	int most = 0;
  for (int i = 0; i < 100; i++) {
    if (!songWords[i].word.empty())
      cout << setw(3) << songWords[i].value << " " << songWords[i].word << " " << endl;
      if (songWords[i].value > most)
        most = songWords[i].value;
  }
  return most;
}

int countArray(number* songWords) {
  int count = 0;
  for (int i = 0; i < 100; i++)
     if (!songWords[i].word.empty())
      count++;
  return count;
}

// Writes the results of the program to a file
void writeToFile(number* songWords, int longest, int most, int count) {
	ofstream outputFile ("words.txt");
	if (outputFile.is_open()) {
    outputFile << count << " words" << endl;
		outputFile << "Maximum length: " << longest << endl;
		outputFile << "Highest frequency: " << most << "\n\n";
		for (int i = 0; i < 100; i++) {
	   if (!songWords[i].word.empty())
      outputFile << setw(3) << songWords[i].value << " " << songWords[i].word << " " << endl;
    }
    outputFile.close();
  } else {
      cout << "Unable to create file to write words";
  }
}

/*
MacBook-Pro-3:project-4 jimmyliu$ ./a.out
Please enter a song name: song_row.txt
  1 a 
  1 boat 
  1 but 
  1 down 
  1 dream 
  1 gently 
  1 is 
  1 life 
  4 merrily 
  3 row 
  1 stream 
  1 the 
  1 your 
MacBook-Pro-3:project-4 jimmyliu$ ./a.out
Please enter a song name: song_ten.txt
  1 accidentally 
  1 and 
  1 be 
  1 bottle 
  3 bottles 
  1 fall 
  4 green 
  3 hanging 
  1 if 
  1 nine 
  3 on 
  1 one 
  1 should 
  2 ten 
  3 the 
  1 there 
  3 wall 
  1 will 
*/