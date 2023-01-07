#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

struct Counts
{
    int LineCount, WordCount, ByteCount;
};

int main(int argc, char** argv)
{
    // variable declaration
    int lineCount1 = 0, lineCount2 = 0;
    int WhiteSpace1 = 0, WhiteSpace2 = 0; 
    int filesize1, filesize2;

    if (argc != 3)
    {
        cerr << "Incorrect number of arguments" << endl;
    }
    else
    {
        // Open input file using 2nd argument
		ifstream f1(argv[1]);
        ifstream f2(argv[2]);
        string line1,line2;

        if(f1.is_open())
        { 
            while(getline(f1, line1))
            {
                lineCount1++; //count number of lines
              
                //split text into words
                for(int i = 0; i < line1.length(); i++)
                {
                    if(iswspace(line1[i])) // count frequency of whitespace, which also gives frequency of words
                    {
                        WhiteSpace1++;
                    } 
                }
                if (f1.eof())
                {        
                    //read file size by reading the position of end of file
                    f1.seekg(0, ios::end);
                    filesize1 = f1.tellg();                  
                } 
                               
            }   
            f1.close();
        }

        if(f2.is_open())
        { 
            while(getline(f2, line2))
            {
                lineCount2++; //count number of lines
              
                //split text into words
                for(int i = 0; i < line2.length(); i++)
                {
                    if(iswspace(line2[i])) // count frequency of whitespace, which also gives frequency of words
                    {
                        WhiteSpace2++;
                    } 
                }
                if (f2.eof())
                {        
                    //read file size by reading the position of end of file
                    f2.seekg(0, ios::end);
                    filesize2 = f2.tellg();                  
                }                
            }   
            f2.close();
        }
    }

    Counts f1 = {lineCount1, WhiteSpace1, filesize1};
    Counts f2 = {lineCount2, WhiteSpace2, filesize2};
    Counts total = {lineCount1 + lineCount2, WhiteSpace1 + WhiteSpace2, filesize1 + filesize2};

    cout << f1.LineCount << "\t" << f1.WordCount << "\t" << f1.ByteCount << "\t" << argv[1] << endl;
    cout << f2.LineCount << "\t" << f2.WordCount << "\t" << f2.ByteCount << "\t" << argv[2] << endl;
    cout << total.LineCount << "\t" << total.WordCount << "\t" << total.ByteCount << "\ttotal" << endl;

    return 0;
}