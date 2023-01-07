#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Filter
{
    protected:
    string _name;

    public:  
    Filter(const string& name) : _name(name) {}
    virtual ~Filter() {};

    virtual string apply(const string& input) = 0;

    string get_name() { return _name; }
};

class Capitalize: public Filter
{
    public:
    Capitalize() : Filter("Capitalize") {} //constructor
    Capitalize(const string& name) : Filter(name) {} //copy constructor
    ~Capitalize() {} //destructor
    string apply(const string& input);
};

// Capitalize every letter
string Capitalize::apply(const string& input)
{
    string capital;
    
    for (int i = 0; i < input.length(); i++)
    {
        if (i != ' ') //as long a whitespace isn't encountered capitalize all letters
        {
            capital += toupper(input[i]);
        }
        else
        {
            capital += input[i]; // if i == ' ' then add the space into string capital
        }
    }
    return capital;
}

class CapitalizeFirstLetter: public Filter
{
    public:
    CapitalizeFirstLetter() : Filter("CapitalizeFirstLetter") {} //constructor
    CapitalizeFirstLetter(const string& name) : Filter(name) {} //copy constructor
    ~CapitalizeFirstLetter() {} //destructor
    string apply(const string& input);
};

// capitalize first letter only, keep rest as it is
string CapitalizeFirstLetter::apply(const string& input)
{
    /* OR string output = input;
          output[0] = toupper(input[0]); */

    string output; 
    output = toupper(input[0]); // capitalize 1st letter only

    for (int i=1; i<input.length(); i++)
    {
        output += input[i]; //add the rest of the input string as it is
    }
    return output;
}

class CapitalizeFirstLetterOfEveryWord: public Filter
{
    public:
    CapitalizeFirstLetterOfEveryWord() : Filter("CapitalizeFirstLetterOfEveryWord") {} //constructor
    CapitalizeFirstLetterOfEveryWord(const string& name) : Filter(name) {} //copy constructor
    ~CapitalizeFirstLetterOfEveryWord() {} //destructor
    string apply(const string& input);
};

string CapitalizeFirstLetterOfEveryWord::apply(const string& input)
{
    string output = input;

    for (int i=0; i<input.length(); i++)
    {
        if (i == 0)
        {
            output[i] = toupper(input[i]); // capitalize 1st letter
        }
        else if (input[i-1] == ' ')
        {
            output[i] = toupper(input[i]); // if there is a whitespace before a letter, capitalize the letter
        }
    }
    return output;
}

class Obenglobish: public Filter
{
    public:
    Obenglobish() : Filter("Obenglobish") {} //constructor
    Obenglobish(const string& name) : Filter(name) {} //copy constructor
    ~Obenglobish() {} //destructor
    string apply(const string& input);
};

bool isVowel(char vowel)
{
    return (vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u' 
            || vowel == 'A' || vowel == 'E' || vowel == 'I' || vowel == 'O' || vowel == 'U');
}

string Obenglobish::apply(const string& input) 
{
    string output, ob = "ob";

    for (int i=0; i<input.length(); i++)
    {
        if (isVowel(input[i]) == true)
        {
            output = output + ob + input[i]; // if the letter is a vowel, add the previous consonant portion of input, "ob" and current letter to output
        }
        else
        {
            output += input[i]; // if letter is a consonant add to output as it is
        }
    }
    return output;
}

class ReverseString: public Filter
{
    public:
    ReverseString() : Filter("ReverseString") {} //constructor
    ReverseString(const string& name) : Filter(name) {} //copy constructor
    ~ReverseString() {} //destructor
    string apply(const string& input);
};

string ReverseString::apply(const string& input)
{
    string output;

    for(int i = input.length()-1; i>=0; i--)
    {
        output += input[i]; // starting from rightmost index, put each character to output string in decreaseing order of index
    }
    return output;
}

class ToSmall: public Filter
{
    public:
    ToSmall() : Filter("ToSmall") {} //constructor
    ToSmall(const string& name) : Filter(name) {} //copy constructor
    ~ToSmall() {} //destructor
    string apply(const string& input);
};

// make every letter lower case
string ToSmall::apply(const string& input)
{
    string lower;
    
    for (int i = 0; i < input.length(); i++)
    {
        if (i != ' ')
        {
            lower += tolower(input[i]); //as long a whitespace isn't encountered lower case all letters
        }
        else
        {
            lower += input[i]; //otherwise add current character as it is to output string
        }
    }
    return lower;
}

class Randomize: public Filter
{
    public:
    Randomize() : Filter("Randomize") {} //constructor
    Randomize(const string& name) : Filter(name) {} //copy constructor
    ~Randomize() {} //destructor
    string apply(const string& input);
};

string Randomize::apply(const string& input)
{
    srand(time(NULL));
    string output("");
    vector<int> set;

    for (int i=0; i<input.length(); i++)
    {
        if (input[i] != ' ')
        {
            set.push_back(i);
        }
    }

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ')
        {
            output += " ";
        }
        else
        {
            int position = rand() % set.size();
            int x = set[position];
            set.erase(set.begin() + position);
            output += input[x];
        }         
    }
    return output;
}

int main()
{
    const int num_filters = 7;
    Filter* filters[num_filters];

    filters[0] = new Capitalize();
    filters[1] = new CapitalizeFirstLetter();
    filters[2] = new CapitalizeFirstLetterOfEveryWord();
    filters[3] = new Obenglobish();
    filters[4] = new ReverseString();
    filters[5] = new ToSmall();
    filters[6] = new Randomize();
    
    string input;
    cout << "Enter string: ";  getline(cin, input);
    
    cout << "Input string: " << input << endl;
    for (int i=0; i<num_filters; ++i) 
    {
        cout << "Filter name:  " << filters[i]->get_name() << endl;
        cout << "Output:       " << filters[i]->apply(input) << endl; 
    }

    for (int i=0; i<num_filters; ++i) delete filters[i];
    return 0;
}