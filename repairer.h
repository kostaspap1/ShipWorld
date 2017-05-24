Repairer :: Repairer(){ //constructor
	set_id(2);
	set_speed(3);
};
//destructor
Repairer :: ~Repairer(){}

Volunteer :: Volunteer(){ //constructor
	set_id(5);	
	set_speed(3);
};
//destructor
Volunteer :: ~Volunteer(){}

void Repairer :: operation(){ //operation for repairer, check if ship exists around and repaire it
	//check left
	if (get_x() > 0 && map[get_x()-1][get_y()].ship_here!=NULL){
		repair(get_x()-1, get_y());
		set_msg("Repaired ship - west");
	}
	//check right
    if (get_x() < map_size-1 && map[get_x()+1][get_y()].ship_here!=NULL){
		repair(get_x()+1, get_y());
		set_msg("Repaired ship - east");
	}
    //check up
    if (get_y() > 0 && map[get_x()][get_y()-1].ship_here!=NULL){
		repair(get_x(), get_y()-1);
		set_msg("Repaired ship - north");
	}
    //check down
    if (get_y() < map_size-1 && map[get_x()][get_y()+1].ship_here!=NULL){
		repair(get_x(), get_y()+1);
		set_msg("Repaired ship - south");
	}

	
}

void Repairer :: repair(int x, int y){
	int new_current_dur;			//temporary variable that handles nearby ship's durability
	int res;						//temporary variable that handles nearby ship's treasure

	
	new_current_dur = map[x][y].ship_here->get_current_dur();	//increase durability to the repaired ship
	new_current_dur = new_current_dur / 10;						// percentage to increase
	new_current_dur += map[x][y].ship_here->get_current_dur();	//increase durability to the nearby ship
	if(new_current_dur>100) new_current_dur = 100;

	map[x][y].ship_here->set_current_dur(new_current_dur);
	if(get_id()!=5){
		//get treasure from repaired ship
		res = map[x][y].ship_here->get_res_tres();
		if(res >= 10){
			map[x][y].ship_here->set_res_tres(res - res/10);
			set_res_tres(get_res_tres() + res/10);
		}
		else {
			map[x][y].ship_here->set_res_tres(0);		//res-res=0
			set_res_tres(get_res_tres() + res);
		}
	}
}
/* create repairer ship and push it into the vector and onto the map */ 
vector<Ship*> create_repairer(vector<Ship*> ships){
	int x, y;
	ships.push_back(new Repairer());
	do {
		x = rand()%map_size;
		y = rand()%map_size;
	} while(map[x][y].ship_here);
	ships.back()->set_x(x);
	ships.back()->set_y(y);
	map[x][y].ship_here = ships.back();

	return(ships);
}

/* create volunteer ship and push it into the vector and onto the map */ 
vector<Ship*> create_volunteer(vector<Ship*> ships){
	int x, y;
	ships.push_back(new Volunteer());
	do {
		x = rand()%map_size;
		y = rand()%map_size;
	} while(map[x][y].ship_here);
	ships.back()->set_x(x);
	ships.back()->set_y(y);
	map[x][y].ship_here = ships.back();

	return(ships);
}
