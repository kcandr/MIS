#include <iostream>
#include <string>
using namespace std;

int main()
{
    string plainText;
    string codeText;
    int key[] = {6, 3, 2, 5, 1, 4};
    cout << "Enter a text: ";
    getline(cin, plainText);
    int pos = 0;
    int size = plainText.size();
    string subCode = "      ";

    codeText.reserve(plainText.size());
    while (pos < size) {
        string subPlain = plainText.substr(pos, pos + 6);
        for (int i = 0; i < 6; ++i) {
            if (key[i]-1 < subPlain.size())
                subCode[i] = subPlain[key[i]-1];;
        }
        codeText += subCode;
        subCode = "      ";
        pos += 6;
    }
    cout << "Encode text:" << codeText << endl;
    return 1;
}