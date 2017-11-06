import java.util.*;

public class Main {
	public static void main(String[] args) {
		Stack<Character> stack = new Stack<Character>();
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		char c = ' ';
		boolean result = true;
		if(input.charAt(0) == ')') result = false;
		else {
			for(int i = 0; i < input.length(); i++) {
				c = input.charAt(i);
				if(c == '(') stack.push(c);
				else {
					if(stack.isEmpty()) result = false;
					else stack.pop();
				}
			}
			if(!stack.isEmpty()) result = false;
		}

		if(result) System.out.println("YES");
		else System.out.println("NO");
	}
}