#include<iostream>
#include<vector>
using namespace std;
class Shape{
protected:
    double area;
    double perimeter;
public:
Shape(double area,double perimeter): 
area(area),perimeter(perimeter){};
virtual double calculate_area()=0;
virtual double calculate_perimeter()=0;
void print_area(){
    cout<<"\nArea = "<<area;
}
void print_perimeter(){
    cout<<"\nPerimeter ="<<perimeter;
}
};
class Polygon: public Shape{
private:
int number_of_sides;
protected:
vector<double> sides;
public:
Polygon(double area,double perimeter,int number_of_sides,vector<double>sides):
Shape(area,perimeter),number_of_sides(number_of_sides), sides(sides){};
double calculate_perimeter()override{
    double P=0;
    for (int i=0;i<number_of_sides;i++){
        P+=sides[i];
    }
    return P;
}
void get_perimeter(){
    this->perimeter=calculate_perimeter();
}
void get_sides(){
    vector<double> dummy;
    double side;
    for (int i=0;i<number_of_sides;i++){
        cout<<"\nEnter a side at a time:";
        cin>>side;
        dummy.push_back(side);
    }
    this->sides=dummy;
};
void get_number_of_sides(int number_of_sides){
    this->number_of_sides=number_of_sides;
}
};
class Square: public Polygon{
public:
Square(double area=1,double perimeter=1,int number_of_sides=4,vector<double>sides={1,1,1,1}):
Polygon(area, perimeter,number_of_sides, sides){};
double calculate_area()override{
    double A = sides[0]*sides[0];
    return A;
}
void get_area(){
    this->area=calculate_area();
}
};
int main(){
Square small_square;
small_square.get_sides();
small_square.get_area();
small_square.get_perimeter();
small_square.print_area();
small_square.print_perimeter();
}