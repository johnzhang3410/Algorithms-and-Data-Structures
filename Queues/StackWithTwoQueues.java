import java.util.ArrayDeque;
import java.util.Queue;

public class StackWithTwoQueues {
    private Queue<Integer> queue1 = new ArrayDeque<>();
    private Queue<Integer> queue2 = new ArrayDeque<>();
    private int top;

    // push to end of stack (queue1)
    public void push(int item) {
        queue1.add(item);
        top = item;
    }

    // Last in first out, remove top of stack
    public int pop() {
        if (isEmpty()) {
            throw new IllegalStateException();
        }

        // only top of stack (to be popped) left in queue1, others are moved in order to
        // queue2. Ex. queue1: [10, 20, 30, 40, 50]. After moving queue1: [50], queue2:
        // [10, 20, 30, 40]
        while (queue1.size() > 1) {
            top = queue1.remove();
            queue2.add(top);
        }

        // swap queue1 with queue2. queue1: [10, 20, 30, 40], queue2: [50]
        var temp = queue1;
        queue1 = queue2;
        queue2 = temp;

        // return item removed (top of stack)
        return queue2.remove();
    }

    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException();
        }

        return top;
    }

    public int size() {
        return queue1.size();
    }

    // check if stack aka queue1 is empty
    public boolean isEmpty() {
        return queue1.isEmpty();
    }

    // for printing out the stack
    @Override
    public String toString() {
        return queue1.toString();
    }
}
