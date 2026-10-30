class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveAliceDay = 0,arriveAliceMonth = 0,leaveAliceDay = 0,leaveAliceMonth = 0;
        int arriveBobDay = 0,arriveBobMonth = 0,leaveBobDay = 0,leaveBobMonth = 0;
        int alicestart = 0, aliceend = 0, bobstart = 0, bobend = 0;

        arriveAliceMonth = stoi(arriveAlice.substr(0,2))-1;
        arriveAliceDay = stoi(arriveAlice.substr(3,2));
        leaveAliceMonth = stoi(leaveAlice.substr(0,2))-1;
        leaveAliceDay = stoi(leaveAlice.substr(3,2));

        arriveBobMonth = stoi(arriveBob.substr(0,2))-1;
        arriveBobDay = stoi(arriveBob.substr(3,2));
        leaveBobMonth = stoi(leaveBob.substr(0,2))-1;
        leaveBobDay = stoi(leaveBob.substr(3,2));

        for(int i = 1 ; i <= arriveAliceMonth ; i++){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
                alicestart += 31;
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11){
                alicestart += 30;
            }
            else alicestart += 28;
        }
        alicestart += arriveAliceDay;

        for(int i = 1 ; i <= leaveAliceMonth ; i++){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
                aliceend += 31;
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11){
                aliceend += 30;
            }
            else aliceend += 28;
        }
        aliceend += leaveAliceDay;

        // For Bob dhakitiki


        for(int i = 1 ; i <= arriveBobMonth ; i++){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
                bobstart += 31;
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11){
                bobstart += 30;
            }
            else bobstart += 28;
        }
        bobstart += arriveBobDay;

        for(int i = 1 ; i <= leaveBobMonth ; i++){
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
                bobend += 31;
            }
            else if(i == 4 || i == 6 || i == 9 || i == 11){
                bobend += 30;
            }
            else bobend += 28;
        }
        bobend += leaveBobDay;
        int ans = min(aliceend, bobend) - max(alicestart, bobstart)+1;
        if(ans < 0) return 0;
        return ans;
    }
};