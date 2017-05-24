Explorer :: Explorer(){
	set_id(3);
	set_speed(1);
};

Explorer :: ~Explorer(){}

void Explorer :: operation(int x,int y){
	/* Check for pirate ship and turn around */
	if(get_x()+1 < map_size && map[x+1][y].ship_here){		// Check down
		if (map[x+1][y].ship_here->get_id() == 0 || map[x+1][y].ship_here->get_id() == 4){
			set_msg("Went north - Pirate!");
			move(3);
			return;
		}
	}
	else if(get_x()-1 > 0 && map[x-1][y].ship_here){ 		// Check up
		if (map[x-1][y].ship_here->get_id() == 0 || map[x-1][y].ship_here->get_id() == 4){
			set_msg("Went south - Pirate!");
			move(2);
			return;
		}
	}
	else if(get_y()+1 < map_size && map[x][y+1].ship_here){ // Check right
		if (map[x][y+1].ship_here->get_id() == 0 || map[x][y+1].ship_here->get_id() == 4){
			set_msg("Went west - Pirate!");
			move(1);
			return;
		}
	}
	else if(get_y()-1 > 0 && map[x][y-1].ship_here){ 		// Check left
		if (map[x][y-1].ship_here->get_id() == 0 || map[x][y-1].ship_here->get_id() == 4){
			set_msg("Went east - Pirate!");
			move(0);
			return;
		}
	}
	/* Check for bad weather and turn around */
	else if (get_x()-1 > 0 && map[get_x()-1][get_y()].get_weather() >= 8){
		move(2);	//move right
		set_msg("Went south - bad weather");
		return;
	}
	else if (get_x()+1 < map_size && map[get_x()+1][get_y()].get_weather() >= 8){
		move(3);	//move left
		set_msg("Went north - bad weather");
		return;
	}
	else if (get_y()-1 > 0 && map[get_x()][get_y()-1].get_weather() >= 8){
		move(0);	//move down
		set_msg("Went east - bad weather");
		return;
	}
	else if (get_y()+1 < map_size && map[get_x()][get_y()+1].get_weather()>=8){
		move(1);	//move up
		set_msg("Went west - bad weather");
		return;
	}

	set_msg("Just move");
	move(rand()%4);			// If they don't find anyone or anything just move randomly
}
/* Create explorer ships and push it into the vector and onto the map */
vector<Ship*> create_explorer(vector<Ship*> ships){
	int x, y;
	ships.push_back(new Explorer());
	do {
		x = rand()%map_size;
		y = rand()%map_size;
	} while(map[x][y].ship_here);
	ships.back()->set_x(x);
	ships.back()->set_y(y);
	map[x][y].ship_here = ships.back();

	return(ships);
}
