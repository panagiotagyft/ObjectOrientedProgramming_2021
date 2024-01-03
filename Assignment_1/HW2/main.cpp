#include <iostream>
#include "Interface.h"

using namespace std;

int main(int argc,char *argv[]){
	int K,M,N,L, i,j,cash; 
		
	K=atoi(argv[1]);                            
	M=atoi(argv[2]);    
	N=atoi(argv[3]);    
	L=atoi(argv[4]);  
	cash=5;
	   
	Bank bank(K,L,cash); // create the Bank
	
	bank.initialize();  // initialize the bank
	
	cout << endl;
	for(i=0; i < M; i++){
		for(j=0; j < N; j++){
			bank.enter();  // enter -> customer
		}
		bank.serve();    // serve -> customer
	}
	
	cout << endl << "Serve waiting customers" <<endl;
	while(bank.num_customers_waiting()!=0){
		bank.service_wainting_customers();   // serve waiting people
	}
	return 0;
}
