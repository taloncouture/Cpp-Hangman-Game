#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

std::string word_bank[12] = {"apple", "banana", "carrot", "orange", "broccoli", "vegetable", "cat", "dog", "science", "mathematics", "coding", "programming"};

int getRandom(int ub) {
    srand((unsigned int)time(NULL));
    return rand() % ub;
}

int main() {

    std::string word = word_bank[getRandom(12)];
    bool completed = false;

    std::string progress;
    for (int i = 0; i < word.length(); i++) {
        progress += "_";
        std::cout << "_ ";
    }

    bool match = false;
    int guesses = 5;

    while (!completed) {

        std::cout << std::endl;
        std::cout << std::endl;

        char guess;
        std::cin >> guess;
        std::cout << std::endl;
    
        match = false;

        for (int i = 0; i < word.length(); i++) {
            if (guess == word[i]) {
                progress[i] = word[i];
                match = true;
            }
        }

        if (match == false) {
            if (guesses > 0) {
                guesses -= 1;
            }
            else {
                std::cout << "You ran out of guesses!" << std::endl;
                break;
            }
        }

        std::cout << std::endl;
        std::cout << "You have " << guesses + 1 << " guesses remaining.";
        std::cout << std::endl;

        completed = true;
        for (int i = 0; i < word.length(); i++) {
            if (progress[i] == '_') {
                completed = false;
            }
            std::cout << progress[i] << " ";
        }

        std::cout << std::endl;
    }
    
    if (guesses > 0) {
        std::cout << "You guessed the word!";
    }

    int x;
    std::cout << std::endl;
    std::cout << "Type in anything and press enter to exit" << std::endl;
    std::cin >> x;
    return 0;
}
