class SnapshotArray {
public:
    int snap_id;
    vector<map<int, int>> mp;

    SnapshotArray(int length) {
        snap_id = 0;
        mp.resize(length);

        for (int i = 0; i < length; i++) {
            mp[i][0] = 0;
        }
    }

    void set(int index, int val) {
        mp[index][snap_id] = val;
    }

    int snap() {
        return snap_id++;
    }

    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id);
        --it;
        return it->second;
    }
};