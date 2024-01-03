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

public class sculpture extends masterpiece
{
        private int volume;
        private String material;
        public sculpture(int i){
            super(i);
            int temp;
            
            volume=ThreadLocalRandom.current().nextInt(0,300);

            temp=ThreadLocalRandom.current().nextInt(0,3);           
            temp=temp+1;
            
            switch(temp){       // Initialize  the material
            	case 1:
            		material="iron";
            		break;
            	case 2:
            		material="stone";
            		break;
            	case 3:
            		material="wood";
            		break;
	    }
            System.out.println("Creating an instance of sculpture");
        }
        
        public void getInfo(){      // Print all info
            super.getInfo();  
            System.out.println("Volume : " + volume);
            System.out.println("Material : " + material);
        }

        public int evaluate(String Movement,String Condition){      // Passing all arguments
            if(Movement.equals(super.get_movement())){
                if(Condition.equals(super.get_condition())){
                    return 1;   // Ssculpture is acceptable
                }
                else if(Condition.equals("good") && super.get_condition().equals("excellent")){
                    return 0;       // Ssculpture is not acceptable
                }
                else{ return 0; }   // Ssculpture is not acceptable
            } 
            else{ return 0; }       // Ssculpture is not acceptable
        }

        public int evaluate(String Movement){
            String Condition;
            Condition ="excellent";       // I initialize the string Condition = excellent
            return evaluate(Movement,Condition);      // Call -->> evalute.Pass all arguments and return the result
        }
}
