#include<systemc.h>
#include "alu.h"
#include "driver.h"
#include "monitor.h"

int main(int argc,char *argv[])
{
    sc_signal<sc_uint<4>> a,b,add,sub,rshift,lshift,op;
    
    alu al("alu");
    driver drive("driver");
    monitor mon("monitor");

    al.a("a");
    al.b("b");
    al.add("add");
    al.sub("sub");
    al.rshift("rshift");
    al.lshift("lshift");

    drive.a("a");
    drive.b("b");
    drive.op("op");

    mon.a("a");
    mon.b("b");
    mon.add("add");
    mon.sub("sub");
    mon.rshift("rshift");
    mon.lshift("lshift");


    sc_trace_file *TF;

    Tf=sc_create_vcd_trace_file("traces");
    sc_trace(Tf,a,"a");
    sc_trace(Tf,b,"b");
    sc_trace(Tf,op,"op");
    sc_trace(Tf,add,"add");
    sc_trace(Tf,sub,"sub");
    sc_trace(Tf,rshift,"rshift");
    sc_trace(Tf,lshift,"lshift");

    sc_close_vcd_trace_file(Tf);

    return 0;
}
