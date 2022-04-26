// https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/
// https://ide.geeksforgeeks.org/hC7twzHirt
// O(m*(n-m+1)) , O(1)
// PRE: 
// NOTE: worst case -> all same, last different, best case -> not present O(n)
// not happens in english but in binary


#include<iostream>
#include<cstring>
using namespace std;

void search(char* pattern, char* text){
    int patLen = strlen(pattern);
    int textLen = strlen(text);

    for(int i = 0; i<=textLen-patLen; i++){
        int j;
        for( j= 0; j<patLen; j++){
            if(text[i+j]!=pattern[j])
                break;
        }
          if(j==patLen)
                cout << "pattern found at " << i << endl;
    }

    
}

int main() 
{ 
    char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
    search(pat, txt); 
    return 0; 
} 