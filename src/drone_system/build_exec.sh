## state transition test
g++ -std=c++11 src/state_manager.cpp test/test_state_transition.cpp -o test/test_state_transition -L/usr/local/lib -lgtest -lgtest_main -lpthread
./test/test_state_transition
