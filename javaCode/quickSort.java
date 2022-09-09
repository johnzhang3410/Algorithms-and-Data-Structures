import java.util.Arrays;

public class quickSort {
    public static void main(String[] args) {
        int array[] = {3, 9, 7, 2, 5, 10, 1, 8, 4, 4};

        int size = array.length;

        quickSort.sort(array, 0, size - 1);

        System.out.println(Arrays.toString(array));
    }

    //partitions around the pivot (greater elements to the right of pivot)
    public static int partition(int array[], int left, int right) {
        int pivot = array[right];
        //pointer for greater element 
        int pointer = left - 1;

        //for every element in right to left index
        for (int i = left; i < right; i++) {
            //swap to the left end if current < pivot
            if (array[i] <= pivot) {
                pointer++;

                int temp = array[pointer];
                array[pointer] = array[i];
                array[i] = temp;
            }
        }

        //move pivot after all elements < pivot
        //swapped pivot with some bigger element
        int temp = array[pointer + 1];
        array[pointer + 1] = pivot;
        array[right] = temp;

        //return index of pivot (now is midpoint of values)
        return pointer + 1;
    }   

    static void sort(int array[], int left, int right) {
        if (left < right) {
            int mid = partition(array, left, right); 
            //partition numbers bigger and smaller than mid value
            sort(array, left, mid - 1);
            sort(array, mid + 1, right);
        }
    }
}
