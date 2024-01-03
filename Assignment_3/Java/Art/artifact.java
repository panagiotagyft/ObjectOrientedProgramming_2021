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

public abstract class artifact {
        private int index;
        private String creator;
        private int year;
        public artifact(int i){     // Constructor
            index=i;
            creator="Creator" + (i+1);   // e.g. i=1  -->>> print Creator2 (-> the second creator)
            year=ThreadLocalRandom.current().nextInt(1,2022);   // random year 
            System.out.println("Creating an instance of artifact");
        }
        public void getInfo(){  // Print the important informations of the creation
            System.out.println("Creator : " + creator);  
            System.out.println("Year : " + year);
        }
        public void getIndex(){ System.out.println("Index : " + index); }  // Print index number 
        
        public abstract int evaluate(String Movement,String Condition);   
        public abstract int evaluate(String Movement);       
}
