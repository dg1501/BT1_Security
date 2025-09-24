#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string caesar(const string &s, int k){
    string r; k = ((k%26)+26)%26;
    for(size_t i=0;i<s.size();++i){
        unsigned char c = s[i];
        if(isalpha(c)){
            char base = isupper(c) ? 'A' : 'a';
            r += char((c - base + k) % 26 + base);
        } else r += c;
    }
    return r;
}

int main(){
    string text;
    int k, choice;
    cout<<"Nhap chuoi: ";
    getline(cin, text);
    cout<<"Nhap khoa (0-25): ";
    cin>>k;
    cout<<"\nChon: 1-Encrypt: , 2-Decrypt: ";
    cin>>choice;

    if(choice==1){
        cout<< caesar(text, k) << endl;
    } else if(choice==2){
        cout<< caesar(text, 26 - (k%26)) << endl;
    } else if(choice==3){
        string enc = caesar(text, k);
        cout << "Encrypted: " << enc << endl;
}
}

