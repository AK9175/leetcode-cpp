// Hidden judge for "Design Bounded Blocking Queue.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Design Bounded Blocking Queue.cpp"

int main() {
    TestRunner T;

    T.test("single thread: fill to capacity then drain in FIFO order", [] {
        BoundedBlockingQueue q(3);
        vector<int> r;
        q.enqueue(1); q.enqueue(2); q.enqueue(3);
        r.push_back(q.size());
        r.push_back(q.dequeue());
        r.push_back(q.dequeue());
        r.push_back(q.dequeue());
        r.push_back(q.size());
        return expectEq(r, vector<int>{3, 1, 2, 3, 0});
    });

    T.test("single thread: interleaved ops track size", [] {
        BoundedBlockingQueue q(5);
        vector<int> r;
        q.enqueue(10); q.enqueue(20);
        r.push_back(q.size());
        r.push_back(q.dequeue());
        q.enqueue(30);
        r.push_back(q.size());
        r.push_back(q.dequeue());
        r.push_back(q.dequeue());
        r.push_back(q.size());
        return expectEq(r, vector<int>{2, 10, 2, 20, 30, 0});
    });

    T.test("enqueue blocks while full until a dequeue frees space", [] {
        BoundedBlockingQueue q(2);
        q.enqueue(1); q.enqueue(2);
        atomic<bool> done{false};
        thread prod([&]{ q.enqueue(3); done.store(true); });
        this_thread::sleep_for(chrono::milliseconds(150));
        int blockedWhileFull = (!done.load() && q.size() == 2) ? 1 : 0;
        int first = q.dequeue();        // frees a slot -> producer proceeds
        prod.join();
        int unblocked = done.load() ? 1 : 0;
        int sz = q.size();
        int second = q.dequeue();
        int third = q.dequeue();
        int szEnd = q.size();
        vector<int> r = {blockedWhileFull, first, unblocked, sz, second, third, szEnd};
        return expectEq(r, vector<int>{1, 1, 1, 2, 2, 3, 0});
    });

    T.test("dequeue blocks while empty until an element arrives", [] {
        BoundedBlockingQueue q(5);
        atomic<bool> done{false};
        int result = -1;
        thread cons([&]{ result = q.dequeue(); done.store(true); });
        this_thread::sleep_for(chrono::milliseconds(150));
        int blockedWhileEmpty = (!done.load() && q.size() == 0) ? 1 : 0;
        q.enqueue(42);
        cons.join();
        vector<int> r = {blockedWhileEmpty, done.load() ? 1 : 0, result, q.size()};
        return expectEq(r, vector<int>{1, 1, 42, 0});
    });

    T.test("one producer one consumer preserves FIFO over 2000 items", [] {
        BoundedBlockingQueue q(10);
        const int N = 2000;
        vector<int> consumed;
        consumed.reserve(N);
        thread prod([&]{ for (int i = 0; i < N; i++) q.enqueue(i); });
        for (int i = 0; i < N; i++) consumed.push_back(q.dequeue());
        prod.join();
        bool ok = (int)consumed.size() == N && q.size() == 0;
        for (int i = 0; i < N && ok; i++) ok = consumed[i] == i;
        return expectValid(consumed.size(), ok, "consumed 0..1999 in order, queue empty");
    });

    T.test("capacity 1 strict handoff preserves FIFO over 1000 items", [] {
        BoundedBlockingQueue q(1);
        const int N = 1000;
        vector<int> consumed;
        thread prod([&]{ for (int i = 0; i < N; i++) q.enqueue(i); });
        for (int i = 0; i < N; i++) consumed.push_back(q.dequeue());
        prod.join();
        bool ok = (int)consumed.size() == N && q.size() == 0;
        for (int i = 0; i < N && ok; i++) ok = consumed[i] == i;
        return expectValid(consumed.size(), ok, "cap=1 FIFO handoff, queue empty");
    });

    T.test("four producers and four consumers move every item exactly once", [] {
        BoundedBlockingQueue q(7);
        const int P = 4, per = 500, N = P * per;
        vector<thread> ts;
        for (int p = 0; p < P; p++)
            ts.emplace_back([&, p]{ for (int i = 0; i < per; i++) q.enqueue(p * per + i); });
        mutex cm;
        vector<int> consumed;
        for (int c = 0; c < 4; c++)
            ts.emplace_back([&]{ for (int i = 0; i < N / 4; i++) { int v = q.dequeue(); lock_guard<mutex> lk(cm); consumed.push_back(v); } });
        for (auto& t : ts) t.join();
        vector<int> expected(N);
        iota(expected.begin(), expected.end(), 0);
        return expectAnyOrder(consumed, expected);
    });

    T.test("timing: capacity 1 under heavy contention, 3 producers 3 consumers", [] {
        BoundedBlockingQueue q(1);
        const int P = 3, per = 1000, N = P * per;
        vector<thread> ts;
        for (int p = 0; p < P; p++)
            ts.emplace_back([&, p]{ for (int i = 0; i < per; i++) q.enqueue(p * per + i); });
        mutex cm;
        vector<int> consumed;
        for (int c = 0; c < 3; c++)
            ts.emplace_back([&]{ for (int i = 0; i < N / 3; i++) { int v = q.dequeue(); lock_guard<mutex> lk(cm); consumed.push_back(v); } });
        for (auto& t : ts) t.join();
        vector<int> expected(N);
        iota(expected.begin(), expected.end(), 0);
        return expectAnyOrder(consumed, expected);
    });

    return T.summary();
}
