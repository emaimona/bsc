package travel;

public class DayAndTime {
    private int year;
    private int month;
    private int day;
    private int hour;
    private int minute;

    public DayAndTime(int year, int month, int day, int hour, int minute) {
        this.year = year;
        this.month = month;
        this.day = day;
        this.hour = hour;
        this.minute = minute;
    }

    public DayAndTime(){
        this(2021, 12, 22, 04, 30);
    }

    public String getTime() {
        String shour = ((this.hour < 10) ? "0"+this.hour : this.hour+"");
        String sminute = ((this.minute < 10) ? "0"+this.minute : this.minute)+"";
        return shour + ":" + sminute;
    }

    @Override
    public String toString() {
        String sday = ((this.day < 10) ? "0"+this.day : this.day+"");
        String shour = ((this.hour < 10) ? "0"+this.hour : this.hour+"");
        String sminute = ((this.minute < 10) ? "0"+this.minute : this.minute)+"";
        String smonth = ((this.month < 10) ? "0"+this.month : this.month+"");
        return this.year + "." + smonth + "." + sday + " at " + shour + ":" + sminute;
    }
 
    public int getYear() {
        return this.year;
    }

    public int getMonth() {
        return this.month;
    }

    public int getDay() {
        return this.day;
    }

    public int getHour() {
        return this.hour;
    }

    public int getMinute() {
        return this.minute;
    }
}
