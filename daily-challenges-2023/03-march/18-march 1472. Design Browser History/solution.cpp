#define pb push_back

class BrowserHistory {
public:
    vector<string> history;
    int currInd = 0;
    int maxInd = 0;
    BrowserHistory(string homepage) {
        history.pb(homepage);
    }

    void print(){
        // for(int i = 0; i <= maxInd; i++){
        //     cout << history[i] << " ";
        // }
        // cout << endl;
    }
    
    void visit(string url) {
        currInd++;
        maxInd = currInd;
        if(currInd == history.size()){
            history.pb(url);
            return;
        }
        
        history[currInd] = url;
    }
    
    string back(int steps) {
        // print();
        if(-steps + currInd < 0){
            currInd = 0;
            return history[0];
        }
            currInd -= steps;
            return history[currInd];

    }
    
    string forward(int steps) {
        if(currInd + steps >= maxInd){
            currInd = maxInd;
            return history[maxInd];
        }
        currInd += steps;
        return history[currInd];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */