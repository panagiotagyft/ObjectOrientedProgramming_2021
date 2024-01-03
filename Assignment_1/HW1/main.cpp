#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include "Interface.h"

using namespace std;

int main(int argc,char *argv[]){
	int NMax,L,K1,K2, i;  
	Book **booktable;
	srand(time(NULL));
	
	NMax=atoi(argv[1]);                            
	L=atoi(argv[2]);    
	K1=atoi(argv[3]);    
	K2=atoi(argv[4]);    
	
	// create bookcase
    Bookcase bookcase(NMax);
    
    // create L books
    booktable=new Book*[L];
    cout << "\n\n -----  Create L= " << L << " books  -----" << endl;
	for(i=0; i < L; i++){
		booktable[i]=new Book(); 
		cout << i+1 ;  // numbering
		booktable[i]->create_book();
	}
	cout << endl << endl;
	
	// K1 random place_book
    cout << "  -----  Place " << K1 << " books  -----" << endl << endl;
    for(i=0; i < K1; i++){
    	if(bookcase.place_book(booktable[i]->get_Title(),booktable[i]->get_Author(),booktable[i]->get_ISBN())==false){
    		cout << "Sorry.There is no more shelf space\n" << endl;
		}		
	}
    cout << endl << endl;
    
    // K2 random take_book
	cout << "  -----  Take " << K2 << " books  -----" << endl << endl;
	for(i=0; i < K2; i++){
		if(bookcase.take_book()==false){
			cout << "Empty Shelf! Cannot remove book\n" << endl;
		}
	}	 
	cout << endl << endl;
	
	// print bookcase
	cout << "-----  Print Bookcase -----"<< endl << endl;
	bookcase.print();
	
	cout << "\n\n -----  Delete L= " << L << " books  -----" << endl;
	for(i=0; i < L; i++){  delete booktable[i]; }
    delete[] booktable;
    cout <<"---------------------------------"<< endl << endl;
    return 0;
}
