import java.util.Scanner;
import java.util.Arrays;

public class swx_1244 {
	static int swap(char[] array, int from, int to) {
		char[] arraycopy = Arrays.copyOf(array, array.length);
		char temp = arraycopy[from];
		arraycopy[from] = arraycopy[to];
		arraycopy[to] = temp;
		
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0; i < arraycopy.length; i++) {
			sb.append(arraycopy[i]);
		}
		return Integer.parseInt(sb.toString());
	}
    static int getMax(String input, int count) {
    	int result = Integer.parseInt(input);

        if(count == 0) {
        	return result;
        }
      	char[] arr = input.toCharArray();
      	

      	int temp = 0;

      	for(int i = 0; i < input.length()-1; i++) {
      		for(int j = i+1; j < input.length(); j++) {
      			if(temp < swap(arr,i,j)){
      				temp = swap(arr,i,j);
      			}
      		}
      	}
        return getMax(new Integer(temp).toString(), count-1);
    }
    
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T;
		String input;
		int count;
        
		T = sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++) {
			input = sc.next();
			count = sc.nextInt();
			int result = getMax(input, count);
			System.out.println("#"+test_case+ " " + result);
		}
	}
}