#include <bits/stdc++.h>
using namespace std;

int main(){
   int W,H,N;
   cin >> W >> H >> N;
   int point[N][3];
   for(int i = 0; i<N; i++)
   {
    for(int j =0; j<3; j++) 
    {
        cin >> point[i][j];
    }
   }
   int BorW[W][H];
   for(int i =0; i<W; i++) {
    for(int j=0; j<H; j++) {
        BorW[i][j] = 0;
    }
   }
   for(int i = 0; i<N; i++) {
    switch(point[i][2]) {
        case 1:
            for(int x = 0; x<point[i][0]; x++) {
                for(int y = 0; y<H; y++) {
                    BorW[x][y] = 1;
                }
            }
        case 2:
            for(int x = point[i][0]; x<W; x++) {
                for(int y = 0; y<H; y++) {
                    BorW[x][y] = 1;
                }
            }
        case 3:
            for(int x = 0; x<W; x++) {
                for(int y = 0; y<point[i][1]; y++) {
                    BorW[x][y] = 1;
                }
            }
        case 4:
            for(int x = 0; x<W; x++) {
                for(int y = point[i][1]; y<H; y++) {
                    BorW[x][y] = 1;
                }
            }
    }
   }
    
   int ans = 0;
    for(int i =0; i<W; i++) {
    for(int j=0; j<H; j++) {
        if(point[i][j] == 0) ans++;
    }
    }
 	cout << ans << endl;
}
