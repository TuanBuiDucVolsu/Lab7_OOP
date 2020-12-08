#ifndef STATE_H
#define STATE_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class state
{
private:
    string country;
    string capital;
    string government;
    string language;
    string religion;
    string continent;
    float area;
    int population;
public:
    state() : country(""), capital(""), government(""), language(""), religion(""), continent(""), area(0), population(0) {};
    state(string, string, string, string, string, string, float, int);
    virtual void read_from_file(ifstream& stream);
    virtual void write_to_file(ofstream& stream);
    virtual void display();
    string get_continent();
    string get_lang();
    string get_country();
    string get_capital();
    float get_area();
    int get_population();
};

class president_state : public state
{
private :
    string name_pre;
    int old_pre;
public:
    president_state() : state(), name_pre(""), old_pre(0) {};
    president_state(string, string , string , string , string , string , float , int , string , int );
    virtual void display();
    virtual void read_from_file(ifstream& stream);
    virtual void write_to_file(ofstream& stream);
};

class state_status : public state
{
private:
    string status;
    float GDP;
public:
    state_status() : state(), status(""), GDP(0) {};
    state_status(string, string, string, string, string, string, float, int, string, float);
    virtual void display();
    virtual void read_from_file(ifstream& stream);
    virtual void write_to_file(ofstream& stream);
    
};
#endif 

