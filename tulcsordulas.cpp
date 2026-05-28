#include <iostream>
#include <bitset>

using namespace std;

int hatvany(int a, int k)
{
    int hanyados = 1;
    while(k > 0)
    {
        if(k % 2 == 0)
        {
            a = a * a;
            k = k / 2;
        }
        else
        {
            hanyados = a * hanyados;
            k--;
        }
    }
    return hanyados;
}

int main()
{

    int x_int = -1;//hatvany(2, 4);
    short x_short = -1;
    long long x_longlong = -1;


    cout << "dec int: " << dec << x_int << endl;
    cout << "hex int: " << hex << x_int << endl;
    cout << "bin int: " << bitset<sizeof(int) * 8>{x_int} << endl;

    cout << endl;

    cout << "dec short: " << dec << x_short << endl;
    cout << "oct short: " << oct << x_short << endl;
    cout << "hex short: " << hex << x_short << endl;
    cout << "bin long: " << bitset<sizeof(short) * 8>{x_short} << endl;

    cout << endl;

    cout << "dec long long: " << dec << x_longlong << endl;
    cout << "oct long long: " << oct << x_longlong << endl;
    cout << "hex long long: " << hex << x_longlong << endl;
    cout << "bin long long: " << bitset<sizeof(long long) * 8>{x_longlong} << endl;

    /*char x_char = -1;
    short x_short = -1;
    int x_int = -1;
    long x_long = -1;
    long long x_longlong = -1;

    cout << "dec char: " << dec << x_char << endl;
    cout << "oct char: " << oct << x_char << endl;
    cout << "hex char: " << hex << x_char << endl;
    cout << "bin char: " << bitset<sizeof(char) * 8>{x_char} << endl;

    cout << endl;

    cout << "dec short: " << dec << x_short << endl;
    cout << "oct short: " << oct << x_short << endl;
    cout << "hex short: " << hex << x_short << endl;
    cout << "bin long: " << bitset<sizeof(short) * 8>{x_short} << endl;

    cout << endl;

    cout << "dec int: " << dec << x_int << endl;
    cout << "oct int: " << oct << x_int << endl;
    cout << "hex int: " << hex << x_int << endl;
    cout << "bin long: " << bitset<sizeof(int) * 8>{x_int} << endl;

    cout << endl;

    cout << "dec long: " << dec << x_long << endl;
    cout << "oct long: " << oct << x_long << endl;
    cout << "hex long: " << hex << x_long << endl;
    cout << "bin long: " << bitset<sizeof(long) * 8>{x_long} << endl;

    cout << endl;

    cout << "dec long long: " << dec << x_longlong << endl;
    cout << "oct long long: " << oct << x_longlong << endl;
    cout << "hex long long: " << hex << x_longlong << endl;
    //cout << "bin long long: " << bitset<sizeof(long long) * 8>{x_longlong} << endl;
    cout << bitset<64>( static_cast<unsigned long long>(x_longlong) ) << endl;
    uint64_t v = static_cast<uint64_t>(x_longlong);
cout << bitset<64>(v) << endl;*/
    return 0;
}
