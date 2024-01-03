class Bank{
	int last_customer;    // count the last customer who entered
	int curr_serving;     // no. customer service
	int counter_open;     // number-->> opened cashiers
	int waiting_people;   // counter no enter
	int cashiers;      
	int i_th;
	int K;   
	class Cash_Desk ** cash_desk_array;
	public:
		Bank(int,int,int);
		~Bank();
    	int check_to_open();
    	int check_to_close();
    	void enter();
    	void serve();
    	void exit();
    	void open(int);
    	void close(int);
    	int wainting_customers();
    	int opened_cashiers();
    	void service_wainting_customers();   // service all customers who didn't enter
    	class Cash_Desk *get_cash_desk_array(int);
    	int  num_customers_waiting();  
        void initialize();    // initialize the Bank
};

class Cash_Desk{
	int open_flag;
	int serving_flag;
	int customers_served;
	int free_flag;
	int L;
	public:
		Cash_Desk(int);
		~Cash_Desk();
        int is_open();
        void open();
      	void close();
        int free();
		int is_free();
		void set_data(int,int);
		
        
};
