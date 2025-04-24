#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int begin, end;
};

// Custom sorting function to arrange events by their end time
bool endTimeSorter(const Event& e1, const Event& e2) {
    return e1.end < e2.end;
}

void chooseEvents(const vector<Event>& events) {
    // Sort a copy of the input events by their end time
    vector<Event> schedule = events;
    sort(schedule.begin(), schedule.end(), endTimeSorter);

    cout << "Optimal Set of Non-Overlapping Events:\n";

    // Select the first event by default
    int timeLimit = schedule[0].end;
    cout << "(" << schedule[0].begin << ", " << schedule[0].end << ")\n";

    // Iterate through the rest of the events
    for (size_t i = 1; i < schedule.size(); ++i) {
        if (schedule[i].begin >= timeLimit) {
            cout << "(" << schedule[i].begin << ", " << schedule[i].end << ")\n";
            timeLimit = schedule[i].end; // Update the current end time
        }
    }
}

int main() {
    vector<Event> timeline = {
        {1, 3}, {2, 5}, {3, 9}, {0, 6}, {5, 7}, {8, 9}
    };

    chooseEvents(timeline);
    return 0;
}
