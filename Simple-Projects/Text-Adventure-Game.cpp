#include <iostream>
using namespace std;

int main() {
    int choice1, choice2;

    cout << "=====================================\n";
    cout << "      MYSTERY OF THE LOST FOREST\n";
    cout << "=====================================\n\n";

    cout << "You wake up alone in a mysterious forest.\n";
    cout << "The moon shines above and you hear strange noises.\n\n";

    cout << "What do you do?\n";
    cout << "1. Follow the river\n";
    cout << "2. Enter the dark cave\n";
    cout << "3. Climb the mountain\n";
    cout << "\nEnter your choice: ";
    cin >> choice1;

    switch(choice1) {
        case 1:
            cout << "\nYou follow the river and discover an old boat.\n";
            cout << "1. Use the boat\n";
            cout << "2. Continue walking\n";
            cout << "Enter your choice: ";
            cin >> choice2;

            if(choice2 == 1) {
                cout << "\nThe boat carries you safely to a village.\n";
                cout << "🏆 GOOD ENDING: You escaped the forest!\n";
            }
            else {
                cout << "\nYou get lost and wander forever.\n";
                cout << "💀 BAD ENDING.\n";
            }
            break;

        case 2:
            cout << "\nInside the cave you find a sleeping dragon.\n";
            cout << "1. Steal the treasure\n";
            cout << "2. Quietly leave\n";
            cout << "Enter your choice: ";
            cin >> choice2;

            if(choice2 == 1) {
                cout << "\nThe dragon wakes up!\n";
                cout << "💀 GAME OVER.\n";
            }
            else {
                cout << "\nYou safely leave the cave and discover a hidden path home.\n";
                cout << "🏆 GOOD ENDING: You survived!\n";
            }
            break;

        case 3:
            cout << "\nYou climb the mountain and meet a wise hermit.\n";
            cout << "1. Ask for guidance\n";
            cout << "2. Ignore him and continue\n";
            cout << "Enter your choice: ";
            cin >> choice2;

            if(choice2 == 1) {
                cout << "\nThe hermit shows you the secret way out.\n";
                cout << "🏆 BEST ENDING: You escaped with wisdom!\n";
            }
            else {
                cout << "\nA storm approaches and you fall from the cliff.\n";
                cout << "💀 GAME OVER.\n";
            }
            break;

        default:
            cout << "\nInvalid choice!\n";
    }

    cout << "\nThanks for playing!\n";

    return 0;
}
