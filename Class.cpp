#include <iostream>
using namespace std;

struct Teacher {
string name;
int age;
};

struct Database{
Teacher* teachers = new Teacher[20];
int number_of_teachers = 0;
//constructor
/*Database(){
number_of_teachers = 0;
}
Database(int n){
    number_of_teachers = n;
}*/
//member functions
void signup(){
    Teacher t;
    string _name;
    int _age;
    cout<<"Enter your name: ";
    cin>>_name;

    cout<<"Enter  your age: ";
    cin>>_age;

    teachers[number_of_teachers] = {_name, _age};
    number_of_teachers++;
}
};
int main(){

    return 0;
}
