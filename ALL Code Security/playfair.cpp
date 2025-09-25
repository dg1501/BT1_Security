#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string generateKeyMatrix(const string &key_input) {
    string key = key_input + "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J = I
    vector<bool> used(26, false);
    string matrix = "";

    for (size_t i = 0; i < key.size(); ++i) {
        char ch = key[i];
        if (!isalpha((unsigned char)ch)) continue;
        ch = toupper((unsigned char)ch);
        if (ch == 'J') ch = 'I';
        int idx = ch - 'A';
        if (!used[idx]) {
            used[idx] = true;
            matrix.push_back(ch);
        }
    }
    if (matrix.size() > 25) matrix = matrix.substr(0, 25);
    return matrix;
}

pair<int,int> findPos(char c, const string &matrix) {
    if (c == 'J') c = 'I';
    int idx = (int)matrix.find(c);
    return make_pair(idx / 5, idx % 5);
}

string prepareText(const string &text) {
    string res = "";
    for (size_t i = 0; i < text.size(); ++i) {
        char ch = text[i];
        if (isalpha((unsigned char)ch)) {
            ch = toupper((unsigned char)ch);
            if (ch == 'J') ch = 'I';
            res.push_back(ch);
        }
    }

    string prepared = "";
    for (size_t i = 0; i < res.size(); ++i) {
        prepared.push_back(res[i]);
        if (i + 1 < res.size() && res[i] == res[i+1]) prepared.push_back('X');
    }
    if (prepared.size() % 2 != 0) prepared.push_back('X');
    return prepared;
}

string playfairEncrypt(const string &text, const string &key_input) {
    string matrix = generateKeyMatrix(key_input);
    string prepared = prepareText(text);
    string cipher = "";

    for (size_t i = 0; i + 1 < prepared.size(); i += 2) {
        char a = prepared[i];
        char b = prepared[i+1];
        pair<int,int> pa = findPos(a, matrix);
        pair<int,int> pb = findPos(b, matrix);

        int ra = pa.first, ca = pa.second;
        int rb = pb.first, cb = pb.second;

        if (ra == rb) {
            // same row -> shift right
            cipher.push_back(matrix[ra*5 + (ca + 1) % 5]);
            cipher.push_back(matrix[rb*5 + (cb + 1) % 5]);
        } else if (ca == cb) {
            // same column -> shift down
            cipher.push_back(matrix[((ra + 1) % 5) * 5 + ca]);
            cipher.push_back(matrix[((rb + 1) % 5) * 5 + cb]);
        } else {
            // rectangle swap columns
            cipher.push_back(matrix[ra*5 + cb]);
            cipher.push_back(matrix[rb*5 + ca]);
        }
    }
    return cipher;
}

string playfairDecrypt(const string &cipher, const string &key_input) {
    string matrix = generateKeyMatrix(key_input);
    string plain = "";

    for (size_t i = 0; i + 1 < cipher.size(); i += 2) {
        char a = cipher[i];
        char b = cipher[i+1];
        pair<int,int> pa = findPos(a, matrix);
        pair<int,int> pb = findPos(b, matrix);

        int ra = pa.first, ca = pa.second;
        int rb = pb.first, cb = pb.second;

        if (ra == rb) {
            // same row -> shift left
            plain.push_back(matrix[ra*5 + (ca + 4) % 5]);
            plain.push_back(matrix[rb*5 + (cb + 4) % 5]);
        } else if (ca == cb) {
            // same column -> shift up
            plain.push_back(matrix[((ra + 4) % 5) * 5 + ca]);
            plain.push_back(matrix[((rb + 4) % 5) * 5 + cb]);
        } else {
            // rectangle swap columns
            plain.push_back(matrix[ra*5 + cb]);
            plain.push_back(matrix[rb*5 + ca]);
        }
    }
    return plain;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    getline(cin, key);

    int choice;
    cout << "Chon chuc nang (1: Ma hoa, 2: Giai ma): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Ban ma hoa: " << playfairEncrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Ban giai ma: " << playfairDecrypt(text, key) << endl;
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }

    return 0;
}

