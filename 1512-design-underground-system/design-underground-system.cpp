class UndergroundSystem {
public:
    unordered_map<string,pair<int,int>>mp;
    map<int,pair<string,int>> checkinmap;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkinmap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto&it=checkinmap[id];
        int entryTime = it.second;
        int timeTaken = t-entryTime;
        string entryStation = it.first;
        string route = entryStation + "_" + stationName;
        mp[route].first  += timeTaken;
        mp[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route =  startStation + "_" + endStation;
        auto&it  =  mp[route];
        return (double)it.first/it.second;
    }
};