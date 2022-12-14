import java.util.Arrays;

class MainTask3 {
    public static <T> void swap(T[] a, int i, int j) {
        T temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    public static void main(String[] args) {
        Integer[] arr1 = {1,2,3,4,5,6};
        swap(arr1, 0, 3);
        System.out.println(Arrays.toString(arr1));

        Double[] arr2 = {2.4, 5.7, 2.1, 3.0, 6.7}; 
        swap(arr2, 0, 3);
        System.out.println(Arrays.toString(arr2));

        Car[] arr3 = {new Car("BMW"), new Car("Ford"), new Car("Kia")};
        swap(arr3, 0, 2);
        System.out.println(Arrays.toString(arr3));
    }
}