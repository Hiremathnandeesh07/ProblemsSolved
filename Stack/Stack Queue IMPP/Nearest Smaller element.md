https://www.interviewbit.com/problems/nearest-smaller-element/

Given an array, find the **nearest** smaller element G\[i\] for every element A\[i\] in the array such that the element has an **index smaller than i**.

More formally,

```
    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
```

Elements for which no smaller element exist, consider next smaller element as -1.

**Input Format**

```
The only argument given is integer array A.
```

**Output Format**

```
Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.
```

**For Example**

```
Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
Explaination 1:
    index 1: No element less than 4 in left of 4, G[1] = -1
    index 2: A[1] is only element less than A[2], G[2] = A[1]
    index 3: No element less than 2 in left of 2, G[3] = -1
    index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
    index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
    
Input 2:
    A = [3, 2, 1]
Output 2:
    [-1, -1, -1]
Explaination 2:
    index 1: No element less than 3 in left of 3, G[1] = -1
    index 2: No element less than 2 in left of 2, G[2] = -1
    index 3: No element less than 1 in left of 1, G[3] = -1
```


```cpp
vector<int> Solution::prevSmaller(vector<int> &A) {
     std::vector<int> G;  // Result vector to store the nearest smaller elements
    std::stack<int> st;  // Stack to keep track of elements

    for (int i = 0; i < A.size(); ++i) {
        // Pop elements from the stack that are not smaller than A[i]
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        // If stack is not empty, the top element is the nearest smaller element
        if (st.empty()) {
            G.push_back(-1);
        } else {
            G.push_back(st.top());
        }
        // Push the current element onto the stack
        st.push(A[i]);
    }

    return G;
}```