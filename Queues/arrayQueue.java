import java.util.Arrays;

// Queue implementation using array
public class arrayQueue {
    // pointers to keep track of queue
    private int front;
    private int back;
    private int[] array;
    private int count;

    // initialize array with parameter capacity
    public arrayQueue(int capacity) {
        array = new int[capacity];
    }

    // enqueue, dequeue
    public void enqueue(int value) {
        if (count == array.length) {
            throw new IllegalStateException();
        }

        // circular array
        if (back == array.length && count != array.length) {
            back = 0;
        }

        array[back] = value;
        back++;
        count++;
    }

    // return the queue item removed
    public int dequeue() {
        // circular array
        if (front == array.length && count > 0) {
            front = 0;
        }

        front++;
        count--;
        return array[front - 1];
    }

    public void printQueue() {
        if (count > 0) {
            if (back > front) {
                for (int i = front; i < back; i++) {
                    System.out.println(array[i]);
                }
            } else {
                int counter = front;
                int total = count;
                while (counter < array.length) {
                    System.out.println(array[counter]);
                    counter++;
                    total--;
                }

                while (total > 0) {
                    System.out.println(array[total - 1]);
                    total--;
                }
            }
        }
    }

    // prints the entire array (shows non-used spots)
    @Override
    public String toString() {
        return Arrays.toString(array);
    }

}
