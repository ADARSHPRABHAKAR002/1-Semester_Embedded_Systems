#include<systemc.h>
SC_MODULE(monitor)
{
    sc_in<uint<4>>a,b,add,sub,rshift,lshift;

    void mon()
    {
        cout<<"inputs"<<a<<b<<"outputs"<<add<<sub<<rshift<<lshift;

    }

    SC_CTOR(monitor)
    {
        SC_METHOD(mon);
        sensitive<<a<<b<<add<sub<<rshift<<lshift;
    }
}