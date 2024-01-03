/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Art;
import java.util.concurrent.ThreadLocalRandom; 
/**
 *
 * @author Panagiota_Gyftou
 */

abstract class masterpiece extends artifact{
        private String movement;
        private String condition;
        public masterpiece(int i){
            super(i);
            int temp;
            
            temp=ThreadLocalRandom.current().nextInt(0,3);                
            temp=temp+1;
  
            switch(temp){   // Initialize  the movement
            	case 1:
            		movement="impressionism";
            		break;
            	case 2:
            		movement="expressionism";
            		break;
            	case 3:
            		movement="naturalism";
            		break;
	    }

            temp=ThreadLocalRandom.current().nextInt(0,3);              
            temp=temp+1;
            
            switch(temp){    // Initialize  the condition
            	case 1:
            		condition="bad";
            		break;
            	case 2:
            		condition="good";
            		break;
            	case 3:
            		condition="excellent";
            		break;
	    }
            System.out.println("Creating an instance of masterpiece");
        }
        
        public String get_movement(){ return movement; }
        public String get_condition(){ return condition; }
        
        public void getInfo(){  // Print info
            super.getInfo();    // Call getInfo (class artifact) to print the important info  
            System.out.println("Movement : " + movement);
            System.out.println("Condition : " + condition);
        }
        
        public abstract int evaluate(String Movement,String Condition);
        public abstract int evaluate(String Movement);
}
