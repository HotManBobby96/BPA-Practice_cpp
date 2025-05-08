//00075707 ID number
// Bryson Blakney
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// Class representing a single bowling game
class BowlingGame {
private:
    std::vector<int> ballScores; // Stores the sequence of ball scores for the game

public:
    // Constructor to initialize the game with ball scores
    explicit BowlingGame(const std::vector<int>& scores) : ballScores(scores) {}

    // Method to calculate the final score of the game
    int calculateScore() const {
        int totalScore = 0;
        int frame = 0;

        // Iterate through the ball scores to calculate the score for each frame
        for (size_t i = 0; i < ballScores.size() && frame < 10; ++frame) {
            if (ballScores[i] == 10) { // Strike
                totalScore += 10 + ballScores[i + 1] + ballScores[i + 2];
                ++i; // Move to the next frame
            }
            else if (i + 1 < ballScores.size() && ballScores[i] + ballScores[i + 1] == 10) { // Spare
                totalScore += 10 + ballScores[i + 2];
                i += 2; // Move to the next frame
            }
            else { // Open frame
                totalScore += ballScores[i] + ballScores[i + 1];
                i += 2; // Move to the next frame
            }
        }

        return totalScore;
    }
};

// Function to parse a line of scores into a vector of integers
std::vector<int> parseScores(const std::string& line) {
    std::vector<int> scores;
    std::stringstream ss(line);
    int score;

    // Extract scores separated by commas
    while (ss >> score) {
        scores.push_back(score);
        if (ss.peek() == ',') {
            ss.ignore(); // Ignore the comma
        }
    }

    return scores;
}

// Main function to handle file input, process games, and display results
int main() {
    std::cout << "Bowling Score Calculator" << std::endl;

    cout << "Enter your filepath here, just right click the file copy the path and enter it here: " << endl; // why wont relative files work 

    string filePath;
    getline(cin, filePath);

    // Remove surrounding quotes if present
    if (!filePath.empty() && filePath.front() == '"' && filePath.back() == '"') {
        filePath = filePath.substr(1, filePath.size() - 2);
    }

    // Open the input file
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file at " << filePath << std::endl;
        return 1;
    }

    cout << "Games: " << endl;

    // Read and process each line in the file
    std::string line;
    int gameNumber = 1;

    while (std::getline(inputFile, line)) {
        // Parse the line into a sequence of ball scores
        std::vector<int> scores = parseScores(line);

        // Instantiate a BowlingGame object
        BowlingGame game(scores);

        // Compute the final score
        int finalScore = game.calculateScore();

        // Output the final score for the game in the required format
        std::cout << "Game " << gameNumber << " Final Score: " << "<" << finalScore << ">" << std::endl;
        ++gameNumber;
    }

    // Close the file
    inputFile.close();

    return 0;
}
