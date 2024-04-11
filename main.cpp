    #include <iostream>
    #include <vector>
    #include <fstream>
    #include <thread>
    #include <mutex>
    #define MAX_THREAD 10

    class Omer {
    public:
        void write(const std::string& filename, const std::string& data) {
            std::ofstream file(filename, std::ios::app);
            if (!file.is_open()) {
                std::cerr << "Unable to open file: " << filename << std::endl;
                return;
            }
            while (!data.empty()) {
                for (char ch : data) {
                    file << ch << std::flush;
                    std::chrono::seconds duration(1);
                    std::this_thread::sleep_for(duration);
                }
            }
            file.close();
        }
        void incrementTh(int& a) {
            std::vector<std::thread> threads;
            std::mutex mutex;

            for (int i = 0; i < 1000000; ++i) {
                //sýnýfýn üye deðiþkenlerini almak için, [] lamba içerisinde kullanýlacak deðiþkenleri ver
                threads.emplace_back([this, &mutex, &a]() {
                    std::lock_guard<std::mutex> lock(mutex);
                    a++;
                    });
            }

            for (auto& thread : threads) {
                thread.join();
            }
        }
        void increment2(int& a) {
            a = a + 1;
        }
        void increment1(int& a) {
            a = a + 1;
        }
        void increment3(int& a) {
            a = a + 1;
        }
        void increment4(int& a) {
            a = a + 1;
        }
        void increment5(int& a) {
            a = a + 1;
        }
        void increment6(int& a) {
            a = a + 1;
        }
        void increment7(int& a) {
            a = a + 1;
        }
        void increment8(int& a) {
            a = a + 1;
        }
        void increment9(int& a) {
            a = a + 1;
        }
        void increment10(int& a) {
            a = a + 1;
        }
    };

    Omer om;
    int main() {
        int a = 0;
        std::string filename = "test.txt";
        std::string data = "Sample data to write.\n";
        std::vector<std::thread> th;

        om.incrementTh(a);
        //om.write(filename, data);
        std::cout << "Value for th fun:" << a << std::endl;
        a = 0;
        for (int i = 0; i < 10000; i++) {
            om.increment1(a);
            om.increment2(a);
            om.increment3(a);
            om.increment4(a); 
            om.increment5(a);
            om.increment6(a);
            om.increment7(a);
            om.increment8(a);
            om.increment9(a);
            om.increment10(a);
        }
        std::cout << "Value for normal fun:" << a << std::endl;
        return 0;
    }
