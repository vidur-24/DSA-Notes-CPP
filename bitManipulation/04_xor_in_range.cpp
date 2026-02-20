// TC : O(1)
// SC : O(1)
int xorOP(int n){ // find xor from (1,n) or (0,n) : both left and right inclusive
    // pattern of 4
    if(n%4 == 1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else return n;
}

int xorInRange(int left, int right){ // find xor from (left,right) : both left and right inclusive
    int xorL = xorOP(left-1);
    int xorR = xorOP(right);
    return (xorL ^ xorR);
}