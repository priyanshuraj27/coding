#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Initialize random seed based on current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate and print 10000 random numbers
    for (int i = 0; i < 10000; i++) {
        int random_number = rand() % 10000 + 1; // Random number between 1 and 10000
        std::cout << random_number << std::endl;
    }

    return 0;
}
