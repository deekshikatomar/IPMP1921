class Solution {
public:
    string check(int board[3][3]) {
        
        for(int i=0; i<3; i++) {
            int count = 0;
            
            for(int j=0; j<3; j++) count += board[i][j];
            
            if(count==3) return "A";
            if(count == 15) return "B";
        }

        for(int i=0; i<3; i++) {
            int count = 0;
            
            for(int j=0; j<3; j++) count += board[j][i];
            
            if(count==3) return "A";
            if(count == 15) return "B";
        }

        int count = 0;
        for(int i=0; i<3; i++) count += board[i][i];
        if(count==3) return "A";
        if(count==15) return "B";
        
        count = 0;
        for(int i=0; i<3; i++) count += board[i][2-i];
        if(count==3) return "A";
        if(count==15) return "B";
        
        return "";
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        int board[3][3] = {0};
        
        for(int i=0; i<moves.size(); i++) {
            int x = moves[i][0], y = moves[i][1];
            
            if(i%2==0) board[x][y] = 1;
            else board[x][y] = 5;
            
            if(i>=4 and check(board).size()) return check(board);
        }
        
        return moves.size()==9 ? "Draw" : "Pending";
    }
};
