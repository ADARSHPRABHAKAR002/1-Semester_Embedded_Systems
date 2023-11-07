#include<systemc.h>
SC_MODULE(alu)
{
    sc_in<sc_uint<4>> a,b;
    sc_out<sc_uint<4>> add,sub,rshift,lshift;
    sc_in<sc_uint<2>> op;

    void compute_alu()
    {
        if(op.read()==0)
        {
            add.write(a.read()+b.read());
            
        }
        else if(op.read()==1)
        {
            sub.write(a.read()-b.read());
           
        }
        else if(op.read()==2)
        {
            rshift.write(a.read()>>1);
        }
        else if(op.read()==3)
        {
            lshift.write(a.read()<<1);

        }
        else
        {
            add.write(0);
            sub.write(0);
            rshift.write(a.read());
            lshift.write(a.read());
        }
    }

    SC_CTOR(alu)
    {
        SC_METHOD(compute_alu);
        sensitive<<a<<b<<op;
    }

};