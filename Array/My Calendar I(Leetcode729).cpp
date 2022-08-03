
/*You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 */
class MyCalendar {
public:
    vector<pair<int,int>> mySchedule;
    MyCalendar() {
        mySchedule.clear();
    }
    
    bool book(int start, int end) {
        if(mySchedule.size()==0)
        {
            mySchedule.push_back({start,end});
            return true;
        }
        else
        {
            bool flag=false;
            int i;
            for(i=0;i<mySchedule.size();i++)
            {
                if(end<=mySchedule[i].first)
                {
                    flag=true;
                    break;
                }
            }
            //cout<<i<<" ";
            if(!flag)
            {
                if(mySchedule[i-1].second<=start)
                {
                    mySchedule.push_back({start,end});
                    return true;
                }
                else
                return false;
            }
            else
            {
                if(i==0||mySchedule[i-1].second<=start)
                {
                   mySchedule.insert(i+mySchedule.begin(),{start,end});
                    return true; 
                }
                
                return false;
            }
        }
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
//[10,20],[20,30],[30,45] 
