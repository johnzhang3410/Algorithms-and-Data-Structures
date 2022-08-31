import java.util.NoSuchElementException;

public class LinkedList {
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

    // add new node with value to the end of the linked list
    public void addLast(int value) {
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

    public void addFirst(int value) {
        var node = new Node(value);

        if (first == null) {
            addLast(value);
        } else {
            node.next = first;
            first = node;
        }

        size++;
    }

    // remove first node of the list
    public void removeFirst() {

        if (first == null) {
            throw new NoSuchElementException();
        } else if (first == last) {
            first = null;
            last = null;
            size--;
            return;
        }

        // removes link between first and second, and set pointer to second
        var second = first.next;
        first.next = null;
        first = second;

        size--;
    }

    // remove last node of the list
    public void removeLast() {
        if (first == null) {
            throw new NoSuchElementException();
        } else if (first == last) {
            first = null;
            last = null;
            size--;
            return;
        }

        var current = first;

        // finds second to last item to unlink
        while (current.next.next != null) {
            current = current.next;
        }

        current.next = null;
        last = current;

        size--;
    }

    // return size of the list
    public int size() {
        return size;
    }

    // returns the index of value
    public int indexOf(int value) {
        int counter = 0;
        var current = first;

        while (current != null) {
            if (current.value == value) {
                return counter;
            }
            counter++;
            current = current.next;
        }

        return -1;
    }

    // checks if list contains a value
    public boolean contains(int value) {
        var current = first;

        while (current != null) {
            if (current.value == value) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    // reverses the linked list
    public void reverse() {
        // last item.next points to its previous item and so on
        // probably want to iterate in a loop

        // var current = last;
        // var current1 = last;
        // var pointer = first;

        // while (pointer != null) {
        // var pointer1 = first;
        // // finds second to last node
        // while (pointer1.next != current1) {
        // pointer1 = pointer1.next;
        // }
        // // last node's next node is second to last node
        // current.next = pointer1;
        // // update last node to be second to last node
        // current = pointer1;
        // // iterate one less time
        // current1 = pointer1;
        // pointer = pointer.next;
        // }

        if (first == null) {
            return;
        }

        var current = first.next;
        var temp = first;
        var prev = first;

        // reverses all the links between nodes
        while (current != null) {
            var next = current.next;
            // point to the previous node blc we want to reverse
            current.next = prev;
            prev = current;
            current = next;
        }

        // prev points to the last node as current is now null
        first = prev;
        last = temp;
        last.next = null;

    }

    // returns value of the kth node from the end of the list in one pass
    public int getKthFromTheEnd(int k) {
        if (first == null) {
            throw new IllegalStateException();
        }

        if (k <= 0) {
            throw new IllegalArgumentException();
        }

        var current = first;
        var second = first;

        // seperates two pointers by the right distance, distance is k - 1
        for (int i = 0; i < k - 1; i++) {
            second = second.next;

            // if k is too large, we out of the linked list
            if (second == null) {
                throw new IllegalArgumentException();
            }
        }

        // move both pointers forward until the end
        while (second != last) {
            second = second.next;
            current = current.next;
        }

        return current.value;
    }

    // print middle node value of the list, if even print middle 2 values
    public void printMiddle() {
        if (first == null) {
            throw new IllegalStateException();
        }

        // Uses 2 pointers to keep distance like in Kth node method
        var current = first;
        var second = first;

        // position of middle node increments by 1 when # of nodes in the list increment
        // by 2. Reaching last or null means we traversed the entire list (odd or even)
        while (second != last && second != last.next) {
            current = current.next;
            second = second.next.next;
        }

        // odd list, current is the middle node
        if (second == last) {
            System.out.println(current.value);
        } else { // even case
            System.out.println(current.value + ", " + current.next.value);
        }
    }

    // checks if linked list has a loop
    // Floyd's cycle-finding algorithm
    public boolean hasLoop() {
        var slow = first;
        var fast = first;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }

    // print list method
    public void printList() {
        var current = first;

        if (first == null) {
            System.out.println("list is empty");
        }

        while (current != null) {
            System.out.println(current.value);
            current = current.next;
        }
    }

    // converts list to array
    public int[] toArray() {
        // creates an array of the same size as list
        int[] array = new int[size];
        var current = first;
        int index = 0;

        for (int i = size; i != 0; i--) {
            array[index] = current.value;
            current = current.next;
            index++;
        }

        return array;
    }

}
