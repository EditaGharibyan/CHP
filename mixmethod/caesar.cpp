#include <iostream>
#include <string>

class CaesarCipher {
private:
    int shift;

public:
   
    CaesarCipher(int s) {
        shift = s;
    }
    std::string encrypt(const std::string& plaintext) {
        std::string result = "";
        for (char ch : plaintext) {
            if (isupper(ch)) {
                result += char(int(ch + shift) );
            } else if (islower(ch)) {
                result += char(int(ch + shift));
            } else {
                result += ch;
            }
        }
        return result;
    }

    std::string decrypt(const std::string& ciphertext) {
        std::string result = "";
        for (char ch : ciphertext) {
            if (isupper(ch)) {
                result += char(int(ch - shift) );
            } else if (islower(ch)) {
                result += char(int(ch - shift));
            } else {
                result += ch;
            }
        }
        return result;
    }
};

// int main() {
//     int shift;
//     std::cout << "Enter shift value: ";
//     std::cin >> shift;

//     std::cin.ignore();

//     CaesarCipher cipher(shift);

//     std::string message;
//     std::cout << "Enter the message to encrypt: ";
//     std::getline(std::cin, message);

//     std::string encrypted = cipher.encrypt(message);
//     std::cout << "Encrypted: " << encrypted << std::endl;

//     std::string decrypted = cipher.decrypt(encrypted);
//     std::cout << "Decrypted: " << decrypted << std::endl;

//     return 0;
// }
