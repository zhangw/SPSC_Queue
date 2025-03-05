#include <bits/stdc++.h>
#include "chrono.h"
#include "rdtsc.h"
#include "cpupin.h"
#include "shmq_msg.h"

int main() {
    if(!cpupin(3)) {
        exit(1);
    }

    MsgQueue* q = getMsgQueue();

    Msg* msg = nullptr;
    while(1) {
        while((msg = q->front()) == nullptr)
            ;
        long latency = rdtsc();
        latency -= msg->ts;
        auto cxx_tp = CXXChrono::now();
        auto latency_cxx_tp = CXXChrono::diff_tps(msg->cxx_tp, cxx_tp);
        std::cout << "recv: " << msg->buf << " ,latency (rdtsc): " << latency << " , latency (cxx clock [ns]): " << latency_cxx_tp << std::endl;
        q->pop();
    }

    return 0;
}


