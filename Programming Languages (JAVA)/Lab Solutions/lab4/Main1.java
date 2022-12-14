class Main1 {
    public static void main(String[] args) {
        double[] array = {1.3, 5.2, 7.7, -2.3, 23.45};

        double sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += array[i];
        }
        double avg = sum /5;

        double[] diff_from_avg = {0,0,0,0,0};
        for (int i = 0;i < 5; ++i) {
            diff_from_avg[i] = Math.abs(avg - array[i]);
        }
        int min_idx = 0;
        for (int i = 1; i < 5; ++i) {
            if (diff_from_avg[i] < diff_from_avg[min_idx]) {
                min_idx = i;
            }
        }
        System.out.println("The average is " + avg + ", and the closest item to the avg is " + array[min_idx]);

    }

}