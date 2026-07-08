class CustomStack {
public:
    vector<int> st, inc;
    int topidx;

    CustomStack(int maxSize) {
        st.resize(maxSize);
        inc.assign(maxSize, 0);
        topidx = -1;
    }

    void push(int x) {
        if (topidx + 1 == st.size())
            return;

        st[++topidx] = x;
    }

    int pop() {
        if (topidx == -1)
            return -1;

        int ans = st[topidx] + inc[topidx];

        if (topidx > 0)
            inc[topidx - 1] += inc[topidx];

        inc[topidx] = 0;
        topidx--;

        return ans;
    }

    void increment(int k, int val) {
        int idx = min(k - 1, topidx);

        if (idx >= 0)
            inc[idx] += val;
    }
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */