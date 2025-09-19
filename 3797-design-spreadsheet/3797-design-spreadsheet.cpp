class Spreadsheet {
private:
    unordered_map<string, int> sheet;
public:
    Spreadsheet(int rows) {}
    void setCell(string cell, int value) {
        sheet[cell] = value;
    }
    void resetCell(string cell) {
        sheet.erase(cell);
    }
    int getValue(string formula) {
        int pi = formula.find("+");
        string s1 = formula.substr(1,pi-1);
        string s2 = formula.substr(pi+1);
        int v1 = ('A'<=s1[0] && s1[0]<='Z') ? sheet[s1] : stoi(s1);
        int v2 = ('A'<=s2[0] && s2[0]<='Z') ? sheet[s2] : stoi(s2);
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */