# Problem Bit Array
- Problem link: [hackerrank](https://www.hackerrank.com/challenges/bitset-1/problem)

You are given four integers: , , , . You will use them in order to create the sequence  with the following pseudo-code.

```
a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 
```

Your task is to calculate the number of distinct integers in the sequence .

Input Format

Four space separated integers on a single line, N, S, P, and Q respectively.

Output Format

A single integer that denotes the number of distinct integers in the sequence .

Constraints

```
1 <= N <= 10^8
0 <= S,P,Q <= 2^31
```

Sample Input
```
3 1 1 1
```
Sample Output
```
3
```
Explanation


Hence, there are  different integers in the sequence.
