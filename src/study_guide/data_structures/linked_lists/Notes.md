# Linked list
Single liked lists are better than arrays in the two factors:
1. Insertion
2. Deletion

Why? it's simple, arrays have to shift all the elements to a side and that is expensive. On the other hand linked lists just have to point to a different node.

Disadvantages:
1. No cache. Arrays have contigous memory which gives them locality of reference, a thing that LL doesn't have.
2. Extra memory space per pointer
3. Only sequential access is allowed (Binary search is hard to implement)

