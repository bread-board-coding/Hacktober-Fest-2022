public class LinkedListCycle {
    public static class Node{
        int data;
        Node next;
        
        Node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }
    public static void main(String[] args) {
        Node head = new Node(-1);
        Node curr = head;
        for(int i=0;i<10;i++)
        {
            curr.next = new Node(i+1);
            curr = curr.next;
        }
        head = head.next;
        Node tail = head;
        while(tail.next != null)
        {
           System.out.println("Data "+tail.data);
           tail = tail.next;
        }
        System.out.println("Data "+tail.data);
        System.out.println("Before Cycle Creation Cycle Detected?? "+detectCycle(head));
        
        int pos = 4;
        tail.next = makeCycle(head,pos);
        // System.out.println("Cycle next data "+tail.next.data);
        
        System.out.println("After Cycle Creation Cycle Detected?? "+detectCycle(head));
        Node meet = returnCycle(head);
        System.out.println("meet at "+meet.data);

        Node first = firstNode(head,meet);
        System.out.println("FirstNode at "+first.data);
        
        removeCycle(first,meet);
        System.out.println("After Cycle deletion Cycle Detected?? "+detectCycle(head));
        
    }
    public static Node makeCycle(Node head,int pos)
    {
        Node curr = head;
        int i=1;
        while(curr.next != null && i < pos)
        {
            curr = curr.next;
            i++;
        }
        return curr;
    }
    
    public static Node reverse(Node head)
    {
        Node curr = head;
        Node prev = null;
        Node forward = null;
        while(curr != null)
        {
            forward = curr.next;
            curr.next = prev;
            prev =  curr;
            curr = forward;
        }
        return prev;
    }
    public static boolean detectCycle(Node head)
    {
        Node slow = head;
        Node fast = head;
        while(fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    public static Node returnCycle(Node head)
    {
        Node slow = head;
        Node fast = head;
        while(fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast)
            {
                return slow;
            }
        }
        return new Node(-1);
    }
    public static Node firstNode(Node head,Node meet)
    {
        Node start = head;
        while(start != meet)
        {
            start = start.next;
            meet = meet.next;
        }
        return start;
    }
    public static void removeCycle(Node first,Node meet)
    {
        
        while(meet.next != first)
        {
            meet = meet.next;
        }
        meet.next = null;
    }
}
