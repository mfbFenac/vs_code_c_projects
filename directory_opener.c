#include <windows.h>

int main() {
    // Replace the network directory path with the actual path using forward slashes
    const char *directoryPath = "file://///192.168.1.99/arge ortak/ORTAK VERSION";

    // Open the directory
    int result = (int)ShellExecuteA(NULL, "open", directoryPath, NULL, NULL, SW_SHOWNORMAL);

    return 0;
}
