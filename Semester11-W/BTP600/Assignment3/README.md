
# Part 2: Reflection
### 1. For your ClassAdapter, describe the class hierarchy. Which class was the Adaptee? Which class was the Target? 
Provide the snippet of code to show how you did this. You may also provide a diagram for clarity, if you do so, 
ensure that the diagram is visible on the wiki page with permissions set so that anyone with link can view the image 
(if you are working with in a team, have a member who didn't do the diagram double check).
- in ClassAdapter, the Adaptee is the DList and the Target is Queue.
- ClassAdapter Code: ![alt text](https://github.com/seneca-btp600-w21/a3-group-10-1/blob/main/images/classAdapter(Code).png)
- ClassAdapter Diagram: ![alt text](https://github.com/seneca-btp600-w21/a3-group-10-1/blob/main/images/classAdapter.png)


### 2. With respect to the ClassAdapter, GOF states that a class adapter "adapts Adaptee to Target by committing to a concrete Adaptee class".
a) Explain what this means with respect to the your implementation.
- in my ClassAdapter, I am using the DList as the concrete Adaptee class and call the Adaptee class function directly in the Queue virtual function. 
b) What would you need to do to adapt the other linked list instead? Is there a way to configure the ClassAdapter at run time to choose the other linked list?
- to adapt the other LinkedList, we can change the inheritance in the ClassAdapter from DList to SList as well as function calling ( private DList -> private SList && DList:: -> SList::)

### 3. For your ObjectAdapter, describe the class hierarchy and explain how the LinkedList is adapted. 
Provide the snippet of code that shows how the LinkedList is set up within the ObjectAdapter. You may also provide a diagram for clarity.
- LinkedList adaptee class, DList, will appear as an object in the ObjectAdapter class and will call the necessary DList function in each of the Queue virtual function.
- ObjectAdapter Code: ![alt text](https://github.com/seneca-btp600-w21/a3-group-10-1/blob/main/images/objectAdapter(Code).png)
- ObjectAdapter Diagram: ![alt text](https://github.com/seneca-btp600-w21/a3-group-10-1/blob/main/images/objectAdapter.png)

### 4.With respect to the ObjectAdapter, GOF states that an object adapter "lets a single adapter work with many adaptees - 
that is the Adapteee itself and all its subclasses". Does this apply to your current implementation of the ObjectAdapter?
a) If yes, explain how this applies to your implementation and how you can use the same adapter to adapt the other linked list?
b) If no, what changes would you need to make so that the adapter can be configured at run time to adapt the other linked list instead.
- At the moment, Adaptee will be itself and it will be able to work with many other adaptees, as long as they all serve similar purpose.
- In order to use that, we need to have an object of the adaptee exist in the ObjectAdapter class and call the adaptee function for eacg of the function in ObjectAdapter
