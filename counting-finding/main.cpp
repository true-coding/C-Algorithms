#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    vector<int> v{ 5,9,6,2,8,-4,5,9,7,-11,0,9,9,7,655 };

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


    """--- FINDING ---""";

    vector<int> f{ 5, 8, 2, -8, 0, 44, 987, 2, 4, 66, 74, 2, 4 };
    string s{ "I am a magic string" };

    """ find first (0) in the collection """;
    auto result = find(begin(f), end(f), 0);
    int found = *result;
    cout << "found: " << found << endl;


    """ find first 2 after that zero """;
    result = find(result, end(f), 2);
    if (result != end(v))
    {
        found = *result;
    }
    cout << "found: " << found << endl;


    """ find first (m) in string (s) """;
    auto letter = find(begin(s), end(s), 'm');
    char a = *letter;
    cout << "first letter (m): " << a << " in string (s)" << endl;


    """ find first odd value  """;
    result = find_if(begin(v), end(v), [](auto e) { return e % 2 != 0; });
    found = *result;
    cout << "odd element: " << found << endl;


    """ find first even value """;
    result = find_if_not(begin(v), end(v), [](auto e) { return e % 2 != 0; });
    found = *result;
    cout << "even element: " << found << endl;


    """ find first prime in vector (v). """;
    vector<int> primes{ 1,2,3,5,7,11,13 };
    result = find_first_of(begin(v), end(v), begin(primes), end(primes));
    found = *result;
    cout << "first prime: " << found << endl;


    """ find first number after sub sequence of ( 9, 7 ) in vector (v).  """;
    vector<int> subsequence{ 9, 7 };
    result = search(begin(v), end(v), begin(subsequence), end(subsequence));
    found = *result;
    result++; result++;
    int minuseleven = *result;
    cout << "-11: " << minuseleven << endl;


    """ find first string 'am' in vector (s).  """;
    string am = "am";
    letter = search(begin(s), end(s), begin(am), end(am)),
    a = *letter;
    cout << "letter a: " << a << endl;


    """ find first number after last sub sequence of ( 9, 7 ) in vector (v).  """;
    result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
    result++; result++;
    int sff = *result;
    cout << "655: " << sff << endl;

    """ find sequence of values (9,9), end return first value before that sequence.  """;
    result = search_n(begin(v), end(v), 2, 9);
    result--;
    int secondnine = *result;
    cout << "second nine: " << secondnine << endl;


    """ find first sequence of same values (?,?). """;
    result = adjacent_find(begin(v), end(v));
    nine = *result;
    result++;
    nine =  *result;
    cout << "nine: " << nine << endl;


    return 0;
}
