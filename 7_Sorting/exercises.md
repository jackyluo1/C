Exercises
Discuss and answer the following questions (Please make sure to elaborate and justify your responses):

Explain what do you think the Big-Oh (worst-case) complexity of this algorithm is? Why?
What do you think the best-case complexity of this algorithm is?
Provide an example of an array of elements that fit the best-case.
Does insertion sort require any additional storage beyond the original array? Explain why or why not.
What is a 'stable sorting' algorithm? Is insertion sort a 'stable' algorithm, why or why not?
Answers:

1.O(n^2).If the array to be sorted is in reverse order,it will be O(n^2).

2.O(n).If the array to be sorted is already ordered, each iteration of the for loop will not be executed inside the while loop,it will be O(n).

3.Yes. We will use a "temp" to locate new thing to finish the "swap".

4.No. A sorting is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear iIn the input array to be sorted. Insertion sort is widely used for small data sets, while for large data sets an asymptotically efficient sort is used, primarily heap sort, merge sort, or quicksort.
