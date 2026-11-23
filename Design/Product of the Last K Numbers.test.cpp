// Hidden judge for "Product of the Last K Numbers.cpp" (LeetCode doesn't show this part).
// Run one test: use the editor's "Run test #" / Debug buttons, or TEST=<n> ./run.sh <file>.
#include "Product of the Last K Numbers.cpp"

int main() {
    TestRunner T;

    T.test("Example 1", [] {
        ProductOfNumbers productOfNumbers;
        vector<string> out = {"null"};
        productOfNumbers.add(3);
        out.push_back("null");
        productOfNumbers.add(0);
        out.push_back("null");
        productOfNumbers.add(2);
        out.push_back("null");
        productOfNumbers.add(5);
        out.push_back("null");
        productOfNumbers.add(4);
        out.push_back("null");
        out.push_back(toStr(productOfNumbers.getProduct(2)));
        out.push_back(toStr(productOfNumbers.getProduct(3)));
        out.push_back(toStr(productOfNumbers.getProduct(4)));
        productOfNumbers.add(8);
        out.push_back("null");
        out.push_back(toStr(productOfNumbers.getProduct(2)));
        return expectEq(out, vector<string>{"null", "null", "null", "null", "null", "null", "20", "40", "0", "null", "32"});
    });

    T.test("single value query", [] {
        ProductOfNumbers productOfNumbers;
        productOfNumbers.add(7);
        return expectEq(productOfNumbers.getProduct(1), 7);
    });

    T.test("zero makes a range product zero", [] {
        ProductOfNumbers productOfNumbers;
        productOfNumbers.add(5);
        productOfNumbers.add(0);
        productOfNumbers.add(4);
        return expectEq(productOfNumbers.getProduct(3), 0);
    });

    T.test("query after the most recent zero", [] {
        ProductOfNumbers productOfNumbers;
        productOfNumbers.add(2);
        productOfNumbers.add(0);
        productOfNumbers.add(3);
        productOfNumbers.add(4);
        return expectEq(productOfNumbers.getProduct(2), 12);
    });

    T.test("consecutive zeros", [] {
        ProductOfNumbers productOfNumbers;
        productOfNumbers.add(0);
        productOfNumbers.add(0);
        productOfNumbers.add(6);
        return expectEq(productOfNumbers.getProduct(2), 0);
    });

    T.test("all ones", [] {
        ProductOfNumbers productOfNumbers;
        for (int i = 0; i < 20; i++) productOfNumbers.add(1);
        return expectEq(productOfNumbers.getProduct(20), 1);
    });

    T.test("multiple queries without adding", [] {
        ProductOfNumbers productOfNumbers;
        productOfNumbers.add(2);
        productOfNumbers.add(3);
        productOfNumbers.add(4);
        vector<int> got = {
            productOfNumbers.getProduct(1),
            productOfNumbers.getProduct(2),
            productOfNumbers.getProduct(3)
        };
        return expectEq(got, vector<int>{4, 12, 24});
    });

    T.test("zero followed by values at the end", [] {
        ProductOfNumbers productOfNumbers;
        productOfNumbers.add(9);
        productOfNumbers.add(8);
        productOfNumbers.add(0);
        productOfNumbers.add(2);
        productOfNumbers.add(5);
        return expectEq(productOfNumbers.getProduct(2), 10);
    });

    T.test("maximum operation count with ones", [] {
        ProductOfNumbers productOfNumbers;
        for (int i = 0; i < 39999; i++) productOfNumbers.add(1);
        return expectEq(productOfNumbers.getProduct(39999), 1);
    });

    return T.summary();
}
