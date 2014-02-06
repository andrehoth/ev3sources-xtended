v 20110115 2
C 40000 40000 0 0 0 title-B.sym
C 41000 46100 1 0 0 connector6-1.sym
{
T 42800 47900 5 10 0 0 0 0 1
device=CONNECTOR_6
T 41100 48100 5 10 1 1 0 0 1
refdes=RJ12
}
C 44100 45100 1 90 0 resistor-2.sym
{
T 43750 45500 5 10 0 0 90 0 1
device=RESISTOR
T 43800 45300 5 10 1 1 90 0 1
refdes=R1
}
N 42700 46600 44000 46600 4
N 44000 46600 44000 46000 4
C 43900 44600 1 0 0 gnd-1.sym
C 44400 44600 1 0 0 gnd-1.sym
N 44000 45100 44000 44900 4
N 42700 47200 44500 47200 4
N 44500 47200 44500 44900 4
T 41000 48500 9 20 1 0 0 0 1
EV3 DUMB OUTPUT
B 40500 44500 6500 4500 3 0 0 0 -1 -1 0 -1 -1 -1 -1 -1
C 45800 46800 1 0 0 dc_motor-1.sym
{
T 46200 47800 5 10 0 0 0 0 1
device=DC_MOTOR
T 46300 47400 5 10 1 1 0 0 1
refdes=M1
}
N 42700 47800 46000 47800 4
N 42700 47500 45500 47500 4
N 45500 47500 45500 46500 4
N 45500 46500 46000 46500 4
N 46000 46800 46000 46500 4
C 45100 45100 1 90 0 resistor-2.sym
{
T 44750 45500 5 10 0 0 90 0 1
device=RESISTOR
T 44800 45300 5 10 1 1 90 0 1
refdes=R2
}
C 44900 44600 1 0 0 gnd-1.sym
N 45000 45100 45000 44900 4
N 45000 47800 45000 46000 4
C 43800 47900 1 0 0 5V-plus-1.sym
C 43000 46200 1 0 0 nc-right-1.sym
{
T 43100 46700 5 10 0 0 0 0 1
value=NoConnection
T 43100 46900 5 10 0 0 0 0 1
device=DRC_Directive
}
N 44000 47900 44000 46900 4
N 44000 46900 42700 46900 4
N 42700 46300 43000 46300 4