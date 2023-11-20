#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

void countdown(std::atomic<bool>& stop_flag, int seconds) {
    while (seconds > 0 && !stop_flag.load()) {
        std::cout << "Czas: " << seconds << " s\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --seconds;
    }
}

int main() {
    std::atomic<bool> stop_flag(false);
    int countdown_seconds = 10;

    // W�tek dla odliczania
    std::thread countdown_thread(countdown, std::ref(stop_flag), countdown_seconds);

    // Inny kod do wykonania
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Inne zadanie wykonuje si�..." << std::endl;
    }

    // Ustaw flag� zatrzymuj�c� odliczanie
    stop_flag.store(true);

    // Do��cz w�tek odliczania do g��wnego w�tku
    countdown_thread.join();

    std::cout << "Odliczanie zako�czone." << std::endl;

    return 0;
}
