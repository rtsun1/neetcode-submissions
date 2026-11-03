class MedianFinder {
public:
    std::priority_queue<int, vector<int>, std::greater<int>>larger;
    std::priority_queue<int>smaller;
    MedianFinder() {
        // larger.push(std::numeric_limits<int>::min());
        // smaller.push(std::numeric_limits<int>::max());
    }
    
    void addNum(int num) {
        // invariant: larger.size() <= smaller.size() by at most 1
        if (smaller.empty()) {
            smaller.push(num);
            return;
        }
        
        if (num < smaller.top()) {
            if (smaller.size() > larger.size()) {
                larger.push(smaller.top());
                smaller.pop();
            }
            smaller.push(num);
        } else {
            larger.push(num);
            // keep invariant
            if (larger.size() > smaller.size()) {
                smaller.push(larger.top());
                larger.pop();
            }
        }
        // cout << smaller.size() << ' ' << larger.size() << endl;
    }
    
    double findMedian() {
        if (larger.size() == smaller.size()) {
            return ((double) smaller.top() + (double) larger.top()) / 2.0;
        } else {
            return smaller.top();
        }
    }
};
