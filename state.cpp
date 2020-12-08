#include "state.h"
#include <iostream>

using namespace std;

string state::get_continent()
{
	return continent;
}
string state::get_lang()
{
	return language;

}

string state::get_country()
{
	return country;
}
string state::get_capital()
{
	return capital;
}
float state::get_area()
{
	return area;
}
int state::get_population()
{
	return population;
}

state::state(string cou, string cap, string gov, string lag, string rel, string con, float are, int pop)
{
	country = cou;
	capital = cap;
	government = gov;
	language = lag;
	religion = rel;
	continent = con;
	area = are;
	population = pop;
	cout << "\nClass constructor called state";
}


void state::read_from_file(ifstream& stream)
{
	getline(stream, country);
	getline(stream, capital);
	getline(stream, government);
	getline(stream, language);
	getline(stream, religion);
	getline(stream, continent);
	stream >> area;
	stream >> population;
	stream.get();
}

void state::write_to_file(ofstream& stream)
{
	stream << country << endl;
	stream << capital << endl;
	stream << government << endl;
	stream << language << endl;
	stream << religion << endl;
	stream << continent << endl;
	stream << area << endl;
	stream << population << endl;

}

void state::display()
{
	cout << "\n-----------##------------";
	cout << "\nCountry : " << country << endl;
	cout << "\nCapital : " << capital << endl;
	cout << "\nGoverment : " << government << endl;
	cout << "\nLanguage : " << language << endl;
	cout << "\nReligion : " << religion << endl;
	cout << "\nArea : " << area << endl;
	cout << "\nPopulation : " << population << endl;
	
}


president_state::president_state(string cou, string cap, string gov, string lag, string rel, string con, float are, int pop, string name, int old) :
	state(cou, cap, gov, lag, rel, con, are, pop), name_pre(name), old_pre(old)
{
	cout << "\nClass constructor called president_state";
}
void president_state::read_from_file(ifstream& stream)
{
	getline(stream, name_pre);
	stream >> old_pre;
	stream.get();
}
void president_state::write_to_file(ofstream& stream)
{
	stream << name_pre << endl;
	stream << old_pre << endl;
	

}
void president_state::display()
{
	state::display();
	cout << "\nName President : " << name_pre << endl;
	cout << "\nPresident Old : " << old_pre << endl;
	
}
state_status::state_status(string cou, string cap, string gov, string lag, string rel, string con, float are, int pop, string stt, float gdp) :
	state(cou, cap, gov, lag, rel, con, are, pop), status(stt), GDP(gdp)
{
	cout << "\nClass constructor called state_status";
}

void state_status::read_from_file(ifstream& stream)
{
	getline(stream, status);
	stream >> GDP;
	stream.get();
}
void state_status::write_to_file(ofstream& stream)
{
	stream << status << endl;
	stream << GDP << endl;

}
void state_status::display()
{
	state::display();
	cout << "\nState status : " << status << endl;
	cout << "\nGDP state : " << GDP << endl;
	
}

