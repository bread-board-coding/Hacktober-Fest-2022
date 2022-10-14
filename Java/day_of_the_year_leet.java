//Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD,
// return the day number of the year.
//
//        Example 1:
//        Input: date = "2019-01-09"
//        Output: 9
//        Explanation: Given date is the 9th day of the year in 2019.
//        Example 2:
//        Input: date = "2019-02-10"
//        Output: 41
//
//        Constraints:
//
//        date.length == 10
//        date[4] == date[7] == '-', and all other date[i]'s are digits
//        date represents a calendar date between Jan 1st, 1900 and Dec 31th, 2019.

public class day_of_the_year_leet {
    public static void main(String[]args){
        System.out.print(dayOfYear("2019-02-10"));
    }
        public static int dayOfYear(String date) {
            int totaldays = 0;
            int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//        String dateoryear = "2019-02-10";
       String[] array = date.split("-");
        int year = Integer.parseInt(array[0]);
        int month = Integer.parseInt(array[1]);
        int day = Integer.parseInt(array[2]);

//            int year = Integer.valueOf(date.substring(0, 4));
//            int month = Integer.valueOf(date.substring(5, 7));
//            int day = Integer.valueOf(date.substring(8));
            for (int i = 0; i < month - 1; ++i) {
                totaldays += days[i];

                if (isLeapYear2(year) == true) {
                    totaldays = totaldays + 1;
                }
            }
             System.out.print("Number of days = ");
            return totaldays + day;

        }
        public static boolean isLeapYear2(int year){

            if( (year %400==0)||(year%100 !=0 && year%4==0))
                return true;

            else
                return false;

        }

    }
