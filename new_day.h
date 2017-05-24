vector<Ship*> new_day(vector<Ship*> ships){	

	/* A new day is upon us... */
	/* Check for location aspects and act accordingly */
	for(int i=0;i<map_size;i++){
		for(int j=0;j<map_size;j++){
			map[i][j].check_weather();
			map[i][j].check_treasure();
			map[i][j].check_port();
		}
	}
	/* Check for destroyed ships or treasure goal */
	for(int l=0;l<(int)ships.size();l++){
		if(ships[l]->get_res_tres() >= MAX_TRE) {f = true; break;}
		if(ships[l]->get_current_dur() <= 0){
			map[ships[l]->get_x()][ships[l]->get_y()].ship_here = NULL;		// Remove ship from map
			map[ships[l]->get_x()][ships[l]->get_y()].set_treasure(true);	// Replace destroyed ship with treasure
			ships.erase(ships.begin()+l); 									// Remove ship from vector
		}
	}

	/* Movement and ship operation */
	for(int l=0;l<(int)ships.size();l++){
		ships[l]->set_msg("- Idle or just moving -");

		if(ships[l]->get_id() == 3) 			// If explorer look around before moving
			ships[l]->operation(ships[l]->get_x(),ships[l]->get_y());	// Overloading method operation()
		else 
			ships[l]->move(rand()%4);			// Move randomly
			ships[l]->operation();				// Action
	}

	/* Change the weather */
	for(int i=0;i<map_size;i++){
		for(int j=0;j<map_size;j++){
			map[i][j].weather_renewal();
		}
	}
	/* ...and we're done for today! */

	signal(SIGINT, handler);
	return ships;
}