#include <iostream>
#include <cstring>

using namespace std;

class creature{
	string Creature_Name;		// creature name
	int Life;                   // the life of the creature
	int Good_Bad;               // the creature is bad or good 
	int position;               // the place of the creature in the community
	 
	public:
		creature(int, int, int, string); 	// constructor
		creature(const creature&); 			// copy constructor
		~creature();			// destructor
		bool is_a_zobie(); 		// creature is a zombie or not? 
		virtual bool is_a_good()=0; 		// override virtual function return if creature is a good or not
		virtual creature* clone()=0; 		// override virtual function return the clone
		virtual void beat()=0; 			// override virtual function -->> beat 
		virtual int bless()=0; 			// override virtual function -->> bless
		string get_creature_name() { return Creature_Name; }   // return the name of creature
		
	protected:
		int increased_the_life(){ return ++Life; }		// increased the life and return life
		int decreased_the_life(){ return --Life; }		// decreased the life and return life	
        int get_creature_life(){ return Life; } 		// return life
};

class good_creature:public creature{
	int good_thrsh;
	
	public:
		good_creature(int, string*, int ,int, int); 		// constructor
		good_creature(const good_creature&);		// copy constructor
		virtual ~good_creature()		// virtual destructor
		{
			cout << "Good creature " << get_creature_name()  << " was destroyed" << endl;
		}
		creature* clone();		// return the good creature clone
		void beat(); 		// beated the good creature
		int bless(); 		// blessed the good creature
		bool is_a_good(){ return true; } 	 // is a good creature and return true 
};

class bad_creature:public creature{
	int bad_thrsh;
	
	public:
		bad_creature(int, string*,  int ,int, int);		// constructor
		bad_creature(const bad_creature&);		// copy constructor
		virtual ~bad_creature()		// virtual destructor
		{
			cout << "Bad creature " << get_creature_name()  << " was destroyed" << endl;
		}	
		creature* clone();		// return the bad creature clone	
		void beat();		// beated the bad creature
		int bless();		// blessed the bad creature
 		bool is_a_good(){ return false; }		// is a bad creature and return false			
};

class creature_society{
	int N;		// number of creatures
	int no_Good;		// number of good creatures
	int no_Zobies;		// number of zombies
	creature** creatures_array;		// pointer pointing to the table of creatures
	public:
		creature_society(int ,int, int, int); 		// constructor
		~creature_society(); 		// destructor
		void beat(int); 		// beated the creature
		void bless(int); 		// blessed the creature
		void clone_next(int);		// Sturdy good creature -->> clone next
		void clone_zobies(int); 		// Sturdy bad creature -->> clone zombies
		int no_of_zobies(){ return no_Zobies; } 	// return number of zombies
		int no_of_good(){ return no_Good;}  		// return number of good creatures
		void print(int ); 			// print creature society
		void check_no_zobies();		// set the new number of zombies
		void check_no_good();		// set the new number of good creatures
}; 
