#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class FixedMatrixEncryptor {
private:
    char matrix[5][3]; 
    const int rows = 5;
    const int cols = 3;

    void clearMatrix() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                matrix[i][j] = ' ';
    }

    void fillMatrix(const std::string& sentence) {
        clearMatrix();
        int row = 0, col = 0;

        for (char ch : sentence) {
            if (ch == ' ') { 
                col++; 
                if (col >= cols) { 
                    col = 0;
                    row++;
                }
                continue;
            }
            
            matrix[row][col++] = ch;
            
            if (col >= cols) { 
                col = 0;
                row++;
            }
            if (row >= rows) break; 
        }
    }

public:
    FixedMatrixEncryptor(const std::string& sentence) {
        fillMatrix(sentence);
    }

    std::string encrypt() {
        std::string encryptedText;

        
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                if (matrix[row][col] != ' ') {
                    encryptedText += matrix[row][col];
                }
            }
            encryptedText += ' '; 
        }

        return encryptedText;
    }
    std::string decrypt(const std::string& encryptedText) {
        clearMatrix();
        int index = 0;
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                if (index < encryptedText.size() && encryptedText[index] != ' ') {
                    matrix[row][col] = encryptedText[index++];
                } else {
                    index++;
                }
            }
        }

        std::string decryptedText;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] != ' ') {
                    decryptedText += matrix[row][col];
                }
            }
        }
        return decryptedText;
    }

    void displayMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << std::setw(2) << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }
};

// int main() {
//     std::string sentence = "A big cat 21";
//     FixedMatrixEncryptor encryptor(sentence);

//     std::cout << "Matrix layout:" << std::endl;
//     encryptor.displayMatrix();

//     std::cout << "\nEncrypted text: " << encryptor.encrypt() << std::endl;

//     return 0;
// }
