class MKAverage {
    int m, k;
    long long sum = 0;
    queue<int> q;
    multiset<int> lo, mid, hi;

    void add(int x) {
        if(!lo.empty() && x <= *lo.rbegin()) lo.insert(x);
        else if(!hi.empty() && x >= *hi.begin()) hi.insert(x);
        else {
            mid.insert(x);
            sum += x;
        }

        if(lo.size() > k){
            auto it = prev(lo.end());
            sum += *it;
            mid.insert(*it);
            lo.erase(it);
        }

        if (hi.size() > k) {
            auto it = hi.begin();
            sum += *it;
            mid.insert(*it);
            hi.erase(it);
        }

        while(lo.size() < k && !mid.empty()) {
            auto it = mid.begin();
            lo.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
        while(hi.size() < k && !mid.empty()) {
            auto it = prev(mid.end());
            hi.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
    }

    void remove(int x) {
        if(lo.find(x) != lo.end()) {
            lo.erase(lo.find(x));
        } else if(hi.find(x) != hi.end()) {
            hi.erase(hi.find(x));
        } else {
            sum -= x;
            mid.erase(mid.find(x));
        }

        while(lo.size() < k && !mid.empty()) {
            auto it = mid.begin();
            lo.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
        while(hi.size() < k && !mid.empty()) {
            auto it = prev(mid.end());
            hi.insert(*it);
            sum -= *it;
            mid.erase(it);
        }
    }

public:
    MKAverage(int m, int k) : m(m), k(k) {}

    void addElement(int num) {
        q.push(num);
        add(num);

        if(q.size() > m) {
            remove(q.front());
            q.pop();
        }
    }

    int calculateMKAverage() {
        if(q.size() < m) return -1;
        return sum / (m - 2 * k);
    }
};