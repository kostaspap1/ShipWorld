Pirate :: Pirate(){ //constructor
	damage = 10;
	set_speed(1);
	set_id(0);
}
//destructor
Pirate :: ~Pirate(){}

Jack_sparrow :: Jack_sparrow(){ //constructor
	set_damage(15);   //different damage from clasic pirate
	set_speed(2);	  //diferrent speed from clasic pirate
	set_id(4);
}
//destructor
Jack_sparrow :: ~Jack_sparrow(){}

void Pirate :: set_damage(int d){
	damage = d;
}

void Pirate :: operation(){ 	// Pirate ship checks for other ships to attack
	//check  left
	if (get_x() > 0 && map[get_x()-1][get_y()].ship_here!=NULL){
		attack(get_x()-1, get_y());
		set_overall_damage(get_overall_damage()+damage);  //set new occured damage
	}
	//check  right
    if (get_x() < map_size-1 && map[get_x()+1][get_y()].ship_here!=NULL){
		attack(get_x()+1, get_y());
		set_overall_damage(get_overall_damage()+damage);
	}
    //check  up
    if (get_y() > 0 && map[get_x()][get_y()-1].ship_here!=NULL){
		attack(get_x(), get_y()-1);
		set_overall_damage(get_overall_damage()+damage);
	}
    //check down 
    if (get_y() < map_size-1 && map[get_x()][get_y()+1].ship_here!=NULL){
		attack(get_x(), get_y()+1);
		set_overall_damage(get_overall_damage()+damage);
	}
}

void Pirate :: attack(int x, int y){	// Pirate ship attacks! 
	int new_current_dur;		
	int res;			

	new_current_dur = map[x][y].ship_here->get_current_dur() - damage;  //new durability to the attacked ship
	map[x][y].ship_here->set_current_dur(new_current_dur);
	res = map[x][y].ship_here->get_res_tres();
	map[x][y].ship_here->set_overall_damage(get_overall_damage()+damage); //Increase overall damage of the attacked ship
	if(res >= 10){		
		set_res_tres(get_res_tres() + res/10);
		map[x][y].ship_here->set_res_tres(res - res/10);
		set_msg("I hit ye ye scurvy scullywag! Arrrr!");
	}
	else {
		set_res_tres(get_res_tres() + res);
		map[x][y].ship_here->set_res_tres(0);
	}
	set_current_dur(get_current_dur()+5);
	if (get_current_dur()>100) set_current_dur(100);
}
/* create pirate ship and push it into the vector and onto the map */ 
vector<Ship*> create_pirate(vector<Ship*> ships){
	int x, y;
	ships.push_back(new Pirate());
	do {
		x = rand()%map_size;
		y = rand()%map_size;
	} while(map[x][y].ship_here);
	ships.back()->set_x(x);
	ships.back()->set_y(y);
	map[x][y].ship_here = ships.back();

	return(ships);
}

/* create jack_sparrow ship and push it into the vector and onto the map */ 
vector<Ship*> create_jack(vector<Ship*> ships){
	int x, y;
	ships.push_back(new Jack_sparrow());
	do {
		x = rand()%map_size;
		y = rand()%map_size;
	} while(map[x][y].ship_here);
	ships.back()->set_x(x);
	ships.back()->set_y(y);
	map[x][y].ship_here = ships.back();

	return(ships);
}
