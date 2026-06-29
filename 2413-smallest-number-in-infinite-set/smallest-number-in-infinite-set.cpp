class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int, vector<int>, greater<int>>pq;
    unordered_set<int>present;
    SmallestInfiniteSet() {
        current = 1;
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int result = pq.top();
            pq.pop();
            present.erase(result);
            return result;
        }
        return current++;
    }
    
    void addBack(int num) {
        if(num < current && !present.count(num)){
            pq.push(num);
            present.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */