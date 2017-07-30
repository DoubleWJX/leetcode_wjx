
/**************************  
 * File Name: solve.cpp
 * Author: No One  
 * E-mail: 1130395634@qq.com  
 * Created Time: 2017-07-30 18:03:34
**************************/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> map;
		for(int i = 0; i < nums.size(); i++){
			if(map.find(target - nums[i]) != map.end())
				return {i, map[target - nums[i]]};
			map[nums[i]] = i;
		}
		return {};
    }
};
int main(){

    

    cout << endl;
}

