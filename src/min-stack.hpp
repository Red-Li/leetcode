
class MinStack {
    stack<int> data;
    stack<int> mins;

public:
    void push(int x) {
        data.push(x);
        if(!mins.size() || x <= mins.top())
            mins.push(x);
    }

    void pop() {
        if(data.top() <= mins.top())
            mins.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return mins.top();
        
    }
};
