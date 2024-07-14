import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder input = new StringBuilder(br.readLine());

        Integer temp = 0;

        for (int i = 0; i < T; i++) {
            temp += input.charAt(i) - '0';
        }

        System.out.println(temp);
    }
}