import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		if(sc.hasNextInt()) {
			int n = sc.nextInt();
			if(n >= 1 && n <= 100) {
				System.out.println(n*(n+1)/2);
			}
		}

	}
}