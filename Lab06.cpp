#include <iostream>
using namespace std;

class Point
{
    public:
    int x, y;

    Point() {}
    Point(int x, int y) { this->x = x; this->y = y;}
    
    friend ostream& operator<<(ostream& os, const Point& pt) 
    {
        os << "(" << pt.x << ", " << pt.y << ")";
        return os;
    }
};

class Shape
{
    // FEEL FREE TO CHANGE THE THIS CLASS
    // AS LONG AS YOU DON'T HAVE TO CHANGE THE
    // CONTENTS OF MAIN() AND 
    // PRINT_SHAPES() FUNCTIONS

    protected:
    Point _location;

    public:
    // constructors 
    Shape() {} 
    Shape(const Point& location) : _location(location) {} //initializer
    ~Shape() {} // destructor
    
    virtual void draw() //virtual function to be overwritten by Triangle/Circle class
    {
        cout << "location: " << _location << endl;
    }
    
    virtual void get_info_from_user() //virtual function to be overwritten by Triangle/Circle class
    {
        cout << "Enter position: ";
        cin >> _location.x >> _location.y;
    }
};

// YOU NEED TO COMPLETE THIS CLASS
class Triangle: public Shape
{
    protected:
    int _width, _height;

    public:
    // constructors 
    Triangle() {}
    Triangle(const Triangle& tri): Shape(), _width(tri._width), _height(tri._height) {} //initializer

    void get_info_from_user()
    {
        Shape::get_info_from_user(); // use the function from Shape class
        cout << "Enter width and height: ";
        cin >> _width >> _height;
    }
    void draw() // overwrites draw() in Shape class
    {
        cout << "\tTriangle" << endl;
        cout << "\tlocation: " << _location << endl;
        cout << "\twidth and height: (" << _width << ", " << _height<< ")" << endl;
    }

};

// YOU NEED TO COMPLETE THIS CLASS
class Circle: public Shape
{
    protected:
    int _radius;

    public:
    // constructors 
    Circle() {}
    Circle(const Circle& cir): Shape(), _radius(cir._radius) {} //initializer

    void get_info_from_user()
    {
        Shape::get_info_from_user(); // use the function from Shape class
        cout << "Enter radius: ";
        cin >> _radius;
    }
    void draw() // overwrites draw() in Shape class
    {
        cout << "\tCircle" << endl;
        cout << "\tlocation: " << _location << endl;
        cout << "\tradius: (" << _radius << ")" << endl;
    }
};

// DO NOT CHANGE CODE BELOW THIS LINE

#define MAX_SHAPES 10

void print_shapes(Shape** shapes, int n)
{
    for (int i=0; i<n; ++i) 
    {
        cout << "[" << i << "] "; 
        shapes[i]->draw();
    }
}

int main()
{
    Shape* shapes[MAX_SHAPES];

    int n = 0;
    char shape_choice;
    do 
    {
        cout << "Choose a shape to add" << endl;
        cout << "\t(a) for triangle" << endl;
        cout << "\t(b) for circle" << endl;
        cout << "\t(p) to print the shapes" << endl;
        cout << "\t(0-9) to modify a shape" << endl;
        cout << "\t(q) to exit" << endl;
        cout << ": ";
        cin >> shape_choice;

        if (shape_choice == 'q') break;
        
        switch(shape_choice)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                shapes[((int) shape_choice) - 48]->get_info_from_user();
            break;

            case 'a':
                if (n >=  MAX_SHAPES) 
                {
                    cout << "== Cannot add any more shapes ==" << endl;
                    continue;
                }      
                cout << "== You selected a triangle. ==" << endl;
                shapes[n] = new Triangle();
                shapes[n]->get_info_from_user();
                ++n;
            break;

            case 'b':
                if (n >=  MAX_SHAPES) 
                {
                    cout << "== Cannot add any more shapes ==" << endl;
                    continue;
                }
                cout << "== You selected a circle. ==" << endl;
                shapes[n] = new Circle();
                shapes[n]->get_info_from_user();
                ++n;     
            break;

            case 'p':
                print_shapes(shapes, n);
            break;

            case 'q':
            break;

            default:
                cerr << "== Invalid choice ==" << endl;
            break;
        }
    } while (true);

    for (int i=0; i<n; ++i) delete shapes[i];
}