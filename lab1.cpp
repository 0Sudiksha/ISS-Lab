#include <iostream>
#include <string>
using namespace std;

string encryptCaesarCipher(string text, int shift) {
    string result = "";
    
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            result += char(int(base + (c - base + shift) % 26));
        } else {
            result += c;
        }
    }
    return result;
}

string decryptCaesarCipher(string text, int shift) {
    return encryptCaesarCipher(text, 26 - (shift % 26));  
}

int main() {
    string plaintext;
    int shift;

    cout << "Enter the text to encrypt: ";
    getline(cin, plaintext);
    cout << "Enter the shift value: ";
    cin >> shift;

    string encryptedText = encryptCaesarCipher(plaintext, shift);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = decryptCaesarCipher(encryptedText, shift);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}



