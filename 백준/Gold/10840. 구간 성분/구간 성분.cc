#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MN 1500
long long hash_char[128];
const long long prime = 1234567891;
char s1[MN+3], s2[MN+3];
int count_char1[MN+3][26], count[26];
int N;
struct INTERVAL{
int left, right;
long long hash;
bool operator()(INTERVAL aa, INTERVAL bb){
return aa.hash < bb.hash;
}
}inter1[(MN+1)*(MN+1)/2];
int isprime(int x){
int i;
for(i=2;i*i<=x;i++) if(!(x%i)) return 0;
return 1;
}
void make_interval_hash(char *s, INTERVAL *inter){
int i, j;
long long hash;
int len = strlen(s);
for(i=0; i<len ; i++){
hash = 0;
for(j=i;j<len;j++){
hash += hash_char[s[j]];
inter[N].hash = hash;
inter[N].left = i;
inter[N].right= j;
N++;
}
}
std::sort(inter,inter+N,INTERVAL());
}
int find_hash(INTERVAL *inter, long long hash){
int left, right, mid;
for(left = 0, right = N-1 ; left <= right ; ){
mid = (left + right) >> 1;
if(inter[mid].hash == hash) return mid;
if(inter[mid].hash > hash) right = mid - 1;
else left = mid + 1;
}
return -1;
}
int is_same(INTERVAL inter, int *count){
if(inter.left) {
for(int i=0;i<26;i++)
if(count_char1[inter.right][i] - count_char1[inter.left-1][i] != count[i])
return 0;
}
else {
for(int i=0;i<26;i++)
if(count_char1[inter.right][i] != count[i])
return 0;
}
return 1;
}
int main(){
int i,j,k,l;
long long hash;
scanf("%s%s",s1,s2);
// make character hash code
hash_char['a'] = prime;
for(i='b' ; i<='z' ; i++) hash_char[i] = hash_char[i-1] * prime;
make_interval_hash(s1, inter1);
int n = strlen(s1);
int m = strlen(s2);
count_char1[0][s1[0]-'a'] = 1;
for(i = 1 ; i < n ; i++){
for(j = 0 ; j < 26 ; j++) count_char1[i][j] = count_char1[i-1][j];
count_char1[i][s1[i]-'a']++;
}
for(i = n; i > 0 ; i--){
hash = 0;
for(j = 0 ; j < 26; j++) count[j] = 0;
for(j = 0 ; j < i-1 ; j++){
count[s2[j] - 'a']++;
hash += hash_char[s2[j]];
}
for(j = i-1 ; j < m ; j++){
count[s2[j] - 'a']++;
hash += hash_char[s2[j]];
k = find_hash(inter1, hash);
if(k>=0){
for(l = k; l<N && inter1[l].hash == hash; l++) if( is_same(inter1[l], count) ){
printf("%d\n",i);
return 0;
}
for(l = k-1; l>=0 && inter1[l].hash == hash; l--) if( is_same(inter1[l], count) ){
printf("%d\n",i);
return 0;
}
}
count[s2[j-i+1] - 'a']--;
hash -= hash_char[s2[j-i+1]];
}
}
printf("0\n");
return 0;
}