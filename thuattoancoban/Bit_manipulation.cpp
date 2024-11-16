/*
**Bitwise operator has the least priority in processing equation**
+++++++++++++++++++++++++++++++
& - and
1 & 1 = 1
0 & 1 = 0
1 & 0 = 0
0 & 0 = 0
Example:
13 (1101) & 4 (0100) = 4
Explanation:
1101
0100
----
0100
+++++++++++++++++++++++++++++++
^ - xor
1 ^ 1 = 0
0 ^ 1 = 1
1 ^ 0 = 1
0 ^ 0 = 0
Example:
13 (1101) ^ 4(0100) = 9
Explanation:
1101
0100
----
1001
+++++++++++++++++++++++++++++++
| - or
1 | 1 = 1
0 | 1 = 1
1 | 0 = 1
0 | 0 = 0
Example:
13 (1101) | 4(0100) = 13
Explanation:
1101
0100
----
1101
+++++++++++++++++++++++++++++++
~ - not // uncommon
~1 = 0
~0 = 1
Example: 
~5 (00000000000000000000000000000101) = -6 (11111111111111111111111111111010)
Integer is stored in computer by 32 bits.
+++++++++++++++++++++++++++++++
<< - left shift
Example: 3 (11) << 2 = 12 (1100)
+++++++++++++++++++++++++++++++
>> - right shift
Example: 11 (1011) >> 2 = 2 (10)
*/

// Important
int getBit(int x, int k) {
	return (x >> k) & 1;
}
// usually used as  
#define BIT(x,k) (((x) >> k) & 1)

// Important
int setBit(int x, int k) {
	return x | (1 << k);
}

int offBit(int x, int k) {
	return x & (~(1 << k));
}

int flipBit(int x, int k) {
	return x ^ (1 << k);
}
// for all functions above, if x is a long long variable, use 1LL << k instead of 1 << k.

// __builtin_popcount(x) return number of 1s in binary representation of x, for x in int
// for long long x, using __builtin_popcountll(x)