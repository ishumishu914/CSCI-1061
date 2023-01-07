#include <iostream> 
#include <fstream>
#include <string>
using namespace std; 

int main(int argc, char** argv)
{
    // variable declaration
    char character;
    string output;

    if (argc != 5)
    {
        cerr << "Incorrect number of arguments" << endl;
    }
    else
    {
        int shift = atoi(argv[2]); //shift value is 3rd argument

        // Open input file using 4th argument
		ifstream f(argv[3]);
		string line;

        if(f.is_open())
        {
            while(getline(f, line))
            {
                for (int i = 0; i < line.length(); i++)
                {
                    character = line[i];

                    if (character >= 'A' && character <= 'Z') // check if the characteracters are A-Z
                    {
                        if (argv[1][1] == 'e') //-e encryption          // argv[1] == '-e' also works 
                        {
                            character += shift;
                            if (character > 'Z')
                            {
                                character = character - 'Z' + 'A' - 1; //if shift = 1 .... character = 91 - 90 + 65 -1 = 65 or 'A'
                            }   
                            output += character;                                       
                        }

                        else if (argv[1][1] == 'd') //-d decryption     // argv[1] == '-d' also works 
                        {
                            character -= shift;
                            if (character < 'A')
                            {
                                character = character + 'Z' - 'A' + 1; //if shift = 1 .... character = 64 + 90 - 65 +1 = 90 or 'Z'
                            }
                            output += character;                     
                        }
                         
                    }
                    else // for numbers and/or any other characteracters
                    {
                        output += character;
                    }                    
                } 
            }
            f.close();
        }
        else
        {
            cerr << "Error oppening " << argv[3] << endl;
        }
    }

    ofstream f(argv[4]); // transfer output using 5th argument
    if (f.is_open())
    {
        f << output<<"\n";   
        f.close();
    }
    else
    {
        cerr << "Error oppening " << argv[4] << endl;
    }

    return 0;
}