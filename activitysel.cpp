#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

void activitySelection(vector<Activity> activities) {
    //activities ko sort kar diya increasing order me unke finish time ke according
    sort(activities.begin(), activities.end(), compare);

    cout << "Selected Activities: \n";
    //first activity ko choose kiya aur uska finish time ,lastfinishtime me store kar diya 
    int lastFinishTime = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";
    
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinishTime) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinishTime = activities[i].finish;
        }
    }
}


int main() {
    vector<Activity> activities = {{1, 3}, {2, 5}, {3, 9}, {0, 6}, {5, 7}, {8, 9}};
    
    activitySelection(activities);
    
    return 0;
}
