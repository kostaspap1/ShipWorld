Merchant :: Merchant(){ //constructor
	set_id(1);
	set_speed(3);
};
//destructor
Merchant :: ~Merchant(){}

void Merchant :: operation(){		//increase treasure if port exists nearby

	int res;
/*chech for port and get treasure*/
	//check left
	if (get_x() > 0 && map[get_x()-1][get_y()].get_port()){
		res = get_res_tres();
		set_res_tres(res+10);
		set_msg("Got treasure from western port");
	}
	//check right
	if (get_x() < map_size-1 && map[get_x()+1][get_y()].get_port()){
		res = get_res_tres();
		set_res_tres(res+10);
		set_msg("Got treasure from eastern port");
	}
	//check up
	if (get_y() > 0 && map[get_x()][get_y()-1].get_port()){
		res = get_res_tres();
		set_res_tres(res+10);
		set_msg("Got treasure from northern port");
	}
	//check down
	if (get_y() < map_size-1 && map[get_x()][get_y()+1].get_port()){
		res = get_res_tres();
		set_res_tres(res+10);
		set_msg("Got treasure from southern port");
	}
}
/* create merchant ship and push it into the vector and onto the map */ 
vector<Ship*> create_merchant(vector<Ship*> ships){
	int x, y;
	ships.push_back(new Merchant());
	do {
		x = rand()%map_size;
		y = rand()%map_size;
	} while(map[x][y].ship_here);
	ships.back()->set_x(x);
	ships.back()->set_y(y);
	map[x][y].ship_here = ships.back();

	return(ships);
}
