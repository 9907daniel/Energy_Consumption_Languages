#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>  // Add this line for std::chrono

void processText(const std::string& filePath) {
    // Open the file
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return;
    }

    // Benchmarking start time
    auto startTime = std::chrono::high_resolution_clock::now();

    // Text processing
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream tokenizer(line);

        // Process each token
        std::string token;
    }

    // Benchmarking end time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "Text processing took " << elapsedTime.count() << " milliseconds." << std::endl;

    // Close the file
    inputFile.close();
}

int main() {
    // Replace "input.txt" with the path to your text file
    std::string filePath = "input.txt";

    // Iterate 20 times
    for (int i = 0; i < 200; ++i) {
        // Text processing
        processText(filePath);
    }
    return 0;
}
