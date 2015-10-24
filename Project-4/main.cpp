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

int readThisFile(map<string, int> &songWords);
int printMap(map<string, int> &songWords, int longest);
void writeToFile(map<string, int> &songWords, int longest, int most);

int main() {
	map<string, int> songWords;
	int longest = readThisFile(songWords);
	if (longest < 0)
		return 0;
	int most = printMap(songWords, longest);
	writeToFile(songWords, longest, most);
	return 0;
}

int readThisFile(map<string, int> &songWords) {
  int longest = 0;
  string line;
  regex e ("[.,]");
  ifstream myfile ("song_row.txt");
  if (myfile.is_open()) { 
    while ( getline (myfile,line) ) {
      string word;
      stringstream stream(line);
      while (stream >> word) {
      	word = regex_replace (word,e,"");
      	transform(word.begin(), word.end(), word.begin(), ::tolower);
      	if (word.length() > longest)
      		longest = word.length();
      	if (songWords.find(word) == songWords.end())
      		songWords[word] = 1;
      	else
      		songWords[word] = songWords[word] + 1;
      }
    }
    myfile.close();
    return longest;
  }
  else cout << "Unable to open file";
  return -1;
}

int printMap(map<string, int> &songWords, int longest) {
	int most = 0;
	for (auto i : songWords) {
        cout << setw(3) << i.second << " " << i.first.c_str() << " " << endl;
        if (i.second > most)
        	most = i.second;
    }
    return most;
}

void writeToFile(map<string, int> &songWords, int longest, int most) {
	ofstream outputFile ("words.text");
	if (outputFile.is_open()) {
        outputFile << songWords.size() << " words" << endl;
		outputFile << "Maximum length: " << longest << endl;
		outputFile << "Highest frequency: " << most << "\n\n";
		for (auto i : songWords)
	        outputFile << setw(3) << i.second << " " << i.first.c_str() << " " << endl;
        outputFile.close();
    } else {
        cout << "Unable to create file to write words";
    }
}