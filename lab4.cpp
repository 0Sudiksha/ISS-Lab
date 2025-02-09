#include <iostream>
#include <string>
using namespace std;
string vigenereEncrypt(const string& plaintext, const string& key) {
    string ciphertext;
    int keyIndex = 0;
    int keyLength = key.length();
    
    for (char c : plaintext) {
        if (isalpha(c)) {
            char shift = toupper(key[keyIndex]) - 'A';
            if (isupper(c)) {
                ciphertext += char((c - 'A' + shift) % 26 + 'A');
            } else {
                ciphertext += char((c - 'a' + shift) % 26 + 'a');
            }
            keyIndex = (keyIndex + 1) % keyLength;
        } else {
            ciphertext += c;
        }
    }
    
    return ciphertext;
}
string vigenereDecrypt(const string& ciphertext, const string& key) {
    string plaintext;
    int keyIndex = 0;
    int keyLength = key.length();
    
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char shift = toupper(key[keyIndex]) - 'A';
            if (isupper(c)) {
                plaintext += char((c - 'A' - shift + 26) % 26 + 'A');
            } else {
                plaintext += char((c - 'a' - shift + 26) % 26 + 'a');
            }
            keyIndex = (keyIndex + 1) % keyLength;
        } else {
            plaintext += c;
        }
    }
    
    return plaintext;
}
int main() {
    string plaintext = "HELLO WORLD";
    string key = "KEY";
    
    string ciphertext = vigenereEncrypt(plaintext, key);
    string decryptedText = vigenereDecrypt(ciphertext, key);
    
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted Text: " << decryptedText << endl;
    
    return 0;
}



