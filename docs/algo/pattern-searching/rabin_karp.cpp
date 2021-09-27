// https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// <runnable link>
// average-> O(n+m), O(nm) -> worst case , <Space Complexity>
// Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings of txt[] match with hash value of pat[]. For example pat[] = “AAA” and txt[] = “AAAAAAA”.
// PRE: naive pattern
// NOTE: Hash at the next shift must be efficiently computable from the current hash 
// value and next character in text or we can say hash(txt[s+1 .. s+m]) 
// must be efficiently computable from hash(txt[s .. s+m-1]) and txt[s+m] i.e., hash(txt[s+1 .. s+m])= rehash(txt[s+m], hash(txt[s .. s+m-1])) 
// and rehash must be O(1) operation.
// rabin karp suggested integer -> So the numeric values cannot be practically stored as an integer, can fit in memory words
// hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q 

// hash( txt[s .. s+m-1] ) : Hash value at shift s.
// hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1)
// d: Number of characters in the alphabet
// q: A prime number
// h: d^(m-1)

#include<iostream>
using namespace std;

int main(){

    return 0;
}