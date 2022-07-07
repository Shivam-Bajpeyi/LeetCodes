Bruteforce I: O(MN)| for every node of L1, check every node of L2 node address.
​
Bruteforce II[Hashing]: tc= O(M+N), sc= O(N)|
Hash nodes of one linklist and trvarse in the another one in order to find same node address.- first submission
​
Optimal: tc= O(N), sc= O(1)|
d1 = headA, d2 = headB
iterate d1 & d2-> assign to other head if one of them reaches to NULL, after such point both nodes will be equal.
​