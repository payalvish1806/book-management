#include <iostream>
#include <fstream>  // File handling ke liye
#include <string>

using namespace std;

string books[5] = {"Harry Potter", "APJ Abdul Kalam", "Ratan Tata", "Albert Einstein", "Jeet Adani"};
bool issued[5]; // Ye status file se load hoga

// Function to save issued book status in file
void saveToFile() {
    ofstream file("library_data.txt");
    for (int i = 0; i < 5; i++) {
        file << issued[i] << endl;
    }
    file.close();
}

// Function to load issued book status from file
void loadFromFile() {
    ifstream file("library_data.txt");
    if (file) {
        for (int i = 0; i < 5; i++) {
            file >> issued[i];
        }
        file.close();
    } else {
        // Agar file nahi mili to sabko false set kar do
        for (int i = 0; i < 5; i++) {
            issued[i] = false;
        }
    }
}

int main() {
    loadFromFile(); // Program start hote hi data load hoga

    while (true) {
        cout << "  " << endl;
        cout << "1. Display books" << endl;
        cout << "2. Issue book" << endl;
        cout << "3. Return book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    cout << i + 1 << ". " << books[i];
                    if (issued[i]) {
                        cout << " (Issued)";
                    }
                    cout << endl;
                }
                break;

            case 2:
                cout << "Enter book number (1-5): ";
                int bookNumber;
                cin >> bookNumber;
                if (bookNumber >= 1 && bookNumber <= 5) {
                    if (!issued[bookNumber - 1]) {
                        issued[bookNumber - 1] = true;
                        saveToFile(); // File me save karna
                        cout << "Book issued successfully!" << endl;
                    } else {
                        cout << "Book is already issued!" << endl;
                    }
                } else {
                    cout << "Invalid book number!" << endl;
                }
                break;

            case 3:
                cout << "Enter book number (1-5): ";
                cin >> bookNumber;
                if (bookNumber >= 1 && bookNumber <= 5) {
                    if (issued[bookNumber - 1]) {
                        issued[bookNumber - 1] = false;
                        saveToFile(); // File me save karna
                        cout << "Book returned successfully!" << endl;
                    } else {
                        cout << "Book is not issued!" << endl;
                    }
                } else {
                    cout << "Invalid book number!" << endl;
                }
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
