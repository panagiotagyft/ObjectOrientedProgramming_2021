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

public class painting extends masterpiece{
        private int length;
        private int width;
        private String technique;
        public painting(int i){
            super(i);
            int temp;
            
             length = ThreadLocalRandom.current().nextInt(0,100);
             width = ThreadLocalRandom.current().nextInt(0,100);
             
            temp=ThreadLocalRandom.current().nextInt(0,3);                
            temp=temp+1;
            
            switch(temp){  // Initialize  the technique
            	case 1:
            		technique="oil";
            		break;
            	case 2:
            		technique="aquarelle";
            		break;
            	case 3:
            		technique="tempera";
            		break;
	    }
             System.out.println("Creating an instance of painting");
        }
        
        public void getInfo(){  // Print all info
            int surface;
            super.getInfo();
            System.out.println("Length : " + length);
            System.out.println("Width : " + width);
            System.out.println("Technique : " + technique);
            surface= length*width;   // Area
            System.out.println("Sureface = " + surface);
        }
 
        public int evaluate(String Movement,String Condition){      // Passing all arguments
            if(Movement.equals(super.get_movement())){
                if(Condition.equals(super.get_condition()) || (Condition.equals("good") && super.get_condition().equals("excellent"))){
                    return 1;      // Painting is acceptable
                }
                else{ return 0; }  // Painting is not acceptable
            }
            else{ return 0; }   // Painting is not acceptable
        }

        public int evaluate(String Movement){       // Incomplete argument
            String Condition;
            Condition ="good";      // I initialize the string Condition = good
            return evaluate(Movement,Condition);    // Call -->> evalute.Pass all arguments and return the result
        }
}
