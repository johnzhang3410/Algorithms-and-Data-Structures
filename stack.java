import java.util.Arrays;

//Stack implementaton using array
public class stack {
    private int[] array = new int[5];
    private int count;

    // Pushes item to the top of stack
    public void push(int item) {
        // if array is full
        if (count == array.length) {
            throw new StackOverflowError();
        }

        array[count] = item;
        count++;
    }

    // pop top of stack and return it
    public int pop() {
        // if stack is empty
        if (count == 0) {
            throw new IllegalStateException();
        }

        count--;
        return array[count];
    }

    // returns what is at the top of stack
    public int peek() {
        if (count == 0) {
            throw new IllegalStateException();
        }

        return array[count - 1];
    }

    // returns true if stack is empty
    public boolean isEmpty() {
        return count == 0;
    }

    // We use toString to display the array aka stack properly
    @Override
    public String toString() {
        int[] items = new int[count];

        // only display items in the stack
        for (int i = 0; i < count; i++) {
            items[i] = array[i];
        }

        return Arrays.toString(items);
    }

}
