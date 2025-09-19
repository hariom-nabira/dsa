class Spreadsheet {
private:
    vector<vector<int>> sheet;
    pair<int,int> getCellCoor(string &s){
        return {(s[0]-'A'), stoi(s.substr(1))};
    }
public:
    Spreadsheet(int rows) {
        sheet = vector<vector<int>> (26, vector<int>(rows,0));
    }
    
    void setCell(string cell, int value) {
        pair<int,int> coors = getCellCoor(cell);
        sheet[coors.first][coors.second - 1] = value;
    }
    
    void resetCell(string cell) {
        pair<int,int> coors = getCellCoor(cell);
        sheet[coors.first][coors.second - 1] = 0;
    }
    
    int getValue(string formula) {
        int ans=0, pi = formula.find("+");
        string cell1 = formula.substr(1,pi-1);
        string cell2 = formula.substr(pi+1);
        // cout<<pi<<"\n"<<cell1<<"\n"<<cell2<<"\n";
        // <<cell1[0]<<" "<<cell2[0]<<"\n";
        if('A' <= cell1[0] && cell1[0] <= 'Z'){
            // cout<<"the fuck";
            pair<int,int> coors = getCellCoor(cell1);
            ans += sheet[coors.first][coors.second-1];
        }else{
            ans += stoi(cell1);
        }
        if('A' <= cell2[0] && cell2[0] <= 'Z'){
            pair<int,int> coors = getCellCoor(cell2);
            ans += sheet[coors.first][coors.second-1];
        }else{
            ans += stoi(cell2);
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */