#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//这是一个区间问题，就是合并有重叠区域的区间。 先将给的区间按照start从小到大排序，然后再一次的比较两个区间之间的关系
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
static bool compare(Interval a,Interval b){
	if(a.start < b.start){
		return true;
	}
	if(a.start > b.start){
		return false;
	}
	else{
		return a.end < b.end;
	}
}

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> result;
	if(intervals.empty()){
		return result;
	}
	sort(intervals.begin(),intervals.end(),compare);
	result.push_back(intervals[0]);
	for(int i = 1;i < intervals.size();i++){
		if(intervals[i].end <= result[result.size()-1].end){
		
		}
		else if(intervals[i].start <= result[result.size()-1].end){
			result[result.size() - 1].end = intervals[i].end;
		}else{
			result.push_back(intervals[i]);
		}
	}
	return result;
}