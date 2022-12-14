class Main1B {
    public static void main(String[] args) {
        System.out.println("Enter the size of the array(N): ");
        int N = Integer.parseInt(System.console().readLine());

        double[] array = new double[N]; //N : size of the array(number of elements )
        for (int i = 0; i < N; ++i) {
            System.out.println("Enter " + i + " th item: ");
            array[i] = Double.parseDouble(System.console().readLine());
        }

        double sum = 0;
        for (int i = 0; i < array.length; ++i) {
            sum += array[i];
        }
        double avg = sum /N;

        double[] diff_from_avg = new double[N];
        for (int i = 0;i < N; ++i) {
            diff_from_avg[i] = Math.abs(avg - array[i]);
        }
        int min_idx = 0;
        for (int i = 1; i < N; ++i) {
            if (diff_from_avg[i] < diff_from_avg[min_idx]) {
                min_idx = i;
            }
        }
        System.out.println("The average is " + avg + ", and the closest item to the avg is " + array[min_idx]);

    }

}