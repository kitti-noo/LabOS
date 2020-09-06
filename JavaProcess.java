import java.io.*;
public class JavaProcess {
    public static void main(String[] args) throws IOException{
        if(args.length !=1){
            System.out.println("Usage: java JavaProcess <command>");
            System.exit(0);
        }
        ProcessBuilder pb = new ProcessBuilder(args[0]);
        Process proc = pb.start();

        InputStream is = proc.getInputStream();
        InputStreamReader isr = new InputStreamReader(is);
        BufferedReader br = new BufferedReader(isr);

        String line;
        while((line = br.readLine())!= null)
            System.out.println(line);
        br.close();
    }
}