#include "../SPSCQueue.h"
#include "../SPSCQueueOPT.h"
#include "shmmap.h"
#include "chrono.h"

struct Msg
{
    long ts;
    CXXChrono::TimePoint cxx_tp;
    char buf[50];
};

typedef SPSCQueue<Msg, 4> MsgQueue;
// typedef SPSCQueueOPT<Msg, 4> MsgQueue;

MsgQueue* getMsgQueue() {
    return shmmap<MsgQueue>("/shm_queue");
}
