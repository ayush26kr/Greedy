int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> timings;
        for(int i = 0; i < n; i++) timings.push_back({start[i], end[i]});
        sort(timings.begin(), timings.end());
        int res = 1, end_time = timings[0].second;
        for(int i = 1; i < n; i++) {
            if(end_time >= timings[i].first) {
                end_time = min(end_time, timings[i].second);
            } else {
                res++;
                end_time = timings[i].second;
            }
        }
        return res;
    }
