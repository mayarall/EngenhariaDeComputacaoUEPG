import serial
import time
import numpy as np
from math import pi
from spatialmath import SE3
from roboticstoolbox import DHRobot, RevoluteDH


ser = serial.Serial(port="COM5",baudrate="9600")

class MYROBOT(DHRobot):
    def __init__(self):
        deg = pi / 180

        L0 = RevoluteDH(
            d=5.5,  # link length (Dennavit-Hartenberg notation)
            a=4.5,  # link offset (Dennavit-Hartenberg notation)
            alpha=pi / 2,  # link twist (Dennavit-Hartenberg notation)
            qlim=[0, 360 * deg])  # minimum and maximum joint angle

        L1 = RevoluteDH(
            d=0, a=11.5, alpha=0,
            qlim=[0, 180 * deg])

        L2 = RevoluteDH(
            d=0, a=10.5, alpha=0,
            qlim=[0, 180 * deg])

        L3 = RevoluteDH()

        super().__init__(
            [L0, L1, L2, L3],
            name="MYROBOT",
            manufacturer="UEPG")

robot = MYROBOT()

Tini = SE3.Trans([0,5,10]) * SE3.OA([0,1,0],[0,0,1])
Tfim = SE3.Trans([10,10,0]) * SE3.OA([0,1,0],[0,0,1])

sol_ini = robot.ikine_LM(Tini)#, qlim=True, ilimit=1000)
sol_fim = robot.ikine_LM(Tfim)#, qlim=True, ilimit=1000)

#
print(sol_ini.q*180/pi)
print()
print(sol_fim.q*180/pi)

print(robot.fkine(sol_ini.q))
print(robot.fkine(sol_fim.q))
#
n_passos = 5

variaveis = np.array([
    [sol_ini.q[0]*180/pi,sol_ini.q[1]*180/pi,sol_ini.q[2]*180/pi],
    [sol_fim.q[0]*180/pi,sol_fim.q[1]*180/pi,sol_fim.q[2]*180/pi]
    ])

time.sleep(1)

k = 0

while( k<1 ):
    for j in range(variaveis.shape[0]):
        dado1 = np.array(variaveis[j]) #np.array([85.0,40.0,20.0,50.0,10.0])
        a = j
        if(j+1 == variaveis.shape[0]):
            dado2 = np.array(variaveis[0]) #np.array([70.0,120.0,50.0,65.0,60.0])
            b = 0
        else:
            dado2 = np.array(variaveis[j+1]) #np.array([70.0,120.0,50.0,65.0,60.0])
            b = j+1

        dado_tmp = np.array([0.0,0.0,0.0])
        passo = np.array((dado2 - dado1)/n_passos)
        
        string_dado = "{:d};{:d};{:d}\0".format((sol_fim.q[0]*180/pi).astype(int), (sol_ini.q[1]*180/pi).astype(int), (sol_ini.q[2]*180/pi).astype(int))
        ser.write(bytes(string_dado, 'ascii'))
        time.sleep(5);
        
        for i in range(n_passos):
            dado1 += passo
            dado_tmp = (np.ceil(dado1)).astype(int)
            string_dado = "{:d};{:d};{:d}\0".format(0, abs(dado_tmp[1]), abs(dado_tmp[2]))
            ser.write(bytes(string_dado, 'ascii'))
            print(string_dado)
            time.sleep(0.5)

    k+=1

ser.close()
