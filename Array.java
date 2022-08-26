// Array class
public class Array {
    private int[] items;
    private int count;

    // constructor, initialize array
    public Array(int length) {
        items = new int[length];
    }

    // Array method (Array.print())
    public void print() {
        for (int i = 0; i < count; i++) {
            System.out.println(items[i]);
        }
    }

    // insert method that inserts an int to end of array
    public void insert(int item) {

        items[count] = item;
        count++;

        // if array is full, double size of the array
        if (count == items.length) {
            int[] items2 = new int[items.length * 2];

            for (int i = 0; i < items.length; i++) {
                items2[i] = items[i];
            }

            items = items2;
        }
    }

    // insert an item at given index
    public void insertAt(int item, int index) {
        if (index < 0 || index > count) {
            throw new IllegalArgumentException();
        }

        // shift items to the right
        // [10, 20, 30, 40]
        // index = 2, count = 4
        for (int i = count - 1; i >= index; i--) {
            items[i + 1] = items[i];
        }

        items[index] = item;
        count++;
    }

    // method that removes item at an index
    public void removeAt(int index) {
        if (index < 0 || index >= count) {
            throw new IllegalArgumentException();
        }

        // shift items in the array to the left
        for (int i = index; i < count - 1; i++) {
            items[i] = items[i + 1];
        }

        // remove last item
        count--;
    }

    // return index of parameter value
    public int indexOf(int number) {

        for (int i = 0; i < count; i++) {
            if (number == items[i]) {
                return i;
            }
        }

        return -1;
    }

    // return largest number in the array
    public int max() {
        int number = 0;

        for (int i = 0; i < count; i++) {
            if (items[i] > number) {
                number = items[i];
            }
        }

        return number;
    }

    // return common item of this and another array
    public Array intersect(Array array) {
        // new array that stores intersection of 2 arrays
        var intersection = new Array(count);

        for (int i = 0; i < count; i++) {
            // if found items[i] in other array, meaning no -1
            if (array.indexOf(items[i]) >= 0) {
                intersection.insert(items[i]);
            }
        }

        return intersection;
    }

    // reverse the current array
    public void reverse() {
        int[] newArray = new int[count];
        int counter = count;

        for (int i = 0; i < count; i++) {
            newArray[i] = items[counter - 1];
            counter--;
        }

        items = newArray;
    }
}
