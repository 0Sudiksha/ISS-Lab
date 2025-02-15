#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encrypt(string plaintext, int numRails) {
    vector<vector<char> > rails(numRails, vector<char>(plaintext.length(), '\0'));
    int row = 0, step = 1;

    for (int i = 0; i < plaintext.length(); i++) {
        rails[row][i] = plaintext[i];
        if (row == 0)
            step = 1;
        else if (row == numRails - 1)
            step = -1;
        row += step;
    }

    string ciphertext = "";
    for (int i = 0; i < numRails; i++) {
        for (int j = 0; j < plaintext.length(); j++) {
            if (rails[i][j] != '\0')
                ciphertext += rails[i][j];
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext, int numRails) {
    vector<vector<char> > rails(numRails, vector<char>(ciphertext.length(), '\0'));
    int row = 0, step = 1;

    for (int i = 0; i < ciphertext.length(); i++) {
        rails[row][i] = '*';
        if (row == 0)
            step = 1;
        else if (row == numRails - 1)
            step = -1;
        row += step;
    }

    int index = 0;
    for (int i = 0; i < numRails; i++) {
        for (int j = 0; j < ciphertext.length(); j++) {
            if (rails[i][j] == '*') {
                rails[i][j] = ciphertext[index++];
            }
        }
    }

    // Read the plaintext from the matrix
    string plaintext = "";
    row = 0, step = 1;
    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += rails[row][i];
        if (row == 0)
            step = 1;
        else if (row == numRails - 1)
            step = -1;
        row += step;
    }

    return plaintext;
}

int main() {
    string plaintext = "HELLOFROMTHEOTHERSIDE";
    int numRails = 3;

    string encrypted = encrypt(plaintext, numRails);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decrypt(encrypted, numRails);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
