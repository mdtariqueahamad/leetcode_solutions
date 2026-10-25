
class Solution {
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        string arrive = max(arriveAlice, arriveBob);
        string leave = min(leaveAlice, leaveBob);

        if(arrive > leave) return 0;

        int am = stoi(arrive.substr(0, 2));
        int ad = stoi(arrive.substr(3, 2));
        int lm = stoi(leave.substr(0, 2));
        int ld = stoi(leave.substr(3, 2));

        if (lm == am) return ld - ad + 1;

        int ans = ld;

        for(int i = am; i < lm-1; i++)
            ans += arr[i];

        
        return ans + (arr[am-1] - ad + 1);
    }
};
