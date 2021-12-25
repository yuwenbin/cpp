#include <vector>
#include <iostream>
#include <time.h>


using namespace std;

int main()
{
    vector < int > ivec;
    vector < double > dvec;
    cout << "ivec: size: " << ivec.size()
        << " capacity: " << ivec.capacity() << endl;
    time_t startTime = clock();
    time_t timePoint ;

    for(int ix =0 ; ix < 1048576;++ix){
        ivec.push_back(ix);
        //cout << "ivec: size: " << ivec.size()
          //  << " capacity: " << ivec.capacity() << endl;
    }
    cout << CLOCKS_PER_SEC << endl;
    time_t endTime = clock();
    cout << "ivec: size: " << ivec.size()
            << " capacity: " << ivec.capacity() << endl;
    cout << "Runtime is " << (endTime - startTime) << "us." << endl;
    for(int ix =0 ; ix < 1048576;++ix){
        dvec.push_back(ix);
        //cout << "ivec: size: " << ivec.size()
          //  << " capacity: " << ivec.capacity() << endl;
    }
    timePoint = clock();
    cout << "double Runtime is " << (timePoint - endTime) << "us." << endl;
}