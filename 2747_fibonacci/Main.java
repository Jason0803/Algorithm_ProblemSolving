import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		if(input > 45 || input <= 0)  System.out.println();
		else System.out.println(fibonacci(input));
	}
	public static int fibonacci(int n) {
		if(n <=1 ) return n;
		return n + fibonacci(n-1);
	}
}