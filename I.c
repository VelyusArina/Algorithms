#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

struct Car {
    int number;
    int entry_time;
};

struct ParkingLot {
    int size;
    unordered_map<int, int> occupied_spots;
};

struct ParkingSimulation {
    vector<Car> cars;
    int entry_count;
    int exit_count;
    ParkingLot parking_lot;

int park_cars(const vector<int>& entry_history) {
        vector<vector<int>> entries(entry_count);
        for (int i = 0; i < entry_history.size(); i++) {
            entries[entry_history[i] - 1].push_back(i);
        }

        priority_queue<pair<int, int>> entry;
        int count = 0;
        for (int i = 0; i < entry_history.size(); i++) {
            int current_entry = entry_history[i] - 1;
            entries[current_entry].erase(entries[current_entry].begin());

            if (parking_lot.occupied_spots.find(current_entry) == parking_lot.occupied_spots.end()) {
                if (parking_lot.occupied_spots.size() >= parking_lot.size) {
                    parking_lot.occupied_spots.erase(entry.top().second);
                    entry.pop();
                }
                count++;
                Car car;
                car.number = current_entry;
                car.entry_time = i;
                cars.push_back(car);
                parking_lot.occupied_spots[current_entry] = i;
            }
            if (entries[current_entry].empty()) {
                entry.push(make_pair(INT_MAX, current_entry));
            }else {
                entry.push(make_pair(entries[current_entry].front(), current_entry));
            }
        }
        exit_count = cars.size() - parking_lot.occupied_spots.size();
        return count;
    }
};

int main() {
    int num_entries, max_cars, num_history;
    cin >> num_entries >> max_cars >> num_history;
    vector<int> entry_history(num_history);
    for (int i = 0; i < num_history; i++) {
        cin >> entry_history[i];
    }

    ParkingSimulation simulation;
    simulation.entry_count = num_entries;
    simulation.parking_lot.size = max_cars;
    int count = simulation.park_cars(entry_history);
    cout << count << endl;

    return 0;
}