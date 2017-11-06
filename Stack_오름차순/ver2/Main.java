import java.util.*;

public class Main {
	public static void main(String[] args) {
        Stack<Integer> input = new Stack<Integer>();
        input.add(34);
        input.add(3);
        input.add(31);
        input.add(98);
        input.add(92);
        input.add(23);
        System.out.println("input: "+input);
        System.out.println("final sorted list: "+sortStack(input));
	}
	public static Stack<Integer> sortStack(Stack<Integer> stack) {
		Stack<Integer> tempStack = new Stack<Integer>();
		int index = 0;
		int temp = 0;
		while(!stack.isEmpty()) {
            int tmp = stack.pop();
            System.out.println("Element taken out: "+tmp);
            while(!tempStack.isEmpty() && tempStack.peek() > tmp) {
                stack.push(tempStack.pop());
            }
            tempStack.push(tmp);
            System.out.println("stack: "+stack);
            System.out.println("tempStack: "+tempStack);
        }

		return tempStack;
	}
}