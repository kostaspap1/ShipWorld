bool run = false;	// Boolean for running/pause state
keyboard key;		// Object of class keyboard for instant input
int in, in1;		
char temp[100];

/************ USER INTERFACE ***************/
vector<Ship*> menu(vector<Ship*> ships){
char input;
	cout<<endl;
	cout<<"----------------------------->"<<endl;
	cout<<"| <Space>:    Play           |"<<endl;
	cout<<"| 's':        Ship Info      |"<<endl;
	cout<<"| 'm':        Map Info       |"<<endl;
	cout<<"| 'a':        Add Ship       |"<<endl;
	cout<<"| 'r':        Remove Ship    |"<<endl;
	cout<<"| 'e':        Edit Map       |"<<endl;
	cout<<"| 'q':        Quit           |"<<endl;
	cout<<"| <Any Key>:  Pause          |"<<endl;
	cout<<"----------------------------->"<<endl;
	if (run) sleep(1);
	/* Pause mode */
	if (!run || (run && key.kbhit())){		// When the simulation is paused or the user presses a button
		input = getchar();
		switch (input){
			case ' ':
				run = true;				// If you hit <space>, simulation resumes
				break;
			case 'q':
				f = true;				// If you hit <q>, simulation stops
				break;
			case 's':
				cout<<"What kind of ship do you seek information for?"<<endl;
				cout<<endl;
				cout<<"----------------------->"<<endl;
				cout<<"| 0:    Pirate         |"<<endl;
				cout<<"| 1:    Merchant       |"<<endl;
				cout<<"| 2:    Repairer       |"<<endl;
				cout<<"| 3:    Explorer       |"<<endl;
				cout<<"| 4:    Jack Sparrow   |"<<endl;
				cout<<"| 5:    Volunteer      |"<<endl;
				cout<<"| Esc:  Back           |"<<endl;
				cout<<"----------------------->"<<endl;
				do {
					input = getchar();
					switch (input){
						case '0':
							system("clear");
							cout<<"                                                  PIRATES"<<endl;
							cout<<"=================================================================================================================="<<endl;
							cout<<"Pirates used to terror the Seven Seas, looking for ships to loot, food and treasure to steal, and take prisoners."<<endl;
							cout<<"If you ever fall into a pirate's hands, better wish you were dead."<<endl;
							cout<<endl;
							cout<<"Speed: 1\tDamage: 10\tLoot: 10 gold"<<endl;
							cout<<"=================================================================================================================="<<endl;
							cout<<endl;
							cout<<"Id\tShips\t\tPosition\tDurability\tTreasure\tDist\tDmg\tOperation"<<endl;
							for(int l=0;l<(int)ships.size();l++){
								if (ships[l]->get_id() == 0) ships[l]->informations(l);
							}
							cout<<endl;
							cout<<"Press any key to go back"<<endl;
							getchar();
							break;
						case '1':
							system("clear");
							cout<<"                                               MERCHANT"<<endl;
							cout<<"=============================================================================================================="<<endl;
							cout<<"Merchant ship, is a ship that transports cargo or passengers. It can be big, it can be fast, or it can be both"<<endl;
							cout<<"A merchant ship gets paid a huge amount of gold when arriving at a port."<<endl;
							cout<<endl;
							cout<<"Speed: 3\tPort fee paid: 10 gold"<<endl;
							cout<<"=============================================================================================================="<<endl;
							cout<<endl;
							cout<<"Id\tShips\t\tPosition\tDurability\tTreasure\tDist\tDmg\tOperation"<<endl;
							for(int l=0;l<(int)ships.size();l++){
								if (ships[l]->get_id() == 1) ships[l]->informations(l);
							}
							cout<<endl;
							cout<<"Press any key to go back"<<endl;
							getchar();
							break;
						case '2':
							system("clear");
							cout<<"                                REPAIRER"<<endl;
							cout<<"==================================================================="<<endl;
							cout<<"A repairing ship can repair any adjacent ship in exchange for gold."<<endl;
							cout<<endl;
							cout<<"Speed: 3\tRepairing fee paid: 10 percent"<<endl;
							cout<<"==================================================================="<<endl;
							cout<<endl;
							cout<<"Id\tShips\t\tPosition\tDurability\tTreasure\tDist\tDmg\tOperation"<<endl;
							for(int l=0;l<(int)ships.size();l++){
								if (ships[l]->get_id() == 2) ships[l]->informations(l);
							}
							cout<<endl;
							cout<<"Press any key to go back"<<endl;
							getchar();
							break;
						case '3':
							system("clear");
							cout<<"                                     EXPLORER"<<endl;
							cout<<"==================================================================================="<<endl;
							cout<<"An exploring ship can look around for pirates and save itself before it's too late."<<endl;
							cout<<"It also can predict the weather so it doesn't fall into a storm."<<endl;
							cout<<endl;
							cout<<"Speed: 1"<<endl;
							cout<<"==================================================================================="<<endl;
							cout<<endl;
							cout<<"Id\tShips\t\tPosition\tDurability\tTreasure\tDist\tDmg\tOperation"<<endl;
							for(int l=0;l<(int)ships.size();l++){
								if (ships[l]->get_id() == 3) ships[l]->informations(l);
							}
							cout<<endl;
							cout<<"Press any key to go back"<<endl;
							getchar();
							break;
						case '4':
							system("clear");
							cout<<"                                           JACK SPARROW - PIRATE"<<endl;
							cout<<"======================================================================================================="<<endl;
							cout<<"Jack Sparrow is one of the nine pirate lords in the Brethren Court, the Pirate Lords of the Seven Seas."<<endl;
							cout<<"He can be treacherous and survives mostly by using wit and negotiation rather than by force."<<endl;
							cout<<endl;
							cout<<"Speed: 2\tDamage: 15\tLoot: 10 gold"<<endl;
							cout<<"========================================================================================================"<<endl;
							cout<<endl;
							cout<<"Id\tShips\t\tPosition\tDurability\tTreasure\tDist\tDmg\tOperation"<<endl;
							for(int l=0;l<(int)ships.size();l++){
								if (ships[l]->get_id() == 4) ships[l]->informations(l);
							}
							cout<<endl;
							cout<<"Press any key to go back"<<endl;
							getchar();
							break;
						case '5':
							system("clear");
							cout<<"                        VOLUNTEER"<<endl;
							cout<<"======================================================="<<endl;
							cout<<"A volunteer ship can repair any adjacent ship for free."<<endl;
							cout<<endl;
							cout<<"Speed: 3\tRepairing fee paid: None"<<endl;
							cout<<"======================================================="<<endl;
							cout<<endl;
							cout<<"Id\tShips\t\tPosition\tDurability\tTreasure\tDist\tDmg\tOperation"<<endl;
							for(int l=0;l<(int)ships.size();l++){
								if (ships[l]->get_id() == 5) ships[l]->informations(l);
							}
							cout<<endl;
							cout<<"Press any key to go back"<<endl;
							getchar();
							break;
						case 27:
							system("clear");
							break;
						default :
							continue;		// Wrong button, try again
					}
					break;
				} while(1);
				run = false;
				break;
			case 'a':
				do {
					cout<<"Which kind of ship do you wish to add?"<<endl;
					cout<<endl;
					cout<<"----------------------->"<<endl;
					cout<<"| 0:    Pirate         |"<<endl;
					cout<<"| 1:    Merchant       |"<<endl;
					cout<<"| 2:    Repairer       |"<<endl;
					cout<<"| 3:    Explorer       |"<<endl;
					cout<<"| 4:    Jack Sparrow   |"<<endl;
					cout<<"| 5:    Volunteer      |"<<endl;
					cout<<"| Esc:  Back           |"<<endl;
					cout<<"----------------------->"<<endl;

					do {
						input = getchar();
						switch (input){
							/* Calling the functions to create and initialize ships into map and vector */
							case '0':
								ships = create_pirate(ships);
								cout<<endl;
								break;
							case '1':
								ships = create_merchant(ships);
								cout<<endl;
								break;
							case '2':
								ships = create_repairer(ships);
								cout<<endl;
								break;
							case '3':
								ships = create_explorer(ships);
								cout<<endl;
								break;
							case '4':
								ships = create_jack(ships);
								cout<<endl;
								break;
							case '5':
								ships = create_volunteer(ships);
								cout<<endl;
								break;
							case 27:
								break;				// Escape, go back
							default :
								continue;			// Wrong key, re-ask for key
						}
						break;	// break while 1
					} while(1);
					break;	//break while 1
				} while(1);
				run = false;
				break;	//break switch
			case 'r':
				cout<<"Which ship do you wish to remove? (Give Id from above and press Enter)"<<endl;
				do {
					cin.getline(temp, 100);
					in = strtol(temp, 0, 10);
					in--;
					if (in+1 <= (int)ships.size() && in >= 0) {
						cout<<"Remove "<<in+1<<"? (y/n)"<<endl;
						input = getchar();
						if (input == 'y') {
							map[ships[in]->get_x()][ships[in]->get_y()].ship_here = NULL;	// Remove ship from map
							map[ships[in]->get_x()][ships[in]->get_y()].set_treasure(true);	// Leave treasure behind
							ships.erase(ships.begin()+in);									// Remove ship from vector
						}
						break;	//break do-while
					}
					else {
						break;	// continue do-while
					}
				} while(1);
				run = false;
				break;	//break switch
			case 'e':
				do {
					cout<<"Choose the location on the map you want to edit"<<endl;
					do {
						cout<<"Type the x coordinate and press Enter(0-"<<map_size<<")"<<endl;
						cout<<"To cancel, type 'c' and press Enter: "<<endl;
						cin.getline(temp, 100);
						in = strtol(temp, 0, 10);
						if (temp[0] == 'c') break;
						if (in > 9) continue;
						in1 = in;
						cout<<endl<<"x coord: "<<in<<"? (y/n)"<<endl;
						input = getchar();
						if (input == 'y') {
							do {
								cout<<"Type the y coordinate and press Enter(0-"<<map_size<<")"<<endl;
								cout<<"To cancel, type 'c' and press Enter"<<endl;
								cin.getline(temp, 100);
								in = strtol(temp, 0, 10);
								if (temp[0] == 'c') break;
								if (in > 9) continue;
								cout<<endl<<"Location: ("<<in1<<","<<in<<")? (y/n)"<<endl;
								input = getchar();
								if (input == 'y') {
									cout<<"What do you wish to change here?"<<endl;
									cout<<"---------------------------"<<endl;
									cout<<"| 1:       Treasure       |"<<endl;
									cout<<"| 2:       Port           |"<<endl;
									cout<<"| <Esc>:   Cancel         |"<<endl;
									cout<<"---------------------------"<<endl;
									do {
										input = getchar();
										switch (input) {
											case '1':
												cout<<"Add/Remove Treasure"<<endl;
												cout<<"---------------------------"<<endl;
												cout<<"| 1:       Add            |"<<endl;
												cout<<"| 2:       Remove         |"<<endl;
												cout<<"| <Esc>:   Cancel         |"<<endl;
												cout<<"---------------------------"<<endl;
												do {
													input = getchar();
													switch (input) {
														case '1':
															map[in1][in].set_treasure(true);
															break;
														case '2':
															map[in1][in].set_treasure(false);
															break;
														case 27:
															break;
														default :
															continue;
													}
													break;
												} while(1);
												break;
											case '2':
												cout<<"Add/Remove Port"<<endl;
												cout<<"---------------------------"<<endl;
												cout<<"| 1:       Add            |"<<endl;
												cout<<"| 2:       Remove         |"<<endl;
												cout<<"| <Esc>:   Cancel         |"<<endl;
												cout<<"---------------------------"<<endl;
												do {
													input = getchar();
													switch (input) {
														case '1':
															map[in1][in].set_port(true);
															break;
														case '2':
															map[in1][in].set_port(false);
															break;
														case 27:
															break;
														default :
															continue;
													}
													break;
												} while(1);
												break;
											case 27:
												break;
										}
										break;
									} while(1);
									break;
								}
								else continue;
							} while(1);
							break;
						}
						else continue;
					} while(1);
					break;
				} while (1);
				run = false;
				break;
			case 'm':
				cout<<"Choose the location on the map you wish to inspect"<<endl;
				do {
					cout<<"Type the x coordinate and press Enter(0-"<<map_size-1<<")"<<endl;
					cout<<"To cancel, type 'c' and press Enter: "<<endl;
					cin.getline(temp, 100);
					in = strtol(temp, 0, 10);
					if (temp[0] == 'c') {run = false; break;}
					if (in > map_size-1) continue;
					in1 = in;
					cout<<endl<<"x coord: "<<in<<"? (y/n)"<<endl;
					input = getchar();
					if (input == 'y') {
						do {
							cout<<"Type the y coordinate and press Enter(0-"<<map_size-1<<")"<<endl;
							cout<<"To cancel, type 'c' and press Enter"<<endl;
							cin.getline(temp, 100);
							in = strtol(temp, 0, 10);
							if (temp[0] == 'c') {run = false; break;}
							if (in > map_size-1) continue;
							cout<<endl<<"Location: ("<<in1<<","<<in<<")? (y/n)"<<endl;
							input = getchar();
							if (input == 'y') {
								cout<<endl<<"Treasure: "<<map[in1][in].get_treasure()<<endl<<"Weather: "<<map[in1][in].get_weather()<<endl;
								if (map[in1][in].ship_here) {
									switch (map[in1][in].ship_here->get_id()) {
										case 0: cout<<"A pirate is here!"; break;
										case 1: cout<<"Merchant ship here"; break;
										case 2: cout<<"Repairing ship here"; break;
										case 3: cout<<"Exploring ship here"; break;
										case 4: cout<<"Jack Sparrow is here!"; break;
										case 5: cout<<"Volunteer ship here"; break;
									}
								}
								else cout<<"No ship here";
								cout<<endl<<endl<<"Press any key"<<endl; getchar(); break;
							}
							else continue;
						} while(1);
						break;
					}
					else continue;
				} while (1);
			default :
				run = false;
		}
	}
	return ships;
}