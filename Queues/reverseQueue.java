import java.util.Queue;
import java.util.Stack;

public class reverseQueue {
    public void reverse(Queue<Integer> queue) {
        Stack<Integer> stack = new Stack<>();

        // push queue items onto the stack
        while (!queue.isEmpty()) {
            stack.push(queue.remove());
        }

        // pop the stack to make reversed queue
        while (!stack.isEmpty()) {
            queue.add(stack.pop());
        }
    }
}
