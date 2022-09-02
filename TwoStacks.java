import java.util.Arrays;

//Two stacks in one array
public class TwoStacks {
    private int[] array;
    private int top1;
    private int top2;
    private int count = 0;

    // constructor that initializes array with capacity
    public TwoStacks(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException();
        }

        array = new int[capacity];
        // top of stack for the 2 stacks
        top1 = 0;
        top2 = capacity;
    }

    // push item to stack 1
    public void push1(int item) {
        // if array is full
        if (top1 + 1 == top2) {
            throw new IllegalStateException();
        }

        array[top1] = item;
        top1++;
        count++;
    }

    public void push2(int item) {
        // if array is full
        if (top1 == top2) {
            throw new IllegalStateException();
        }

        top2--;
        array[top2] = item;
        count++;
    }

    // pop from top of stack 1
    public int pop1() {
        if (top1 == 0) {
            throw new IllegalStateException();
        }

        top1--;
        count--;
        return array[top1];
    }

    // pop from top of stack 2
    public int pop2() {
        if (top2 == array.length) {
            throw new IllegalStateException();
        }

        top2++;
        count--;
        return array[top2 - 1];
    }

    // checks if stack 1 is empty
    public boolean isEmpty1() {
        return top1 == 0;
    }

    public boolean isEmpty2() {
        return top2 == array.length;
    }

    public boolean isFull1() {
        return top1 == top2;
    }

    public boolean isFull2() {
        return top1 == top2;
    }

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
