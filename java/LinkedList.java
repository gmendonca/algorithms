import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

class Node {
    Node next;
    int data;

    public Node(int data) {
        this.data = data;
    }
}

class LinkedListImpl {
    Node head;

    public void append(int data) {
        if (head == null) {
            head = new Node(data);
            return;
        }
        Node current = head;

        while (current.next != null) {
            current = current.next;
        }
        current.next = new Node(data);
    }

    public void prepend(int data) {
        if (head == null) {
            head = new Node(data);
            return;
        }
        Node newHead = new Node(data);
        newHead.next = head;
        head = newHead;
    }

    public boolean hasCycle(Node head) {
            ArrayList<Node> visitedList = new ArrayList<Node>();
            Node current = head;
            if(current == null) {
                return false;
            }
            while (true) {
                if (current.next == null) {
                return false;
            } else if (visitedList.contains(current.next)) {
                return true;
            }
            visitedList.add(current);
            current = current.next;
        }
    }

    public boolean hasCycleSlowFast(Node head) {
        if (head == null) return false;

        Node slow = head;
        Node fast = head.next;
        while (slow != fast) {
            if (fast == null || fast.next == null) return false;
            
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }

    public void deleteWithValue(int data) {
        if (head == null)  return;
        if (head.data == data) {
            head = head.next;
            return;
        }
        Node current = head;

        while (current.next != null) {
            if (current.next.data == data) {
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }
    }
}

public class LinkedList {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        scanner.close();

    }
}







