class AllOne {
public:
    unordered_map<string, int> freq;
    map<int, unordered_set<string>> mp;

    AllOne() {
    }

    void inc(string key) {
        int oldFreq = freq[key];

        if (oldFreq > 0) {
            mp[oldFreq].erase(key);
            if (mp[oldFreq].empty())
                mp.erase(oldFreq);
        }

        freq[key]++;
        mp[oldFreq + 1].insert(key);
    }

    void dec(string key) {
        int oldFreq = freq[key];

        mp[oldFreq].erase(key);
        if (mp[oldFreq].empty())
            mp.erase(oldFreq);

        if (oldFreq == 1) {
            freq.erase(key);
        } else {
            freq[key]--;
            mp[oldFreq - 1].insert(key);
        }
    }

    string getMaxKey() {
        if (mp.empty())
            return "";

        return *mp.rbegin()->second.begin();
    }

    string getMinKey() {
        if (mp.empty())
            return "";

        return *mp.begin()->second.begin();
    }
};