## equivalence partitioning test
$ g++ -std=c++11 robot_distance.cpp test_class.cpp -o test_class -L/usr/local/lib -lgtest -lgtest_main -lpthread
$ ./test_class

## boundary value analysis test
$ g++ -std=c++11 robot_distance.cpp test_boundary.cpp -o test_boundary -L/usr/local/lib -lgtest -lgtest_main -lpthread
$ ./test_boundary

## failure test
$ g++ -std=c++11 robot_distance.cpp test_fail.cpp -o test_fail -L/usr/local/lib -lgtest -lgtest_main -lpthread
$ ./test_fail
