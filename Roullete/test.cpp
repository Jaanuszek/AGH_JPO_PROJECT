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

    // W¹tek dla odliczania
    std::thread countdown_thread(countdown, std::ref(stop_flag), countdown_seconds);

    // Inny kod do wykonania
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Inne zadanie wykonuje siê..." << std::endl;
    }

    // Ustaw flagê zatrzymuj¹c¹ odliczanie
    stop_flag.store(true);

    // Do³¹cz w¹tek odliczania do g³ównego w¹tku
    countdown_thread.join();

    std::cout << "Odliczanie zakoñczone." << std::endl;

    return 0;
}
