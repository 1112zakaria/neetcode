/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
struct Car {
    int position;
    float time;
};

class Solution {
public:
    /**
     * Constraints:
     * - given: position and speed
     * - cars cannot pass each other
     * Observations:
     * - if car1's travel time is less or equal than car2's travel time
     * where car1's starting position is less than car2's starting point,
     * then they are part of the same fleet
     * 
     * Approach (?, O(?)):
     * - calculate travel time for all cars
     * - check all pairs of cars to identify all common fleets, only retain
     * the leader (the one with the smallest position)
     * - Q: would storing the leaders in a heap work? the cars could be saved in
     * min-heap time order
     * 
     * Approach (sorting + check right-left, O(nlogn)):
     * - calculate travel time for all cars, keep track of position
     * - store all cars in a list sorted by position
     * - iterate the array in reverse order using two pointers
     *      - if back_car.time <= front_car.time, decrement num_fleet count
     *      and iterate back_car until back_car.time > front_car.time
     *      - shift back_car and front_car ptrs to the next two cars behind
     * 
    */
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        Car local_car, back_car, front_car;
        int back_car_idx, front_car_idx;
        int num_fleets = position.size();

        for (int i=0; i<position.size(); i++) {
            local_car = {position[i], (float)(target - position[i])/speed[i]};
            cars.push_back(local_car);
        }

        sort(cars.begin(), cars.end(), [](Car a, Car b) {return a.position > b.position;});

        back_car_idx = 1;
        front_car_idx = 0;
        
        while (back_car_idx < cars.size() && front_car_idx < cars.size()) {
            front_car = cars[front_car_idx];
            while (back_car_idx < cars.size() && cars[back_car_idx].time <= front_car.time) {
                back_car_idx++;
                num_fleets--;
            }
            front_car_idx = back_car_idx;
            back_car_idx = front_car_idx + 1;
        }
        return num_fleets;
    }
};
// @lc code=end

