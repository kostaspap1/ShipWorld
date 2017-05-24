Point_map map[map_size][map_size];//xarths
 
Point_map :: Point_map(){
	weather = 1;
	treasure = false;
	port = false;
	ship_here = NULL;
}

int Point_map :: get_weather(){
	return weather;
}
 
int Point_map :: get_treasure(){
	return treasure;
}
 
int Point_map :: get_port(){
	return port;
}
 
void Point_map :: set_weather(int w){
	if(w < 1) weather = 1;
	else if(w > 10) weather = 10;
	else weather = w;
}
 
void Point_map :: set_treasure(bool t){
	treasure = t;
}
 
void Point_map :: set_port(bool p){
	port = p;
}

int Point_map :: get_x(){
	return x;
}
  
int Point_map :: get_y(){
	return y;
}

void Point_map :: set_x(int x1){
	x = x1;
}
  
void Point_map :: set_y(int y1){
	y = y1;
}

void Point_map :: check_weather(){
	if (ship_here){
		if(get_weather() > 7){
			int temp = ship_here->get_current_dur();	// Temporary variable for "dur"
			int new_current_dur;
			if(temp > 9){
				new_current_dur = temp - 5;				// Damage the ship 5 units
				if(ship_here->get_id()!=0 && ship_here->get_id()!=4)				
					ship_here->set_overall_damage(ship_here->get_overall_damage()+5); //Increase overall damage of the attacked ship			
			} else
				new_current_dur = 0;
			ship_here->set_current_dur(new_current_dur);	
		}
	}
}

void Point_map :: check_treasure(){
	int new_res_tres;
	if (ship_here && treasure){
		new_res_tres = ship_here->get_res_tres();
		new_res_tres += 10;		// Ship obtains the treasure
		ship_here->set_res_tres(new_res_tres);
		treasure = false;		// Remove treasure from map
	}
}

/* Check ports if there's an adjacent ship */
void Point_map :: check_port(){
	if (map[get_x()][get_y()].get_port() == 1){

		if (get_x() > 0 && map[get_x()-1][get_y()].ship_here)			// Look up
			do_ship(get_x()-1,get_y());
		if (get_x() < map_size-1 && map[get_x()+1][get_y()].ship_here)	// Look down
			do_ship(get_x()+1,get_y());
		if (get_y() > 0 && map[get_x()][get_y()-1].ship_here)			// Look left
			do_ship(get_x(),get_y()-1);
		if (get_y() < map_size-1 && map[get_x()][get_y()+1].ship_here)	// Look right
			do_ship(get_x(),get_y()+1);
	}
}	

/* For ports, damage pirate ships and repair the "good ones" */
void Point_map :: do_ship(int x, int y){
	int ship_id;
	int new_current_dur;
		ship_id = map[x][y].ship_here->get_id();
		if (ship_id == 0){	// If pirate
			new_current_dur = map[x][y].ship_here->get_current_dur()-5;
			if(new_current_dur < 0) new_current_dur = 0;
		}
		else {
			new_current_dur = map[x][y].ship_here->get_current_dur()+5;
			if(new_current_dur > 100) new_current_dur = 100;
		}	
	map[x][y].ship_here->set_current_dur(new_current_dur); 
}

void Point_map :: weather_renewal(){
	if(rand()%2){
		if(weather < 10) weather++;	// Increase weather
	}
	else {
		if(weather > 1) weather--;	// Decrease weather
	}	
}
