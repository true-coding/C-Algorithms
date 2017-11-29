#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    vector<int> v{ 5,9,6,2,8,-4,5,9,7,-11,0,9,655 };

    """ count how many entries have the target value (9). """;
    int nine = 0;
    int const target = 9;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == target)
        {
            nine++;
        }
    }
    cout << "Loop For: " << nine << " times." << endl;

    nine = 0;
    nine = count(v.begin(), v.end(), target);
    cout << "count whit v.begin() and v.end(): " << nine << " times." << endl;

    nine = 0;
    nine = count(begin(v), end(v), target);
    cout << "count whit begin(v) and end(v): " << nine << " times." << endl;


    """ count how many odd elements are in vector (v). """;
    int odds = 0;
    for (auto e: v)
    {
        if (e % 2 != 0)
        {
            odds++;
        }
    }
    cout << "foreach loop has: " << odds << " occurrences." << endl;


    """ count how many elements are odd in vector (v) using count_if & lambda. """;
    odds = count_if(begin(v), end(v), [](auto e) { return e % 2 != 0; });
    cout << "lambda function has: " << odds << " occurrences." << endl;


    """ are all, any, or none of the values odd?. """;
    bool allof, noneof, anyof;
    allof = (odds = v.size());
    noneof = (odds == 0);
    anyof = (odds > 0);

    allof = all_of(begin(v), end(v), [](auto e) { return e % 2 != 0; });
    noneof = none_of(begin(v), end(v), [](auto e) { return e % 2 != 0; });
    anyof = any_of(begin(v), end(v), [](auto e) { return e % 2 != 0; });


    """ count how many months having 31 days are odd in map(monthlengths) using count_if & lambda. """;
    map<int, int> monthlengths{ { 1,31 }, { 2,28 }, { 3,31 }, { 4,30 }, { 5,31 }, { 6,30 },
                                { 7,31 }, { 8,31 }, { 9,30 }, { 10,31 }, { 11,30 }, { 12,31 } };

    int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto m) { return m.second == 31; });
    cout << "year has: " << longmonths << " months with 31 days." << endl;





    return 0;
}
















































