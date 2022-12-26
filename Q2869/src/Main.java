import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int V = sc.nextInt();
        int day;
//        int current = A;
//        while(current < V) {
//            current -= B;
//            day++;
//            current += A;
//        }
//        System.out.println(day);
        //시간초과가 나서 보니 반복문을 간단히 해야겠다!
        //마지막엔 B값이 빠지지 않고 A값 더하고 계산이 끝나니까
        //A값을 한번 빼고 남은 값은 A-B 의 값으로 나누면 계산이 빠를 것 같다.
//        if(V - A <= 0){ //한번도 안미끄러지고 하루만에 올라가니까 1일
//            day = 1;
//       }
//       else{
//            day = 1 + (int) Math.ceil((double) (V - A) / (double)(A - B)); //마지막날 올라가는거 1일
//       } //나눗셈 소수점이 날라가서 코드가 더러워졌다...
        //이것도 시간초과..
        //형변환이 시간도 먹고 코드도 더러운 것 같아서 안하기로 해보자
        day = 1 + (V-A)/(A-B);
        if(((V - A) % (A - B)) != 0){ //나머지가 존재하는 경우에는 1을 더해줘야함.
            day++;
        }

        System.out.println(day);
    }   //시간초과가 나서 알아보니 java8로 제출하니까 통과됐다!
}