#include<systemc.h>
SC_MODULE(driver)
{
    sc_out<sc_uint<4>> a,b;
    sc_out<sc_uint<2>>op;

    void inputs()
    {
        op.write(0);
        a.write(0);
        b.write(0);
        wait(5,SC_NS);

        op.write(0);
        a.write(1);
        b.write(1);
        wait(5,SC_NS);

        op.write(0);
        a.write(2);
        b.write(2);
        wait(5,SC_NS);

        op.write(0);
        a.write(5);
        b.write(4);
        wait(5,SC_NS);

        op.write(0);
        a.write(14);
        b.write(3);
        wait(5,SC_NS);

        op.write(0);
        a.write(9);
        b.write(10);
        wait(5,SC_NS);





        op.write(1);
        a.write(0);
        b.write(0);
        wait(5,SC_NS);

        a.write(1);
        b.write(1);
        wait(5,SC_NS);

        a.write(2);
        b.write(2);
        wait(5,SC_NS);

        a.write(5);
        b.write(4);
        wait(5,SC_NS);

        a.write(14);
        b.write(3);
        wait(5,SC_NS);

        a.write(9);
        b.write(10);
        wait(5,SC_NS);


        op.write(2);
        a.read(0);

        a.read(1);

        a.read(2);

        a.read(3);

        a.read(4);

        a.read(5);

        a.read(6);

        a.read(7);

        a.read(8);

        a.read(9);

        a.read(10);



        op.read(3);

        a.read(0);

        a.read(1);

        a.read(2);

        a.read(3);

        a.read(4);

        a.read(5);

        a.read(6);

        a.read(7);

        a.read(8);

        a.read(9);

        a.read(10);

        
    }
    SC_CTOR(driver)
    {
        SC_THREAD(inputs);
        sensitive<<a<<b<<op;
    }
}