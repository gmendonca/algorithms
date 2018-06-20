class Node {
    int data;
    Node next;
    public Node(int data) {
        this.data = data;
    }
}



class StackImpl {
    Node top;

    public boolean isEmprty() {
        return top == null;
    }

    public int peek() {
        return top.data;
    }

    public void push(int data) {
        Node node = new Node(data);
        node.next = top;
        top = node;
    }

    public int pop() {
        int data = top.data;
        top = top.next;
        return data;
    }
}
    
