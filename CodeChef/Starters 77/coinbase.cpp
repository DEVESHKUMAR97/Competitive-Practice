
class Worker {
    public:
    string id;
    string position;
    int compensation;
    int totalTimeSpent;
    int currentStatus; // 0 -> not in office, 1 -> in office;
    int lastTimeStamp;
    vector<int> perDayTimeSpents;
    map<string, pair<int, int>> mp; // comp, time
    
};



void print(Worker worker) {
    cout << worker.id << ", "
    << worker.compensation << ", "
    << worker.currentStatus << ", "
    << worker.totalTimeSpent << ", "
    << worker.lastTimeStamp << ", "
    << endl;
}
bool addWorker(string& id, string& position, string comp, unordered_map<string, Worker>& workerMap) {
    if(workerMap.find(id) != workerMap.end()) {
        // id already existed
        return false;
    }
    Worker worker;
    worker.id = id;
    worker.position = position;
    worker.compensation = stoi(comp);
    worker.totalTimeSpent = 0;
    worker.currentStatus = 0;
    worker.lastTimeStamp = -1;
    // pair<int, int> pp = {comp, 0}
    worker.mp[position] = {stoi(comp), 0};
    
    workerMap[id] = worker;
    
    return true;
    
    
}

bool registerWorker(string& id, string& timeStamp, unordered_map<string, Worker>& workerMap) {
    if(workerMap.find(id) == workerMap.end()) {
        // id not existed
        return false;
    }
    
    Worker& worker = workerMap[id];
    
    if(worker.currentStatus == 0) {
        // entering office
        worker.currentStatus = 1;
        worker.lastTimeStamp = stoi(timeStamp);
        
    } else if(worker.currentStatus == 1) {
        // leaving office
        worker.currentStatus = 0;
        int currDayTimeSpent = stoi(timeStamp) - worker.lastTimeStamp;
        worker.perDayTimeSpents.push_back(currDayTimeSpent);
        worker.totalTimeSpent += currDayTimeSpent;
        worker.lastTimeStamp = -1;
    }
    
    return true;
    
}

string promote(string& id, string& nPos, string ncomp, string time, unordered_map<string, Worker>& workerMap) {
    if(workerMap.find(id) == workerMap.end()) {
        // id not existed
        return "invalid_request";
    }
    
    
}
string getWorker(string& id, unordered_map<string, Worker>& workerMap) {
    if(workerMap.find(id) == workerMap.end()) {
        // id already existed
        return "invalid_request";
    }
    
    Worker& worker = workerMap[id];
    
    // print(worker);
    
    return to_string(worker.totalTimeSpent);
}

bool myComp(Worker& a, Worker& b) {
    if(a.totalTimeSpent > b.totalTimeSpent) return true;
    if(a.totalTimeSpent < b.totalTimeSpent) return false;
    return a.id < b.id;
}

string top(int n, string pos, unordered_map<string, Worker>& workerMap) {
    vector<Worker> temp;
    for(auto wp: workerMap) {
        Worker w = wp.second;
        if(w.position == pos) {
            temp.push_back(w);
        }
    }
    
    sort(temp.begin(), temp.end(), myComp);
    
    Worker w;
    
    string ans = "";
    
    int k;
    if(temp.size() < n) {
        k = temp.size();
    } else {
        k = n;
    }
    
    for(int i = 0; i < k; i++) {
        w = temp[i];
        // print(w);
        ans += (w.id + "(" + to_string(w.totalTimeSpent) + ")");
        if(i != k -1) {
            ans += ", ";
        }
    }
    return ans;
}
vector<string> solution(vector<vector<string>> queries) {
    int q = queries.size();
    unordered_map<string, Worker> workerMap;
    vector<string> ans;
    string queryType;
    for(int i = 0; i < q; i++) {
        queryType = queries[i][0];
        if(queryType == "ADD_WORKER") {
            if(addWorker(queries[i][1], queries[i][2], queries[i][3], workerMap)) {
                ans.push_back("true");
            } else {
                ans.push_back("false");
            }
        } else if(queryType == "REGISTER") {
            if(registerWorker(queries[i][1], queries[i][2], workerMap)) {
                ans.push_back("registered");
            } else {
                ans.push_back("invalid_request");
            }
            
        } else if(queryType == "GET") {
            ans.push_back(getWorker(queries[i][1], workerMap));
        } else if(queryType == "TOP_N_WORKERS") {
            ans.push_back(
                top(stoi(queries[i][1]), queries[i][2], workerMap)
                );
                // ans.push_back("");
        }
    }
    return ans;

}
