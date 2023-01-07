#include <iostream> 
#include <fstream>
#include <string>
using namespace std; 

int main(int argc, char** argv)
{
    // variable declaration
    char character;
    string output, text, line;

    while(getline(cin, line))
    {
        text += line + "\n";   
    }

    if (argc != 3)
    {
        cerr << "Incorrect number of arguments" << endl;
    }
    else
    {
        int shift = atoi(argv[2]); //shift value is 3rd argument

        for (int i = 0; i < text.length(); i++)
        {
            character = text[i];

            if (character >= 'A' && character <= 'Z') // check if the characters are A-Z
            {
                if (argv[1][1] == 'e') //-e encryption
                {
                    character += shift;
                    if (character > 'Z')
                    {
                        character = character - 'Z' + 'A' - 1;  //if shift = 1 .... character = 91 - 90 + 65 -1 = 65 or 'A'
                    }   
                    output += character;                                       
                }

                else if (argv[1][1] == 'd') //-d decryption
                {
                    character -= shift;
                    if (character < 'A')
                    {
                        character = character + 'Z' - 'A' + 1; //if shift = 1 .... character = 64 + 90 - 65 +1 = 90 or 'Z'
                    } 
                    output += character;                     
                }                    
            }
            else // for numbers and/or any other characters
            {
                output += character;
            }                    
        } 
    }

    cout << output <<"\n";
  
    return 0;
}