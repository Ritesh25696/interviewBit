There are N children standing in a line. Each child is assigned a rating value.

 You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Sample Input :

Ratings : [1 2]
Sample Output :

3
The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. So rating 2 candidate gets 2 candies. In total, 2+1 = 3 candies need to be given out.
***************************************************************************************************************************************************

int Solution::candy(vector<int> &ratings) {
     int candiesCnt = 0, curCandy, pos;
            vector<pair<int, int> > valueWithPos; 
            for (int i = 0; i < ratings.size(); i++) {
                valueWithPos.push_back(make_pair(ratings[i], i));
            }
            sort(valueWithPos.begin(), valueWithPos.end());
            vector<int> candies (ratings.size(), 0);
            for (int i = 0; i < valueWithPos.size(); i++) {
                pos = valueWithPos[i].second;
                curCandy = 0;
                if (pos > 0 && ratings[pos - 1] < ratings[pos]) {
                    curCandy = candies[pos - 1];
                } 
                if (pos < ratings.size() - 1 && ratings[pos + 1] < ratings[pos]) {
                    curCandy = max(curCandy, candies[pos + 1]);
                }
                candies[pos] = curCandy + 1;
                candiesCnt += candies[pos];
            }
            return candiesCnt;
}
