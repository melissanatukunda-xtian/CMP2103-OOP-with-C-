#include <iostream>
#include <vector>
using namespace std;
int total_mark(vector<char>A,vector<char>B){ // to obtain the total number of correct answers for each element 
    int mark=0;
    for (int i = 0;i< A.size(); i++)
    {
        if (A[i]==B[i])
        {
          mark++;
        }
    }
    return mark;
}

int main(){
    vector<vector<char>>students_answers={{'A','B','A','C','C','D','E','E','A','D'}, // Student 1
                                    {'D','B','A','B','C','A','E','E','A','D'}, // Student 1
                                    {'E','D','D','A','C','B','E','E','A','D'}, // Student 2
                                    {'C','B','A','E','D','C','E','E','A','D'}, // Student 3
                                    {'A','B','D','C','C','D','E','E','A','D'}, // Student 4
                                    {'B','B','E','C','C','D','E','E','A','D'}, // Student 5
                                    {'B','B','A','C','C','D','E','E','A','D'}, // Student 6
                                    {'E','B','E','C','C','D','E','E','A','D'}  // Student 7
                                    };

vector<char> key = {'D','B','D','C','C','D','A','E','A','D'};
for (int i=0;i<students_answers.size();i++){
    cout<<"\nStudent "<<i<<": "<<total_mark(students_answers[i],key);  //run the function total_marks through all the elements of students_answers
}

 return 0;
}
