Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

******************************************************************************************************************************************************************************************************************

int Solution::trap(const vector<int> &towerHeight) {
            int maxSeenSoFar = 0;
	
	        vector<int> maxSeenRight(towerHeight.size());
	        int maxSeenLeft = 0;
	
	        int rainwater = 0;
	
	        for (int i = towerHeight.size() - 1; i >= 0; i--) {
	            if (towerHeight[i] > maxSeenSoFar) {
	                maxSeenSoFar = towerHeight[i];
	                maxSeenRight[i] = maxSeenSoFar;
	            } else {
	                maxSeenRight[i] = maxSeenSoFar;
	            }
	        }
	
	        for (int i = 0; i < towerHeight.size(); i++) {
	            rainwater = rainwater + max(min(maxSeenLeft, maxSeenRight[i]) - towerHeight[i], 0);
	            if (towerHeight[i] > maxSeenLeft) {
	                maxSeenLeft = towerHeight[i];
	            }
	        }
	
	        return rainwater;

}
