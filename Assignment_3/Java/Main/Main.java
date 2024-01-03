/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package Main;
import Art.painting;
import Art.sculpture;
import Art.artifact;
import java.util.concurrent.ThreadLocalRandom; 
/**
 *
 * @author @author Panagiota_Gyftou
 */
public class Main{
    public static void auction(artifact[] art_array, int N, String movement, String condition, int flag){
        int i;
        System.out.println();
        for(i=0 ; i < N ; i++){
            art_array[i].getIndex();        // Print the index
            art_array[i].getInfo();         // Print info
            // Get the evaluate 
            if(flag==1){
            System.out.println("Evaluate with condition  : " + art_array[i].evaluate(movement,condition) );
            }
            else{
            System.out.println("Evaluate without condition: " + art_array[i].evaluate(movement));
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        int N, paint_sculpt, i, flag;
        String movement="", condition="";

	if(args.length==0){ 
            System.out.println("Missing arguments...\n");
            return;
	}
        else if(args.length==2){
            N=Integer.parseInt(args[0]);         // N-->> objects to create
            movement=args[1];                    // Movement
            flag=2;
        }
        else if(args.length==3){
            N=Integer.parseInt(args[0]);         // N-->> objects to create
            movement=args[1];                    // Movement
            condition=args[2];                   // Condition
            flag=1;
	}
        else{
            System.out.println("Too many arguments...\n");
  	    return;
        }
	
        artifact[] art_array=new artifact[N];
        
        for(i=0 ; i < N; i++){   
	 	paint_sculpt=ThreadLocalRandom.current().nextInt(0,2);    // random selection
	 	if(paint_sculpt==0){ art_array[i]=new painting(i); }  // If paint_sculpt=0-->> created a painting
	 	else{  art_array[i]=new sculpture(i); }   // If paint_sculpt=1-->> created a sculpture
	}
        
        // Call--> auction to print all the info about all the masterpieces 
        auction(art_array, N, movement, condition, flag); 
        return;
    }
    
}
