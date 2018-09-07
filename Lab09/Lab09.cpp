#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

class Person{
  private:
     string name;
     int age;
     string homeCity;
  public:   
     Person( string name, int age, string homeCity ) 
          : name( name )
          , age( age )
          , homeCity( homeCity ){
              
     }
     virtual ~Person(){
     }
     string getName(){
          return this->name;
     }
     int getAge(){
          return this->age;
     }
     string getHomeCity(){
          return this->homeCity;
     }
     void setName( string newName ){
          name = newName;
     }
     void setAge( int newAge ){
          age = newAge;
     }
     void setHomeCity( string newHomeCity ){
          homeCity = newHomeCity;
     }
     virtual void print(){
         cout << getName() << endl;
         cout << "\t Age: " << getAge() << endl;
         cout << "\t Homecity: " << getHomeCity() << endl;
     }
};

class Student : public Person{
  private:
     string school;
     int classYear;
     double gradDate;
     vector<string> skills;
  public:
     Student( string name, int age, string homeCity,
              string school, int classYear, double gradDate )
            : Person( name, age, homeCity ),
              school( school ),
              classYear( classYear ),
              gradDate( gradDate ){
     }
     ~Student(){
     }
     string getSchool(){
              return this->school;
     }
     int getClassYear(){
              return this->classYear;
     }
     double getGradDate(){
              return this->gradDate;
     }
     vector<string> getSkills(){
              return this->skills;
     }
     void setSchool( string newSchool ){
              school = newSchool;
     }
     void setClassYear( int newClassYear ){
              classYear = newClassYear;
     }
     void setGradDate( double newGradDate ){
              gradDate = newGradDate;
     }
     void addSkill( string newSkill ){
              skills.push_back( newSkill );
     }
     virtual void print(){
         cout << getName() << endl;
         cout << "\t Age: " << getAge() << endl;
         cout << "\t Homecity: " << getHomeCity() << endl;
         cout << "\t \t School: " << getSchool() << endl;
         cout << "\t \t Class year: " << getClassYear() << endl;
         cout << "\t \t Grad date: " << getGradDate() << endl;
         cout << "\t \t Skills: ";
         for( int i = 0; i < getSkills().size(); i++ ){
             cout << getSkills().at( i ) << ", "; 
         }
         cout << endl;
     }
};

class Intern : public Student{
  private:
     string company;
     double pay;
     double endDate;
  public:
     Intern(string name, int age, string homeCity,
            string school, int classYear, double gradDate,
            string company, double pay, double endDate )
            : Student( name, age, homeCity, school, classYear, gradDate ),
              company( company ),
              pay( pay ),
              endDate( endDate ){
     }
     ~Intern(){
     }
     string getCompany(){
         return this->company;
     }
     double getPay(){
         return this->pay;
     }
     double getEndDate(){
         return this->endDate;
     }
     void setCompany( string newCompany ){
         company = newCompany;
     }
     void setPay( double newPay ){
         pay = newPay;
     }
     void setEndDate( double newEndDate ){
         endDate = newEndDate;
     }
     void print(){
         cout << getName() << endl;
         cout << "\t Age: " << getAge() << endl;
         cout << "\t Homecity: " << getHomeCity() << endl;
         cout << "\t \t School: " << getSchool() << endl;
         cout << "\t \t Class year: " << getClassYear() << endl;
         cout << "\t \t Grad date: " << getGradDate() << endl;
         cout << "\t \t Skills: ";
         for( int i = 0; i < getSkills().size(); i++ ){
             cout << getSkills().at( i ) << ", "; 
         }
         cout << endl;
         cout << "\t \t \t Company: " << getCompany() << endl;
         cout << "\t \t \t Hourly pay: " << getPay() << endl;
         cout << "\t \t \t End date: " << getEndDate() << endl;
     }
};

int main(){

     Person *ppl = new Person( "Prof Carpenter", 103, "Badlands - TrumpTownUSA" );
     Student *stu = new Student( "Matt Bennett", 5, "LandOfShouldveAppliedAlready",
                                "WIT", 3, 2300.08 );
    
     Intern *job = new Intern( "Mr. Got it Together", 25, "RealityTown",
                             "WIT", 4, 2250.08, 
                             "ExchangesGood&ServicesFor$$$.Co",
                             100.00, 2300.01);
     stu->addSkill( "Unemployment" );
     stu->addSkill( "Random useless factoids" );
     stu->addSkill( "Being unfashionably late");
     stu->addSkill( "Putting foot in mouth at important times disorder");
     job->addSkill( "Having a job" );
     job->addSkill( "Knowing useful things" );
     job->addSkill( "Being on time" );
     ppl->print();
     stu->print();
     job->print();
     return 0;
}

#endif
