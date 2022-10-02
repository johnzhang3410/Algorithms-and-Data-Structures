import java.util.Arrays;

public class priorityQueue {
    // iterate from the back of array, if array index value is greater than input,
    // shift index to the right. Else insert input to index of array
    private int[] array = new int[5];
    private int count;

    // still need to fix
    public void add(int value) {
        if (count == array.length) {
            throw new IllegalStateException();
        }

        int i;
        for (i = count - 1; i >= 0; i--) {
            if (array[i] > value) {
                array[i + 1] = array[i];
            } else {
                break;
            }
        }
        array[i + 1] = value;
        count++;
    }

    public int remove() {
        if (count == 0) {
            throw new IllegalStateException();
        }

        count--;
        return array[count];
    }

    public boolean isEmpty() {
        return count == 0;
    }

    @Override
    public String toString() {
        // int[] items = new int[count];

        // // only display items in the stack
        // for (int i = 0; i < count; i++) {
        // items[i] = array[i];
        // }

        return Arrays.toString(array);
    }
}
