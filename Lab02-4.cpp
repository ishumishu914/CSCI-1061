#include <iostream> 
#include <fstream>
#include <string>
using namespace std; 

//function decleration when files are not specified
string encryption(string text, int shiftl, int shiftd);
string decryption(string text, int shiftl, int shiftd);

//encryption function  
string encryption(string text, int shiftl, int shiftd)
{
    for (int i = 0; i < text.length(); i++)
    {
        char chars = text[i];
        if (chars >= 'A' && chars <= 'Z')
        {
            chars += shiftl;
            if (chars > 'Z')
            {
                chars = chars - 'Z' + 'A' - 1; //if shift = 1 .... character = 91 - 90 + 65 -1 = 65 or 'A'
            }
            text[i] = chars; 
        }

        else if (chars >= 'a' && chars <= 'z') // check if the chars are a-z
        {
            chars += shiftl;
            if (chars > 'z')
            {
                chars = chars - 'z' + 'a' - 1; //if shift = 1 .... character = 123 - 122 + 97 -1 or 'a'
            }   
            text[i] = chars;                                                               
        }       

        else if (chars >= '0' && chars <= '9') // check if chars are numbers 0-9
        {
            chars += shiftd;
            if(chars > '9')
            {
                chars = chars - '9' + '0' - 1; // if shift =1 ... character = 58 - 57 + 48 - 1
            }
            text[i] = chars;            
        }
    }
    return text;
}

// decryption function 
string decryption(string text, int shiftl, int shiftd)
{
    for (int i = 0; i < text.length(); i++)
    {
        char chars = text[i];

        if (chars >= 'A' && chars <= 'Z')
        {
            chars -= shiftl;
            if (chars < 'A')
            {
                chars = chars + 'Z' - 'A' + 1;               
            }
            text[i] = chars;
        }

         else if (chars >= 'a' && chars <= 'z') // check if the chars are a-z
        {
            chars -= shiftl;
            if (chars < 'a')
            {
                chars = chars + 'z' - 'a' + 1; //if shift = 1 .... character = 123 - 122 + 97 -1 or 'a'
            }   
            text[i] = chars;                                                               
        }       

        else if (chars >= '0' && chars <= '9') // check if chars are numbers 0-9
        {
            chars -= shiftd;
            if(chars < '0')
            {
                chars = chars + '9' - '0' + 1; // if shift =1 ... character = 58 - 57 + 48 - 1
            }
            text[i] = chars;            
        }
    }
    return text;
}

int main(int argc, char** argv)
{
    // variable declaration
    char character;
    string output, text;
    int shiftl = atoi(argv[2]); // letter shift value is 3rd argument
    int shiftd = atoi(argv[3]); // digit shift value is 4th argument    

    if (argc < 4)
    {
        cerr << "Incorrect number of arguments" << endl;
    }
    
    else if (argc == 4) // if user does not include input & output files in command, run the following
    {
        cout << "\nEnter plaintext text (no spaces): ";
        cin >> text; 

        if (argv[1][1] == 'e') //-e encryption
        {
            string encrypt = encryption(text, shiftl, shiftd);
            cout << "Encrypted text: " << encrypt << "\n" << endl;            
        }

        else if (argv[1][1] == 'd') //-d decryption
        {
            string decrypt = decryption(text, shiftl, shiftd);
            cout << "Decrypted text: " << decrypt << "\n" <<endl;      
        }
    }
    
    else
    {
        // Open input file using 5th argument
		ifstream f(argv[4]);
		string line;

        if(f.is_open())
        {
            while(getline(f, line))
            {
                for (int i = 0; i < line.length(); i++)
                {
                    character = line[i];

                    if (character >= 'A' && character <= 'Z') // check if the chars are A-Z
                    {
                        if (argv[1][1] == 'e') //-e encryption
                        {
                            character += shiftl;
                            if (character > 'Z')
                            {
                                character = character - 'Z' + 'A' - 1; //if shift = 1 .... character = 91 - 90 + 65 -1 = 65 or 'A'
                            }   
                            output += character;                                       
                        }

                        else if (argv[1][1] == 'd') //-d decryption
                        {
                            character -= shiftl;
                            if (character < 'A')
                            {
                                character = character + 'Z' - 'A' + 1; //if shift = 1 .... character = 64 + 90 - 65 +1 = 90 or 'Z'
                            }
                            output += character;                     
                        }
                    }   
                    else if (character >= 'a' && character <= 'z') // check if the chars are a-z
                    {
                        if (argv[1][1] == 'e') //-e encryption
                        {
                            character += shiftl;
                            if (character > 'z')
                            {
                                character = character - 'z' + 'a' - 1; //if shift = 1 .... character = 123 - 122 + 97 -1 or 'a'
                            }   
                            output += character;                                       
                        }

                        else if (argv[1][1] == 'd') //-d decryption
                        {
                            character -= shiftl;
                            if (character < 'a')
                            {
                                character = character + 'z' - 'a' + 1; //if shift = 1 .... character = 96 + 122 - 97 + 1 or 'z'
                            }
                            output += character;                     
                        }                         
                    }
                    else if (character >= '0' && character <= '9') // check if chars are numbers 0-9
                    {
                        if (argv[1][1] == 'e') //-e encryption
                        {
                            character += shiftd;
                            if(character > '9')
                            {
                                character = character - '9' + '0' - 1; // if shift =1 ... character = 58 - 57 + 48 - 1
                            }
                            output += character;
                        }

                        else if (argv[1][1] == 'd') //-d decryption
                        {
                            character -= shiftd;
                            if(character < '0')
                            {
                                character = character + '9' - '0' + 1; // if shift =1 ... character = 47 + 58 - 48 + 1
                            }
                            output += character;                            
                        }
                    }
                    else // for any other chars
                    {
                        output += character;
                    }
                }                  
            }
            f.close();
        }
        else
        {
            cerr << "Error oppening " << argv[4] << endl;
        }
    }

    ofstream f(argv[5]); // transfer output using 6th argument
    if (f.is_open())
    {
        f << output<<"\n";   
        f.close();
    }
    else
    {
        cerr << "Error oppening " << argv[5] << endl;
    }

    return 0;
}

