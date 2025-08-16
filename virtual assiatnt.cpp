#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Function to get current date and time
string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    string dateTime = "Date: " + to_string(ltm->tm_mday) + "/" +
                      to_string(1 + ltm->tm_mon) + "/" +
                      to_string(1900 + ltm->tm_year) +
                      " Time: " + to_string(ltm->tm_hour) + ":" +
                      to_string(ltm->tm_min) + ":" +
                      to_string(ltm->tm_sec);
    return dateTime;
}

// Function to provide motivational quotes
string getMotivationalQuote() {
    string quotes[] = {
        "Believe in yourself and all that you are.",
        "The best way to predict the future is to create it.",
        "Success is not final, failure is not fatal: It is the courage to continue that counts.",
        "Dream big and dare to fail."
    };
    int index = rand() % 4; // Randomly select a quote
    return quotes[index];
}

int main() {
    string userInput;

    cout << "Hello! I am your virtual assistant. How can I help you today?" << endl;

    while (true) {
        cout << "\nEnter a command (greet, date, quote, exit): ";
        getline(cin, userInput);

        if (userInput == "greet") {
            cout << "Hello! It's nice to see you." << endl;
        } else if (userInput == "date") {
            cout << getCurrentDateTime() << endl;
        } else if (userInput == "quote") {
            cout << getMotivationalQuote() << endl;
        } else if (userInput == "exit") {
            cout << "Goodbye! Have a great day!" << endl;
            break;
        } else {
            cout << "I'm sorry, I didn't understand that command. Please try again." << endl;
        }
    }

    return 0;
}



