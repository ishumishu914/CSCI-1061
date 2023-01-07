#include <iostream> 
#include <string>
using namespace std; 

//function decleration 
string encryption(string text, int shift);
string decryption(string text, int shift);

int main()
{      
    // variable declaration
    string text;
    int shift;

    cout << "Enter shift +/- 26: ";
    cin >> shift;
    
    cout << "Enter plaintext text (A-Z only, no spaces): ";
    cin >> text; 

    string encrypt = encryption(text,shift);
    string decrypt = decryption(encrypt,shift);

    cout << "ciphertext: " << encrypt <<endl;
    cout << "plaintext: " << decrypt <<endl;

    return 0;
}

//encryption function  
string encryption(string text, int shift)
{
    for (int i = 0; i < text.length(); i++)
    {
        char characters = text[i];

        if (characters >= 'A' && characters <= 'Z')
        {
            characters += shift;

            if (characters > 'Z')
            {
                characters = characters - 'Z' + 'A' - 1; //if shift = 1 .... character = 91 - 90 + 65 -1 = 65 or 'A'
            }

            else if (characters < 'A')
            {            
                characters = characters + 'Z' - 'A' + 1; //if shift = 1 .... character = 64 + 90 - 65 +1 = 90 or 'Z'
            }
            text[i] = characters;
        }
    }
    return text;
}

// decryption function 
string decryption(string text, int shift)
{
    for (int i = 0; i < text.length(); i++)
    {
        char characters = text[i];

        if (characters >= 'A' && characters <= 'Z')
        {
            characters -= shift;
            if (characters > 'Z')
            {
                characters = characters - 'Z' + 'A' - 1;
            }

            else if (characters < 'A')
            {
                characters = characters + 'Z' - 'A' + 1;               
            }
            text[i] = characters;
        }
    }
    return text;
}