class Solution {
public:
   struct Rectangle{
        int x1;
        int y1;
        int x2;
        int y2;
      
    }res;

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        Rectangle r1 = {rec1[0],rec1[1],rec1[2],rec1[3]};
        Rectangle r2 = {rec2[0],rec2[1],rec2[2],rec2[3]};
        
        res.x1 = max(r1.x1,r2.x1);
        res.y1 = max(r1.y1,r2.y1);
        res.x2 = min(r1.x2,r2.x2);
        res.y2 = min(r1.y2,r2.y2);
        
        if(res.x1 >= res.x2 || res.y1 >= res.y2) return false;
        else return true;

    }

};
