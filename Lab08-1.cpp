#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Stats
{
    private:
    vector<T> _data;

    public:
    Stats (T const data[], int size)
    {
        for (int i=0; i<size; i++)
        {
            _data.push_back(data[i]);
        }
    }
    ~Stats() {};

    void add(T value)
    {
        _data.push_back(value);
    }

    double average()
    {
        double sum=0, average;

        for (int i=0; i< _data.size(); i++)
        {
            sum += _data[i];
        }
        average = sum / _data.size();

        return average;
    }

    T min()
    {
        T min = _data[0];

        for (int i=1; i<_data.size(); i++)
        {
            if (_data[i] < min)
            {
                min = _data[i];
            }
        }
        return min;
    }

    T max()
    {
        T max = _data[0];

        for (int i=1; i<_data.size(); i++)
        {
            if (_data[i] > max)
            {
                max = _data[i];
            }
        }
        return max;
    }
};

int main() 
{
    cout << "Example 1:" << endl;
    Stats<short> s1 = Stats<short>((const short[]){1, 2, 3, 4, 5}, 5);
    s1.add(6);

    cout << "shorts average: " << s1.average() << endl;
    cout << "shorts min: " << s1.min() << endl;
    cout << "shorts max: " << s1.max() << endl;

    cout << "\nExample 2:" << endl;
    Stats<int> s2 = Stats<int>((const int[]){12, 32, 53, 4, 42}, 5);
    s2.add(56);

    cout << "int average: " << s2.average() << endl;
    cout << "int min: " << s2.min() << endl;
    cout << "int max: " << s2.max() << endl;

    cout << "\nExample 3:" << endl;
    Stats<double> s3 = Stats<double>((const double[]){10.9, 82.0, 63.1, 45.2, 59.6}, 5);
    s3.add(12.5);

    cout << "double average: " << s3.average() << endl;
    cout << "double min: " << s3.min() << endl;
    cout << "double max: " << s3.max() << endl;

    return 0;
}