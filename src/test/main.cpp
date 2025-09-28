#include "sorter_test.hpp"
#include <cppunit/ui/text/TestRunner.h>

int main() {
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(SorterTest::suite());
    runner.run();
}