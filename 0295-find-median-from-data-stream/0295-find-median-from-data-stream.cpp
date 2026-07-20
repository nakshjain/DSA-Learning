class MedianFinder {
private:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    int highSize=0, lowSize=0;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(low.empty()){
            low.push(num);
            lowSize++;
            return;
        }
        if(num < low.top()){
            low.push(num);
            lowSize++;
        } else {
            high.push(num);
            highSize++;
        }
        if(lowSize-highSize>1){
            high.push(low.top());
            highSize++;
            low.pop();
            lowSize--;
        } else if(highSize-lowSize >1){
            low.push(high.top());
            lowSize++;
            high.pop();
            highSize--;
        }
    }
    
    double findMedian() {
        if(lowSize>highSize) return low.top();
        else if(highSize>lowSize) return high.top();
        return (double)(low.top()+high.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */