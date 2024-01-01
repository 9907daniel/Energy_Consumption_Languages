
#include <drogon/drogon.h>
#include <random>

int generateRandomNumber() {
    // Use std::random_device to seed the random number generator
    std::random_device rd;
    // Use std::mt19937 as the random number engine
    std::mt19937 gen(rd());
    // Use std::uniform_int_distribution to generate random integers in the desired range
    std::uniform_int_distribution<int> distribution(0, 99); // Adjust the range as needed

    return distribution(gen);
}

int main() {
    drogon::app().addListener("0.0.0.0", 5555);

        int randomNumber = generateRandomNumber();

    std::exit(0);

    return 0;
}
