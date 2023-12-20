// #include<iostream>
// using namespace std;

// class sample{
//     int x;
//     int y;
//     public :
//         sample(){}
//         sample(int a, int b): x(a), y(b){}

//         // void operator-(){
//         //     x = -x;
//         // }

//         sample operator +(sample s2){
//             sample s3; 
//             s3.x = x + s2.x;
//             s3.y = y + s2.y;
//             return s3;
//         }

//         void display(){
//            cout<<x<<endl;
//            cout<<y<<endl;
//         }
// };

// int main()
// {
//     // sample s(5);
//     // -s;
//     sample s1(10,5);
//     sample s2(5,7);
//     sample s3;

//     s3 = s1 + s2;

//     s3.display();
//     return 0;
// }


#include<iostream>
#include<vector>
using namespace std;

vector<int> duplicates(long long arr[], int n) {
        // code here
        vector<int> ans;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] == arr[j]){
                    ans.emplace_back(i);
                }
            }
        }
        return ans;
    }

int main()
{
    vector<long long> arr = {2,1,2,3,1};
    duplicates(arr, 5);
    return 0;
}