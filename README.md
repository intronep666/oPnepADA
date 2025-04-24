# Algorithms and Data Structures

This repository contains various implementations of algorithms and data structures in C++. Below is a list of available programs:
---
## Sorting Algorithms
Sorting algorithms are used to arrange elements in a specific order, typically ascending or descending. Different sorting techniques vary in terms of efficiency, stability, and space complexity.
| Sorting Algorithm        | Best Case | Average Case | Worst Case | Space Complexity | Stable? |
|-------------------------|------------|-------------|------------|-----------------|---------|
| **Selection Sort**      | O(n²)      | O(n²)       | O(n²)      | O(1)            |  No  |
| **Bubble Sort**         | O(n)       | O(n²)       | O(n²)      | O(1)            |  Yes |
| **Insertion Sort**      | O(n)       | O(n²)       | O(n²)      | O(1)            |  Yes |
| **Merge Sort**          | O(n log n) | O(n log n)  | O(n log n) | O(n)            |  Yes |
| **Quick Sort**          | O(n log n) | O(n log n)  | O(n²)      | O(log n)        |  No  |
| **Iterative Quick Sort**| O(n log n) | O(n log n)  | O(n²)      | O(log n)        |  No  |
- ### Selection Sort
 :Finds the minimum element and places it at the beginning, repeating the process for the rest of the list.
  ![image](https://github.com/user-attachments/assets/64d7911b-0d39-4a29-ade0-b05c73b76fa4)

- ### Bubble Sort (`bubblesort.cpp`)
:Repeatedly swaps adjacent elements if they are in the wrong order.
![image](https://github.com/user-attachments/assets/44e10685-e8bb-42ca-a97a-3789231adfcf)

- ### Insertion Sort (`insertionsort.cpp`)
:Inserts each element at the correct position in the sorted part of the array.
![image](https://github.com/user-attachments/assets/081bc999-fee3-440d-8022-0c335c6db472)

- ### Merge Sort
:  Uses the divide-and-conquer approach by recursively splitting the array and merging sorted halves.
![image](https://github.com/user-attachments/assets/7e20aad0-c0c1-4314-b8ac-a440ec14c35d)

 - ### Quick Sort
:Selects a pivot, partitions the array, and recursively sorts the partitions.
![image](https://github.com/user-attachments/assets/4490b334-7399-4897-b3ed-cfd714ba2f78)

- **Iterative Quick Sort** (`iterativequicksort.cpp`)
:Implements quick sort iteratively using a stack instead of recursion.
![image](https://github.com/user-attachments/assets/71371d7e-2ef7-4ffb-a7f3-08fbe110196d)

  
---

##  Mathematical & Miscellaneous Algorithms
These algorithms solve various computational problems.

### 🔹 Find Peak Element in 1D & 2D Array
- Finding an element which is >= to its neighbours
- **1D**
Implemented using algo similar to Binary Search
- **2D**
Implemented using algo similar to Binary Search but works in a 2D array
- **Used in optimization problems** to find local maxima.
- Efficiently finds peaks in **logarithmic time**.

### 🔹 Magic Square (`magicsquare.cpp`)
- A square matrix where the sum of numbers in each row, column, and diagonal is the same.
- Follows a set pattern in where the numbers increase in a diagonal upwards to the left and goes down one when number is a multiple of the size
- **Used in cryptography and mathematical puzzles.**
  ![image](https://github.com/user-attachments/assets/8d84b44a-ef0c-43e9-aa0e-19a352068fb3)


### 🔹 Cosine Similarity (`cosinsimilarity.cpp`)
- Measures similarity between two non-zero vectors.
- Each files words are treated like a vector and the angle between the vectors created from the two file give the value for cosQ which tells us the similarity between the files
- **Used in recommendation systems and NLP.**

### 🔹 Jaccard Similarity (`jaccard.cpp`)
- Measures similarity between two sets.
- **Used in machine learning and clustering.**

---


##  Divide And Conquer Algorithms
These algorithms **break a problem into smaller subproblems, solve them recursively, and combine the results.**

### 🔹 Binary Search (`binarysearch.cpp`)
- Searches for an element in a sorted array in **O(log n) time**.
- **Much faster than linear search** for large datasets.

### 🔹 Max-Min Problem (`maxmin.cpp`)
- Finds the maximum and minimum in an array using **divide and conquer**.
- More efficient than brute force approaches.

### 🔹 Strassen's Matrix Multiplication
**Conventional Method
Using divide and conquer to break the matrix into smaller parts and multiplying them to get the resulting martix**
- Strassen's is  fast matrix multiplication algorithm.
- **Reduces multiplication complexity from O(n³) to O(n^2.81).**
---
## Greedy Algorithms
Greedy algorithms make locally optimal choices at each step **without considering future consequences**.

### 🔹 Activity Selection (`activitysel.cpp`)
- Selects the **maximum number of activities** that don’t overlap.
- **Used in scheduling problems.**

### 🔹 Knapsack Problem (`knapsack.cpp`)
- Optimizes item selection to **maximize value** within a weight constraint.
- We sort the array according to the metric we need(here we sort 3 time, according to profit, weight and ratio of profit/weight) and then pick the items in non-increasing manner
- The fractional part allows us to pick out items in fraction
For example if we have a capacity of 10 and the item weights 20 we can take out 10 out the weight instead of leaving that item and going to the next
- **Used in resource allocation problems.**
-![image](https://github.com/user-attachments/assets/e03ba061-e8e1-448e-814f-3dd2d56b37b0)


### 🔹 Dijkstra's Algorithm (`dijkstra.cpp`)
- Finds the **shortest path from a source node to all other nodes**.
- **Time Complexity: O(V²) (Using adjacency matrix) or O((V+E) log V) (Using priority queue + adjacency list).**
- **Used in network routing and GPS systems.**

### 🔹 Prim’s Algorithm
- Finds the **minimum spanning tree** of a graph.
- **Time Complexity: O(V²) (Using adjacency matrix) or O((V+E) log V) (Using priority queue + adjacency list).**
- **Used in network design problems.**

### 🔹 Kruskal’s Algorithm (`kruskals.cpp`)
- Another algorithm for finding the **minimum spanning tree**.
- **Time Complexity: O(E log E) (Using sorting and union-find data structure).**
- **Works well with edge list representation.**
---
##  Dynamic Programming (DP)
Dynamic Programming solves problems **by breaking them into overlapping subproblems and storing results**.

### 🔹 Multi-Stage Graph Problem (`MGP.cpp`)
- Solves shortest path problems in a multi-stage graph.
- **Time Complexity : O(V+E)**

### 🔹 All Pairs Shortest Path (Floyd-Warshall) (`allPairdp.cpp`)
- Finds **shortest paths between all pairs of nodes**.
- **O(n³) complexity, useful for dense graphs.**

---



