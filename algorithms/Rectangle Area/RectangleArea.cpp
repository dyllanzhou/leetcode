/*Rectangle Area
Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int r1[4]={A,B,C,D};
        int r2[4]={E,F,G,H};
        int *l,*r;
        int subr = 0;
        //sort, first left, then height
        if(A < E ||(A==E && D >= H))
            l = r1,r = r2;
        else
            l = r2,r = r1;
        if(l[2] < r[0] || l[3] < r[1] ||
           l[1] > r[3]) //no intersect
            subr = 0;
        else{
            int l1 = max(l[0],r[0]);
            int l2 = max(l[1],r[1]);
            int m1 = min(l[2],r[2]);
            int m2 = min(l[3],r[3]);
            subr =  (m1-l1)*(m2-l2);
        }
        
        return (C-A)*(D-B) + (G-E)*(H-F) - subr;
    }
};