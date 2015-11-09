// Homework Four
// Jimmy (Sicong) Liu 20076260
// CIS 22B
// October 24th 2015
// XCode 7.0

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <regex>
#include <algorithm>
#include <iterator>
using namespace std;

// Data structure used as value in map, .value gets count of word
struct number {
  int value;
};

string promptForFile();
int readThisFile(map<string, number> &songWords, string name);
int printMap(map<string, number> &songWords, int longest);
void writeToFile(map<string, number> &songWords, int longest, int most);

// Main function of the program
int main() {
	map<string, number> songWords;
  string temp = promptForFile();
	int longest = readThisFile(songWords, temp);
	if (longest < 0)
		return 0;
	int most = printMap(songWords, longest);
	writeToFile(songWords, longest, most);
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

// Reads the file into the Map data structure and counts the number of repeat words, regex to clean
int readThisFile(map<string, number> &songWords, string name) {
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
      	if (songWords.find(word) == songWords.end())
      		songWords[word].value = 1;
      	else
      		songWords[word].value = songWords[word].value + 1;
      }
    }
    myfile.close();
    return longest;
  }
  else cout << "Unable to find and/or open file" << endl;
  return -1;
}

// Prints the map to display value to user
int printMap(map<string, number> &songWords, int longest) {
	int most = 0;
	for (auto i : songWords) {
        cout << setw(3) << i.second.value << " " << i.first.c_str() << " " << endl;
        if (i.second.value > most)
        	most = i.second.value;
    }
    return most;
}

// Writes the results of the program to a file
void writeToFile(map<string, number> &songWords, int longest, int most) {
	ofstream outputFile ("words.txt");
	if (outputFile.is_open()) {
        outputFile << songWords.size() << " words" << endl;
		outputFile << "Maximum length: " << longest << endl;
		outputFile << "Highest frequency: " << most << "\n\n";
		for (auto i : songWords)
	        outputFile << setw(3) << i.second.value << " " << i.first.c_str() << " " << endl;
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