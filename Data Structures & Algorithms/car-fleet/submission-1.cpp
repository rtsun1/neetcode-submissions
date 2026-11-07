class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars_by_position;
        for (int car = 0; car < position.size(); ++car) {
            cars_by_position.push_back({position[car], car});
        }
        std::sort(cars_by_position.begin(), cars_by_position.end(), std::greater<pair<int, int>>());
        
        double prev_arrival_time = numeric_limits<double>::min();
        int fleets = 0;
        for (auto [position, car] : cars_by_position) {
            double distance_to_go = target - position;
            double arrival_time = distance_to_go / (double)(speed[car]);

            if (prev_arrival_time < arrival_time) {
                // new fleet
                ++fleets;
                prev_arrival_time = arrival_time;
            }
        }

        return fleets;
    }
};
