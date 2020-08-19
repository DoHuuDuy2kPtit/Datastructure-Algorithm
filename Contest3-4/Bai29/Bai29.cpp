#include<bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
};

bool compareX(point a,point b) {
    return a.x < b.x;
}

bool compareY(point a,point b) {
    return a.y < b.y;
}

float dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float findMinDist(point p[],int n) {
    float min = FLT_MAX;
    for(int i = 0; i < n ;i++) {
        for(int j = i+1; j < n; j++) {
            if(dist(p[i],p[j]) < min) min = dist(p[i],p[j]);
        }
    }
    return min;
}

float stripClosest(point strip[],int sizes, float d){
    float min = d;
    sort(strip,strip+sizes,compareY);
    for(int i = 0; i < sizes; i++) {
        for(int j = i+1; j < sizes && (strip[j].y-strip[i].y);j++) {
            if(dist(strip[i],strip[j]) < min) min = dist(strip[i],strip[j]);
        }
    }
    return min;
}

float closestUtil(point p[],int n) {
    if(n<=3) {
        return findMinDist(p,n);
    }
    int mid = n/2;
    point midPoint = p[mid];

    float dl = closestUtil(p,mid);
    float dr = closestUtil(p + mid,n - mid);

    float d = (dl < dr) ? dl:dr;
    point strip[n];
    int j = 0;
    for(int i = 0; i < n; i++)
        if(abs(p[i].x - midPoint.x) < d)
            strip[j] = p[i], j++;
    return (d < stripClosest(strip,j,d)) ? d : stripClosest(strip,j,d);
}

float closest(point p[],int n) {
    sort(p,p+n,compareX);
    return closestUtil(p,n);
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        point P[n+1];
        for(int i = 0; i < n; i++) {
            cin >> P[i].x >> P[i].y;
        }
        printf("%0.6f",closest(P,n));
        cout << endl;
    }
	return 0;
}
