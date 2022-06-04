## brief explanation
The code includes a sample of a drone system.

State transition diagram is shown in
```
./pictures/drone_state_transition.png
```

## start tests
Execute the following commands to build and start tests.

```
$ g++ -std=c++11 src/state_manager.cpp test/test_state_transition.cpp -o test/test_state_transition -L/usr/local/lib -lgtest -lgtest_main -lpthread
$ ./test/test_state_transition
```
