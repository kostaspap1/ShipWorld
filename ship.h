Ship :: Ship(){
	max_dur = 100;
	speed = 0;
	res_tres = 0;
	id = 5;
	current_dur = 100;
	overall_dist = 0;
	overall_damage = 0;
}

Ship :: ~Ship(){}


int Ship :: get_overall_dist(){
	return overall_dist;
}

void Ship :: set_overall_dist(int movement){
	overall_dist=movement;
}

int Ship :: get_overall_damage(){
	return overall_damage;
}

void Ship :: set_overall_damage(int dmg){
	overall_damage=dmg;
}
int Ship :: get_speed(){
	return speed;
}
 
int Ship :: get_res_tres(){
	return res_tres;
}

int Ship :: get_max_dur(){
	return max_dur;
}

void Ship :: set_speed(int s){
	speed = s;
}
 
void Ship :: set_res_tres(int rt){
	res_tres = rt;
}
 
int Ship :: get_x(){
	return x;
}
 
int Ship :: get_y(){
	return y;
}

void Ship :: set_x(int x1){
	x = x1;
}
 
void Ship :: set_y(int y1){
	y = y1;
}

int Ship :: get_current_dur(){
	return current_dur;
}
	
void Ship :: set_current_dur(int cu){
	current_dur = cu;
}

int Ship :: get_id(){
	return id;
}
	
void Ship :: set_id(int i){
	id = i;
}

void Ship :: set_damage(int){}

void Ship :: set_msg(string ms){
            msg = ms;
        }
string Ship :: get_msg(){
    return msg;
}

void Ship :: operation(int,int){}	// Empty declaration with arguments

void Ship :: operation(){}			// Empty declaration without arguments

void Ship :: move(int direction){	// Method for movement with coordinates arguments
	switch(direction){
		case 0: // Right
			if(get_y() + speed < map_size){
				if(map[get_x()][get_y() + speed].ship_here == NULL){		// Move only if space is empty
					map[get_x()][get_y()].ship_here = NULL;					// Leave its position
					set_y(get_y() + speed);									// Set the new position
					set_overall_dist(get_overall_dist() + speed);			// Increase the overall movement
					map[get_x()][get_y()].ship_here = this;					// Install in new position
				}
			}
			/* If new position falls off the map, adjust accordingly */
			else {
				if(map[get_x()][map_size-1].ship_here == NULL){
					map[get_x()][get_y()].ship_here = NULL;
					set_overall_dist(get_overall_dist()+((map_size-1)-get_y()));
					set_y(map_size-1);
					map[get_x()][get_y()].ship_here = this;
				}
			}
			break;
		case 1: // Left
			if(get_y() - speed >= 0){ 
				if(map[get_x()][get_y() - speed].ship_here == NULL){
					map[get_x()][get_y()].ship_here = NULL;
					set_y(get_y() - speed);
					set_overall_dist(get_overall_dist() + speed);
					map[get_x()][get_y()].ship_here = this;
				}
			}
			else {
				if(map[get_x()][0].ship_here == NULL){
					map[get_x()][get_y()].ship_here = NULL;
					set_overall_dist(get_overall_dist() + get_y());
					set_y(0);
					map[get_x()][get_y()].ship_here = this;
				}
			}
			break;
		case 2: // Up
			if(get_x() - speed >= 0){ 
				if(map[get_x() - speed][get_y()].ship_here == NULL){
					map[get_x()][get_y()].ship_here = NULL;
					set_x(get_x() - speed);
					set_overall_dist(get_overall_dist() + speed);
					map[get_x()][get_y()].ship_here = this;
				}
			}
			else {
				if(map[0][get_y()].ship_here == NULL){
					map[get_x()][get_y()].ship_here = NULL;
					set_overall_dist(get_overall_dist() + get_x());
					set_x(0);
					map[get_x()][get_y()].ship_here = this;
				}
			}
			break;
		case 3: // Down
			if(get_x() + speed < map_size){
				if(map[get_x()+speed][get_y()].ship_here == NULL){
					map[get_x()][get_y()].ship_here = NULL;
					set_x(get_x()+speed);
					set_overall_dist(get_overall_dist() + speed);
					map[get_x()][get_y()].ship_here = this;
				}
			}
			else {
				if(map[map_size-1][get_y()].ship_here == NULL){
					map[get_x()][get_y()].ship_here = NULL;
					set_overall_dist(get_overall_dist()+((map_size-1)-get_x()));	
					set_x(map_size-1);
					map[get_x()][get_y()].ship_here=this;
				}
			}
		break;
	}
}

void Ship :: informations(int count){
	string type;
	if(id==0) type="Pirate         ";
	if(id==1) type="Merchant       ";
	if(id==2) type="Repairer       ";
	if(id==3) type="Explorer       ";
	if(id==4) type="Jack Sparrow   ";
	if(id==5) type="Volunteer      ";
	cout<<count+1<<"\t"<<type<<"\t("<<get_x()<<","<<get_y()<<")\t\t";	// Print Id, ship type, coords
	cout<<map[get_x()][get_y()].ship_here->get_current_dur()<<"\t\t"<<res_tres;	// Print durability, treasure
	cout<<"\t\t"<<overall_dist<<"\t"<<map[get_x()][get_y()].ship_here->get_overall_damage(); // Print distance, damage
	cout<<"\t"<<map[get_x()][get_y()].ship_here->get_msg()<<endl;	// Print op message
}

bool f = false;
void handler(int x){			// Handling the Ctrl-C signals
    cout<<endl<<"Closing unexpectedly...";
    x= x;
    f = true;
}

void end(vector<Ship*> ships, int day) {	// Printing out closing message
    int max_res = 0;
    for (int l = 0; l < (int)ships.size(); l++)
    {
    	if (ships[l]->get_res_tres() > max_res)
			max_res = ships[l]->get_res_tres();	// Find the biggest amount of treasure in one ship
	}
    cout<<endl<<"Simulation ended after "<<day-1<<" day(s) with ";
    if (max_res >= 200) 
    	cout<<"a ship achieving the "<<MAX_TRE<<" GOLD goal!"<<endl;
    else if (ships.empty())
    	cout<<"no ship left on the map..."<<endl;
    else
    	cout<<"nothing interesting happening :/"<<endl;
    cout<<endl;
}