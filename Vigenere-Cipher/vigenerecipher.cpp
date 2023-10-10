/*
Nama    : Sarah Khairunnisa Prihantoro
Kelas   : A
NPM     : 140810210063
Program : Vigenere Cipher
*/

#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char encrypted = (c + key[i % key.length()] - 2 * base) % 26 + base;
            result += encrypted;
        } else {
            result += c;
        }
    }
    return result;
}

string decrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char decrypted = (c - key[i % key.length()] + 26) % 26 + base;
            result += decrypted;
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text, key;

    cout << "Masukkan Kata: ";
    getline(cin, text);

    cout << "Masukkan Key: ";
    cin >> key;

    string encrypted_text = encrypt(text, key);
    cout << "Hasil Enkripsi: " << encrypted_text << endl;

    string decrypted_text = decrypt(encrypted_text, key);
    cout << "Hasil Dekripsi: " << decrypted_text << endl;

    return 0;
}
