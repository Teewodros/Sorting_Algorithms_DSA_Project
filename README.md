#Bubble Sort

Bubble sort is a simple comparison‑based algorithm that repeatedly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order. With each full pass, the largest unsorted element “bubbles” up to its correct position at the end of the list. Although easy to understand and implement, bubble sort is inefficient for large datasets because it performs many repeated comparisons and swaps. Its strength lies in its simplicity and its ability to detect when a list is already sorted, allowing it to stop early in best‑case scenarios.

#Selection Sort

Selection sort works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and placing it in its correct position. The algorithm divides the list into two parts: a sorted section that grows from the front and an unsorted section that shrinks as the smallest elements are extracted. It performs fewer swaps than bubble sort, but it still requires scanning the entire unsorted portion for each selection, making it inefficient for large datasets. Its predictable behavior and minimal swapping make it useful in situations where memory writes are costly.

#Insertion Sort

Insertion sort builds a sorted list one element at a time by taking each new element and inserting it into its correct position among the previously sorted elements. It behaves much like sorting playing cards in your hand—each new card is placed where it belongs relative to the others. This algorithm is efficient for small datasets or nearly sorted lists because it minimizes unnecessary comparisons and shifts. Its adaptive nature and stable behavior make it a practical choice for real‑time systems or as a subroutine in more advanced sorting algorithms.

#Merge Sort

Merge sort is a divide‑and‑conquer algorithm that splits a list into smaller sublists until each contains a single element, then merges these sublists back together in sorted order. The merging process ensures that the final result is fully sorted, regardless of the initial arrangement of elements. Merge sort is highly efficient and guarantees good performance even on large datasets, thanks to its consistent time complexity. However, it requires additional memory to store temporary sublists, which can be a drawback in memory‑constrained environments.

#Quick Sort

Quick sort is another divide‑and‑conquer algorithm, but instead of splitting the list evenly, it selects a pivot element and partitions the remaining elements into two groups: those less than the pivot and those greater. It then recursively sorts the partitions. When the pivot is chosen well, quick sort is extremely fast and efficient, often outperforming other algorithms in practice. However, poor pivot choices can lead to degraded performance. Despite this, its in‑place partitioning and average‑case speed make it one of the most widely used sorting algorithms.
