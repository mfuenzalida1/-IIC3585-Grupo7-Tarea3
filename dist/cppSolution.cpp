#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 4;

vector<int> generateSet(vector<int> numbers)
{
    vector<int> set;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            set.push_back(numbers[i] + numbers[j]);
            set.push_back(numbers[i] * numbers[j]);
        }
    }
    return set;
}

bool checkRepeated(vector<int> numbers)
{
    for (const auto &i: numbers)
    {
       sort(numbers.begin(), numbers.end());
    }
    for (int i = 1; i < numbers.size(); i++)
    {
        if (numbers[i-1] == numbers[i])
        {
            return false;
        }
    }
    return true;
}

vector<int> getNextNumbers(vector<int> numbers)
{
    for (int i = 1; i < n; i++)
    {
        if (numbers[i-1] + 1 < numbers[i])
        {
            numbers[i-1] = numbers[i-1] + 1;
            for (int j = 1; j < i; j++)
            {
                numbers[j-1] = j;
            }
            return numbers;
        }
    }
    numbers[numbers.size() - 1] = numbers[numbers.size() - 1] + 1;
    for (int i = 1; i < numbers.size(); i++) 
    {
        numbers[i-1] = i;
    }
    return numbers; 
}

int main()
{
    vector<int> numbers;
    for (int i = 1; i <= n; i++) 
    {
        numbers.push_back(i);
    }
    while (true) {
        if (checkRepeated(generateSet(numbers)))
        {
            break;
        } 
        else 
        {
            numbers = getNextNumbers(numbers);
        }
    }
    for (const auto &i: numbers)
        cout << i << ' ';
    cout << "\n";
    vector<int> generatedSet = generateSet(numbers);
    for (const auto &i: generatedSet)
    {
       sort(generatedSet.begin(), generatedSet.end());
    }
    for (const auto &i: generatedSet)
        cout << i << ' ';
    cout << "\n";
    
    return 0;
}
