#include<iostream>
using namespace std;
class Rectangle {
private:
double width;
double length;
public:
Rectangle(
    double width = 4,
    double length = 5.0): 
    width(width),length(length){}
void set_width(double width){
    this->width = width;
}
void set_length(double length){
    this ->length = length;
}
double Perimeter(){
   return 2*(width+length);
}
double Area(){
    return width*length;
}
double get_length(){
    return length;
}
double get_width(){
    return width;
}
};
int main(){
    Rectangle small_Rectangle;
    small_Rectangle.set_length(1.2);
    small_Rectangle.set_width(2.0);
    cout<<"\nA rectangle of length "<<small_Rectangle.get_length();
    cout<<" and width "<<small_Rectangle.get_width()<<
    " has an area of "<<small_Rectangle.Area()<<" and perimeter "
    <<small_Rectangle.Perimeter();
    Rectangle userDefined;
    double L,W;
    cout<<"\nEnter the length and width of the rectangle of choice: ";
    cin>> L>>W;
    userDefined.set_length(L);
    userDefined.set_width(W);
    cout<<"\nA rectangle of length "<<userDefined.get_length();
    cout<<" and width "<<userDefined.get_width()<<
    " has an area of "<<userDefined.Area()<<" and perimeter "
    <<userDefined.Perimeter();
}