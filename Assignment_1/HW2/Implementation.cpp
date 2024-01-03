#include <iostream>
#include <cstdlib>
#include "Interface.h"

using namespace std;

Bank::Bank(int k, int l, int cashiers):K(k), cashiers(cashiers){
	int i;
	cash_desk_array=new Cash_Desk*[cashiers]; 
	for(i=0; i < cashiers; i++){
		cash_desk_array[i]=new Cash_Desk(l);   // i creat the cash_desk. l equal with L
	}
	
	cout<<"The bank was created"<<endl;
}

Bank::~Bank(){
	int i;
	cout << "The bank was destroyed "<<endl;
	
	for(i=0; i < cashiers; i++){   
		delete cash_desk_array[i]; // delete cash desk
	}
	
	delete[] cash_desk_array;
}

Cash_Desk::Cash_Desk(int l):L(l){
	cout<<"The cash desk was created"<<endl;
}

Cash_Desk::~Cash_Desk(){
	cout << "The cash desk was destroyed "<<endl;
}

//==============================================================      Bank     ======================================================================

int Bank::check_to_open(){
	int difference, mult;
	difference=last_customer-curr_serving;
	mult=K*counter_open;
	if(difference > mult){ return 1;}   // last_customer-curr_serving > K*counter_open -->> open cashier
	else{ return 0;}
}

int Bank::check_to_close(){
	int difference, mult, x; 

	difference=last_customer-curr_serving;
	x=counter_open-1;
	mult=x*K;
	if(difference <= mult){ return 1;} 
	else{ return 0;}
}

void Bank::enter(){
	int i, x, flag, first;

	if(check_to_open()==0){  last_customer++;} // if the number of open cashiers is sufficient --> increase the last_customer
	else{ 
	    if(opened_cashiers()!=5){    // if are not all chashiers open
	    	for(i=0; i < cashiers; i++){ // find the first close cashier
	    		if(get_cash_desk_array(i)->is_open()==0){ break; }  
			}			
			open(i);         // open -> the closed cashier
			last_customer++; //and increase the last_customer
		} 
		else{ // if all cashiers are open
			cout <<"Sorry you cannot enter until some customers are served!" << endl;
			waiting_people++;  // increase the number of customers who didn't enter the bank		
		}
	}
}

void Bank::serve(){
	int i, l, k;
	i_th=0;
    
    k=wainting_customers(); // return last_customer-curr_serving
    for(l=0; l < k; l++){  // i serve the wainting_customers
    	if(opened_cashiers()==0){ 
			open(0);
	        i_th=0;
	        i=0;
		}
		else{
			if(i_th>4 || get_cash_desk_array(i_th)->is_open()==0){ i_th=0;}  // if i_th=5 -->> i_th=0 or if the next (i_th) cashier isn't open -> i_th=0
			for(i=i_th; i < cashiers; i++){
				if(get_cash_desk_array(i)->is_open()==1 && get_cash_desk_array(i)->is_free()==1){
					i_th=i;
					i_th++;
					break;
				}
			}
		}
		cout << "Customer no:	" <<  curr_serving << endl;
		cout << "by cashier no:	" << i + 1  << endl << endl;
		
		get_cash_desk_array(i)->set_data(0,1); //serve free_flag=0 is not free and serving_flag=1 the cashier serve 
		if(get_cash_desk_array(i)->free()==1){ close(i);}  // free the cashier .If free() return 0 should be close the i cashier
		exit();
	}
	
	cout << "===============================================================\n" << endl;
}

void Bank::exit(){
	int i;
	curr_serving++;  //increase curr_serving  is the counter -> customer service
	if(check_to_close()==1){ // if check_to_close return 1 -->> close the first open cashier
		for(i=0; i < cashiers; i++){ if (get_cash_desk_array(i)->is_open()==1){ break;} }
		close(i);
	}
}

void Bank::close(int i){
	get_cash_desk_array(i)->close(); // close cashier
	counter_open--; 
	cout << "Cashier no:  " << i+1 << "	-->	closed" << endl << endl;
}

void Bank::open(int i){
	get_cash_desk_array(i)->open(); // open the i cash desk
	get_cash_desk_array(i)->set_data(1,0);  // i set the free_flag=1 --> is free and serving_flag=0 -->> the cashier don't serve
	counter_open++;                 // increase the counter of open cashiers
	cout << "Cashier no:  " << i+1 << "	-->	open" << endl << endl;   //print the no.cashier is open 
}

void Bank::service_wainting_customers(){
	int i, w;
	w=waiting_people;
	waiting_people=0;
	for(i=0; i <w; i++){
		enter();
	}
	serve();
}

int Bank::wainting_customers(){
	cout<< endl << "Waiting_customers:	" << last_customer-curr_serving << endl;
	return last_customer-curr_serving;
}

int Bank::opened_cashiers(){
	return counter_open;
}

void Bank::initialize(){
	last_customer=1;    // i initialize last_customer equal with 1
	counter_open=0;     // i initialize the counter of open cashiers equal with 0
	waiting_people=0;   // waiting_people -->> customers who didn't enter the bank.I initialize this counter equal with 0
	open(0);            // open the first cash desk
	curr_serving=1;     // i initialize curr_serving=1 
}

int Bank::num_customers_waiting(){
	cout << waiting_people << "	customers waiting to be served." << endl << endl;
	return waiting_people;
}
//==============================================================      Cash_Desk      ======================================================================

void Cash_Desk::open(){
	open_flag=1;
	customers_served=0;
}

void Cash_Desk::close(){
	open_flag=0;
}

int Cash_Desk::free(){
	free_flag=1;
	customers_served++;  // counter -> non-stop customer service
	serving_flag=0;

	if(customers_served==L){ customers_served=0; return 1;}  // The cashier has reached the maximum number of services it can provide --> close this cashier
	return 0;  
}

class Cash_Desk *Bank::get_cash_desk_array(int i){
	return cash_desk_array[i];
}

int Cash_Desk::is_free(){
	return free_flag;
}

int Cash_Desk::is_open(){
	return open_flag;
}

void Cash_Desk::set_data(int flag1, int flag2){
	free_flag=flag1;  // the cashier is free if flag=1 else if flag=0 is not free
	serving_flag=flag2; //if flag=0 the cashier don't serve else if flag=1 the cashier serve
}

