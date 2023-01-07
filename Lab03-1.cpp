#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main(int argc, char** argv)
{
    // variable declaration
    int lineCount = 0;
    int WhiteSpace = 0; 
    int filesize;

    if (argc != 2)
    {
        cerr << "Incorrect number of arguments" << endl;
    }
    else
    {
        // Open input file using 2nd argument
		ifstream f(argv[1]);
		string line; 

        if(f.is_open())
        {      
            while(getline(f, line))
            {
                lineCount++; //count number of lines
          
                //split text into words
                for(int i = 0; i < line.length(); i++)
                {
                    if(iswspace(line[i])) // count frequency of whitespace, which also gives frequency of words
                    {
                        WhiteSpace++;
                    } 
                }
                if (f.eof())
                {        
                    //read file size by reading the position of end of file
                    f.seekg(0, ios::end);
                    filesize = f.tellg();                  
                }                
            } 
            f.close();
        }
    }
  
    //cout << "# of lines: " << lineCount << "\t # of words: " << WhiteSpace << "\t# of bytes: " << filesize << "\t" << argv[1] << endl;
    cout << lineCount << "\t" << WhiteSpace << "\t" << filesize << "\t" << argv[1] << endl;
    
    return 0;
}