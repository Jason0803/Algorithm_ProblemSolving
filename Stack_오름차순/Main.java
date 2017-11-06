import java.util.*;

public class Main {
	public static void main(String[] args) {
		int[] list = {3,2,5,1,4};
		System.out.println("Initial :");
		for(int i = 0; i < list.length; i++) {
			System.out.print(list[i] + ", ");
		}
		System.out.println();
		ascendingSort(list);
		for(int i = 0; i < list.length; i++) {
			System.out.print(list[i] + ", ");
		}
	}
	public static void ascendingSort(int[] list) {
		int temp = 0;
		for(int i=0; i < list.length; i++) {
			int pos = i;
			for(int j = i+1; j < list.length; j++) {
				if(list[j] < list[pos]){
					pos = j;
				}
			}
			temp = list[i];
			list[i] = list[pos];
			list[pos] = temp;
		}
	}
}