#include <iostream>
#include <Windows.h>

using namespace std;

static inline int64_t GetTicks() {

    LARGE_INTEGER ticks;
    if (!QueryPerformanceCounter(&ticks)) {
        // Handle error (you can throw an exception or handle it differently)
        // For example, using WinRT's throw_last_error():
        // winrt::throw_last_error();
    }
    return ticks.QuadPart;
}

int main(){

    fastio;
    
    int64_t start = GetTicks();

    ///Code here
  
    int64_t end = GetTicks();

    cout << "\n" << start << ' ' << end << ' ' << end - start << '\n';

    double elapsedTimeSeconds = (double)(end - start);

    cout << "Elapsed time: " << fixed << setprecision(3) << elapsedTimeSeconds / 1e7 << " seconds";


    return 0;
}
