import java.util.Random;
import java.io.*;
public class act03 {
    public static void main(String[] args) {
        int num=0;
        if (args.length<1){
            System.out.println("\n This program requires an integer argument.");
            System.exit(1);
        }
        System.out.println("Compare Number \n-Greater than -> Win \n-Less than -> Lost");
        try {
            num = Integer.parseInt(args[0]);
        }
        catch (NumberFormatException nfe){
            System.out.println("The first argument must be an integer.");
            System.exit(1);
        }
        System.out.println("\nYou enter "+ num);
        Random randomGenerator = new Random();
        int randomInt = randomGenerator.nextInt(100);
        System.out.println("Ans : "+ randomInt);
        
        
        if (num < randomInt){
            System.out.println("You lost!");
        }
        else if (num > randomInt){
            System.out.println("You won!");
        }
        else {
            System.out.println("Wow! We should go out coz we think alike.");
        }
    }
}