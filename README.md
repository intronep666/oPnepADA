# Algorithms and Data Structures

This repository offers a variety of algorithms and data structures implemented in C++. Below is a categorized list of the available programs:

---

## Sorting Algorithms

Sorting techniques are used to organize elements in a specific sequence—most commonly in ascending or descending order. Each method varies in speed, space usage, and stability.

| Sorting Algorithm        | Best Case   | Average Case | Worst Case | Space Complexity | Stable? |
|-------------------------|-------------|--------------|------------|------------------|---------|
| **Selection Sort**      | O(n²)       | O(n²)        | O(n²)      | O(1)             | No      |
| **Bubble Sort**         | O(n)        | O(n²)        | O(n²)      | O(1)             | Yes     |
| **Insertion Sort**      | O(n)        | O(n²)        | O(n²)      | O(1)             | Yes     |
| **Merge Sort**          | O(n log n)  | O(n log n)   | O(n log n) | O(n)             | Yes     |
| **Quick Sort**          | O(n log n)  | O(n log n)   | O(n²)      | O(log n)         | No      |
| **Iterative Quick Sort**| O(n log n)  | O(n log n)   | O(n²)      | O(log n)         | No      |

- ### Selection Sort  
: Selects the smallest element and places it at the beginning of the array, repeating the process for the remaining elements.  
  ![image](https://github.com/user-attachments/assets/64d7911b-0d39-4a29-ade0-b05c73b76fa4)

- ### Bubble Sort (`bubblesort.cpp`)  
: Repeatedly compares and swaps adjacent elements if they are in the wrong order.  
  ![image](https://github.com/user-attachments/assets/44e10685-e8bb-42ca-a97a-3789231adfcf)

- ### Insertion Sort (`insertionsort.cpp`)  
: Takes one element at a time and inserts it into its correct position in the already sorted portion.  
  ![image](https://github.com/user-attachments/assets/081bc999-fee3-440d-8022-0c335c6db472)

- ### Merge Sort  
: Applies a divide-and-conquer method by splitting the array into halves, sorting, and merging them.  
  ![image](https://github.com/user-attachments/assets/7e20aad0-c0c1-4314-b8ac-a440ec14c35d)

- ### Quick Sort  
: Chooses a pivot, partitions the array around the pivot, and recursively sorts the sub-arrays.  
  ![image](https://github.com/user-attachments/assets/4490b334-7399-4897-b3ed-cfd714ba2f78)

- **Iterative Quick Sort** (`iterativequicksort.cpp`)  
: An iterative version of quick sort using an explicit stack instead of recursion.  
  ![image](https://github.com/user-attachments/assets/71371d7e-2ef7-4ffb-a7f3-08fbe110196d)

---

## Mathematical & Miscellaneous Algorithms

These algorithms address a mix of computational and problem-solving tasks.

### 🔹 Find Peak Element in 1D & 2D Array  
- Identifies an element that is greater than or equal to its neighbors  
- **1D**  
Uses a binary search-inspired approach  
- **2D**  
Adapts binary search logic to two-dimensional arrays  
- Helpful in **optimization scenarios** to locate local peaks  
- Efficient performance with **logarithmic time complexity**

### 🔹 Magic Square (`magicsquare.cpp`)  
- A square matrix in which the totals of all rows, columns, and diagonals are identical  
- Constructed by a pattern where numbers move diagonally upward-left and drop one row when needed  
- **Applicable in puzzles and cryptographic systems**  
  ![image](https://github.com/user-attachments/assets/8d84b44a-ef0c-43e9-aa0e-19a352068fb3)

### 🔹 Cosine Similarity (`cosinsimilarity.cpp`)  
- Determines the similarity between two non-zero vectors  
- Treats the words in files as vectors and calculates the angle between them to determine similarity  
- **Commonly used in NLP and recommendation engines**

### 🔹 Jaccard Similarity (`jaccard.cpp`)  
- Measures how similar two sets are based on intersection and union  
- **Useful in clustering and machine learning**

---

## Divide And Conquer Algorithms

These algorithms break down a problem into smaller parts, solve each part recursively, and then combine their solutions.

### 🔹 Binary Search (`binarysearch.cpp`)  
- Efficiently searches for an element in a sorted array  
- **Time Complexity: O(log n)**

### 🔹 Max-Min Problem (`maxmin.cpp`)  
- Finds the maximum and minimum values using a recursive divide-and-conquer approach  
- More optimized than linear scanning

### 🔹 Strassen's Matrix Multiplication  
**Standard Method**  
Breaks matrices into sub-matrices for recursive multiplication  
- Strassen’s technique is faster than classical matrix multiplication  
- **Reduces complexity to approximately O(n^2.81)**

---

## Greedy Algorithms

These algorithms make the best decision at each step without revisiting previous choices.

### 🔹 Activity Selection (`activitysel.cpp`)  
- Picks the maximum number of non-overlapping activities  
- **Ideal for scheduling problems**

### 🔹 Knapsack Problem (`knapsack.cpp`)  
- Aims to maximize total value without exceeding the weight limit  
- Sorts based on profit, weight, and profit-to-weight ratio to choose items  
- Allows fractional selection of items  
- **Useful in resource allocation problems**  
  ![image](https://github.com/user-attachments/assets/e03ba061-e8e1-448e-814f-3dd2d56b37b0)

### 🔹 Dijkstra's Algorithm (`dijkstra.cpp`)  
- Calculates shortest paths from a starting node to all others  
- **Time Complexity:**  
  - O(V²) using adjacency matrix  
  - O((V+E) log V) using priority queue with adjacency list  
- **Common in GPS navigation and network routing**

### 🔹 Prim’s Algorithm  
- Builds a minimum spanning tree from a graph  
- **Time Complexity:**  
  - O(V²) using adjacency matrix  
  - O((V+E) log V) using priority queue with adjacency list  
- **Applied in network infrastructure design**

### 🔹 Kruskal’s Algorithm (`kruskals.cpp`)  
- Finds the minimum spanning tree using edge sorting and union-find  
- **Time Complexity: O(E log E)**  
- **Performs well with edge-list representations**

---

## Dynamic Programming (DP)

DP solves problems by breaking them into subproblems, solving each once, and storing the results for reuse.

### 🔹 Multi-Stage Graph Problem (`MGP.cpp`)  
- Solves shortest path problems in graphs divided into stages  
- **Time Complexity: O(V+E)**

### 🔹 All Pairs Shortest Path (Floyd-Warshall) (`allPairdp.cpp`)  
- Computes shortest paths between every pair of vertices  
- **Effective for dense graphs with O(n³) complexity**

---
