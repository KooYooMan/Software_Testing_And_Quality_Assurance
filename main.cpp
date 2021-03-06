#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
const int N = 1e5 + 10;

int m, n, Prev[N];
char a[N], b[N];

int main() {
    
    scanf("%s%s", a + 1, b + 1);
    
    m = strlen(a + 1);
    n = strlen(b + 1);

    Prev[0] = -1;
    for (int i = 1; i <= n; i++) {
        Prev[i] = 0;
        for (int j = Prev[i - 1]; j != -1; j = Prev[j])
            if (b[j + 1] == b[i]) {
                Prev[i] = j + 1;
                break;
            }
    }

    int u = 0;
    for (int i = 1; i <= m; i++) {
        while (u != 0 && b[u + 1] != a[i]) u = Prev[u];
        if (b[u + 1] == a[i]) u++;
        if (u == n) printf("%d ", i - n + 1);
    }
    
    printf("\n");

    return 0;
}