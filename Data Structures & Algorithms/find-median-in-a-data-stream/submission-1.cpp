class MedianFinder {
public:
    std::multiset<int> nums;
    std::multiset<int>::iterator median1, median2;
    MedianFinder() {
        median1 = nums.begin();
        median2 = nums.end();
    }
    
    void addNum(int num) {
        nums.insert(num);
        int median = findMedian();
        if (num >= median) {
            if (nums.size() % 2 == 1) {
                median1 = median2 = next(median1);
            } else {
                median2 = next(median1);
            }
        } else {
            if (nums.size() % 2 == 1) {
                median1 = median2 = prev(median2);
            } else {
                median1 = prev(median2);
            }
        }
    }
    
    double findMedian() {
        return static_cast<double>(*median1 + *median2) / 2.0;
    }
};
