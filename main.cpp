#include <iostream>
#include <vector>
#include <algorithm>

int min_rotates(std::vector<int>& A, std::vector<int>& B, int K)
{
    int size = A.size();
    std::vector<int> Diff;
    int rotations = 0;
    int sum = 0;
    for(int i = 0; i < size; ++i)
    {
        Diff.push_back(B.at(i) - A.at(i));
    }
    std::sort(Diff.begin(),Diff.end(),std::greater<int>());
    for(int i = 0; i < size; ++i){
        sum += A.at(i);
    }
    if(sum > K)
    {
        return rotations;
    }
    std::vector<int>::iterator iter = Diff.begin();
    while(sum <= K)
    {
        sum += *iter;
        rotations++;
        iter++;
        if(*iter <=0){
            return -1;
        }
    }
    return rotations;
}

int main() {
    std::vector<int> Up;
    std::vector<int> Down;
    Up.push_back(2);
    Up.push_back(1);
    Up.push_back(4);
    Up.push_back(1);
    Down.push_back(3);
    Down.push_back(5);
    Down.push_back(2);
    Down.push_back(6);
    int rot = min_rotates(Up,Down,16);
    std::cout << rot << std::endl;
}
