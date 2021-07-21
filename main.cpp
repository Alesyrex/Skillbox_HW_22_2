#include <iostream>
#include <map>
#include <string>

bool correct_data (std::string name) {
    if (name[0] < 'A' || name[0] > 'Z')
        return false;

    for (int i=1;i < name.length();i++) {
        if (name[i] < 'a' || name[i] > 'z')
            return false;
    }
    return true;
}

int main() {

    std::map<std::string,int> queue;
    std::string request;

    while (true) {
        do {
            std::cout << "Input name or 'Next':";
            std::cin >> request;
            if (!correct_data(request))
                std::cout << "Incorrect input!" << std::endl;
        } while (!correct_data(request));

        if (request == "Next") {
            std::map<std::string,int>::iterator called = queue.begin();
            if (called != queue.end()) {
                std::cout << "Next " << called->first << std::endl;
                --called->second;
                if (called->second == 0) queue.erase(called);
            }
            else std::cout << "The queue is empty!" << std::endl;
        }
        else {
            std::map<std::string,int>::iterator come = queue.find(request);
            if (come == queue.end())
                queue.insert(std::pair<std::string,int>(request,1));
            else ++come->second;
            std::cout << request << " added to the queue" << std::endl;
        }

    }
    return 0;
}
