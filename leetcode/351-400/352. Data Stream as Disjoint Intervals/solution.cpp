#define pb push_back

bool comp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }


class SummaryRanges {
public:
    vector<vector<int>> v;
    vector<vector<int>> arr;
    SummaryRanges() {
        
    }

    bool intersectInterval(vector<int> &a, vector<int> &b){
        if(a[0] <= b[0] && b[0] <= a[1]+1){
            return true;
        }
        if(b[0] <= a[0] && a[0] <= b[1]+1){
            return true;
        }
        return false;
    }

    int lowerbound(vector<int> &m){
        if(m[0] <= v[0][0]){
            return 0;
        }
        int st = 0, en = v.size()-1;
        while(st <= en){
            int mid = (st+en)/2;
            if(v[mid][0] == m[0]){
                return mid;
            }

            if(v[mid][0] < m[0]){
                st = mid +1;
            }
            else {
                en = mid-1;
            }
            
        }

        return st;
    }



    void mergeInterval(vector<int> &m){
        if(v.size() == 0){
            v.pb(m);
            return;
        }

        int l = lowerbound(m);
        // cout << (l - v.begin());
        v.insert(v.begin()+l, m);
        arr.pb(v[0]);
        for(int i = 1; i < v.size(); i++){
            if(intersectInterval(v[i], arr.back())) {
                arr.back() = {min(arr.back()[0], v[i][0]), max(arr.back()[1], v[i][1])};
            }
            else {
                arr.pb(v[i]);
            }
        }
        v = arr;
        arr.clear();
    }
    
    void addNum(int value) {
        // arr.pb(value);
        vector<int> temp = {value, value};
        mergeInterval(temp);
    }
    
    vector<vector<int>> getIntervals() {
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */