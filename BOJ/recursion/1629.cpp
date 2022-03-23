#include <iostream>
#define ll long long 
using namespace std;

ll func(ll a, ll b, ll c) //a를 b번 곱하고 c로 나눈 나머지를 반환하는 함수
{
    if (b == 1) return a % c;
    ll val = func(a, b / 2, c);
    val = val * val % c; //2k승 구하기
    if (b % 2 == 0) return val; //b가 짝수면 2k승
    else return val * a % c; //b가 홀수면 2k+1승 구해야 하니까 2k에 a를 한번 더 곱함
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;

    cin >> a >> b >> c;
    cout << func(a, b, c);
}
