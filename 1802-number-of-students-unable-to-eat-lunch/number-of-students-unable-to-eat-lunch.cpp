class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt0=0,cnt1=0;
        for(int i=0; i<students.size(); i++){
            if(students[i]==1){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }

        int c1=0, c0=0, idx=-1;
        for(int i=0; i<students.size(); i++){
            if(sandwiches[i]==1){
                c1++;
            }
            else{
                c0++;
            }

            if(c1 > cnt1 || c0 > cnt0){
                idx=i;
                break;
            }
        }
        if(idx==-1) return 0;
        return students.size()-idx;
    }
};