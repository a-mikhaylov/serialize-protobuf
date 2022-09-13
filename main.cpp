#include "header.hpp"

int main() {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (int i = 0; i < 100; i++) {
        // cout << i << "----------------------------------------------" << endl;
        SlideMeanFilter flt;
        SlideMeanFilter parsed;

        vector<int> buff = {123, 150243, 777, 666666};
        for (size_t i = 0; i < buff.size(); i++) {
            flt.add_buf(buff[i]);
        }
        flt.set_k(123);
        flt.set_mean_sum(456);
        flt.set_window(25);
        flt.set_need_restart(true);

        // printSMF(flt);
        // cout << "Saving filter" << endl;
        saveSMF("my_flt.dat", flt);
        // cout << "Loading filter" << endl;
        loadSMF("my_flt.dat", parsed);
        // printSMF(parsed);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    std::cout << duration << endl;

}