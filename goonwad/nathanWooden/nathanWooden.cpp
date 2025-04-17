// MEMBER ID (we did that last year at national gang)
// including libraires 
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

// namespaces
using namespace std;


// functions 
string normalizeString(string userInput) {

	// checking every sysmbol on the keyboard
	const vector<char> specialCharacters = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', '\\', '|', ';', ':', '\'', '\"', ',', '<', '.', '>', '/', '?'};
	string normalizedString = ""; // sets string

	for (char c : userInput) {
		if (find(specialCharacters.begin(), specialCharacters.end(), c) == specialCharacters.end() && c != ' ') {
			normalizedString += tolower(c); // filters and adds to swing by character
		}
	}

	return normalizedString;
}

string encodeMessage(string normalizedString, const int& rows, const int& cols, const int& length) {
	string encodedMessage = ""; // sets string

	// creates a 2d vector according to the rubric
	vector<vector<char>> messageArray(rows, vector<char>(cols, '#'));

	int index = 0;
	for (int j = 0; j < cols; j++) {
		for (int i = 0; i < rows; i++) {
			if (index < length) {
				messageArray[i][j] = normalizedString[index]; // fills the array with the normalized string
				index++;
			} // if
		} // i 
	} // j

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			encodedMessage += messageArray[i][j];
		}
		encodedMessage += " ";
	}

	return encodedMessage; // return the encoded message string

}

// main

int main()
{
	string userInput;

	cout << "Enter: The way to get started is to quit talking and begin doing." << endl; // prompting the user
	cout << "Enter Here: ";
	getline(cin, userInput);

	string normalizedString = normalizeString(userInput); // getting the normalized string and saving it to a variable
	cout << "Normalized String: " << normalizedString << endl;

	if (normalizedString.empty()) { // error handleing
		cout << "Error: nothing was returned and or empty"; 
		return 1; // returns 1 to indicate an error
	}

	size_t length = normalizedString.length(); // gets the length for math when calcualting the box

	
	// I couldve done this much easier dawg
	int columns = static_cast<int>(ceil(sqrt(static_cast<double>(length))));  // calculates the columns by taking the square root of the length and rounding up
	int rows = static_cast<int>(ceil(static_cast<double>(length) / columns)); // calculates the rows by taking the length and dividing it by the columns and rounding up

	string encodedMessage = encodeMessage(normalizedString, rows, columns, length); // encodes the message
	cout << encodedMessage << endl; // prints the encoded message

	return 0; // end of program

}