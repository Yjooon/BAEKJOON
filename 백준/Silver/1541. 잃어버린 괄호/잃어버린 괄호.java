import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stMinus = new StringTokenizer(br.readLine(), "-");
        StringTokenizer stPlus;

        Queue<Integer> queue = new LinkedList<>();

        while (stMinus.hasMoreTokens()) {
            stPlus = new StringTokenizer(stMinus.nextToken(), "+");
            int temp = 0;
            while (stPlus.hasMoreTokens()) {
                int num = Integer.parseInt(stPlus.nextToken());
                temp += num;
            }
            queue.add(temp);
        }

        int result = queue.poll();
        while (!queue.isEmpty()) {
            result -= queue.poll();
        }
        System.out.println(result);
    }
}