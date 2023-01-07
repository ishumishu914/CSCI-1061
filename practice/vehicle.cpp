#include <fstream>
#include <iostream>
using namespace std;

struct vehicle
{
    int wheels, horsepower;
    double max_speed;
};
int main()
{
    ifstream f("vehicle.bin", ios::binary);
    vehicle v;
    
    f.read((char*) &v, sizeof(vehicle));

    f.read((char*) &v.wheels, sizeof(v.wheels));
    f.read((char*) &v.horsepower, sizeof(v.horsepower));
    f.read((char*) &v.max_speed, sizeof(v.max_speed));
    f.close();

    cout << v.wheels << " " << v.horsepower << " "<< v.max_speed;

    return 0;
}