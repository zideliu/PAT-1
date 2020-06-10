#include <iostream>
const int maxn = 200005;
int n, m, a1[maxn], a2[maxn], cnt = 0, i, j, ans;
int main() {
    scanf("%d", &n);
    for(i = 1; i <= n; i++) scanf("%d", &a1[i]);
    scanf("%d", &m);
    for(i = 1; i <= m; i++) scanf("%d", &a2[i]);
    int target = (n + m + 1) / 2;
    i = 1, j = 1;
    while(i <= n && j <= m) {
        ans = a1[i] <= a2[j] ? a1[i++] : a2[j++];
        if(++cnt == target) break;
    }
    if(i <= n && cnt < target)  
        ans = a1[i + target - cnt - 1];
    else if(j <= m && cnt < target) 
        ans = a2[j + target - cnt - 1];
    printf("%d", ans);
    return 0;
}


//时间复杂度O(log(min(m,n)))
//虽然有点复杂，但是算法很优秀
#include <iostream>
#include <cmath>
using namespace std;
//整个算法利用 中位数的性质，即中位数划分之后的两组数长度相等（或差一）
//且中位数左边的最大值 ≤ 中位数右边的最小值
//例如
// A[0]...[i-1] [i]...[m-1]
// B[0]...[j-1] [j]...[n-1]
// 也即是说找一条线划分这两个数组，使得左边一部分的数目为(n+m+1)/2，
// 我们要在[0,m]中找最大的 i 使得 A[i]≥B[j-1] A[j-1]≤B[j]
void findmid(int nums1[],int nums2[],int m,int n){
    int left = 0, right = m;
    // 分割线左边的所有元素需要满足的个数 m + (n - m + 1) / 2;
    // 两个数组长度之和为偶数时，当在长度之和上+1时，由于整除是向下取整，所以不会改变结果
    // 两个数组长度之和为奇数时，按照分割线的左边比右边多一个元素的要求，此时在长度之和上+1，就会被2整除，会在原来的数
    // 的基础上+1，于是多出来的那个1就是左边比右边多出来的一个元素 也即保证我们所要求的解是左部分的最大值。
    int totalleft=(m+n+1)/2;
    // 在 nums1 的区间 [0, m] 里查找恰当的分割线，
    // 使得 nums1[i - 1] <= nums2[j] && nums2[j - 1] <= nums1[i],这两个条件随便一个都行，因为A,B都是递增序列且我们要找最大的 i
    while(left<right){
        int i=left+(right-left+1)/2;//用二分思想找确定i
        int j=totalleft-i;          //根据总长度为totalleft确定j
        if(nums1[i-1]>nums2[j]){    
            right=i-1;              //下一轮搜索区域[left,i-1]
        }else{
            left=i;                 //下一轮搜索区域[i,right]
        }
    }
    int i=left;                     //此为找到的i，A中 [0]...[i-1]属于左部分
    int j=totalleft-i;              //由i+j=totalleft，得j，B中[0]...[j-1]属于右部分
    int nums1LeftMax = nums1[i - 1];
    int nums2LeftMax = nums2[j - 1];
    cout<<max(nums1LeftMax,nums2LeftMax);//那我们所需要的就是求两者最大值
}
const int maxn=200001;
int a[maxn];
int b[maxn];
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    cin>>m;
    for(int i=0;i<m;i++)scanf("%d",b+i);
    if(n>m){
        findmid(b,a,m,n);
    }else{
        findmid(a,b,n,m);
    }
    return 0;
}
