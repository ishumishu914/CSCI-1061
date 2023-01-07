#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    /*int size;
    double* a = new double[size];

    ifstream f("exercise-data.bin", ios::binary);
    //if (f.is_open())
    //{
        
        f.read((char*)&size, sizeof(int));

        f.read((char*)a, sizeof(double)*size);
        
    //}
    //double min = a[0];
    for(int i=1; i<size; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        } 
        cout << a[i] << endl;
               
    }
    //cout<<"min: "<<min<<endl;

    delete[] a;
    f.close();*/
    
    //option 1
    /*std::ifstream f("exercise-data.bin", std::ios::binary);
    int size;
    f.read((char*) &size, sizeof(int));

    double* a = new double[size];
    f.read((char*) a, sizeof(double)*size);
    f.close();

    double min = a[0]; 
    for (int i=1; i<size; ++i) {
        if (a[i]<min) { min = a[i]; }
    }
    std::cout << min << std::endl;

    delete[] a;

    //option 2
    std::ifstream reader("exercise-data.bin", std::ios::binary);
    int toRead;
    double min = 0;
    reader.read((char*)&toRead, sizeof(int));
    std::cout << "Number of doubles: " << toRead << std::endl;

    double current;
    reader.read((char*)&min, sizeof(double));
    for (int i = 0; i < toRead; ++i)
    {
        reader.read((char*)&current, sizeof(double));
        if (current < min)
        {
            min = current;
        }
    }
    reader.close();

    std::cout << "Minimum is " << min << std::endl;*/

    //midterm 1
    /*ifstream f("numbers_100.bin", ios::binary);

    double* a = new double[100];
    f.read((char*)a, sizeof(double)*100);
    f.close();

    double sum=0;
    for(int i=0; i<100; i++)
    {
        sum += a[i];
    }

    double average = sum/100;
    cout<<"avg is: " << average << endl;*/

    ofstream f("data", ios::binary);

    if(f.is_open())
    {
        //double* a = new double[100];
        double a=0.0;
        for(int i=0; i<100; i++)
        {
            f.write((char*)&a, sizeof(double));
            a++;
        }
        f.close();
    }

    ifstream f2("data", ios::binary);
    if(f2.is_open())
    {
        int v;
        f2.seekg(sizeof(int)*49, ios::beg);
        f2.read((char*)&v, sizeof(int));

        if(!f2.fail())
        {
            cout << v << endl;
        }
    }

    /*ifstream f("data.bin", ios::binary);
    if(f.is_open())
    {
        f.seekg(sizeof(double)*31, ios::beg);
        cout << f.tellg() <<endl;
    }*/
    //create the data.bin in workspace first

    return 0;
}