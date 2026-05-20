#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

int main() {

    // Variable to store the user's name
    string name;

    // Ask the user for their name
    // Keep asking until the user enters a valid name
do {
    cout << "Enter your name: ";
    getline(cin, name);

    // Check if the input is empty
    if (name.empty()) {
        cout << "Name cannot be empty. Please try again.\n";
    }

} while (name.empty());
    /*
        A vector is like a dynamic array.
        Here, we store 10 roast templates inside the vector.

        The text "{name}" is a placeholder.
        Later, we will replace it with the actual user's name.
    */
    vector<string> roasts = {
        "{name}'s coding strategy is basically copy, paste, pray.",
        "{name} writes bugs faster than the compiler can detect them.",
        "{name}'s GPA and WiFi signal have one thing in common: both are unstable.",
        "{name} debugs by staring at the screen until the bug feels guilty.",
        "{name}'s code has more red lines than a failed math test.",
        "Even AI needs extra processing time to understand {name}'s logic.",
        "{name} treats assignment deadlines like optional side quests.",
        "{name}'s keyboard works harder than their problem-solving skills.",
        "{name} opens Stack Overflow before even reading the question.",
        "{name}'s favorite programming technique is 'hope-driven development.'"
    };

    /*
        Seed the random number generator.

        time(0) gives the current time.
        This ensures a different random roast
        is selected each time the program runs.
    */
    srand(time(0));

    /*
        Generate a random index number.

        rand() % roasts.size()

        - rand() gives a random number
        - roasts.size() is 10
        - % keeps the result between 0 and 9
    */
    int randomIndex = rand() % roasts.size();

    // Pick one random roast from the vector
    string selectedRoast = roasts[randomIndex];

    /*
        Find the position of "{name}"
        and replace it with the user's actual name.
    */
    size_t position = selectedRoast.find("{name}");

    if (position != string::npos) {
        selectedRoast.replace(position, 6, name);
    }

    // Display the final roast
    cout << "\nAI Roast Generator says:\n";
    cout << selectedRoast << endl;

    return 0;
}
