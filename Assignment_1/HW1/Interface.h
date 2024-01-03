class Bookcase{
	int N;   // the current number of books in the bookcase
	class Shelf **shelf_array;
	class Cabinet *cabinet;
    class Base *base;
    
	public:
    	Bookcase(int);
    	~Bookcase();
    	class Shelf *get_shelf_array(int); // return self i_th
    	class Cabinet* get_cabinet();      // return cabinet
    	bool place_book(char*,char*,int);  
		bool take_book();  
		void print(void);
};

class Shelf{
	int NMax;  // maximum capacity of shelf
	int current_capacity; // current capacity of shelf
	int *reserved_table;
	class Book **book_array;
	public:
		Shelf(int);
		~Shelf();
		void set_data(int);
		int free_space();
		int get_maxN();   // return maximum capacity of shelf
		void seat_reservation(int,int); 
		int reservation_table(int);
		class Book *get_book_array(int);  // return book i_th
		int get_empty();       // return 1 -->> empty , retuen 0 -->> isn't empty
		void print_shelf(int);
};


class Cabinet{
	class Shelf **shelf_array;
	public:
		Cabinet(int);
    	~Cabinet();
		class Shelf *get_shelf_array(int);
		void print_cabinet(int);
};

class Base{
	public:
		Base();
		~Base();
};

class Book{
	char* Title;
	char* Author;
	int ISBN;
	public:
		Book();     // constructor
	  	~Book();       // destructor
	    char* get_Title();   // return the Title
	    char* get_Author();  // return the Author
	    int get_ISBN();      // return ISBN
	    void set_book(char*,char*,int);  // set the new book
	    void remove_book();              // remove the book
		void print_book_array();         // print the book info
		void create_book();              
		
};
