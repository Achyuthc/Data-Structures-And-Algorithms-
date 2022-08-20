/*A car travels from a starting position to a destination which is target miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.

The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.

Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.

Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.*/


Algorithm

to reach the target we need use less number of stations to maintain that we need to use stations with more fuel and also use stations when we cannot reach next station.
consider state currentFuel,previosStationPosition,maxFuelQueue contains all unused stations fuel capacity.
At every station we check is it possible to reach current staion,
currentFuel-=(distance b/w present station and previos station)
if currentFuel <0 the we need to use previos maxFuelQueue fuel to reach present station so we add all fuels until fuel becomes empty or currentFuel>=0.
Again if we see currentFuel<0 then current Station cannot be reached so we return -1;
if currentFuel==0 then take maxFuel
else push fuel into the maxFuelQueue.
check for the target also.
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long long currentFuel=startFuel;
		int i=0;
        priority_queue<int> maxFuelQueue;
        sort(stations.begin(),stations.end());
        int previousStationPosition=0;
        int numberOfStops=0;
        while(i<stations.size())
        {
            currentFuel-=(stations[i][0]-previousStationPosition);
            previousStationPosition=stations[i][0];
            
            while(currentFuel<0&&!maxFuelQueue.empty())
            {
                currentFuel+=maxFuelQueue.top();
                maxFuelQueue.pop();
                numberOfStops++;
            }
            
            if(currentFuel<0)
                return -1;
            else if(currentFuel==0)
            {
                maxFuelQueue.push(stations[i][1]);
                currentFuel+=maxFuelQueue.top();
                maxFuelQueue.pop();
                numberOfStops++;
            }
            else
				maxFuelQueue.push(stations[i][1]);
			i++;
        }
        
        currentFuel-=(target-previousStationPosition);
        while(currentFuel<0&&!maxFuelQueue.empty())
        {
            currentFuel+=maxFuelQueue.top();
            maxFuelQueue.pop();
            numberOfStops++;
        }
        
        return currentFuel<0?-1:numberOfStops;
      }
};
