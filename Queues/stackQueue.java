import java.util.Stack;

public class stackQueue {
    // use 2 stacks (as we need to remove from front)
    // stack1 used for enqueue and stack2 for dequeue, move contents of stack1 to
    // stack2 when stack2 is empty but want to dequeue
    private Stack<Integer> stack1 = new Stack<>();
    private Stack<Integer> stack2 = new Stack<>();

    public void enqueue(int number) {
        stack1.push(number);
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException();
        }

        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        return stack2.pop();
    }

    public int peek() {
        if (isEmpty()) {
            throw new IllegalStateException();
        }

        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }

        return stack2.peek();
    }

    public boolean isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
}
