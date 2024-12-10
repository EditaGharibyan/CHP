#include <iostream>
#include <string>

#include "caesar.cpp"  
#include "Mat.cpp"  

int main() {
    int shift;
    std::string plaintext;

    std::cout << "Enter shift for Caesar Cipher: ";
    std::cin >> shift;
    std::cin.ignore();  

    std::cout << "Enter plaintext to encrypt with both Caesar and Matrix methods: ";
    std::getline(std::cin, plaintext);

    CaesarCipher caesarCipher(shift);
    std::string caesarEncrypted = caesarCipher.encrypt(plaintext);
    std::cout << "Caesar Encrypted Text: " << caesarEncrypted << std::endl;

    FixedMatrixEncryptor matrixEncryptor(caesarEncrypted);
    std::string finalEncrypted = matrixEncryptor.encrypt();
    std::cout << "Final Encrypted Text (Caesar + Matrix): " << finalEncrypted << std::endl;

    std::string matrixDecrypted = matrixEncryptor.decrypt(finalEncrypted);
    std::cout << "After Matrix Decryption (Caesar Encrypted Text): " << matrixDecrypted << std::endl;

    std::string originalText = caesarCipher.decrypt(matrixDecrypted);
    std::cout << "Original Text after Full Decryption: " << originalText << std::endl;

    return 0;
}
