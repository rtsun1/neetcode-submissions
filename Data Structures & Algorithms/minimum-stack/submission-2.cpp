struct StackNode {
    int val;
    int minBelow;
};

class MinStack {
public:
    MinStack() {
        data.push({std::numeric_limits<int>::max(), std::numeric_limits<int>::max()});
    }
    
    void push(int val) {
        int minBelow = min(data.top().minBelow, data.top().val);
        data.push({val, minBelow});
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return data.top().val;
    }
    
    int getMin() {
        return std::min(data.top().val, data.top().minBelow);
    }

private:
    stack<StackNode> data;
};
