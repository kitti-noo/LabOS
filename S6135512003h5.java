//6135512003
class Sequence implements Runnable{
    private int n;
    private int [] S ;
    public Sequence (int number){
        
        this.n = number;
    }  
    public void run (){
   
        S = new int[n+4]; 
        S[0] = 1;
        S[1] = 1;
        S[2] = 2;
        S[3] = 2;
        for (int i=0;i<n;i++){
            if (i>3){
                if (i%3==0){
                    S[i]=S[i-1];
                }
                else{
                    S[i]=S[i-2]+S[i-2]-1;
                }
            }
            System.out.print(S[i] + " ");
        }
         System.out.println();       
    }
    
}

public class S6135512003h5 {
    public static void main(String[] args) {
        if(args.length !=1){
            System.out.println("Usage: java S6135512003h5 <number>");
            System.exit(0);
        }
        Integer number = Integer.parseInt(args[0]);
        int m = 2; // m is 2 because studentID : 3 is odd number

        System.out.println("<<Create two thread>>");
        for (int i = 0; i < m; i++) {
            Thread thread = new Thread(new Sequence(number)); //create thread 
            System.out.print("Thread ID"+thread.getId()+": "); //print out the Thread ID
            thread.start(); 
            try{
                thread.join();
            }    
            catch(InterruptedException e){
                e.printStackTrace();
            }
        }
    }
}
