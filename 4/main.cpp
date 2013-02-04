#include <iostream>
#include <string>
using namespace std;

int key[] = {6, 3, 2, 5, 1, 4};

string encode(const string &text)
{
    int pos = 0;
    int size = text.size();
    string subCode = "      ";
    string encodeText;
    encodeText.reserve(text.size());
    while (pos < size) {
        string subPlain = text.substr(pos, pos + 6);
        for (int i = 0; i < 6; ++i) {
            if (key[i]-1 < subPlain.size())
                subCode[i] = subPlain[key[i]-1];;
        }
        encodeText += subCode;
        subCode = "      ";
        pos += 6;
    }

    return encodeText;
}

string decode(const string &encodeText)
{
    int pos = 0;
    int size = encodeText.size();
    string subCode = "      ";
    string decodeText;
    decodeText.reserve(encodeText.size());
    while (pos < size) {
        string subPlain = encodeText.substr(pos, pos + 6);
        for (int i = 0; i < 6; ++i) {
            if (key[i]-1 < subPlain.size())
                subCode[key[i]-1] = subPlain[i];;
        }
        decodeText += subCode;
        subCode = "      ";
        pos += 6;
    }

    return decodeText;
}

int main()
{
    string plainText;
    
    cout << "Enter a text: ";
    getline(cin, plainText);
    
    string encodeText = encode(plainText);
    cout << "Encode text: " << encodeText << endl;

    string decodeText = decode(encodeText);
    cout << "Decode text: " << decodeText << endl;

    return 1;
}