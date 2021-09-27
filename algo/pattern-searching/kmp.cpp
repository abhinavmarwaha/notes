// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
// <runnable link>
// O(n) , O(m) lps array
// PRE: 
// NOTE:  uses degenerating property (pattern having same sub-patterns appearing more than once in the pattern
// idea -> mismatch (after some matches), we already know some of the characters in the text of the next window.
// preprocessing -> an integer array lps[] that tells us the count of characters to be skipped. 
// lps -> longest proper prefix which is also suffix.
// we focus on sub-strings of patterns that are either prefix and suffix.
// Note : lps[i] could also be defined as longest prefix which is also proper suffix. We need to use properly at one place to make sure that the whole substring is not considered.



#include <iostream> 
#include <cstring>
void computeLPSArray(char* pat, int M, int* lps); 


void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	int lps[M]; 

	computeLPSArray(pat, M, lps); 

	int i = 0;
	int j = 0; 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found pattern at index %d ", i - j); 
			j = lps[j - 1]; 
		} 

		else if (i < N && pat[j] != txt[i]) { 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

void computeLPSArray(char* pat, int M, int* lps) 
{ 
	int len = 0; 

	lps[0] = 0; 

	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

int main() 
{ 
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
} 
