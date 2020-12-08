#include "tstate.h"
#include "state.h"
#include<iostream>
#include <string>
using namespace std;

int main()
{
	tstate my_state(40,30,30);
	my_state.read_from_file("state.txt");
	state state1("japan", "tokyo", "democratic", "japanese", "none", "asia", 332, 2231);
	state_status state2("korea", "seoul", "democratic", "korean", "none", "asia", 443, 353, "developed", 343);
	president_state state3("england", "london", "democratic", "english", "none", "europe", 323, 221, "Boris Johnson", 56);
    int key;

    do {
        cout << "Programm C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Add state.                                    **\n";
        cout << "**  2. Add updated state.                            **\n";
        cout << "**  3. Add president state.                          **\n";
        cout << "**  4. Show state.                                   **\n";
        cout << "**  5. Write to file.                                **\n";
        cout << "**  6. Find.                                         **\n";
        cout << "**  7. Sum.                                          **\n";
        cout << "**  0. Exit                                          **\n";
        cout << "*******************************************************\n";
        cout << "You choose: ";
        cin >> key;
        switch (key) {
        case 1:
            my_state += state1;
            break;
        case 2:
            my_state += state2;
            break;
        case 3:
            my_state += state3;
            break;
        case 4:
            my_state.display();
            break;
        case 5:
            my_state.write_ststates_to_file("state1.txt");
            my_state.write_pststate_to_file("state2.txt");
            break;
        case 6:
            my_state.find("spainish");
            break;
        case 7:
            my_state.Sum("northamerica");
            break;
        case 0:
            break;
        }
    } while (key);
}

