#include <iostream>
#include "tstate.h"

using namespace std;

tstate::tstate(int max_nst, int max_pst, int max_stt)
{
	max_num_state = max_nst;
	max_num_pstates = max_pst;
	max_num_tstates = max_stt;
	states = new state[max_num_state];
	pstates = new president_state[max_num_pstates];
	tstates = new state_status[max_num_tstates];

	num_state = 0;
	num_pstate = 0;
	num_tstate = 0;
	cout << "\nThe constructor of the tstate class is called:";
	cout << "\n selected objects - " << max_num_state;
	cout << "\n loaded state - " << num_state << endl;
}

tstate::~tstate()
{
	max_num_state = 0;
	delete[] states;
	num_state = 0;
	max_num_tstates = 0;
	delete[] tstates;
	num_tstate = 0;
	max_num_pstates = 0;
	delete[] pstates;
	num_pstate = 0;
	cout << "\nThe destructor of the tstate class is called:";
	cout << "\n allocated memory is freed";
}

void tstate::operator+=(state& ostate)
{
	if (num_state < max_num_state)
	{
		states[num_state] = ostate;
		num_state++;
	}
}

void tstate::operator +=(const state_status& ststate)
{
	if (num_tstate < max_num_tstates)
	{
		tstates[num_tstate] = ststate;
		num_tstate++;
	}
}

void tstate::operator +=(const president_state& ptstate)
{
	if (num_pstate < max_num_pstates)
	{
		pstates[num_pstate] = ptstate;
		num_pstate++;
	}
}


void tstate::read_from_file(string filename)
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
	{
		cout << "\n\nFile not found!" << endl;
		system("pause");
		exit(1);
	}
	int N;
	infile >> N;
	infile.get();
	for (int i = 0; i < N; i++)
	{
		state new_state;
		new_state.read_from_file(infile);
		this->operator+=(new_state);
	}
	infile.close();
	cout << "\nLoaded data from file " << filename << ":";
	cout << "\n number of loaded state - " << num_state;
}

void tstate::write_to_file(string filename)
{
	ofstream outfile;
	outfile.open(filename);
	outfile << num_state << endl;
	for (int i = 0; i < num_state; i++)
		states[i].write_to_file(outfile);
	outfile.close();
	cout << "\nData written to file " << filename << ":";
	cout << "\n number of written state - " << num_state;
}

void tstate::display()
{
	cout << "\n\nFULL RANGE STATE \n";
	cout << "\n A) Original editions\n";
	for (int i = 0; i < num_state; i++)
		states[i].display();
	cout << "\n B) President of state \n";
	for (int i = 0; i < num_pstate; i++)
	{
		pstates[i].display();
	}
	cout << "\n C) Status state \n";
	for (int i = 0; i < num_tstate; i++)
		tstates[i].display();
}

void tstate::write_ststates_to_file(string filename)
{
	ofstream outfile;
	outfile.open(filename);
	outfile << num_tstate << endl;
	for (int i = 0; i < num_tstate; i++)
		tstates[i].write_to_file(outfile);
	outfile.close();
	cout << "\nData written to file " << filename << ":";
	cout << "\n number of written updated status state -  " << num_tstate;
}

void tstate::write_pststate_to_file(string filename)
{
	ofstream outfile;
	outfile.open(filename);
	outfile << num_tstate << endl;
	for (int i = 0; i < num_pstate; i++)
		pstates[i].write_to_file(outfile);
	outfile.close();
	cout << "\nData written to file " << filename << ":";
	cout << "\n number of written updated status state -  " << num_pstate;
}

void tstate::Sum(string acontinent)
{
	cout << "\n+Enter the continent : " << acontinent;
	float sumarea = 0;
	int sumpop = 0;
	for (int i = 0; i < num_state; i++)
	{
		if (states[i].get_continent() == acontinent)
		{
			sumarea += states[i].get_area();
			sumpop += states[i].get_population();
		}
	}
	cout << "\nSum area : " << sumarea << endl;
	cout << "Sum population : " << sumpop << endl;

}

void tstate::find(string lang)
{
	int max = states[0].get_population();
	int j = 0;
	for (int i = 1; i <= num_state; i++)
	{
		if (states[i].get_lang() == lang)
		{
			if (max < states[i].get_population())
			{
				max = states[i].get_population();
				j = i;
			}
		}
	}
	cout << "\nName and capital of the largest state in terms of population :" << endl;
	cout << "Country : " << states[j].get_country() << endl;
	cout << "Capital : " << states[j].get_capital() << endl;
}