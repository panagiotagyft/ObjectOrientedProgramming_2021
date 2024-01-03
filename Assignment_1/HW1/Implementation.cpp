#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include "Interface.h"

using namespace std;



Bookcase::Bookcase(int maxN){
	int i;
	
	shelf_array=new Shelf*[3];
	for(i=0; i < 3; i++){
		shelf_array[i]=new Shelf(maxN);     // create 3 shelves with maximum capacity maxN
		shelf_array[i]->set_data(0);   // i initialize the data. ( current_capacity) 
	}
	cabinet=new Cabinet(maxN);  // create cabinet
	base=new Base();            // create base
	N=0;       // i nitialize the number of books in the bookcase equal with zero
	
	cout<<"The bookcase was created"<<endl;
}

Bookcase::~Bookcase(void){
	int i;
	cout << "The bookcase was destroyed "<<endl;
	delete base; // delete the base
	delete cabinet; // delete the cabinet
	
	for(i=0; i < 3; i++){
		delete shelf_array[i];   // delete the array of shelves
	}
	
	delete[] shelf_array;    
}

Cabinet::Cabinet(int maxN){
	int i;
	shelf_array=new Shelf*[2];
	for(i=0; i < 2; i++){
		shelf_array[i]=new Shelf(maxN);      // create 2 shelves with maximum capacity maxN
		shelf_array[i]->set_data(0);    // i initialize the data. ( current_capacity and maximum capacity) 
	} 
	cout<<"The cabinet was created"<<endl;
}

Cabinet::~Cabinet(void){
	int i; 
	cout << "The cabinet was destroyed "<<endl;	

	for(i=0; i < 2; i++){
		delete shelf_array[i];   // delete the array of shelves
	}
	delete[] shelf_array;
	
}

Shelf::Shelf(int maxN):NMax(maxN) {
	int i; 

	book_array=new Book*[maxN];
	reserved_table= new int[maxN];
	for(i=0; i < maxN ; i++){
		book_array[i]=new Book(); // create book. 0 -->> i initialize the book data
		reserved_table[i]=-1;      // reserved_table is array with flags.I save if the position is free or not
	}
		cout << "A shelf was created " << endl;
}

Shelf::~Shelf(void){
	int i;
	cout << "A shelf was destroyed "<<endl;	

	delete[] reserved_table;
	
	for(i=0; i < NMax; i++){
		delete book_array[i];  // delete array of books
	}
	delete[] book_array;	
}

Base::Base(){
	cout<<"The base was created"<<endl;
}

Base::~Base(){
	cout<<"The base was destroyed"<<endl;
}

Book::Book(){
	Title = new char[100];
	Author = new char[100];
	
	ISBN=-1;
    strcpy(Title,"NULL");	
	strcpy(Author,"NULL");	 
		   
	cout<<"The book was created"<<endl;	
}

Book::~Book(){
	delete[] Title;
	delete[] Author;
	cout<<"The book was destroyed"<<endl;
}

//=====================================================================          Bookcase          =====================================================================
bool Bookcase::place_book(char* title, char* author, int isbn){
	
	int i,p,max,position;
	p=rand()%5;       // choose  random shelf to place the book
    position=p+1;     
    
    // numbering shelves
	switch(position){
    	case 1:
    		cout << "1: Placing book on the top bookcase shelf " << endl;
    		break;
		case 2:
			cout << "2: Placing book in middle bookcase shelf" << endl;
			break;
		case 3:
			cout<< "3: Placing book on the bottom bookcase shelf " << endl;
			break;
		case 4:
			cout << "4: Placing book on the top cabinet shelf of bookcase" << endl;
			break;
		case 5:
			cout << "5: Placing book on the bottom cabinet shelf of bookcase" << endl;
			break;
	}
    	
	if(p <=2){  // if shelves is: 1.(on the top shelf) or 2.(in middle shelf) or 3.(on the bottom shelf)
		if(get_shelf_array(p)->free_space()!=0){    // checking free space 
			get_shelf_array(p)->set_data(1);    // capacity update
			max=get_shelf_array(p)->get_maxN();    // max -> maximum capacity of shelf
			for(i=0; i < max; i++){                 // find free position
				if(get_shelf_array(p)->reservation_table(i)==-1){  // if current position is free 
					get_shelf_array(p)->seat_reservation(1,i);     // reserved the position
					N=N+1;                                         // increase the number of books in the bookcase 
					cout << "number books:    "<< N <<endl << endl;
					get_shelf_array(p)->get_book_array(i)->set_book(title,author,isbn); // add a new book (info:Author,Title,ISBN)
					cout << "Print Shelf" << endl;
					get_shelf_array(p)->print_shelf(p);   // print shlef
				    break; }
			}
		}
		else{ return false;} // if shelf is full -->> There is no more space (return false)
	}
	else {  // the identification of the cupboard shelves is 0 and 1.If p=3 the shelf is p=p-3=3-3=0  0.(on the top cabinet shelf ) and 1.(on the bottom cabinet)
		if(get_cabinet()->get_shelf_array(p-3)->free_space()!=0){    // checking free space 
			get_cabinet()->get_shelf_array(p-3)->set_data(1);    // capacity update
			max=get_cabinet()->get_shelf_array(p-3)->get_maxN();    // max ->  maximum capacity of shelf
			for(i=0; i < max; i++){                                  // find free position
				if(get_cabinet()->get_shelf_array(p-3)->reservation_table(i)==-1){   // if current position is free 
					get_cabinet()->get_shelf_array(p-3)->seat_reservation(1,i);      // reserved the position
					N=N+1;                                                           // increase the number of books in the bookcase
					cout << "number books:    "<< N <<  endl << endl;
					get_cabinet()->get_shelf_array(p-3)->get_book_array(i)->set_book(title,author,isbn);   // add a new book (info:Author,Title,ISBN)
					cout << "Print Shelf" << endl;
					get_cabinet()->print_cabinet(p-3); // print shlef
				    break;	}
			}
		}
		else{ return false;}  // if shelf is full -->> There is no more space (return false)
	}
	return true; // if process place_book successed  -->> return true
}

bool Bookcase::take_book(){
	int i,p,max,position; 
	p=rand()%5;      // choose  random shelf to take the book
    position=p+1;
    
    // numbering shelves
	switch(position){
    	case 1:
    		cout << "1: Removing book from the top bookcase shelf " << endl;
    		break;
		case 2:
			cout << "2: Removing book from the middle bookcase shelf " << endl;
			break;
		case 3:
			cout<< "3: Removing book from the bottom bookcase shelf " << endl;
			break;
		case 4:
			cout << "4: Removing book from the top cabinet shelf of bookcase" << endl;
			break;
		case 5:
			cout << "5: Removing book from the bottom cabinet shelf of bookcase" << endl;
			break;
	}
	if(p <=2){    // if shelves is: 1.(on the top shelf) or 2.(in middle shelf) or 3.(on the bottom shelf)
		if(get_shelf_array(p)->free_space()!=1){     // checking free space 
			get_shelf_array(p)->set_data(-1);    // capacity update
			max=get_shelf_array(p)->get_maxN();     // max ->  maximum capacity of shelf
			for(i=0; i < max; i++){                  // find reserved position
				if(get_shelf_array(p)->reservation_table(i)==1){  // if current position isn't free 
					get_shelf_array(p)->seat_reservation(-1,i);   // released the position
					N=N-1;                                        // reduce the number of books in the bookcase
					cout << "number books:    "<< N << endl << endl; 
					get_shelf_array(p)->get_book_array(i)->remove_book();  // remove the book
					cout << "Print Shelf" << endl;
					get_shelf_array(p)->print_shelf(p); // print shelf
				    break; }
			}
		}
		else{ return false;}  // if shelf is empty return false (there is no book to remove)
	}
	else{  // the identification of the cupboard shelves is 0 and 1.If p=3 the shelf is p=p-3=3-3=0  0.(on the top cabinet shelf ) and 1.(on the bottom cabinet)
		if(get_cabinet()->get_shelf_array(p-3)->free_space()!=1){  
			get_cabinet()->get_shelf_array(p-3)->set_data(-1);
			max=get_cabinet()->get_shelf_array(p-3)->get_maxN();    
			for(i=0; i < max; i++){  
				if(get_cabinet()->get_shelf_array(p-3)->reservation_table(i)==1){
					get_cabinet()->get_shelf_array(p-3)->seat_reservation(-1,i);
					N=N-1;
					cout << "number books:    "<< N << endl << endl;
					get_cabinet()->get_shelf_array(p-3)->get_book_array(i)->remove_book(); // remove the book
					cout << "Print Shelf" << endl;
					get_cabinet()->print_cabinet(p-3); // print shelf
				    break;	} 
			}
		}
		else{ return false;}
	}
	return true;
	
	
}

class Shelf *Bookcase::get_shelf_array(int i){
	return shelf_array[i];    // return the i shelf (i=0,1,2,3,4) 
}

void Bookcase::print(){
	int i;

	for(i=0; i < 3; i++){ get_shelf_array(i)->print_shelf(i); } // printf shelves
	for(i=0; i < 2; i++)get_cabinet()->print_cabinet(i);        // printf cabinet
}

class Cabinet *Bookcase::get_cabinet(){
	return cabinet;    // return the cabinet
}


//=====================================================================          Cabinet          ======================================================================


class Shelf *Cabinet::get_shelf_array(int i){
	return shelf_array[i];    // return self i
}


void Cabinet::print_cabinet(int i){
	int position, maxN, j;
	maxN=get_shelf_array(0)->get_maxN();
	

	position=i+1;
	switch(position){
		case 1:
			cout << "\nOn the top cabinet shelf of bookcase:" << endl<<"----------------------------------------\n"<<endl;
    		break;
		case 2:
		    cout << "\nOn the bottom cabinet shelf of bookcase:" << endl <<"----------------------------------------\n"<<endl;
			break;
	}
	    
	for(j=0; j < maxN; j++){
		if(get_shelf_array(i)->get_empty()){  // if the shelf is empty -->> stop the printing process and print the message "Empty Shelf"
			cout << "Empty Shelf" << endl; 
			break;
		} 
		else{ 
			cout<< j+1; 
			get_shelf_array(i)->get_book_array(j)->print_book_array(); } // print books
	}
	cout << "_______________________________________________________________________________________________" << endl;
    
}

//=====================================================================          Shelf          =====================================================================

void Shelf::set_data(int space){
	current_capacity=current_capacity+space;  // capacity update, current_capacity-->> reserved space
}

class Book *Shelf::get_book_array(int i){
	return book_array[i];  // return the content of the position 
}

int Shelf::get_maxN(){
	return NMax;	// return maximum capacity of shelf
}

int Shelf::free_space(){
	if(current_capacity==NMax) { return 0;}   // if current capacity is equal with maximum capacity of shelf -->> the shelf is full (return 0);
	else if(current_capacity==0){ return 1;}  // else if the shelf isn empty (return 1)
	else{ return 2;}                          // else the shelf isn't full and isn't empty (return 2)
}

void Shelf::seat_reservation(int flag, int position){
	reserved_table[position]=flag;    // if flag is 1 the position is reserved else if flag is 0 the position is free
}

int Shelf::reservation_table(int seat){
	return reserved_table[seat];  // return the position if is free or reserved position
}

void Shelf::print_shelf(int i){ 
	int j, position, maxN;
	position=i+1;
	maxN=NMax;
	
	// numbering shelves.
    switch(position){
    	case 1:
   		cout << "\nThe top bookcase shelf:" << endl<<"----------------------------------------\n"<<endl;
   		    break;
	    case 2:
	    	cout << "\nThe middle bookcase shelf:" << endl<<"----------------------------------------\n"<<endl;
		    break;
	    case 3:
	    	cout<< "\nThe bottom bookcase shelf:" << endl <<"----------------------------------------\n"<<endl;
	    	break;
    }
	for(j=0; j < maxN; j++){
		if(get_empty()==1){  // if the shelf is empty -->> stop the printing process and print the message "Empty Shelf"
			cout << "Empty Shelf" << endl;
			break;
		} 
		else{
			cout<< j+1;
		 	get_book_array(j)->print_book_array();} // print books
	}
	cout << "_______________________________________________________________________________________________" << endl;
}

int Shelf::get_empty(){
	if(current_capacity==0){ return 1;} // if current_capacity equal with 1 -->> empty shelf (return 1)
	else{ return 0;}  // else the shelf isn't empty (return 0)
}

//=====================================================================            Book            ======================================================================

void Book::create_book(){
	int i, isbn, y;
	Title = new char[100];
	Author = new char[100];
	char *random;
    random=new char[100];
    char alphanum[] ="AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"; 
    
	for (int i = 0; i < 5; ++i) { // random Title
        y=rand()%52;
        random[i]=alphanum[y];
	}
    
    strcpy(Title,random);
    cout<<". Title:	"<< Title;
        
    for (int i = 0; i < 5; ++i) { // random Author 
        y=rand()%52;
        random[i]=alphanum[y];
	}
	strcpy(Author,random);
    cout<<"		Author:  "<< Author;      

    isbn=rand()%1000; // random isbn (0...999)
    ISBN=isbn;
    cout<<"		ISBN:  "<< ISBN << endl << endl; 
    
}

int Book::get_ISBN(){
	return ISBN;    // return ISBN (International Standard Book Number)
}

char* Book::get_Title(){
	return Title;  // The title of book
}

char* Book::get_Author(){
	return Author;  // return the Name of author
}

void Book::set_book(char* title,char *author,int isbn){  // info:book
	strcpy(Title,title);  
	strcpy(Author,author);
	ISBN=isbn;
	cout<<"Book Title:	" << Title <<",	Book Author:	" << Author  <<",	Book Number (ISBN):	" << ISBN <<  endl; 
}

void Book::remove_book(){ // remove book
	strcpy(Title,"NULL");
	strcpy(Author,"NULL");
	ISBN=-1;
}

void Book::print_book_array(){ // print books informations
	if(ISBN==-1){ cout << ".	Empty Position\n" << endl;}
	else{ cout<<".	{Book Title:   " << Title <<"	}		{Book Author:   " << Author  <<"	}		{Book Number (ISBN):   " << ISBN <<"	}\n"<<  endl; } 
} 


