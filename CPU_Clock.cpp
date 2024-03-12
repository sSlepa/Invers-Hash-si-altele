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

    double CPU_freq = 0.0;
    CPU_freq = double(GetTicks());

    int64_t start = GetTicks();

    ///Code here
  
    int64_t end = GetTicks();

    cout << "\n" << start << ' ' << end << ' ' << end - start << '\n';

    double elapsedTimeSeconds = (double)(end - start) / CPU_freq;

    cout << "Elapsed time: " << fixed << setprecision(5) << elapsedTimeSeconds << " seconds";


    return 0;
}
