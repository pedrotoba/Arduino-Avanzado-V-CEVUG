#!/usr/bin/python
# -*- coding: iso-8859-1 -*-

import serial
import sys
import time

serialPort = 'COM3'

def comunicacion():
	outfile = open('salidaTarea5.txt', 'w')
	x = 0
	while x < 10:
		arduinoPort = serial.Serial(serialPort, 9600, timeout=1)
		print '\nEstado del puerto: %s' % (arduinoPort.isOpen())
		# Reset manual del Arduino
		arduinoPort.setDTR(False)  
		time.sleep(0.3)  
		# Se borra cualquier data que haya quedado en el buffer
		arduinoPort.flushInput()  
		arduinoPort.setDTR()  
		time.sleep(0.3)
		#valor = arduinoPort.readline()
		getSerialValue = arduinoPort.read()
		#print '\n Valor de el sensor: %s' %(valor)
		print '\n Valor de el sensor: %s' %(getSerialValue)
		outfile = open('salidaTarea5.txt', 'w')
		outfile.write("Valor")
		outfile.write('x')
		outfile.write('\n')
		outfile.write(getSerialValue)
		#outfile.write(" ")
		outfile.close()
		arduinoPort.close() 
		x+=1

if __name__ == '__main__':
	comunicacion()
