# Problem Description

> **Medium**

A linked list of length ```n``` is given such that each node contains an additional random pointer, which could point to any node in the list, or ```null```.

Construct a [deep copy](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list. The deep copy should consist of exactly ```n``` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the ```next``` and ```random``` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list**.

For example, if there are two nodes ```X``` and ```Y``` in the original list, where ```X.random --> Y```, then for the corresponding two nodes ```x``` and ```y``` in the copied list, ```x.random --> y```.

Return *the head of the copied linked list*.

The linked list is represented in the input/output as a list of ```n``` nodes. Each node is represented as a pair of ```[val, random_index]``` where:

```val```: an integer representing ```Node.val```
```random_index```: the index of the node (range from ```0``` to ```n-1```) that the ```random``` pointer points to, or ```null``` if it does not point to any node.

Your code will **only** be given the ```head``` of the original linked list.

 

**Example 1:**

![ ](https://assets.leetcode.com/uploads/2019/12/18/e1.png)
```
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
```
**Example 2:**

![ ](https://assets.leetcode.com/uploads/2019/12/18/e2.png)
```
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
```
**Example 3:**

![ ](https://assets.leetcode.com/uploads/2019/12/18/e3.png)
```
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
```
 

### Constraints:

```0 <= n <= 1000```

```-104 <= Node.val <= 104```

```Node.random``` is ```null``` or is pointing to some node in the linked list.

# Solution

I will be going over a solution that utilizes the **hashmap**.

##  Hashmap Solution
In this approach, we use a hashmap to store the original node along with the copy as a pair (original node, copy node).

First of all, we copy the linked list without the random pointer. While traversing the linked list, we store the original nodes as keys and the copy as values in our hashmap.

Then we traverse the linked list a second time to copy the random node. At this stage, we already have a mapping of all our original node and copy node. So, it's just a matter of retrieving the random copy node using nodes from the original linked list as keys to the hashmap.

So basically:
* Copy the linked list without random pointers.
    * Store each node of the copied linked list in a hashmap.
* Traverse the linked list again to set the random pointers.

## Algorithm
* Create a hashmap equivalent data structure for mapping original nodes to their copies

```hashmap = createHashMapEquivalent()```

**Copy the original linked list to a new linked list**

* Create a new linked list node; this will be our return list

```newNode = createNewNode()```

* Create a pointer, that refers to the new linked list's current node (I will be using tail)

```tail = newNode```

* Create a pointer, that refers to the head of the original linked list (I will be using cur)

```cur = head```

* Traverse through the original linked list

```while cur is not NULL```

**Inner Loop**

* Create a copy of the current node from the original linked list, then assign it to the tail's next pointer. This makes the new linked list start at tail's next pointer

```tail.next = copyNode(current)```

* Store the original linked list node as the key in our hashmap from step 1, and the copy made in the previous step as the value

```hashmap.set(current) = tail.next```

* Update both pointers to avoid getting stuck in an infinite loop

```current = current.next```

```tail = tail.next```

**Set the random pointers**

* Reset the pointer tail, to the beginning of the new linked list

```tail = startOfNewLinkedList```

* Traverse through the original linked list, this time using the original head itself

```while head is not NULL```

**Inner Loop**
    
* Check if the random pointer of the current node points to a non-NULL node

    ```if head.random is not NULL```
    
    * If true, retrieve the node that the random pointer points to
    
    ```nodeOfRandomPointer = hashmap.retrieve(head.random)```
    
   * Assign this node (retrieved in the previous step) to tail's random pointer

    ```tail.random = nodeOfRandomPointer```
    
    * Update both pointers to avoid getting stuck in an infinite loop

    ```head = head.next```

    ```tail = tail.next```

* Return the new linked list. Depending on your language, you may return the starting node

```return startOfNewLinkedList```
    
### Worst-Case Complexity Analysis
**Time Complexity:** Given a linked list with ```n``` nodes, our algorithm traverses each node twice. While it may appear as ```O(2n)```, we typically drop the constant factor and express it as ```O(n)``` because the constant factor doesn't affect the overall order of growth. Therefore, our algorithm is bounded by ```O(n)``` time.

**Space Complexity:** The space complexity of this algorithm scales linearly with the input size. This algorithm creates a new linked list that is essentially a copy of the original linked list. If the size of the input list is ```n```, the size of this copy will be ```n + 1```. It also utilizes copies of node, these variables and nodes occupy constant space, ```O(1) ```, because their number doesn't depend on the size of the original linked list. This algorithm also use a hashmap. In the worst case, if there are ```n``` nodes in the original linked list, the hashmap would store all ```n``` entries, where each entry consists of a reference to an original node as the key and a reference to a copied node as the value. Therefore, the space used by the hashmap is ```O(n)```. Putting it all together, our algorithm uses O(2n+1), but again, we typically drop the constant factor and express it as ```O(n)``` because the constant factor doesn't affect the overall order of growth. Therefore, our algorithm is bounded by ```O(n)``` space.