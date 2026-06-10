#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

class PasswordAnalyzer {
private:
    string password;
    int score;

public:

    PasswordAnalyzer(string pwd) {
        password = pwd;
        score = 0;
    }

    void analyze() {

        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSymbol = false;

        int length = password.length();

        for(char ch : password) {

            if(isupper(ch))
                hasUpper = true;

            else if(islower(ch))
                hasLower = true;

            else if(isdigit(ch))
                hasDigit = true;

            else
                hasSymbol = true;
        }

        score = 0;

        if(length >= 8)
            score += 20;

        if(length >= 12)
            score += 20;

        if(hasUpper)
            score += 15;

        if(hasLower)
            score += 15;

        if(hasDigit)
            score += 15;

        if(hasSymbol)
            score += 15;

        cout << "\n===== PASSWORD ANALYSIS =====\n";

        cout << "Password Length : " << length << endl;
        cout << "Uppercase       : "
             << (hasUpper ? "Yes" : "No") << endl;

        cout << "Lowercase       : "
             << (hasLower ? "Yes" : "No") << endl;

        cout << "Digits          : "
             << (hasDigit ? "Yes" : "No") << endl;

        cout << "Symbols         : "
             << (hasSymbol ? "Yes" : "No") << endl;

        cout << "\nStrength Score : "
             << score << "/100\n";

        if(score < 40)
            cout << "Security Level : WEAK\n";

        else if(score < 70)
            cout << "Security Level : MEDIUM\n";

        else
            cout << "Security Level : STRONG\n";

        cout << "\nSuggestions:\n";

        if(length < 12)
            cout << "- Increase password length.\n";

        if(!hasUpper)
            cout << "- Add uppercase letters.\n";

        if(!hasLower)
            cout << "- Add lowercase letters.\n";

        if(!hasDigit)
            cout << "- Add numbers.\n";

        if(!hasSymbol)
            cout << "- Add special characters.\n";

        if(score >= 70)
            cout << "- Excellent password!\n";

        saveReport();
    }

    void saveReport() {

        ofstream file("password_report.txt",
                      ios::app);

        file << "Password: " << password << endl;
        file << "Score: " << score << "/100\n";

        if(score < 40)
            file << "Level: WEAK\n";

        else if(score < 70)
            file << "Level: MEDIUM\n";

        else
            file << "Level: STRONG\n";

        file << "--------------------------\n";

        file.close();
    }

    static void viewReports() {

        ifstream file("password_report.txt");

        string line;

        cout << "\n===== SAVED REPORTS =====\n";

        while(getline(file, line))
            cout << line << endl;

        file.close();
    }
};

int main() {

    int choice;

    do {

        cout << "\n=================================\n";
        cout << " CYBER SECURITY PASSWORD ANALYZER\n";
        cout << "=================================\n";

        cout << "1. Analyze Password\n";
        cout << "2. View Saved Reports\n";
        cout << "3. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        cin.ignore();

        switch(choice) {

        case 1: {

            string pwd;

            cout << "\nEnter Password: ";
            getline(cin, pwd);

            PasswordAnalyzer analyzer(pwd);
            analyzer.analyze();

            break;
        }

        case 2:
            PasswordAnalyzer::viewReports();
            break;

        case 3:
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while(choice != 3);

    return 0;
}
