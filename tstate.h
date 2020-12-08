#ifndef TSTATE_H
#define TSTATE_H
#include <string>
#include <fstream>
#include "state.h"

class tstate
{
private:
	int max_num_state;
	int num_state;
	int max_num_pstates;
	int num_pstate;
	int max_num_tstates;
	int num_tstate;
	state* states;
	state_status* tstates;
	president_state* pstates;
public:
	tstate(int max_nst,int max_pst,int max_stt);
	~tstate();

	void operator += (state& astate);
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
