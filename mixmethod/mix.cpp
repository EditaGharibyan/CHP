#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string caesarEncrypt(const string& plaintext, int key) {
    string encrypted = "";
    for (char ch : plaintext) {
        if (isupper(ch)) {
            encrypted += char(int(ch + key - 65) % 26 + 65);
        } else if (islower(ch)) {
            encrypted += char(int(ch + key - 97) % 26 + 97);
        } else {
            encrypted += ch;
        }
    }
    return encrypted;
}

string caesarDecrypt(const string& ciphertext, int key) {
    string decrypted = "";
    for (char ch : ciphertext) {
        if (isupper(ch)) {
            decrypted += char(int(ch - key - 65 + 26) % 26 + 65);
        } else if (islower(ch)) {
            decrypted += char(int(ch - key - 97 + 26) % 26 + 97);
        } else {
            decrypted += ch;
        }
    }
    return decrypted;
}

string vigenereEncrypt(const string& plaintext, const string& key) {
    string encrypted = "";
    int keyIndex = 0;
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            encrypted += char(((ch - base + (key[keyIndex % key.length()] - base)) % 26) + base);
            keyIndex++;
        } else {
            encrypted += ch;
        }
    }
    return encrypted;
}

string vigenereDecrypt(const string& ciphertext, const string& key) {
    string decrypted = "";
    int keyIndex = 0;
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            decrypted += char(((ch - base - (key[keyIndex % key.length()] - base) + 26) % 26) + base);
            keyIndex++;
        } else {
            decrypted += ch;
        }
    }
    return decrypted;
}

int main() {
    string inputText;
    int caesarKey = 3;
    string vigenereKey = "KEY";
    
    cout << "Enter the text to encrypt: ";
    getline(cin, inputText);

    string caesarEncrypted = caesarEncrypt(inputText, caesarKey);
    cout << "\nCaesar Cipher Encrypted: " << caesarEncrypted << endl;
    
    string vigenereEncrypted = vigenereEncrypt(caesarEncrypted, vigenereKey);
    cout << "Vigenère Cipher Encrypted: " << vigenereEncrypted << endl;

    string vigenereDecrypted = vigenereDecrypt(vigenereEncrypted, vigenereKey);
    cout << "\nVigenère Cipher Decrypted: " << vigenereDecrypted << endl;
    
    string caesarDecrypted = caesarDecrypt(vigenereDecrypted, caesarKey);
    cout << "Caesar Cipher Decrypted: " << caesarDecrypted << endl;

    return 0;
}
