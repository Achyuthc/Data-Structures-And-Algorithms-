/*Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
 */

class NumberContainers {
public:
   //map<index,number>  to store number at index
    map<int,int> numbers;
	//unordered_map<number,map<index,bool>> tostore all indexes for number with sorting by map
    unordered_map<int,map<int,bool>> indexes;
    NumberContainers() {
        numbers.clear();
        indexes.clear();
        
    }
    
    void change(int index, int number) {
        //if number exists in index
        if(numbers.find(index)!=numbers.end())
        {
			//remove index from prev num and change number at index ,add index into number map
            int num=numbers[index];
            indexes[num].erase(index);
            numbers[index]=number;
            indexes[number][index]=true;
        }
        else
        {
			//if number doesn't exist
            numbers[index]=number;
            indexes[number][index]=true;
        }
        return ;
        
    }
    
    int find(int number) {
        //if number doesn't have any indexes
        if(indexes.find(number)==indexes.end()||indexes[number].begin()==indexes[number].end())
        {
            return -1;
        }
		//if number has indexes then return first index
        return indexes[number].begin()->first;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
