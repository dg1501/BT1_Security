#include <iostream>
#include <string>
using namespace std;

// Mã hóa Vigenere
string vigenereEncrypt(const string &text, const string &key) {
    string result = "";
    int m = key.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int k = tolower(key[i % m]) - 'a';
            result += char((c - base + k) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

// Gi?i mã Vigenere
string vigenereDecrypt(const string &text, const string &key) {
    string result = "";
    int m = key.size();
    for (int i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int k = tolower(key[i % m]) - 'a';
            result += char((c - base - k + 26) % 26 + base);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    cin >> key;

    int choice;
    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma hoa: " << vigenereEncrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << vigenereDecrypt(text, key) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}

