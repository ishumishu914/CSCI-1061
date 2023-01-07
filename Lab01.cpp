#include <iostream>
#include <ctime>
using namespace std;

const int N = 120;

char generate_random_char()
{
    int i = 26.0 * rand() / RAND_MAX;

    if (static_cast<double>( rand() ) / RAND_MAX  < 0.5) 
    {
        return static_cast<char>( 65+i );
    }
    
    return static_cast<char>( 97+i );
}

int main()
{
    srand(time(0));

    // Set up an array of characters
    char arr[N];
    for (int i=0; i<N; ++i) 
    {
        arr[i] = generate_random_char();
    }

    // Printing the contents of the input array
    cout << "Input array:" << endl;
    for (int i = 0; i<N; ++i) 
    {
        cout << arr[i];
    }
    cout << endl;

    /* TO DO: Complete the following to get the output seen above.
    Notice that the characters consists of both lowercase and uppercase letters. 
    For the purposes of counting, treat all letters as uppercase letters. */

    int temp, alphabetCount[26] = {0};

    for (int i = 0; i < N;)
    {
        while (toupper(arr[i]) != '\00') // '00'= NULL char
        {
            int k = (static_cast<int>(toupper(arr[i]))); // type conversion to ASCII numeric representation 

            if (k >= 65 && k <= 90) // 65 = char A    90 = char Z
            {
                temp = k - 65; // identifying specific character between A-Z
                alphabetCount[temp]++; // counter increment for character frequency
            }
            i++;
        }        
    }

    cout << "\nCounts:" << endl;

    for (int i = 0; i < 26; i++)
    {
        cout << char(65 + i) <<": " << alphabetCount[i] << endl; /* char(65 + i): prints all characters A-Z in alphabetical order 
                                                                alphabetCount[i]: prints counter frequency corresponding to each 
                                                                characters from alphabetCount array */
    }   

    cout << "Total number of characters: " << N << endl;
    return 0;

    /*bool checked[N] = {false};
    cout << "\nCounts:" << endl;

    for (int i = 0; i < N; i++)
    {
        if (checked[i] == true) 
        {
            continue; 
        }
            
        int count = 0;
        for (int j=i; j<N; j++)
        {
            if(toupper(arr[i]) == toupper(arr[j]))
            {
                checked[j] = true;
                count++;
            }
        }
        char output = toupper(arr[i]);
        cout << output << ": " << count << endl;    
    }*/

    /*int j, alphabetCount[26] = {0};

    for (int i = 0; i < N;)
    {
        while (toupper(arr[i]) != '\00') // '\00'= NULL char
        {
            if (toupper(arr[i]) >= 'A' && toupper(arr[i]) <= 'Z') 
            {
                j = toupper(arr[i]) - 'A';
                alphabetCount[j]++;
            }
            i++;
        }        
    }

    cout << "\nCounts:" << endl;

    for (int i = 0; i < 26; i++)
    {
        cout << char('A' + i) <<": " << alphabetCount[i] << endl;
    } */

}