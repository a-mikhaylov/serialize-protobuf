#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <chrono>
#include <Game.pb.h>

using namespace std;
using namespace std::chrono;
using namespace me::eax::examples::game;

void saveSMF(const char* fname, const SlideMeanFilter& smf) {
    fstream out (fname, ios::out | ios::trunc | ios::binary);
    if(!smf.SerializeToOstream(&out))
        throw runtime_error("saveSMF() failed");
}


void loadSMF(const char* fname, SlideMeanFilter& smf) {        
    fstream in(fname, ios::in | ios::binary);
    if(!smf.ParseFromIstream(&in))
        throw runtime_error("loadSMF() failed");
}

void printSMF(const SlideMeanFilter& smf) {
    cout << smf.k() << endl;
    cout << smf.need_restart() << endl;
    cout << smf.window() << endl;
    cout << smf.mean_sum() << endl;
    for (int i = 0; i < smf.buf_size(); i++) {
        cout << smf.buf(i) << " ";
    }
    cout << endl << endl;
}