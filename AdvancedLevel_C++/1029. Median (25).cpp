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

#include <iostream>
#include <cmath>
using namespace std;
const int minn=-99999;
void findmid(int nums1[],int nums2[],int m,int n){
    int left = 0, right = m;
    int totalleft=(m+n+1)/2;
    while(left<right){
        int i=left+(right-left+1)/2;
        int j=totalleft-i;
        if(nums1[i-1]>nums2[j]){
            right=i-1;
        }else{
            left=i;
        }
    }
    int i=left;
    int j=totalleft-i;
    int nums1LeftMax = nums1[i - 1];
    int nums2LeftMax = nums2[j - 1];
    cout<<max(nums1LeftMax,nums2LeftMax);
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
