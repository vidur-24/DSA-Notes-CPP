#include <bits/stdc++.h>
using namespace std;


// 1. SWAP 2 NUMBERS
int a;
int b;
a = a ^ b;
b = a ^ b;
a = a ^ b;



// 2. CHECK IF A NUMBER IS EVEN OR ODD
int n;
if(n & 1) cout << "ODD"; // if lsb is 1 then number is odd
else cout << "EVEN";



// 3. CHECK IF i-th (starting from 0-th) BIT IS SET
// using left shift
// explanation: - 1 << i will give a number with i-th bit set and all other bits unset
//              - if we do n & (1 << i) then if i-th bit is set in n then the result will be non-zero
if(n & (1 << i)) cout << "SET";
else cout << "NOT SET";
// using right shift
// explanation: - n >> i will give a number with i-th bit as lsb
//              - if we do n & 1 then if i-th bit is set in n then the result will be 1(non-zero)
if((n >> i) & 1) cout << "SET";
else cout << "NOT SET";



// 4. SET i-th BIT
// using left shift
// explanation: - 1 << i will give a number with i-th bit set and all other bits unset
//              - if we do n | (1 << i) then i-th bit will be set in n
n = n | (1 << i);



// 5. UNSET i-th BIT
// using left shift
// explanation: - ~(1 << i) will give a number with i-th bit unset and all other bits set
//              - if we do n & ~(1 << i) then i-th bit will be unset in n
n = n & ~(1 << i);



// 6. TOGGLE i-th BIT : 0 to 1 and 1 to 0
// using left shift
// explanation: - 1 << i will give a number with i-th bit set and all other bits unset
//              - if we do n ^ (1 << i) then i-th bit will be toggled in n
n = n ^ (1 << i);



// 7. REMOVE THE RIGHTMOST(LAST) SET BIT : 1100 -> 1000
// explanation: - n & (n-1) will remove the rightmost set bit
//              - n-1 will have all bits same as n except the rightmost set bit and all bits to the right of it
//              - n = 101000 , n-1 = 100111 
//              -       ^              ^     } in n-1 , rightmost bit is unset and trailing 0s are set
n = n & (n-1);



// 8. CHECK IF A NUMBER IS A POWER OF 2 : only 1 set bit
// explanation: - n = 10000 , n-1 = 01111
//              - if n is a power of 2 then n & (n-1) will be 0
if((n & (n-1)) == 0) cout << "POWER OF 2";
else cout << "NOT POWER OF 2";



// 9. COUNT NUMBER OF SET BITS
int n;
int count = 0;
while(n){
    count = count + (n & 1); // adds 1 to count, if lsb is 1
    n = n >> 1;
}
// another way
while(n){
    n = n & (n-1); // turn rightmost set bit off
    count++; // and increase count by 1
}



// 10. TO FIND POWER OF 2
// explanation: - 1 << n will give 2^n
int n;
int ans = 1 << n;