#include <iostream>
#include <vector>
#include <ctime> // time()
#include <cstdlib> // srand(), rand()
#include <algorithm> // min_element(), max_element(), sort()
using namespace std;

class Student
{
    private:
    std::string name_;
    int number_;
    std::vector<int> grades_;
    int num_courses_;

    // You need to implement the following four methods
    static std::string gen_name() // To do
    {
        //std::srand(std::time(0)); 
        string name;
        char characters[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v',
                            'w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        const int length = 62; // length of the characters array
        int nameLength = rand() % (12 - 6 + 1) + 6; //random number of string character between 6-12

        for (int i=0; i<nameLength; i++)
        {
            name += characters[rand() % length];
        }
        return name;
    }  

    static int gen_number() // To do
    { 
        //std::srand(std::time(0)); 
        int randNum = rand()% (201600000 - 201100000 + 1) + 201100000;

        return randNum;
    }  

    static int gen_grade() // To do 
    { 
        //std::srand(std::time(0)); 
        int randGrade = rand()% (100 - 70 + 1) + 70;

        return randGrade;  
    } 

    double compute_average() // To do 
    { 
        double sum, average;

        for (int i=0; i<5; i++)
        {
            sum += grades_.at(i);
        }
        average = sum / 5;
        return average;
    } 

    public:
    Student():num_courses_(5)
    {
        name_ = gen_name();
        number_ = gen_number();

        for(int i = 0; i < num_courses_; i++)
        {
            grades_.push_back(gen_grade());
        }
    }

    Student(const std::string& name, int number) : name_(name), number_(number), num_courses_(5) // constructor
    {
        for (int i=0; i<num_courses_; ++i) 
        {
            grades_.push_back(std::rand());
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Student& s) 
    {
        os << "Name = " << s.name_ << ", Number = " << s.number_;
        return os;
    }

    void print_grades(std::ostream& os) const
    {
        for (int i=0; i<num_courses_; ++i) 
        {
            os << grades_[i] << ", ";
        }
        os << grades_[num_courses_ -1] << endl; //highest average
    }

    friend bool sortByName(Student a, Student b); 
    friend bool sortByAverage(Student a, Student b); 
};

bool sortByName(Student a, Student b)
{
    return a.name_ < b.name_; //compare names 
} 

bool sortByAverage(Student a, Student b)
{
    return a.compute_average() < b.compute_average(); //compare average
} 

bool sort(int i, int j) 
{ 
    return (i<j); 
}

int main(int argc, char** argv)
{
    vector<Student> vecStud; 

    if(argc != 2)
    {
        cout <<  "Number of students missing!"  << endl;
    }

    int studentNum = atoi(argv[1]); // convert user enter number into int

    for(int i=0; i<studentNum; i++)
    {
        Student s1;
        vecStud.push_back(s1);
    }

    cout <<  "\nStudent records: " << endl; // print student records
    for (vector<Student>::iterator xi = vecStud.begin(); xi != vecStud.end(); xi++) 
    {
        cout << *xi << endl; // print name & number
        cout << "Grades: ";
        xi->print_grades(cout); //call print grades function
    }

    cout << "\nStudent records sorted by name:" << endl; // print student records
    std::sort(vecStud.begin(), vecStud.end(), sortByName);
        
    for (vector<Student>::iterator xi = vecStud.begin(); xi != vecStud.end(); xi++) 
    {
        cout << *xi << endl; // print name & number
        cout << "Grades: ";
        xi->print_grades(cout); //call print grades function
    }

    cout << "\nStudent records sorted by average grade:" << endl; // print student records
    std::sort(vecStud.begin(), vecStud.end(), sortByAverage);

    for (vector<Student>::iterator xi = vecStud.begin(); xi != vecStud.end(); xi++) 
    {
        cout << *xi << endl; // print name & number
        cout << "Grades: ";
        xi->print_grades(cout); //call print grades function
    }

    cout << "\nStudent record with highest average grade:" << endl;

    //Get the student with the highest grade
    cout << *max_element(vecStud.begin(), vecStud.end(), sortByAverage) << endl; // print name & number
    cout << "Grades: ";
    max_element(vecStud.begin(), vecStud.end(), sortByAverage)->print_grades(cout); //call print grades function
    cout << endl;

    /*std::srand(std::time(0));

    std::vector<int> x;
    int n = 10;
    for (int i=0; i<n; ++i) 
    {
        x.push_back(std::rand());
    }

    for (std::vector<int>::iterator xi = x.begin(); xi != x.end(); xi++) 
    {
        std::cout <<  *xi << std::endl;
    }

    std::cout <<  "min value = " << *std::min_element(x.begin(), x.end()) << std::endl;
    std::cout <<  "index of min value = " << std::min_element(x.begin(), x.end()) - x.begin() << std::endl;

    std::cout <<  "max value = " << *std::max_element(x.begin(), x.end()) << std::endl;
    std::cout <<  "index of max value = " << std::max_element(x.begin(), x.end()) - x.begin() << std::endl;

    std::sort(x.begin(), x.end());
    for (std::vector<int>::iterator xi = x.begin(); xi != x.end(); xi++) 
    {
        std::cout <<  *xi << std::endl;
    }

    std::sort(x.begin(), x.end(), sort);
    for (std::vector<int>::iterator xi = x.begin(); xi != x.end(); xi++) 
    {
        std::cout <<  *xi << std::endl;
    }*/

    return 0;
}