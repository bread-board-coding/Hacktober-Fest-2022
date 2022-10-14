class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None
class Doubly_linked_list:
    def __init__(self):
        self.head = None
    def append(self, data):
        if self.head is None:
            new_node = Node(data)
            new_node.prev = None
            self.head = new_node
        else:
            new_node = Node(data)
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = new_node
            new_node.prev = cur
            new_node.next = None
    def prepend(self, data):
        if self.head is None:
            new_node = Node(data)
            new_node.prev = None
            self.head = new_node
        else:
            new_node = Node(data)
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
            new_node.prev = None
    def print_list(self):
        cur = self.head
        while cur:
            print(cur.data)
            cur = cur.next
    def add_after_node(self, key, data):
        cur = self.head
        while cur:
            if cur.next is None and cur.data == key:
                self.append(data)
                return
            elif cur.data == key:
                new_node = Node(data)
                nxt = cur.next
                cur.next = new_node
                new_node.prev = cur
                new_node.next = nxt
                nxt.prev = new_node
            cur = cur.next
    def add_before_node(self, key, data):
        cur = self.head
        while cur:
            if cur.prev is None and cur.data == key:
                self.prepend(data)
                return
            elif cur.data == key:
                new_node = Node(data)
                prev = cur.prev
                prev.next = new_node
                new_node.prev = prev
                new_node.next = cur
                cur.prev = new_node
            cur = cur.next
obj = Doubly_linked_list()
obj.append(1)
obj.append(2)
obj.append(3)
obj.append(4)
obj.prepend(0)
obj.print_list()
