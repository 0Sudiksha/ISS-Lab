#include <iostream>
#include <vector>
#include <string>

using namespace std;

int charToInt(char c) {
    return toupper(c) - 'A';
}

char intToChar(int n) {
    return n + 'A';
}

vector<int> multiplyMatrix(const vector<vector<int>>& keyMatrix, const vector<int>& textVector) {
    int size = keyMatrix.size();
    vector<int> result(size, 0);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i] += keyMatrix[i][j] * textVector[j];
        }
        result[i] %= 26; 
    }

    return result;
}

string encryptHillCipher(const string& plaintext, const vector<vector<int>>& keyMatrix) {
    int size = keyMatrix.size();
    string ciphertext = plaintext;

    while (ciphertext.length() % size != 0) {
        ciphertext += 'X';
    }
    string encryptedText = "";
    for (size_t i = 0; i < ciphertext.length(); i += size) {
        vector<int> textVector(size);
        
        for (int j = 0; j < size; j++) {
            textVector[j] = charToInt(ciphertext[i + j]);
        }

        vector<int> result = multiplyMatrix(keyMatrix, textVector);

        for (int j = 0; j < size; j++) {
            encryptedText += intToChar(result[j]);
        }
    }

    return encryptedText;
}

void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    string plaintext;
    cout << "Enter the plaintext (uppercase letters only): ";
    cin >> plaintext;

    vector<vector<int>> keyMatrix = {
        {6, 24},
        {1, 13}
    };

    cout << "\nKey Matrix: \n";
    displayMatrix(keyMatrix);

    string encryptedText = encryptHillCipher(plaintext, keyMatrix);

    cout << "\nEncrypted Text: " << encryptedText << endl;

    return 0;
}










