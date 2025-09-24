#include <iostream>
#include <string>
#include <vector>
using namespace std;

string transposeEncrypt(const string &text, const vector<int> &key) {
    int cols = key.size();
    int rows = (text.size() + cols - 1) / cols;
    // C++98-safe: note the space between > >
    vector<vector<char> > matrix(rows, vector<char>(cols, 'X'));

    int idx = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (idx < (int)text.size()) matrix[r][c] = text[idx++];
        }
    }

    string result;
    for (size_t k = 0; k < key.size(); ++k) {
        int c = key[k] - 1;
        for (int r = 0; r < rows; ++r) result.push_back(matrix[r][c]);
    }
    return result;
}

int main(){
    string text;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);

    int n;
    cout << "Nhap do dai khoa: ";
    cin >> n;
    vector<int> key(n);
    cout << "Nhap khoa (vi du: 3 1 2): ";
    for (int i = 0; i < n; ++i) cin >> key[i];

    cout << "Ban ma hoa: " << transposeEncrypt(text, key) << endl;
    return 0;
}

