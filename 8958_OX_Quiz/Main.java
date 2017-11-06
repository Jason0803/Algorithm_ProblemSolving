import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<String> inputList = new ArrayList<String>();
		
		String input = sc.nextLine();
		calculate(input);
	}
	public static void calculate(String input) {
		Stack<Character> stack = new Stack<Character>();
		int sum = 0;
		for(int i = 0; i < input.length(); i++) {
			stack.push(input.charAt(i));
		}
		
		while(!stack.isEmpty()) {
			int count = 0;
			while(!stack.isEmpty() && stack.pop() == 'O')
				count++;
			sum += count;
		}

		System.out.println(sum);
	}	
}