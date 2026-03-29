class EventManager {
    
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    unordered_map<int,int> mp;

public:
    EventManager(vector<vector<int>>& events) {
        auto denqoravil = events;

        for(auto &e : events){
            int id = e[0];
            int pr = e[1];
            mp[id] = pr;
            pq.push({pr, id});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto top = pq.top();
            int pr = top.first;
            int id = top.second;
            
            if(mp[id] == pr){
                pq.pop();
                mp.erase(id);
                return id;
            }
            
            pq.pop();
        }
        return -1;
    }
};
