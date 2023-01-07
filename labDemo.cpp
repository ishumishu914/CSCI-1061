#include <iostream>
using namespace std;

template<typename T>
struct Item{
    T _data;
    Item(T newdata){
        _data = newdata;
    }
};

template<typename T>
class Calculation{
    private:
        Item<T>* itemPtr1;
        Item<T>* itemPtr2;
    public:
        Calculation(T value1, T value2){
            itemPtr1 = new Item<T>(value1);
            itemPtr2 = new Item<T>(value2);
        }
        T add(){
            return itemPtr1->_data + itemPtr2->_data;
        }
};

int main(){
    Calculation<int> intCalc = Calculation<int>(1,2);
    Calculation<string> strCalc = Calculation<string>("hello"," goodbye");
    Calculation<double> doubleCalc = Calculation<double>(2.32,1.01);
    cout << "int addition: " << intCalc.add() << endl; //3
    cout << "string addition: " << strCalc.add() << endl; //hello goodbye
    cout << "double addition: " << doubleCalc.add() << endl; //3.33
}