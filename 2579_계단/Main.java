import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> steps = null;
		int input = 0;
		while (!sc.hasNextInt())
			sc.nextLine();
		
		int loop = sc.nextInt();

		if(loop <= 0 && loop >300) {
			System.out.println();
		} else {
			steps = new ArrayList<Integer>();
			steps.add(0);

			for(int i = 0; i < loop; i++) {

				while (!sc.hasNextInt())
					sc.nextLine();
				input = sc.nextInt();
				if(steps.get(i) >= input) break;
				else steps.add(input);
			}
		}
		// to check the steps
		System.out.println(steps);


		
	}
	public static int maximumScore(ArrayList<Integer> steps) {
		int rand = 0;
		int sum = 0;
		for(int i = 0; i < steps.size();) {
			if(i == steps.size()) sum += steps.get(i+1);
			else {
				rand = (Math.random*10 +1) % 2 +1; // 1 or 2 
				i += rand;
			}
		}

	}
}