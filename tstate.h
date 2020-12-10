#ifndef TSTATE_H
#define TSTATE_H
#include <string>
#include <fstream>
#include "state.h"

class tstate
{
private:
	int max_num_state;         //максимальное количество state
	int num_state;             //  фактический номер state 
	int max_num_pstates;       // максимальное количество president state
	int num_pstate;            // фактический номер president state
	int max_num_tstates;       // максимальное количество обновлен state
	int num_tstate;            //фактический номер обновлен state
	state* states;             //массив оригинальных state
	state_status* tstates;     // массив обновлен
	president_state* pstates;  // массив president state
public:
	tstate(int max_nst,int max_pst,int max_stt);         ////конструкторы и деструкторы
	~tstate();

	void operator += (state& astate);                       // перегрузка оператора += для добавления нового
	void operator +=(const state_status& ststate); 
	void operator +=(const president_state& ptstate);
	void read_from_file(string filename);
	void write_to_file(string filename);
	void write_ststates_to_file(string filename);
	void write_pststate_to_file(string filename);
	void display();
	void Sum(string acontinent);
	void find(string lang);

};
#endif
