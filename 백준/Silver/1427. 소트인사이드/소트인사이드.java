import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder(br.readLine());

        ArrayList<Character> arr = new ArrayList<>();

        for (int i = 0; i < sb.length(); i++) {
            arr.add(sb.charAt(i));
        }

        arr.sort(Character::compareTo);

        for (int i = arr.size(); i > 0; i--) {
            System.out.print(arr.get(i - 1));
        }
    }
}