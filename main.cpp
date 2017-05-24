#include "header.h"
#include <iostream>
#include <ctime>
#include <cerrno>
#include <unistd.h>
#include <vector>
#include <string>
#include <stdio.h>
#include "kbhit.h"				// Methods for instant key input
#include "map.h"				// Methods of class map
#include "ship.h"
#include "pirate.h"
#include "merchant.h"
#include "explorer.h"
#include "repairer.h"
#include "menu.h"
#include "new_day.h"

using namespace std;

int main () {
	srand((unsigned int)getpid());		// "Randomize" rand()

	/* Creating our map */
	for(int i=0;i<map_size;i++){
		for(int j=0;j<map_size;j++){
			map[i][j].set_weather(rand()%10 + 1);	// Random values 1-10
			map[i][j].set_treasure(rand()%2);
			map[i][j].set_x(i);
			map[i][j].set_y(j);
		}
	}
	for (int p = 0; p < map_size; p++) {
		map[rand()%map_size][rand()%map_size].set_port(1);	// Setting up ports randomly
	}
	cout<<endl;

	/* Creating a vector for ships */
	vector<Ship*> ships;

	/* Creating new ships and push into vector and onto the map */
	for(int l=0;l<NUM_PIR;l++){
		ships = create_pirate(ships);
	}
	for(int l=0;l<NUM_MER;l++){
		ships = create_merchant(ships);
	}
	for(int l=0;l<NUM_EXP;l++){
		ships = create_explorer(ships);
	}
	for(int l=0;l<NUM_REP;l++){
		ships = create_repairer(ships);
	}
	for(int l=0;l<NUM_JP;l++){
		ships = create_jack(ships);
	}
	for(int l=0;l<NUM_VOL;l++){
		ships = create_volunteer(ships);
	}

	int day = 1;		// Rounds
	/************************/
	/*  SIMULATION - START  */
	/************************/

	while(!ships.empty()) {		// Simulation loop

		if (f) break;					// Terminating when user hits 'q'

		system("clear");
		cout<<"Day "<<day<<endl;
		cout<<endl;

		cout<<"Id\tShips\t\tPosition\tDurability\tTreasure\tDist\tDmg\tOperation"<<endl;

		for(int l=0;l<(int)ships.size();l++){
			/* Print ship information */
			ships[l]->informations(l);	// in "ship.h"
		}
		/* Figure out the # of ports */
		int k = 0;
		for (int i = 0; i < map_size-1; i++) {
			for (int j = 0; j < map_size-1; j++) {
				if (map[i][j].get_port()) k++;
			}
		}
		cout<<endl<<"Ports: "<<k<<endl;

		if (f || (int)ships.empty()) break;		// Terminating conditions

		ships = menu(ships);						// Print the menu - "menu.h"

		if (run) {ships = new_day(ships); day++;}	// Move on to the next day - "new_day.h"
			
	}
	/**********************/
	/*  SIMULATION - END  */
	/**********************/
	
	cout<<endl<<"Game Over!"<<endl;
	end(ships, day);					// Printing final message in case of Ctrl-C or treasure > MAX_TRE
	return 0;
}