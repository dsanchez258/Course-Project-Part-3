
#include <iostream>
#include <string>
using namespace std;

// Function prototypes
string Encrypt(string text, string keyword);
string Decrypt(string text, string keyword);
string RepeatKey(string keyword, int length);
int charToNum(char character);
char numToChar(int number);

int main() {
    int choice;
    string text, keyword, result;

    cout << "Welcome to Vigenère Cipher Program\n";
    cout << "Choose an option: 1. Encrypt  2. Decrypt\n";
    cin >> choice;
    cin.ignore(); // Clear input buffer

    if (choice == 1) {
        cout << "You selected Encryption.\n";
        cout << "Enter plaintext to encrypt (uppercase letters only):\n";
        getline(cin, text);
        cout << "Enter keyword (uppercase letters only):\n";
        getline(cin, keyword);

        result = Encrypt(text, keyword);
        cout << "Encrypted text: " << result << endl;
    } else if (choice == 2) {
        cout << "You selected Decryption.\n";
        cout << "Enter ciphertext to decrypt (uppercase letters only):\n";
        getline(cin, text);
        cout << "Enter keyword (uppercase letters only):\n";
        getline(cin, keyword);

        result = Decrypt(text, keyword);
        cout << "Decrypted text: " << result << endl;
    } else {
        cout << "Invalid choice! Please restart the program.\n";
    }

    return 0;
}

// Function definitions
string Encrypt(string text, string keyword) {
    cout << "Encrypting...\n";
    string expandedKey = RepeatKey(keyword, text.length());
    string result = "";

    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int charOffset = (charToNum(text[i]) + charToNum(expandedKey[i])) % 26;
            result += numToChar(charOffset);
        } else {
            cout << "Invalid character in plaintext! Skipping.\n";
        }
    }

    return result;
}

string Decrypt(string text, string keyword) {
    cout << "Decrypting...\n";
    string expandedKey = RepeatKey(keyword, text.length());
    string result = "";

    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int charOffset = (charToNum(text[i]) - charToNum(expandedKey[i]) + 26) % 26;
            result += numToChar(charOffset);
        } else {
            cout << "Invalid character in ciphertext! Skipping.\n";
        }
    }

    return result;
}

string RepeatKey(string keyword, int length) {
    cout << "Generating expanded key...\n";
    string expandedKey = "";
    while (expandedKey.length() < length) {
        expandedKey += keyword;
    }
    return expandedKey.substr(0, length);
}

int charToNum(char character) {
    return character - 'A';
}

char numToChar(int number) {
    return static_cast<char>(number + 'A');
}
