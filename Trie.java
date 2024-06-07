class Node {
    public int val;
    public List<Node> neighbors;

    // constructor for the node class
    public Node() {
        // when a new node is created, we set its val to be 0 and create a list for its
        // neighbors
        val = 0;
        neighbors = new ArrayList<Node>();
    }
}