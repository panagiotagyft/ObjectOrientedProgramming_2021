#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <ctime> //
#include "Interface.h"

using namespace std;


//=====================================================             Constructors and Destructors                =========================================================  
//___creature___

creature::creature(int L, int pos, int good_bad, string name): Life(L), Good_Bad(good_bad), position(pos){
	string s;
    stringstream conversion;
    
	//Converting an int to std::string -->> full name of creature= name PLUS the place of the creature in the community
	conversion << position; 
	s=conversion.str();
	Creature_Name=name+s;		//  full name of creature= name PLUS the place of the creature in the community
}

creature::creature(const creature& clone) {
	 // copy informations
	Life=clone.Life;   
	Good_Bad=clone.Good_Bad;
	position=clone.position;
	Creature_Name=clone.Creature_Name;	
	cout << "A creature was just created by copying..." << endl;
}

creature::~creature() {
	cout << "Creature " << get_creature_name() << " was destroyed" << endl;
}

//___good_creature__

good_creature::good_creature(int L, string Good_names[], int good_thrsh,int pos,int good_bad):creature(L, pos, good_bad, Good_names[rand()%10]), good_thrsh(good_thrsh){
	cout << "Good creature " << get_creature_name() << " was created" << endl;	
}

good_creature::good_creature(const good_creature& good) : creature(good), good_thrsh(good.good_thrsh){
	cout << "Good creature " << get_creature_name() << " was copied" << endl << endl;
}

//___bad_creature__

bad_creature::bad_creature(int L, string Bad_names[], int bad_thrsh, int pos, int good_bad):creature(L, pos, good_bad, Bad_names[rand()%10]), bad_thrsh(bad_thrsh){
	cout << "Bad creature " << get_creature_name() << " was created" << endl;	
}

bad_creature::bad_creature(const bad_creature& bad) : creature(bad), bad_thrsh(bad.bad_thrsh){
	cout << "Bad creature " << get_creature_name() << " was copied" << endl << endl;
}

//___creature_society___

creature_society::creature_society(int N ,int L, int good_thrsh, int bad_thrsh):N(N){
	int i, good_bad, no_zobies;
	
	string Good_names[10]={"Gabriella", "Gaia", "George", "Gerard", "Gianna", "Giovanni", "Giulia", "Gloria", "Graham", "Gregory"};
	string Bad_names[10]={"Banjamin","Barbara", "Bella", "Bernadette", "Bethany", "Bradley", "Brandon", "Brianna", "Bruno", "Bryant"};
	
	no_Good=0;
	no_Zobies=0;
	
	creatures_array=new creature*[N];
	for(i=0; i < N; i++){
		good_bad=rand()%2;  		// random selection  -->> create good or bad creature 
		if(good_bad == 1){ 		// if good_bad = 1 -->> create good creature
			creatures_array[i]=new good_creature(L, Good_names, good_thrsh, i, good_bad);
			no_Good++;
		}
		else{  creatures_array[i]=new bad_creature(L, Bad_names, bad_thrsh, i, good_bad); } 		// if good_bad = 0 -->> create bad creature
	}
	
	cout<<"The creature society was created"<<endl<< endl;	 
}

creature_society::~creature_society() {
	cout << "Creature society was destroyed" << endl;
	for (int i=0; i< N; i++) {
		delete creatures_array[i]; // delete creature
	}
	delete[] creatures_array; // delete array of creatures
}

//________________________________________________________________________________________________________________________________________________________________________

//=======================================================================      creature      ==============================================================================

bool creature::is_a_zobie(){
	if (Life==0){ return true; } // Is a zombie
	else { return false; }       // Is not a zombie
}

//=======================================================================        GOOD        ==============================================================================

void good_creature::beat(){
	if(get_creature_life() > 0){ // if creature is alive  
		if (decreased_the_life() > 0){ cout << "Good creature " << get_creature_name() << "--->>  was beated" << endl; }
		else{ cout << "Good creature " << get_creature_name() << "--->>  was beated and and turned into a zombie!" << endl;	}
		cout << "-current life:" << get_creature_life() << endl << endl;	
	}
	else{  cout << "Sorry the creature " << get_creature_name() << " is a zombie.You couldn't complete this action." << endl; }  // If creature is a zombie -->>  don't do nothing
}

int good_creature::bless(){
	if(get_creature_life() > 0){ // if creature is alive  
		if(increased_the_life() > good_thrsh){  // if the current life of the creature is greater than the good threshold (good_thrsh)
			cout << "Good creature " << get_creature_name() << "--->>  was blessed and became sturdy!" << endl;
			cout << "-current life: " << get_creature_life() << endl << endl;
			return 1;
		}
		else{ 
			cout << "Good creature " << get_creature_name() << "--->>  was blessed" << endl;  
			cout << "-current life: " << get_creature_life() << endl << endl;
			return 0;
		}
	}
	else {  
		cout << "Sorry the creature " << get_creature_name() << " is a zombie.You couldn't complete this action." << endl;  // If creature is a zombie -->>  don't do nothing
		return 0;
	}
}

creature* good_creature::clone(){
	cout << "Creating the clone " << endl;
	return new good_creature(*this); // call good copy constructor to create the clone and return the good creature
}

//=======================================================================        BAD        ===============================================================================

void bad_creature::beat(){
	if(get_creature_life() > 0){ 	// if creature is alive  
		if (decreased_the_life() > 0){ cout << "Bad creature " << get_creature_name() << "--->>  was beated" << endl; }
		else{ cout << "Bad creature " << get_creature_name() << "--->>  was beated and and turned into a zombie!" << endl;	}
		cout << "-current life:" << get_creature_life() << endl << endl;	
	}
	else{  cout << "Sorry the creature " << get_creature_name() << " is a zombie.You couldn't complete this action." << endl; } // If creature is a zombie -->>  don't do nothing
}

int bad_creature::bless(){ 	
	if(get_creature_life() > 0){			// if creature is alive  
		if(increased_the_life() > bad_thrsh){		// if the current life of the creature is greater than the bad threshold (bad_thrsh)		
			cout << "Bad creature " << get_creature_name() << "--->>  was blessed and became sturdy!" << endl;
			cout << "-current life: " << get_creature_life() << endl << endl;
			return 1;
		}
		else{ 
			cout << "Bad creature " << get_creature_name() << "--->>  was blessed" << endl;
			cout << "-current life: " << get_creature_life() << endl << endl;
			return 0;
		}
	}
	else {  
		cout << "Sorry the creature " << get_creature_name() << " is a zombie.You couldn't complete this action." << endl;  // If creature is a zombie -->>  don't do nothing
		return 0;
	}
}

creature* bad_creature::clone(){
	cout << "Creating the clone " << endl;
	return new bad_creature(*this); // call bad copy constructor to create the clone and return the bad creature
}

//================================================================    creature_society    =================================================================================

void creature_society::beat(int position) {
	creatures_array[position]->beat();		// beated the bad or good creature 
	check_no_good();		// set the new number of good creatures 
	check_no_zobies();		// set the new number of zombies
}


void creature_society::clone_next(int position){
	if(position ==	N-1 ){ 
		delete creatures_array[0];           // if sturdy creature is the last -->> clone the first creature in the community (delete the first)
		creatures_array[0]=creatures_array[position]->clone(); // call copy constructor to create the clone
	}
	else{ 
		delete creatures_array[position+1];  // if sturdy creature is not the last -->> clone the next creature in the community
		creatures_array[position+1]=creatures_array[position]->clone(); // call good copy constructor to create the clone
	}
	check_no_good();
}

void creature_society::clone_zobies(int position){
	int i;
	if(position!=N-1){          //if the current bad creature is not in the last position
		for(i=position+1; i < N; i++){		// check all subsequent positions
			if(creatures_array[i]->is_a_zobie()==true){  // if the next creature is a zombie --> clone
				delete creatures_array[i];   // delete zombie   
				creatures_array[i]=creatures_array[i-1]->clone(); //  call bad copy constructor to create the clone
			}
			else{ break; }   // if the next creature is not a zombie -->> break 
		}
	}
	check_no_zobies();
}

void creature_society::bless(int position) {
	if(creatures_array[position]->bless()==1){		// if creature became sturdy 
		if(creatures_array[position]->is_a_good()==true){ clone_next(position); }		// if creature is a good -->> clone next creature
		else{ clone_zobies(position);}		// if creature is a bad -->> clone zombies creatures
	}
}

void creature_society::check_no_zobies(){
	int count;
	count=0;
	for (int i=0; i<N; i++){
		if(creatures_array[i]->is_a_zobie()==true){ 	// check if current creature is a zombie --->> if is a zombie -> increase the counter 
			count++;		
		}
	}
	no_Zobies=count; 		// set the new number of zombies
}

void creature_society::check_no_good(){
	int count;
	count=0;
	for (int i=0; i<N; i++){
		if(creatures_array[i]->is_a_good()==true){ 	// check if current creature is a good --->> if is a good -> increase the counter 
			count++;		
		}
	}
	no_Good=count;		// set the new number of good creatures
}

void creature_society::print(int N) {		// print creature society
	cout << endl << "Creature society:" << endl;
	for (int i=0; i<N; i++){
		cout << "{ " << creatures_array[i]->get_creature_name() << " }\t";  // print current creature
	}
	cout<<endl<<endl;
}
