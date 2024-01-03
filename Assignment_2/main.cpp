#include <iostream>
#include <ctime>
#include "Interface.h"

using namespace std;

int main(int argc, char* argv[]){
	int N, M, L, good_thrsh, bad_thrsh, i, get_random_action, get_random_creature;	
	
	if(argc==1 || argc<=5){
		printf("Missing arguments...\n");
		return 1;
	}
	
	srand(time(NULL));
		
	N=atoi(argv[1]);										
	M=atoi(argv[2]);
	L=atoi(argv[3]);
	good_thrsh=atoi(argv[4]);
	bad_thrsh=atoi(argv[5]);
	
	creature_society Creature_Society(N, L, good_thrsh, bad_thrsh); 		// create the creature society 

	for(i=0; i < M; i++){
		get_random_creature=rand()%N;  		// select a random creature
		get_random_action=rand()%2;    		// select a random action
		
		if(get_random_action==0){  Creature_Society.bless(get_random_creature); }  // if get_random_action = 0 -->> blessed the chosen creature
		else{  Creature_Society.beat(get_random_creature);  }		 // if get_random_action = 1 -->> beated the chosen creature 
	}
	
	cout << endl; 
    
	if (Creature_Society.no_of_good()==N){ cout << "Good Dominates in World" << endl; } 		// all creatures in the community is good
	else if (Creature_Society.no_of_zobies()==N){ cout << "This is a dead society" << endl; }	 // all creatures in the community is dead -->>(= zombie)
	else{ cout << "Try aggain to improve the world" << endl; }		// society is made up of both good and bad creatures
  
	cout << endl; 
	Creature_Society.print(N);	
	return 0;
}
