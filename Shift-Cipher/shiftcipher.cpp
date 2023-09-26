/*
	Nama     : Sarah Khairunnisa Prihantoro
	NPM      : 140810210063
	Kelas    : A
	Program  : Shift Cipher
*/

#include <iostream>

using namespace std;

string enkripsi(string plainText, int key) {
    string cipherText;

    for(int i = 0; plainText[i] != '\0'; ++i) {
        if (plainText[i] == ' ') {
            cipherText += ' ';
        }
        else if (isupper(plainText[i])) {
            cipherText += char(int(plainText[i] + key - 65) % 26 + 65);
        }
        else {
            cipherText += char(int(plainText[i] + key - 97) % 26 + 97);
        }
    }
    return cipherText;
}

string dekripsi(string cipherText, int key) {
    string plainText;
    for(int i = 0; cipherText[i] != '\0'; ++i) {
        if (cipherText[i] == ' ') {
            plainText += ' ';
        }
        else if (isupper(cipherText[i])) {
            plainText += char(int(cipherText[i] + (26 - key) - 65) % 26 + 65);
        }
        else {
            plainText += char(int(cipherText[i] + (26 - key) - 97) % 26 + 97);
        }
    }
    return plainText;
}

int main() {
    char confirm;
    do {
        size_t choice;

        do {       
            cout << "+-+-+-+- Program Shift Cipher +-+-+-+-\n";
            cout << "1. Enkripsi\n";
            cout << "2. Dekripsi\n";
            cout << "Pilihan \t: ";
            cin >> choice;
        } while (choice != 1 && choice != 2);

        string inputText;
        cout << "\nMasukan Kata\t: ";
        cin.ignore();
        getline(cin, inputText);

        int key;
        do {
            cout << "Masukan Key\t: ";
            cin >> key;
        } while (cin.fail());

        if (choice == 1) {
            cout << "\nHasil Enkripsi\t: " << enkripsi(inputText, key) << "\n";
        }
        else {
            cout << "\nHasil Dekripsi\t: " << dekripsi(inputText, key) << "\n";
        }
        cout << "\nUlangi Program [y/n]\t: ";
        cin >> confirm;
    } while (toupper(confirm) == 'Y');
}