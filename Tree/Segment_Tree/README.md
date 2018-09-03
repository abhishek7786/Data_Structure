## What I learned from this Implementation?
    How Segment Tree are Implemented. 
## If there are L leafes nodes then how many Internal nodes are there.<br>
       Internal nodes -> which are not pendant vertex.
  <br>**Duality counting Principle** is used here.
  ### What is this Duality Counting Principle ?<br>
  This is simple principle of counting same thing in two manners and then equating them.<br><br>
  For e.g -> There are **n** numbers of people in a room. Now number of ways you can select any number of person is
  2<sup>n</sup> <br> **how?**,simple ask each person whether he want to attend the party or not.<br> 2+2+2+...+2(n-times).
  why n times, because there are n persons.<br><br>
  Now count this thing again by different way , suppose select 0 from n ,then select 1 from n. <br><tab>Now for selecting **k** from **n** we can use this formula  **<sup>n</sup>C<sub>k<sub>**<br><br>
    And as both thing are calculating the same we can write 
    **2<sup>n</sup> =     $\sum_{k=0}^n$<sup>n</sup>C<sub>k</sub>** <br><br>
  Now Use this same concept in deciding the number of nodes in **Segment Tree** 
  <br>
### What is **Segment Tree**?
It is a binary tree whose each node represent an **interval** and each nodes stores a value. This value can be anything regarding your query.<br> for e.g -> It may store the **minimum** or **maximum** or **sum** of the **interval** represented by a node.
    Now as it is a binary tree, moreover it is a **binary complete tree** ( what is Binary complete Tree-> It is a binary tree whose each node can have either **0 or 2 children**,simple as it is)
    <br><br> Now to count number of nodes this segment tree has we already know that it will have **n** leaf nodes.
    <br> So by **Euler's Handshaking Lemma** we know that
     **2*E = $\sum_{i=0}^N$deg(v<sup>i</sup>)** i-i-th node of the tree. Lets say there are total number of nodes N.
    <br><br>
    Now we have to calculate this N.
    Number of edges in segment tree is = (L+ I -1)   -eq1<br>
    $\sum_{i=0}^N$deg(v<sup>i</sup>) = L + 3*(I-1) +2   -eq2<br><br>
 By hanshaking lemma these two are equal <br>  **L + 3(I-1) + 2 = 2(L+I-1)**   (why mutliplied with 2, see above formula)
    <br>This give us **I = L-1**
    <br> so our segment tree will have **I +L** nodes and if l = n, which is generally the size of array which is used to built the segment tree then that tree will have total **I+L= L-1 + L = 2n-1** nodes.
    <br>And suppose we using the array representation of tree and we need to store the all the nodes, then for the safety use the **4n** as the size of that array which you are using to built the segment tree.
     
