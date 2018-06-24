#include <iostream>
#include <memory>
int main() {
    std::shared_ptr<int> a{new int{5}};
    std::weak_ptr<int> b{a};
    std::cout << b.lock().use_count() << " " << a.use_count() <<  std::endl;
    std::cout << a.use_count() << std::endl;
}