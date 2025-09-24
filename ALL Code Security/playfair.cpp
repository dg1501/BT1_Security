#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string generateKeyMatrix(const string &key_input) {
    string key = key_input;
    // Thêm ph?n còn l?i c?a b?ng ch? d? d?m b?o d? ch?
    key += "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J g?p v?i I

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
    // matrix nên có 25 ký t?
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
        if (i + 1 < res.size() && res[i] == res[i+1]) {
            prepared.push_back('X');
        }
    }
    if (prepared.size() % 2 != 0) prepared.push_back('X');
    return prepared;
}

string playfairEncrypt(const string &text, const string &key_input) {
    string matrix = generateKeyMatrix(key_input);
    if (matrix.size() < 25) {
        // fallback: fill missing letters (shouldn't happen)
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (c == 'J') continue;
            if (matrix.find(c) == string::npos) matrix.push_back(c);
            if (matrix.size() == 25) break;
        }
    }

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
            char na = matrix[ra*5 + (ca + 1) % 5];
            char nb = matrix[rb*5 + (cb + 1) % 5];
            cipher.push_back(na); cipher.push_back(nb);
        } else if (ca == cb) {
            // same column -> shift down
            char na = matrix[((ra + 1) % 5) * 5 + ca];
            char nb = matrix[((rb + 1) % 5) * 5 + cb];
            cipher.push_back(na); cipher.push_back(nb);
        } else {
            // rectangle swap columns
            char na = matrix[ra*5 + cb];
            char nb = matrix[rb*5 + ca];
            cipher.push_back(na); cipher.push_back(nb);
        }
    }
    return cipher;
}

int main() {
    string text, key;
    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    getline(cin, key);

    string encrypted = playfairEncrypt(text, key);
    cout << "Ban ma: " << encrypted << endl;
    return 0;
}

