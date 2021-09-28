# Hashing in Java

**intersection-union of 2 LL**

```
import java.util.HashMap; 
import java.util.HashSet; 

class LinkedList { 
	Node head;

	class Node { 
		int data; 
		Node next; 
		Node(int d) 
		{ 
			data = d; 
			next = null; 
		} 
	} 

	void printList() 
	{ 
		Node temp = head; 
		while (temp != null) { 
			System.out.print(temp.data + " "); 
			temp = temp.next; 
		} 
		System.out.println(); 
	} 

	void push(int new_data) 
	{
		Node new_node = new Node(new_data); 

		new_node.next = head; 

		head = new_node; 
	} 

	public void append(int new_data) 
	{ 
		if (this.head == null) { 
			Node n = new Node(new_data); 
			this.head = n; 
			return; 
		} 
		Node n1 = this.head; 
		Node n2 = new Node(new_data); 
		while (n1.next != null) { 
			n1 = n1.next; 
		} 

		n1.next = n2; 
		n2.next = null; 
	} 

	boolean isPresent(Node head, int data) 
	{ 
		Node t = head; 
		while (t != null) { 
			if (t.data == data) 
				return true; 
			t = t.next; 
		} 
		return false; 
	} 

	LinkedList getIntersection(Node head1, Node head2) 
	{ 
		HashSet<Integer> hset = new HashSet<>(); 
		Node n1 = head1; 
		Node n2 = head2; 
		LinkedList result = new LinkedList(); 

		while (n1 != null) { 
			if (hset.contains(n1.data)) { 
				hset.add(n1.data); 
			} 
			else { 
				hset.add(n1.data); 
			} 
			n1 = n1.next; 
		} 

		while (n2 != null) { 
			if (hset.contains(n2.data)) { 
				result.push(n2.data); 
			} 
			n2 = n2.next; 
		} 
		return result; 
	} 

	LinkedList getUnion(Node head1, Node head2) 
	{ 
		HashMap<Integer, Integer> hmap = new HashMap<>(); 
		Node n1 = head1; 
		Node n2 = head2; 
		LinkedList result = new LinkedList(); 

		while (n1 != null) { 
			if (hmap.containsKey(n1.data)) { 
				int val = hmap.get(n1.data); 
				hmap.put(n1.data, val + 1); 
			} 
			else { 
				hmap.put(n1.data, 1); 
			} 
			n1 = n1.next; 
		} 

		while (n2 != null) { 
			if (hmap.containsKey(n2.data)) { 
				int val = hmap.get(n2.data); 
				hmap.put(n2.data, val + 1); 
			} 
			else { 
				hmap.put(n2.data, 1); 
			} 
			n2 = n2.next; 
		} 

		for (int a : hmap.keySet()) { 
			result.append(a); 
		} 
		return result; 
	} 

	public static void main(String args[]) 
	{ 
		LinkedList llist1 = new LinkedList(); 
		LinkedList llist2 = new LinkedList(); 
		LinkedList union = new LinkedList(); 
		LinkedList intersection = new LinkedList(); 

		/*10->15->4->20 */

		llist1.push(20); 
		llist1.push(4); 
		llist1.push(15); 
		llist1.push(10); 

		/*8->4->2->10 */
		
		llist2.push(10); 
		llist2.push(2); 
		llist2.push(4); 
		llist2.push(8); 

		intersection 
			= intersection.getIntersection(llist1.head, 
										llist2.head); 
		union = union.getUnion(llist1.head, llist2.head); 

		System.out.println("First List is"); 
		llist1.printList(); 

		System.out.println("Second List is"); 
		llist2.printList(); 

		System.out.println("Intersection List is"); 
		intersection.printList(); 

		System.out.println("Union List is"); 
		union.printList(); 
	} 
} 
```