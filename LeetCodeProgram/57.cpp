#include<iostream>
#include<vector>
#include<algorithm>
//#include<stdio.h>
//#include <WinDef.h>
//#include<Windows.h>
using namespace std;
//#define NOMINMAX
//给定一个没有没有重叠的间隔，现在插入一个新的间隔，要求重新返回
//这可以把要加入的间隔直接加到给定的间隔组中，然后用56的merge方法

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
static bool compare(Interval v1,Interval v2){
	if(v1.start < v2.start)
		return true;
	else if(v1.start > v2.start)
		return false;
	else 
		return v1.end < v2.end;
}

vector<Interval> insert_solutionone(vector<Interval>&intervals,Interval newInterval){
	vector<Interval> result;
	intervals.push_back(newInterval);
	if(intervals.empty())
		return intervals;
	
	sort(intervals.begin(),intervals.end(),compare);
	result.push_back(intervals[0]);
	for(int i = 1;i < intervals.size();i++){
		if(intervals[i].end <= result[result.size()-1].end){
			//do nothing
		}
		else if(intervals[i].start <= result[result.size()-1].end){
			result[result.size()-1].end = intervals[i].end;
		}else{
			result.push_back(intervals[i]);
		}

	}
	return result;
}



vector<Interval> insert(vector<Interval>&intervals,Interval newInterval){
	vector<Interval> result;
	int i = 0;
	while( i < intervals.size()&& intervals[i].end < newInterval.start){
		result.push_back(intervals[i]);
		i++;
	}
	result.push_back(newInterval);
	while(i<intervals.size()&& result[result.size()-1].end >= intervals[i].start){
		result[result.size() - 1].start = min(intervals[i].start,result[result.size()-1].start);
		result[result.size() - 1].end = max(intervals[i].end,result[result.size()-1].end);
		i++;
	}
	while(i < intervals.size()){
		result.push_back(intervals[i]);
		i++;
	}
	return result;
}