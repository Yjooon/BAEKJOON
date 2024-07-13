import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < input.length(); i++) {
            char chars = input.charAt(i);
            if (chars >= 'A' && chars <= 'M') {
                chars = (char) (chars + 13);
            } else if (chars > 'M' && chars <= 'Z') {
                chars = (char) (chars - 13);
            } else if (chars >= 'a' && chars <= 'm') {
                chars = (char) (chars + 13);
            } else if (chars > 'M' && chars <= 'z') {
                chars = (char) (chars - 13);
            }
            output.append(String.valueOf(chars));
        }
        System.out.println(output);
    }
}
