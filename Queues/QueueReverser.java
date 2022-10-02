import java.util.Queue;
import java.util.Stack;

public class QueueReverser {
    // reverse first num elements of the queue
    public void reverse(int num, Queue<Integer> queue) {
        if (num < 0 || num > queue.size()) {
            throw new IllegalArgumentException();
        }

        Stack<Integer> stack = new Stack<>();

        // [1, 2, 3, 4, 5]
        // push what is to be reversed on to the stack
        for (int i = 0; i < num; i++) {
            stack.push(queue.remove());
        }

        // [1, 2, 3]
        // popping off the stack would reverse the numbers back to queue, and the
        // numbers are added to the back of the queue
        while (!stack.empty()) {
            queue.add(stack.pop());
        }

        // remove unreversed strings from the front of queue to back of the queue
        for (int i = 0; i < queue.size() - num; i++) {
            queue.add(queue.remove());
        }
    }
}
