#include <iostream>
#include<unordered_map>
using namespace std;
class HashFu;

class Student{
    string name;
    int age;
    int roll;
    friend class HashFu;
  public:
    Student(const string &s, const int &a, const int &r){
        name = s;
        age = a;
        roll = r;
    }

    bool operator == (const Student &other) const{
        return roll==other.roll;
    }
    friend ostream & operator << (ostream&, const Student&);

};

ostream & operator << (ostream &o, const Student &s) {
        o<<"roll no : "<<s.roll<<"\n";
        o<<"   name : "<<s.name<<"\n";
        o<<"   age : "<<s.age<<"\n";
        o<<"   marks : ";
        return o;
 
} 

class HashFu{
public:
   size_t operator()(const Student &s) const{
       return s.name.length()^s.age^s.roll;
   }
};

int main() {
    unordered_map<Student, int, HashFu> slist;
    int n;
    cin>>n;
    string name;
    int roll, age, marks;
    for (int i=0; i<n; i++){
        cin>>name>>age>>roll>>marks;
        Student s(name, age, roll);
        slist[s] = marks;
    }
    for (auto i: slist){
        cout<<i.first;
        cout<<i.second<<'\n';

    }
}
