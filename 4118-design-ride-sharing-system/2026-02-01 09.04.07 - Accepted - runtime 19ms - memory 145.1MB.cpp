class RideSharingSystem {
public:
    queue<int> rider;
    queue<int> driver;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(driver.empty() || rider.empty()) return {-1,-1};
        int d=driver.front();
        driver.pop();
        int r=rider.front();
        rider.pop();
        return {d,r};
    }
    
    void cancelRider(int riderId) {
        int n=rider.size();
        for(int i=0;i<n;i++){
            int cur=rider.front();
            rider.pop();
            if(cur!=riderId) rider.push(cur);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */