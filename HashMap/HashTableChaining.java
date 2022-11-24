import java.util.LinkedList;

public class HashTable {
    // put(k, v)
    // get(k) : v
    // remove(k)
    // k: int, v: string
    // collisions: chaining
    private class EntryNode {
        private int key;
        private String value;

        // constructor that initializes created node with key and value
        public EntryNode(int key, String value) {
            this.key = key;
            this.value = value;
        }
    }

    // An array of linked lists, with each linked list containing EntryNode
    private LinkedList<EntryNode>[] entries = new LinkedList[5];

    public void put(int key, String value) {
        int index = hash(key);

        // if no entry in the linked list (linked list not created), create new linked
        // list at index
        if (entries[index] == null) {
            entries[index] = new LinkedList<>();
        }

        // iterate over the linked list at index to check whether the key already
        // exists,
        // if so just replace the value that pairs with the key (avoids duplication)
        for (int i = 0; i < entries[index].size(); i++) {
            // check against each EntryNode's key and update value if key already exists
            if (entries[index].get(i).key == key) {
                entries[index].get(i).value = value;
                return;
            }
        }

        // no duplciation, add new key value pair to the end of the linked list
        entries[index].addLast(new EntryNode(key, value));
    }

    // get the value associated with key
    public String get(int key) {
        int index = hash(key);

        // iterate over the linked list where the key value pair would be stored if it
        // exists. The if makes sure the linked list exists.
        if (entries[index] != null) {
            for (int i = 0; i < entries[index].size(); i++) {
                // Checks each EntryNode's key with argument
                if (entries[index].get(i).key == key) {
                    return entries[index].get(i).value;
                }
            }
        }

        // The key doesn't exist
        return null;
    }

    // remove the key value pair for the given key
    public void remove(int key) {
        int index = hash(key);

        // if the linked list is empty
        if (entries[index] == null) {
            throw new IllegalStateException();
        }

        // go through the linked list and remove the key value pair if it exists
        for (int i = 0; i < entries[index].size(); i++) {
            if (entries[index].get(i).key == key) {
                entries[index].remove(entries[index].get(i));
                return;
            }
        }

        // went through linked list and key value pair to remove is not found
        throw new IllegalStateException();
    }

    // hash function that returns index where to save the key value pair
    // the function makes sure we are in array length
    private int hash(int key) {
        return key % entries.length;
    }
}
