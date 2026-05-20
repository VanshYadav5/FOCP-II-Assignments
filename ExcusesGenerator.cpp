#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {

    // Variable to store the student's name
    string studentName;

    // Ask the user to enter their name
    cout << "Enter the student's name: ";
    getline(cin, studentName);

    // Check if the user entered an empty name
    while(studentName.empty()) {
        cout << "Name cannot be empty. Please enter the student's name: ";
        getline(cin, studentName);
    }

    // Vector storing exactly 10 funny technology-themed excuses
    vector<string> excuses = {
        "{name}'s laptop decided to install updates right before submission time.",
        "{name}'s Wi-Fi vanished mysteriously, leaving {name} completely disconnected.",
        "{name}'s code worked perfectly until the computer saw the professor and ruined {name}'s day.",
        "{name}'s keyboard stopped responding after too much gaming practice.",
        "{name}'s browser opened 47 tabs and crashed the entire system.",
        "{name}'s assignment was abducted by a suspicious computer virus.",
        "{name}'s charger gave up emotionally during the final project.",
        "{name}'s AI assistant generated homework in ancient Latin.",
        "{name}'s cloud storage forgot to sync the assignment overnight.",
        "{name}'s laptop fan sounded like a helicopter and shut the system down."
    };

    // Seed the random number generator using current time
    srand(time(0));

    // Generate a random index
    int randomIndex = rand() % excuses.size();

    // Pick one random excuse from the vector
    string selectedExcuse = excuses[randomIndex];

    // Placeholder text to replace
    string placeholder = "{name}";

    // Find the first occurrence of "{name}"
    size_t position = selectedExcuse.find(placeholder);

    // Replace ALL occurrences of "{name}"
    while(position != string::npos) {

        // Replace the placeholder with the actual student name
        selectedExcuse.replace(position, placeholder.length(), studentName);

        // Search again for the next occurrence
        position = selectedExcuse.find(placeholder);
    }

    // Display the final excuse
    cout << "\nGenerated Excuse:\n";
    cout << selectedExcuse << endl;

    return 0;
}
