public class HashMapLinearProbing {
    private class EntryNode {
        private int key;
        private String value;

        // constructor that initializes created node with key and value
        public EntryNode(int key, String value) {
            this.key = key;
            this.value = value;
        }
    }

    // an array of EntryNode
    private EntryNode[] entries = new EntryNode[5];

    int count = 0;

    // if conflict, go forward one by one and store at next available slot
    // add entry to the array if there is empty slot, or update value if key exists
    public void put(int key, String value) {

        // loop over array to find an empty slot
        int i = 0;
        while (i < entries.length) {
            int index = index(key, i);
            // if a slot is empty, then add in the key value pair
            if (entries[index] == null) {
                entries[index] = new EntryNode(key, value);
                count++;
                return;
            }

            // if key already exists, update its value
            if (entries[index].key == key) {
                entries[index].value = value;
                return;
            }

            i++;
        }
        // no empty slot and no matching key, can't insert or update
        throw new IllegalStateException();
    }

    // gets the value associated with key if it exists
    public String get(int key) {
        // loop over array to find an empty slot
        // entries are stored according to hash function, so we access it the same way
        // we find which index the key would be stored and start incrementing index to
        // find the matching key.
        int i = 0;
        while (i < entries.length) {
            int index = index(key, i);
            if (entries[index] != null) {
                if (entries[index].key == key) {
                    return entries[index].value;
                }
            }
            i++;
        }
        return null;
    }

    // loop to find key and set entry to null, else just return
    public void remove(int key) {
        int i = 0;
        while (i < entries.length) {
            int index = index(key, i);
            if (entries[index] != null) {
                if (entries[index].key == key) {
                    entries[index] = null;
                    count--;
                    return;
                }
            }

            i++;
        }
    }

    public int size() {
        return count;
    }

    // linear probing hash function, increment i until empty index found
    private int index(int key, int i) {
        return (hash(key) + i) % entries.length;
    }

    private int hash(int key) {
        return key % entries.length;
    }
}
