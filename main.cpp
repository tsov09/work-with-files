#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



bool contains_word(std::string &line, std::string &word) {
	bool contains = false;
	//cout << line.length() << " " << word.length() << " line length" << endl;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == word[0]) {
			bool is_the_same = true;
			for (int g = 1; g < word.length(); g++) {
				i++;
				if (line[i] != word[g]) {
					contains = false;
					break;
				}
				else {
					cout << line[i] << " " << word[g] << endl;
				}
			}
			if (is_the_same) {
				contains = true;
				cout << line << endl;
				//cout << line[i - word.length() + 1] << " " << line[i] << endl;
				/*for (int g = i - word.length() + 1; g <= i; g++) {
					cout << line[g];
				}
				cout << endl;*/
				break;
			}
		}
	}
	return contains;
}

int main() {

	ifstream about;
	about.open ("about_armenia.txt");

	ofstream filtered;
	filtered.open ("rows_containing_armenia.txt");


	std::string word = "Armenia";
	std::string line;
	int count = 0;
	while (std::getline(about, line)) {
		if (contains_word(line, word)) {
			filtered << line << endl;
			count++;
		}
	}
	cout << count << " count" << endl;

	
	about.close();
	filtered.close();
	return 0;
}