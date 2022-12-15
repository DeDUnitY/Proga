#include <iostream>
#include <vector>


void cout_vector(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << "\n";
    }
}


class cat
{
private:
    int m_age;
    std::string m_name;
public:
    cat(int age, std::string name) {
        m_age = age;
        m_name = name;

    }
    void get() {
        std::cout << m_age << " " << m_name << std::endl;
    }
    ~cat() {}

};


int main()
{
    std::vector <int> arr;
    std::vector <cat> mas;
    int a;
    for (int i = 0; i < 3; i++) {
        std::cin >> a;
        arr.push_back(a);
    }

    //erase
    arr.erase(arr.begin());
    std::cout << "erase" << "\n";
    cout_vector(arr);
    std::cout << "\n";
    //


    // insrert
    arr.insert(arr.end() - 1, 10);
    std::cout << "insert:" << "\n";
    cout_vector(arr);
    std::cout << "\n";
    //


    // emplace_back
    mas.emplace_back(10, "martin");
    for (int i = 0; i < mas.size(); i++) {
        mas[i].get();
    }
    std::cout << "\n";


    // resize
    std::vector <int> nums{ 1,2,3,4,5 };
    std::cout << "resize1" << "\n";
    nums.resize(4);
    cout_vector(nums);
    std::vector <int> nums1{ 1,2,3 };
    std::cout << "resize2" << "\n";
    nums1.resize(5, 8);
    cout_vector(nums1);
    std::cout << "\n";

    //reserve and capacity
    std::cout << "reserve and capacity" << "\n";
    std::vector <int> nums3;

    nums3.push_back(45);
    std::cout << nums3.capacity() << "\n";

    nums3.reserve(10);
    std::cout << nums3.capacity() << "\n";
    std::cout << "\n";

    //shrink_to_fit
    nums3.shrink_to_fit();
    std::cout << "shrink_to_fit" << "\n";
    std::cout << nums3.capacity() << "\n";
    std::cout << "\n";

    //clear
    std::cout << "clear" << "\n";
    std::vector<int> nums4{ 1,2,3,4,5,6,7,8,9 };
    nums4.clear();
    cout_vector(nums4);
    std::cout << "\n";


    std::vector<int> nums5;
    nums5.push_back(5);
    std::cout << nums5[0] << "\n";
    nums5[0] = 2;
    std::cout << nums5[0] << "\n";

    std::cout << sizeof(nums5) << "\n";
}