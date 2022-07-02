//n1=1,3,5,7,8,9,10,11
//n2=2,4,6
//11个数找第6个,k=6,可以先删除6/2=3个，因为5<6，删除n1的3个肯定没问题，因为其实删除1,3,4,2,4都可以
//但是不能一次删除4个，最多3个，因为4个的话，及时上面的比下面的小，有可能这个数就是被找的那个
//重点是理解 5<6 保证了删除n1的3个不会删多了
double findK(int* n1, int s1, int* n2, int s2, int k) {
    if (s1 <= 0) {
        return n2[k-1];
    }
    if (s2 <= 0) {
        return n1[k-1];
    }
    
    int d = k/2;
    if (d == 0) {
        return n1[0] > n2[0] ? n2[0] : n1[0];
    }
    int mid1 = INT_MAX;
    int mid2 = INT_MAX;
    if (d <= s1) {
        mid1 = n1[d-1];
    }
    if (d <= s2) {
        mid2 = n2[d-1];
    }
    if (mid1 < mid2) {
        return findK(&n1[d], s1-d, n2, s2, k-d);
    } else {
        return findK(n1, s1, &n2[d], s2-d, k-d);
    }
}

double findMedianSortedArrays(int* n1, int s1, int* n2, int s2){
    int total = s1 + s2;
    int k = (total+1)/2;
    if (total % 2) {
        return findK(n1, s1, n2, s2, k);
    } else {
        return (findK(n1, s1, n2, s2, k) + findK(n1, s1, n2, s2, k+1))/2;
    }
}
