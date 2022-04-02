# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap?
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity?
4. Whaisis 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. Yes,they are in O(1).
2. define "char*Key, int BucketSize" in the struct hashmap and repeat them when using them in the following codes.
3. Maybe it goes up from O(1) to O(i).（1<i<n） 
4. Hash maps uses the "Function(i) = i" idea and keeps looking for the next available address, which may lead to primary clustering. 


