class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x=max(x1,min(x2,xCenter));
        int y=max(y1,min(y2,yCenter));

        int dist1=x-xCenter;
        int dist2=y-yCenter;

        return dist1*dist1 + dist2*dist2 <=radius*radius;
    }
};