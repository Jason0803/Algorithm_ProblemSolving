import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Date today = new Date(2007,1,1);
		int inputMonth, inputDay;
		while (!sc.hasNextInt())
			sc.nextLine();
		
		inputMonth = sc.nextInt();
		inputDay = sc.nextInt();

		if(inputMonth < 1 || inputMonth > 12) {
			System.out.println();
		} else {
			switch(inputMonth) {
				case 2: {
					if(inputDay < 1 || inputDay > 28) {
						System.out.println();
						break;
					} else {
						Date input = new Date(2007,inputMonth,inputDay);
						getWeekDay(input, today);
						break;
					}
					
				}
				case 4: case 6: case 9: case 11: {
					if(inputDay < 1 || inputDay > 30) {
						System.out.println();
						break;
					} else {
						Date input = new Date(2007,inputMonth,inputDay);
						getWeekDay(input, today);
						break;
					}
				} 
				default: {
					if(inputDay < 1 || inputDay > 31) {
						System.out.println();
						break;
					} else {
						Date input = new Date(2007,inputMonth,inputDay);
						getWeekDay(input, today);
						break;
					}
				}
			}
		}
		
	}

	public static void getWeekDay(Date input, Date today) {
		int count = input - today;
		String day = "";
		switch(count%7) {
			case 0 : {
				day = "MON";
				break;
			}
			case 1 : {
				day = "TUE";
				break;
			}
			case 2 : {
				day = "WED";
				break;
			}
			case 3 : { 
				day = "THU";
				break;
			}
			case 4 : {
				day = "FRI";
				break;
			}
			case 5 : { 
				day = "SAT";
				break;
			}
			case 6 : {
				day = "SUN";
				break;
			}
			default : break;
		}
		System.out.println(day);
	}
}