public class LinkedListQueue {
    private Node first;
    private Node last;
    private int size;

    // Node class, internal to LinkedList class
    private class Node {
        // value of current node
        private int value;
        // points to next node
        private Node next;

        // Node class constructor
        public Node(int value) {
            // Node should always have a value
            this.value = value;
        }
    }

    public void enqueue(int value) {
        var node = new Node(value);

        // set node to be first and last if list empty
        if (first == null) {
            first = node;
            last = node;
        } else {
            last.next = node;
            last = node;
        }

        size++;
    }

    public int dequeue() {
        // return the value that we pop
        int value = first.value;

        if (first == null) {
            throw new IllegalStateException();
        } else if (first == last) {

            first = null;
            last = null;
            size--;
            return value;
        }

        // removes link between first and second, and set pointer to second
        var second = first.next;
        first.next = null;
        first = second;
        size--;

        return value;
    }

    public int peek() {
        if (first == null) {
            throw new IllegalStateException();
        }

        return first.value;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return first == null;
    }

}
